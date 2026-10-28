#ifndef RTTSTATS_H
#define RTTSTATS_H
#include <stddef.h>

struct rttstats;
struct rttstats *rttstats_create(size_t cap);
void rttstats_destroy(struct rttstats *s);
void rttstats_push(struct rttstats *s, double rtt_ms);
void rttstats_push_loss(struct rttstats *s);
void rttstats_get(struct rttstats *s, struct rtt_summary *out);

#endif