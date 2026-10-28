#ifndef PROBE_H
#define PROBE_H
#include <stddef.h>

struct probe;
struct probe *probe_create(const char *name, size_t history);
void probe_destroy(struct probe *p);
int probe_add_sample(struct probe *p, double rtt_ms);

#endif