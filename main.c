#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define NUMBER_OF_THREADS     5

void *Hello(void *i)
{
	long id = (long)i;
	printf("Wątek #%ld\n", id);
	pthread_exit(NULL);
	return NULL;
}

int main ()
{
	pthread_t threads[NUMBER_OF_THREADS];
	int error;
	long i;
	for(i=0; i<NUMBER_OF_THREADS; i++)
	{
		error = pthread_create(&threads[i], NULL, Hello, (void *)i);
		if (error)
		{
			printf("BŁĄÐ (przy tworzeniu wątku): %s\n", strerror(error));
			exit(-1);
		}
	}
	for(i=0; i<NUMBER_OF_THREADS; i++)
	{
		error = pthread_join(threads[i], NULL);
		if(error)
		{
			printf("BŁĄD (przy oczekiwaniu na zakończenie wątków): %s\n", strerror(error));
			exit(-1);
		}
	}
	printf("Koniec wątku głównego\n");
	pthread_exit(NULL);
	return 0;
}
