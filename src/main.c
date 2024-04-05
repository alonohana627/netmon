#include <stdlib.h>

#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "packet_info.h"
#include "netmon_memory.h"
#include "socket_listeners.h"


int main() {
    int sockfd, icmpfd;
    pthread_t tcp_thread, icmp_thread;
    pthread_attr_t attr = create_netmon_pthread_attr();

    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP)) < 0) {
        perror("Creating Raw TCP Socket Error!\n");
        exit(EXIT_FAILURE);
    }
    if ((icmpfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("Creating Raw ICMP Socket Error!\n");
        exit(EXIT_FAILURE);
    }

    pthread_create(&icmp_thread, &attr, icmp_listener, &icmpfd);
    pthread_create(&tcp_thread, &attr, tcp_listener, &sockfd);

    pthread_attr_destroy(&attr);

    while (1) {
        getchar();
        break;
    }

    close(sockfd);
    close(icmpfd);

    return 0;
}
