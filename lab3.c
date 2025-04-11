int is_safe() {
	//TODO
	
	
	if(!found)
	{
		return -1;
	}

}

int periodical_detector(void *arg)
{
	while(1) {
		sleep(5);
		pthread_mutex_lock(&lock);
		if(!is_safe())
		{
			if(!finished)
			{
				break;
			}
		}
	}
	return 0;
}


int main()
{

}
