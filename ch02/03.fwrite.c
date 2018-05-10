#include <stdio.h>
#include <stdlib.h>



typedef struct _INFO{
	char name[20];
	int age;
	float height;
}INFO;



int main(int argc, char **argv){

	INFO data[3] = {
		"Ravi", 30,160.1F,
		"KIM", 22, 170.5F,
		"Lee", 30, 155,
	};

	FILE *fp;
	size_t ret;

	if(argc <2){
		printf("Usage: %s <filename>\n", argv[0]);
		exit(1);
	}

	fp = fopen(argv[1], "w");
	if(fp == NULL){
		perror("fopen");
		exit(1);
	}
	int i;
	for(i = 0; i < 3; ++i){
		ret = fwrite(&data[i],sizeof(INFO),1, fp);
		if(ret == 0)
			perror("fwrite");
	}
	getchar();
	fclose(fp);
	return 0;	
}
