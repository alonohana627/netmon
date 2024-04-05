#ifndef NETMON_NETMON_MEMORY_H
#define NETMON_NETMON_MEMORY_H

#include <pthread.h>

extern pthread_mutex_t mutex;

pthread_attr_t create_netmon_pthread_attr(void);

#endif //NETMON_NETMON_MEMORY_H
