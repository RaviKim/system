#include <stdio.h>
#include <signal.h>
#include <unistd.h>
int print_sigset_t (sigset_t *set){
    int i;
    i = SIGRTMAX;
    while(i >= 4){ 
        int x = 0;
        i -= 4;
        if(sigismember(set, i+1)) x |= 1;
        if(sigismember(set, i+2)) x |= 2;
        if(sigismember(set, i+3)) x |= 3;
        if(sigismember(set, i+4)) x |= 4;
        printf("%x", x); 
    }   


    printf("\n");
}


int main(){
	sigset_t set1,set2,set3,set4;

	sigemptyset(&set1);	
	sigemptyset(&set2);	
	sigemptyset(&set3);	
	sigemptyset(&set4);	

	sigaddset(&set1, 1);
	sigaddset(&set2, 2);
	sigaddset(&set3, 3);
	sigaddset(&set4, 4);

	sigprocmask(SIG_BLOCK, &set1, NULL);
	sigprocmask(SIG_BLOCK, &set2, NULL);
	sigprocmask(SIG_SETMASK, &set3, NULL);
	sigprocmask(SIG_UNBLOCK, &set4, NULL);

while(1){
	printf("I am doing my job\n");
	sleep(1);
}
	return 0;
}
