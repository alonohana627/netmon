#ifndef NETMON_SOCKET_LISTENERS_H
#define NETMON_SOCKET_LISTENERS_H

#include <stdlib.h>
#include <packet_info.h>

#define BUFFER_SIZE 65536

void *tcp_listener(void *arg);
void *icmp_listener(void *arg);

#endif
