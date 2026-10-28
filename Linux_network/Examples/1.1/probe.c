#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <net/if.h>
#include "probe.h"

struct probe {
    char ifname[IF_NAMESIZE];
    double *samples;
    size_t cap, count;
};

struct probe *probe_create(const char *ifname, size_t history)
{
    struct probe *p = calloc(1,sizeof *p);
    if(!p)
        return NULL;

    if(strlen(ifname) >= sizeof p -> ifname)
    {
        errno = ENAMETOOLONG;
        goto err_free_p;
    }
    strcpy(p -> ifname, ifname);

    p -> samples = calloc(history, sizeof *p -> samples);
    if(!p -> samples)
        goto err_free_p;
    p -> cap = history;
    return p;

err_free_p:
    free(p);
    return NULL;
}

void probe_destroy(struct probe *p)
{
    if(!p)
        return;
    free(p -> samples);
    free(p);
}