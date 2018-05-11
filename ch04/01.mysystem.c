#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
	char buf[128];

	printf("******************** system start *****************\n");
	system("ls -l");
	printf("******************** system end  *****************\n");
	system("cd /home/pi/Workspace.d/git.d/linuxSystem.d/lab");
	return 0;
}
