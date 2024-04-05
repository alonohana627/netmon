#include <socket_listeners.h>

void *tcp_listener(void *arg) {
    int sockfd = *(int *) arg;
    char buffer[BUFFER_SIZE];
    ssize_t packet_size;

    while (1) {
        packet_size = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (packet_size < 0) {
            perror("recv");
            exit(EXIT_FAILURE);
        }

        print_tcp_packet_info(buffer, packet_size);
    }

    return NULL;
}

void *icmp_listener(void *arg) {
    int sockfd = *(int *) arg;
    char buffer[BUFFER_SIZE];
    ssize_t packet_size;

    while (1) {
        packet_size = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (packet_size < 0) {
            perror("recv");
            exit(EXIT_FAILURE);
        }

        print_icmp_packet_info(buffer, packet_size);
    }

    return NULL;
}
