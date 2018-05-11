#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_function(void *arg){
	int j;
	for(j = 0; j < 10; ++j){
		printf("\tThread (%d) -- %d\n", getpid(),j);
		sleep(1);
	}
 	printf("Enter to end thread job\n");
	getchar();
	return 0;
}

int main(){
	pthread_t tid;
	int i;
	int thread_ret;
	// thread 생성
	thread_ret = pthread_create(&tid,NULL,thread_function,(void *)NULL);
	if(thread_ret == -1){
		perror("Error");
		exit(1);
	}
	for(i = 0; i < 5; ++i){
		printf("Main Process(%d) -- %d\n",getpid(),i);
		sleep(1);
	} 
	
	getchar();
	return 0;
}


