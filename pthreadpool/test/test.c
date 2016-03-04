#include <unistd.h>
#include "./pthreadpool.h"

int main()
{
	pthreadpool_init();
	sleep(5);
	pthreadpool_dump();
}
