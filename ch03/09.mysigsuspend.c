#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>


void handler(int signo){
printf("Signal caught was # (%d)\n", signo);	

}


int main(){
	sigset_t set1, set2;
	
	signal(2,handler);

	sigemptyset(&set1);

	sigaddset(&set1,2);
	
	//set1 을 set2로 일단 저장.
	sigprocmask(SIG_BLOCK,&set1,&set2);

	printf("Critical section1 start \n");
	sleep(5);
	printf("Critical section 1 end \n");

	//sigsuspend(&set2);
	sigprocmask(SIG_SETMASK, &set2, NULL);
	pause();

	printf("Critical section1\n");
	sleep(5);
	printf("Critical section 1 end\n");

	sigprocmask(SIG_SETMASK, &set2, NULL);
	return 0;
}
