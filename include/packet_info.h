#ifndef PACKET_INFO_H
#define PACKET_INFO_H

#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>

#include <stdio.h>

#include <netmon_memory.h>

void print_tcp_packet_info(char *buffer, ssize_t packet_size);
void print_icmp_packet_info(char *buffer, ssize_t packet_size);

// General Payload Printer
void print_payload(char *payload, unsigned int payload_size);

#endif
