#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
	int fd;
	int cnt =0;
	char buf[128];

	if((mkfifo("/tmp/myfifo", S_IRUSR | S_IWUSR)) == -1){
		perror("mkfifo");
		exit(1);
	}
	fd = open("tmp/myfifo", O_RDWR);

	for(;;){
		memset(buf, 0, sizeof(buf));
		read(fd, buf, sizeof(buf));
		printf("RX -- %d : %s\n", cnt, buf);
		if(strstr(buf, "end")){
			break;
		}
	}
	unlink("/tmp/myfifo");
		close(fd);
	return 0;
}
