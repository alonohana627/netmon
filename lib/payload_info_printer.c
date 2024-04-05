#include <packet_info.h>

void print_payload(char *payload, unsigned int payload_size) {
    for (unsigned int i = 0; i < payload_size; ++i) {
        if (payload[i] >= 32 && payload[i] <= 126) {
            printf("%c", payload[i]);
        } else {
            printf(".");
        }
    }
}
