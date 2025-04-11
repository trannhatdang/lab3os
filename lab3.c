#include <stdio.h>
#include <string.h>
#include <time.h>
#include <float.h>
#include <pthread.h>

bool break = false;

void dummy_func()
{
	char[200] input;
	while(fgets(input, 200, stdin))
	{
		pthread_mutex_lock(&lock);
		if(strcmp(input, "err"))
		{
			break = true;
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


}
