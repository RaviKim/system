#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

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
		print("%x", x);
	}


	printf("\n");
}
