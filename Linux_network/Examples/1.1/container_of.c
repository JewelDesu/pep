#include <stddef.h>
#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

struct list_node {struct list_node *next, *prev;};

struct wan_link {
    char name[16];
    int metric;
    struct list_node node;
};