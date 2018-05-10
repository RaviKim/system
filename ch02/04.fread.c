#include <stdio.h>
#include <stdlib.h>
typedef struct _INFO{
	char name[20];
	int age;
	float height;
}INFO;

int main(int argc, char *argv[]){


	FILE *fp;
	size_t ret;
	int i;
	INFO data;

	if( argc <2){
		printf("USage: %s <filename>\n", argv[0]);
		exit(1);
	}

	fp = fopen(argv[1], "r");
	if(fp == NULL){
		perror("fopen");
		exit(1);
	}

	for(;;){
		ret = fread(&data, sizeof(INFO), 1, fp);
		if(feof(fp)) break;
		printf("Name : %s, Age : %d, Height : %1f",data.name, data.age, data.height);
	}
	getchar();
	fclose(fp);


	return 0;
}
