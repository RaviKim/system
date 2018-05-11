#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	int i;

	for(i = 0; i < atoi(argv[1]); i++){
		printf("MyTask _____%d\n", i);
		sleep(1);
	}

		return 0;
}
