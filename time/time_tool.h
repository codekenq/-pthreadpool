#ifndef __TIME_TOOL_H__
#define __TIME_TOOL_H__
#include <time.h>

/*
 * This is a lib about time
 * */

void start_timen(struct timespec *);
void end_timen(struct timespec *);
void run_timen(struct timespec *, struct timespec *, struct timespec *);
void get_current_time(char *);
#endif /*__TIME_TOOL_H__*/
