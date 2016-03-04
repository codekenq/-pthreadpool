#include <time.h>
#include <stdio.h>
#include "time_tool.h"

int main()
{
	  struct timespec begin;
	  struct timespec end;
	  struct timespec differ;

	  start_timen(&begin);
	  printf("delay\n");
	  end_timen(&end);
	  run_timen(&begin, &end, &differ);
	  printf("differ sec: %ld\ndiffer nsec:%ld\n", differ.tv_sec, differ.tv_nsec);
}
