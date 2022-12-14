//
// Created by jgodinho on 22-09-2022.
//

#include "entrypoint.h"

static const char IP_FORMAT[] = "10.%d.%d.%d/31";
static const char CONTAINER_NAMESPACE_FORMAT[] = "containerns%d";
static const char ENTRYPOINT_VETH_FORMAT[] = "entrypointveth%d";
static const char CONTAINER_VETH_FORMAT[] = "containerveth%d";
static int ip_count_4 = 0;
static int ip_count_3 = 0;
static int ip_count_2 = 0;
static int container_namespace_count = 0;

void increment_counters() {
    container_namespace_count++;
    if (ip_count_4 == 255) {
        if (ip_count_3 == 255) {
            ip_count_2++;
        } else {
            ip_count_3++;
        }
    } else {
        ip_count_4++;
    }
}

void create_new_container() {
    char entrypoint_ip[256], container_ip[256], container_namespace_name[256], entrypoint_veth_name[256], container_veth_name[256];
    if (sprintf(entrypoint_ip, IP_FORMAT, ip_count_2, ip_count_3, ip_count_4) < 0) {
        printf("Error formatting ip\n");
        exit(0);
    }
    ip_count_4++;
    if (sprintf(container_ip, IP_FORMAT, ip_count_2, ip_count_3, ip_count_4) < 0) {
        printf("Error formatting ip\n");
        exit(0);
    }
    if (sprintf(container_namespace_name, CONTAINER_NAMESPACE_FORMAT, container_namespace_count) < 0) {
        printf("Error formatting container namespace\n");
        exit(0);
    }
    if (sprintf(entrypoint_veth_name, ENTRYPOINT_VETH_FORMAT, container_namespace_count) < 0) {
        printf("Error formatting ip\n");
        exit(0);
    }
    if (sprintf(container_veth_name, CONTAINER_VETH_FORMAT, container_namespace_count) < 0) {
        printf("Error formatting ip\n");
        exit(0);
    }
    increment_counters();
    isolate_container(entrypoint_ip, container_ip, container_namespace_name, entrypoint_veth_name, container_veth_name);
}

void run_entrypoint() {
    create_new_container();
    create_new_container();
}
