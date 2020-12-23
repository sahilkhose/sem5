#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<stdio.h>

int main()
{
	int s,r,recb,sntb,x,ns,a=0;
	socklen_t len;
	struct sockaddr_in server,client;
	char buff[50];

	s=socket(AF_INET,SOCK_STREAM,0);
	if(s==-1)
	{
		printf("\nSocket creation error.");
		exit(0);
	}
	printf("\nSocket created.");

	server.sin_family=AF_INET;
	server.sin_port=htons(3212);
	server.sin_addr.s_addr=htonl(INADDR_ANY);

	r=bind(s,(struct sockaddr*)&server,sizeof(server));
	if(r==-1)
	{
		printf("\nBinding error.");
		exit(0);
	}
	printf("\nSocket binded.");

	r=listen(s,2);
	if(r==-1)
	{
		close(s);
		exit(0);
	}
	printf("\nSocket listening.");

	len=sizeof(client);

	ns=accept(s,(struct sockaddr*)&client, &len);
	if(ns==-1)
	{
		close(s);
		exit(0);
	}
	printf("\nSocket accepting.");
	int f;
	recb = recv(ns, buff, sizeof(buff), 0);
	if(recb == -1){
		printf("Receive Error\n");
		close(s);
		exit(0);
	}
	printf("%lu\n", sizeof(buff));
	char arr[50];
	int ch = 1;
	while(ch != 4){
		recb = recv(ns, arr, sizeof(arr), 0);
		if(recb == -1){
			printf("Receive error inside while!\n");
			close(s);
			exit(0);
		}
		ch = arr[0];
		int n = arr[1];
		int search;
		int j, k, l, temp;
		switch(ch){
			case 1: search = arr[2];
					for( j = 0; j < n; j++){
						if(buff[j] == search){
							printf("Element found at %d\n", j+1);
							break;
						}
					}
					if(j >= n){
						printf("Element not found\n");
					}
					break;
			case 2: for(k = 0; k < (n-1); k++){
						for(l = k+1; l < n; l++){
							if(buff[k] > buff[l]){
								temp = buff[k];
								buff[k] = buff[l];
								buff[l] = temp;
							}
						}
					}


					for(k = 0; k < n; k++){
						printf("%d\n", buff[k]);
					}
					break;
			case 3: break;
			case 4: break;
			default: printf("Wrong Command\n");
		}
	}
		close(s);
	exit(0);
}

