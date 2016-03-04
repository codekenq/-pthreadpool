pthread_pool:
	gcc -c -fpic ./pthreadpool/pthreadpool.c
	gcc -c -fpic ./queue/queue.c -lpthread
pthread_pool_link:
	gcc -shared -olibpthreadpool.so pthreadpool.o queue.o
