#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

int main(){
	int sockfd, newsockfd, retval, recvbytes, sendbytes;
	char buff[50];
	struct sockaddr_in server, client;
	printf("Hi\n");
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd == -1){
		printf("Creation Error\n");
		exit(0);
	}

	server.sin_family = AF_INET;
	server.sin_port = htons(3212);
	server.sin_addr.s_addr = htonl(INADDR_ANY);

	retval = bind(sockfd, (struct sockaddr*) &server, sizeof(server));
	if(retval == -1){
		printf("Binding Error\n");
		exit(0);
	}
	printf("Socket Binded\n");

	retval = listen(sockfd, 5);
	if(retval == -1){
		printf("Listening Error\n");
		exit(0);
	}
	printf("Socket Listening\n");
	socklen_t clilen;
	while(1){
		clilen = sizeof(client);
		newsockfd = accept(sockfd, (struct sockaddr*)&client, &clilen);
		if(newsockfd == -1){
			printf("Accepting Error\n");
			close(sockfd);
			exit(0);
		}
		printf("Socket Accepting\n");	

		char temp1[50], temp2[50];
		recvbytes = recv(newsockfd, temp1, sizeof(temp1), 0);
		if(recvbytes == -1){
				printf("Receiving Error\n");
				close(newsockfd);
				exit(0);
			}
		puts(temp1);
		recvbytes = recv(newsockfd, temp2, sizeof(temp2), 0);
		if(recvbytes == -1){
				printf("Receiving Error\n");
				close(newsockfd);
				exit(0);
			}
		puts(temp2);

		if(strlen(temp1)!=strlen(temp2)){
			printf("Not anagram\n");
			sendbytes = send(newsockfd, "Not an anagram", sizeof("Not an anagram"), 0);
				if(sendbytes == -1){
				printf("Send Error\n");
				close(newsockfd);
				close(sockfd);
				exit(0);

		}		
	}
		else{
			int t1[26] = {0};
			int t2[26] = {0};
			for(int i = 0; i < strlen(temp1); i++){
				t1[i]++;
			}
			for(int i = 0; i < strlen(temp2); i++){
				t2[i]++;
			}
			int i;
			for(i = 0; i < 26; i++){
				if(t1[i] != t2[i]){
					break;
				}
			}
			if(i != 26){
				sendbytes = send(newsockfd, "Not an anagram", sizeof("Not an anagram"), 0);
				if(sendbytes == -1){
				printf("Send Error\n");
				close(newsockfd);
				close(sockfd);
				exit(0);
			}
			}
			else{
				sendbytes = send(newsockfd, "Anagram", sizeof("Anagram"), 0);
				if(sendbytes == -1){
				printf("Send Error\n");
				close(sockfd);
				close(newsockfd);
				exit(0);
			}
		}
	}
	close(newsockfd);
}

	
	close(sockfd);
	exit(0);
}