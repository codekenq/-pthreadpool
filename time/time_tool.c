#include "time_tool.h"
#include <time.h>
#include <memory.h>
#include <stdio.h>

void start_timen(struct timespec* val)
{
	 memset(val, 0, sizeof(*val));
	 clock_gettime(CLOCK_REALTIME, val);
}

void end_timen(struct timespec* val)
{
	 memset(val, 0, sizeof(*val));
	 clock_gettime(CLOCK_REALTIME, val);
}

void run_timen(struct timespec* begin, struct timespec* end, struct timespec* differ)
{
	differ->tv_sec = end->tv_sec - begin->tv_sec;
	differ->tv_nsec = end->tv_nsec - begin->tv_nsec;
}

/*
 * 这个函数以Fri May 1 01:00:42 2015格式返回一个时间
 * This function return time as format Fri May 1 01:00:42 2015
 * */

void get_current_time(char buf) 
{
	 time_t t = time(NULL);
     struct tm *current = localtime(&t);
     sprintf(buf, "%s", asctime(current));
}
