#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{

	int pid;
	pid = fork();
	if(pid>0)
		printf("parent\n");
	if(pid == 0)
		printf("child");
	// char th[1024];
	// strcpy(th, "sahil");
	// // th[0] = 'a';
	// // th[1] = 'b';
	// // th[2] = '\0';
	// // for(int i=0; th[i]!='\0'; i++)
	// // 	printf("%c", th[i]);
	// puts(th);
	return 0;
}