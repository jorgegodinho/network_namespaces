//
// Created by jgodinho on 22-09-2022.
//

#include "enable_lo.h"

static const char ENABLE_LO[] = "ip netns exec %s ip link set dev lo up";

void enable_lo(char *container_namespace_name) {
    char command[256];
    if (sprintf(command, ENABLE_LO, container_namespace_name) < 0) {
        printf("Error formatting enable_lo command\n");
        exit(0);
    }
    printf("cmd: %s\n", command);
    if (system(command) == -1) {
        printf("Error while running enable_lo command\n");
        exit(0);
    }
}
