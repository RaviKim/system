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
   return "thank you";
}

int main(){
    pthread_t tid;
    int i;
    int thread_ret;
	void * thread_result;
    // thread 생성
    thread_ret = pthread_create(&tid,NULL,thread_function,(void *)NULL);

    if(thread_ret == -1){
        perror("Error");
        exit(1);
    }   

//    pthread_join(tid, &thread_result);
printf("Thread Returned with %s\n", thread_result);

    for(i = 0; i < 5; ++i){
        printf("Main Process(%d) -- %d\n",getpid(),i);
        sleep(1);
    }   

    pthread_join(tid, &thread_result);

    return 0;
}


