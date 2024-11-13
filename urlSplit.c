#include <stdio.h>
#include <string.h>

void split_url(char *url) {
    char scheme[50], host[100], path[200], port[10];
    int scheme_end, host_start, path_start;

    // Extract Scheme
    scheme_end = strstr(url, "://") - url;
    strncpy(scheme, url, scheme_end);
    scheme[scheme_end] = '\0';

    // Extract Host
    host_start = scheme_end + 3;
    path_start = strstr(url + host_start, "/") - url;
    if (path_start == -1) path_start = strlen(url); // no path present

    strncpy(host, url + host_start, path_start - host_start);
    host[path_start - host_start] = '\0';

    // Extract Path
    strcpy(path, url + path_start);

    // Extract Port (if any)
    char *port_start_pos = strstr(host, ":");
    if (port_start_pos != NULL) {
        // Port exists, calculate the length of the port and extract it
        int port_len = strlen(host) - (port_start_pos - host) - 1;
        strncpy(port, port_start_pos + 1, port_len);
        port[port_len] = '\0';
        // Null-terminate the host at the port position
        host[port_start_pos - host] = '\0';
    } else {
        // Default port for HTTP
        strcpy(port, "80");
    }

    // Printing the results
    printf("Scheme: %s\n", scheme);
    printf("Host: %s\n", host);
    printf("Port: %s\n", port);
    printf("Path: %s\n", path);
}

int main() {
    char url[300];

    printf("Enter a URL: ");
    fgets(url, sizeof(url), stdin);
    url[strcspn(url, "\n")] = 0;  // Remove the newline character from the input

    split_url(url);




    return 0;
}







/*
Enter a URL: https://www.example.com:8080/path/to/resource
Scheme: https
Host: www.example.com
Port: 8080
Path: /path/to/resource


*/
