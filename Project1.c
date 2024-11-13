#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_SEQ 7
#define WINDOW_SIZE 4

void send_frame(int frame) {
    printf("Sending frame %d\n", frame);
}

int receive_ack(int frame) {
    int ack_received;
    printf("Enter ACK (1 for received, 0 for not received) for frame %d: ", frame);
    scanf("%d", &ack_received);
    return ack_received;
}

void selective_repeat_sender(int num_frames) {
    int next_frame_to_send = 0,i;
    int ack_received[MAX_SEQ + 1] = {0};  

    while (next_frame_to_send < num_frames) {
        if (next_frame_to_send < num_frames) {
            send_frame(next_frame_to_send);
        }

        for ( i = 0; i < next_frame_to_send + 1 && i < num_frames; i++) {
            int ack = receive_ack(i);
            if (ack == 1) {
                ack_received[i] = 1;
                printf("Received ACK for frame %d\n", i);
            } else {
                printf("No ACK for frame %d, retransmitting\n", i);
                send_frame(i);
            }
        }

        next_frame_to_send++;
        sleep(1);
    }

    printf("All frames successfully acknowledged!\n");
}

int main() {
    int num_frames;

    printf("Enter the number of frames to be sent: ");
    scanf("%d", &num_frames);

    selective_repeat_sender(num_frames);

    return 0;
}









/*
Enter the number of frames to be sent: 5
Enter ACK (1 for received, 0 for not received) for frame 0: 1
Enter ACK (1 for received, 0 for not received) for frame 1: 0
Enter ACK (1 for received, 0 for not received) for frame 1: 1
Enter ACK (1 for received, 0 for not received) for frame 2: 1
Enter ACK (1 for received, 0 for not received) for frame 3: 0
Enter ACK (1 for received, 0 for not received) for frame 3: 1
Enter ACK (1 for received, 0 for not received) for frame 4: 1

*/
