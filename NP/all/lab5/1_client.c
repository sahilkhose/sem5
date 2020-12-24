#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

int main(){
	int sockfd, recvbytes, sentbytes, retval;
	char buff[50];
	struct sockaddr_in server;

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
		close(sockfd);
		exit(0);
	}
	printf("Connection Estabilished\n");

	strcpy(buff, "Institute of");
	puts(buff);
	sentbytes = send(sockfd, buff, sizeof(buff), 0);
	if(sentbytes == -1 ){
		printf("Send Error\n");
		close(sockfd);
		exit(0);
	}


	close(sockfd);
	exit(0);

}