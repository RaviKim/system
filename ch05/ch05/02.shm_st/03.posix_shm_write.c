#include <stdio.h>
#include <unistd.h>  
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h> 

#define  MEM_SIZE    1024

int main() {
	int fd;
	void *shm_addr;
	int count;
	
	//�޸� ��ü ����
	fd = ______("______", O_RDWR | O_CREAT, 0777);
	if(fd == -1){
		perror("shm_open");
		exit(1);
		//return EXIT_FAILURE;
	}
	
	//�޸� ��ü ũ�� ����
	if(_____(fd, MEM_SIZE) == -1){
		perror("ftruncate");
		return EXIT_FAILURE;
	}
		
	//�޸� ��ü ����
	shm_addr = _____(0, ______, PROT_READ | PROT_WRITE, ______, fd, 0);
	if(shm_addr == (void *)-1){
		perror("mmap error");
		return EXIT_FAILURE;
	}
	
	printf( "Map addr is %p\n", shm_addr );
	
	for(count=11; count<=20; count++){
		// write counter to shared memory
		sprintf( (char *)shm_addr, "%d", count);  
		sleep(1);
	}
	sprintf( (char *)shm_addr, "end");
	
	printf("Input Enter to unmap shm...");
	getchar();
	
	______(_____, ______);
	close(fd);
	
	________("/mydata");
	
	return 0;
}