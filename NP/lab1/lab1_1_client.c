#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(){
	int sockfd, retval, recvbytes, sendbytes;
	struct sockaddr_in server;
	char buff[50];

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd == -1){
		printf("Creation Error\n");
		exit(0);
	}

	server.sin_family = AF_INET;
	server.sin_port = htons(3212);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");

	retval = connect(sockfd, (struct sockaddr*)&server, sizeof(server));
	if(retval == -1){
		printf("Connection Error\n");
		exit(0);
	}
	printf("Socket Connected\n");
	int n;
	printf("Enter integers\n");
	scanf("%d", &n);
	printf("Enter integers\n");
	int arr[50];
	int i;
	for( i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	for(i = 0; i < n; i++){
		buff[i] = arr[i];
	}
	sendbytes = send(sockfd, buff, sizeof(buff), 0);
	if(sendbytes == -1){
		printf("Send Error\n");
		close(sockfd);
		exit(0);
	}

	printf("Array sent successfully!\n");

	int input = 0;
	while(input!=4)
	{
		printf("Select one of the following:\n");
		printf("\n1. Find ele\n 2. Sort array \n 3. Nothing \n 4. Exit\n");
		scanf("%d", &input);
		buff[0] = input;
		buff[1] = n;
		switch(input){
			case 1:
			printf("Enter the element to search:\n");
			int ele;
			scanf("%d", &ele);
			buff[2] = ele;
			sendbytes = send(sockfd, buff, sizeof(buff), 0);
			if(sendbytes == -1){
				printf("send error in case 1\n");
				close(sockfd);
				exit(0);
			}
			break;
			
			case 2:
			sendbytes = send(sockfd, buff, sizeof(buff), 0);
			if(sendbytes == -1){
				printf("send error in case 2\n");
				close(sockfd);
				exit(0);
			}
			break;
			
			case 3:
			break;
			case 4: sendbytes = send(sockfd, buff, sizeof(buff), 0);
			if(sendbytes == -1){
				printf("send error in case 2\n");
				close(sockfd);
				exit(0);
			}
			break;
			default: printf("Wrong Command\n");
		} 
	}

	close(sockfd);
	exit(0);
}