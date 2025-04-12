#include <stdio.h>
#include <string.h>
#include <time.h>
#include <float.h>
#include <pthread.h>

bool break = false;

void dummy_func(void *arg)
{
	char[200] input;
	while(fgets(input, 200, stdin))
	{
		pthread_mutex_lock(&lock);
		if(strcmp(input, "err"))
		{
			break = true;
			while(1)
			{

			}
		}
		pthread_mutex_unlock(&lock);
	}
	printf("\nexiting...");
}


int is_safe() 
{	
	if(!break)
	{
		return -1;
	}
}

int periodical_detector(void *arg)
{
	while(1) {
		sleep(5);
		pthread_mutex_lock(&lock);
		if(is_safe() == -1)
		{	
			pthread_mutex_unlock(&lock);
			break;
		}
		pthread_mutex_unlock(&lock);
	}
}


int main()
{
	pthread_t dummy_func_thread;
	pthread_t detect;


	pthread_create(&dummy_func_thread, NULL, &dummy_func, NULL);
	pthread_create(&detect, NULL, &periodical_detector, NULL);

}
