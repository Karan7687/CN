#include <stdio.h>
#include <stdlib.h>

#define MAX_BUCKET_CAPACITY 10  // Maximum number of packets the bucket can hold
#define LEAK_RATE 1             // Packets per unit of time (leak rate)

int bucket = 0;                // Current number of packets in the bucket

// Function to simulate incoming packets and processing them
void process_packet(int packet) {
    if (bucket < MAX_BUCKET_CAPACITY) {
        // Add packet to bucket if there is space
        bucket++;
        printf("Packet %d added to the bucket. Current bucket size: %d\n", packet, bucket);
    } else {
        // Drop packet if bucket is full
        printf("Bucket is full. Packet %d is dropped.\n", packet);
    }
}

// Function to simulate the leaking of packets
void leak_packets() {
    if (bucket > 0) {
        bucket -= LEAK_RATE;  // Leak one packet per unit of time
        if (bucket < 0) {
            bucket = 0;  // Prevent bucket size from being negative
        }
        printf("Leaking... Current bucket size: %d\n", bucket);
    } else {
        printf("No packets to leak.\n");
    }
}

int main() {
    int choice;
    int packet;

    printf("Leaky Bucket Algorithm Simulation\n");

    while (1) {
        printf("\nEnter 1 to simulate incoming packet or 2 to simulate leak or 3 to exit: ");
        scanf("%d", &choice);

        if (choice == 1) {
            // Simulate incoming packet
            printf("Enter packet number: ");
            scanf("%d", &packet);
            process_packet(packet);
        } else if (choice == 2) {
            // Simulate leaking of packets
            leak_packets();
        } else if (choice == 3) {
            // Exit the simulation
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}




/*
Enter 1 to simulate incoming packet or 2 to simulate leak or 3 to exit: 1
Enter packet number: 1

Enter 1 to simulate incoming packet or 2 to simulate leak or 3 to exit: 1
Enter packet number: 2

Enter 1 to simulate incoming packet or 2 to simulate leak or 3 to exit: 2
Leaking... Current bucket size: 1

Enter 1 to simulate incoming packet or 2 to simulate leak or 3 to exit: 1
Enter packet number: 3

Enter 1 to simulate incoming packet or 2 to simulate leak or 3 to exit: 2
Leaking... Current bucket size: 0

Enter 1 to simulate incoming packet or 2 to simulate leak or 3 to exit: 1
Enter packet number: 4
*/
