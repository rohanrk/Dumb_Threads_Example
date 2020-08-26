#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

void* first_routine(void *arg);
void* second_routine();

int main() {
	pthread_t producer_thread, consumer_thread;
	int result = pthread_create(&producer_thread, NULL, first_routine, &consumer_thread); 
	if (result) {
		fprintf(stderr, "%s\n", strerror(result));
	}
	result = pthread_create(&consumer_thread, NULL, second_routine, NULL);
	if (result) {
		fprintf(stderr, "%s\n", strerror(result));
	}
	pthread_join(producer_thread, NULL);
}

void* first_routine(void *arg) {
	pthread_t *threadToJoin = arg;
	void *thread_return;
	int result = pthread_join(*threadToJoin, &thread_return);
	if (result) {
		fprintf(stderr, "%s\n", strerror(result));
	}
	printf("%d\n", (int)thread_return);
	return thread_return;
}

void* second_routine() {
	sleep(2);
	return (void*) 1;
}
