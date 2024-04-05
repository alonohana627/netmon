#include <packet_info.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void print_tcp_packet_info(char *buffer, ssize_t packet_size) {
    struct iphdr *ip_header = (struct iphdr *) buffer;
    struct tcphdr *tcp_header = (struct tcphdr *) (buffer + sizeof(struct iphdr));
    char *payload = buffer + sizeof(struct iphdr) + sizeof(struct tcphdr);
    unsigned int payload_size = packet_size - sizeof(struct iphdr) - sizeof(struct tcphdr);

    pthread_mutex_lock(&mutex);

    printf("Source IP: %s\n", inet_ntoa(*(struct in_addr *) &(ip_header->saddr)));
    printf("Destination IP: %s\n", inet_ntoa(*(struct in_addr *) &(ip_header->daddr)));
    printf("Source Port: %u\n", ntohs(tcp_header->source));
    printf("Destination Port: %u\n", ntohs(tcp_header->dest));
    printf("Payload Size: %d bytes\n", payload_size);

    printf("Payload Data:\n");
    // Print payload data as ASCII text
    print_payload(payload, payload_size);
    printf("\n");
    pthread_mutex_unlock(&mutex);
}

void print_icmp_packet_info(char *buffer, ssize_t packet_size) {
    struct iphdr *ip_header = (struct iphdr *) buffer;
    struct icmphdr *icmp_header = (struct icmphdr *) (buffer + sizeof(struct iphdr));
    char *payload = buffer + sizeof(struct iphdr) + sizeof(struct icmphdr);
    int payload_size = packet_size - sizeof(struct iphdr) - sizeof(struct icmphdr);

    pthread_mutex_lock(&mutex);

    printf("Source IP: %s\n", inet_ntoa(*(struct in_addr *) &(ip_header->saddr)));
    printf("Destination IP: %s\n", inet_ntoa(*(struct in_addr *) &(ip_header->daddr)));
    printf("ICMP Type: %u\n", icmp_header->type);
    printf("ICMP Code: %u\n", icmp_header->code);
    printf("ICMP Checksum: %u\n", icmp_header->checksum);
    printf("Payload Size: %d bytes\n", payload_size);

    printf("Payload Data:\n");
    // Print payload data as ASCII text
    print_payload(payload, payload_size);
    printf("\n");
    pthread_mutex_unlock(&mutex);
}