#include "netmon_memory.h"

pthread_attr_t create_netmon_pthread_attr(void) {
    pthread_attr_t attr;

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    return attr;
}
