#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <malloc.h>
#include <string.h>
#include <unistd.h>


typedef struct alarm_tag{
	int seconds;
	char msg[64];
}alarm_t;

void *alarm_function(void *arg){
	alarm_t *alarm;
	alarm = (alarm_t *)arg;
	sleep(alarm -> seconds);
	printf("(%d) %s\n", alarm -> seconds, alarm -> msg);
	free(alarm);
	pthread_exit(NULL);
}


int main(void){
	char line[128];
	char msg[64];
	alarm_t *alarm;
	pthread_t tid;


	while(1){
		printf("Alarm> ");
		if(fgets(line, sizeof(line), stdin) == NULL) exit(0);
		if(strlen(line) < 1) continue;
		if(!strncmp(line, "exit", 4))	pthread_exit(NULL);

		alarm = (alarm_t *) malloc (sizeof(alarm_t));

		sscanf(line, "%d %s\n", &alarm->seconds, alarm->msg);
		pthread_create(&tid, NULL, alarm_function, alarm);

	}
	pthread_exit(NULL);
}
