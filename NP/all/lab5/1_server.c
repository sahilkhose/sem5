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

	pid_t child;
	socklen_t clilen;
	int connection = 0;
	char str[50];
	str[0] = '\0';
	while(1){
		clilen = sizeof(client);
	
		newsockfd = accept(sockfd, (struct sockaddr*) &client, &clilen);
		if(newsockfd == -1){
			printf("Accepting Error\n");
			close(sockfd);
			exit(0);
		}
		printf("Socket Accepting\n");
		connection++;
		if(connection > 2){
				printf("Connection exceeds Max Limit\n");
				FILE *fptr1, *fptr2;
				if((fptr1 = fopen("new.txt", "r")) == NULL){
					close(newsockfd);
					close(sockfd);
					exit(0);
				}
				char temp[100];
				char str[100];
				while(fgets(temp, 100, fptr1) != NULL){
					strcpy(str, temp);
					printf("%s\n", str );
				}
				if(fptr1){
					fclose(fptr1);
				}
				if((fptr2 = fopen("ip.txt", "r")) == NULL){
					close(newsockfd);
					close(sockfd);
					exit(0);
				}
				char temp2[100];
				char str2[100];
				while(fgets(temp2, 100, fptr2) != NULL){
					strcpy(str2, temp2);
					printf("%s\n", str2 );
				}
				if(fptr2){
					fclose(fptr2);	
				}
				close(newsockfd);
				close(sockfd);
				exit(0);
			}
			printf("%s\n", str);
		if((child = fork()) == 0){
			
			close(sockfd);
			recvbytes = recv(newsockfd, buff, sizeof(buff), 0);
			if(recvbytes == -1){
				printf("Receiving Error\n");
				close(newsockfd);
				exit(0);
			}
			puts(buff);
			strcat(str, buff);
			strcat(str, " ");
			FILE *fp;
			fp = fopen("ip.txt", "a");
			char ip[INET_ADDRSTRLEN];
			inet_ntop(AF_INET, &client.sin_addr, ip, sizeof(ip));
			fputs(ip, fp);
			fputs(" ", fp);
			fclose(fp);
			FILE *fp1;
			fp1 = fopen("new.txt", "a");
			fputs(buff, fp1);
			fputs(" ", fp1);
			fclose(fp1);
			close(newsockfd);
		}
		
	}
	
	close(sockfd);
	exit(0);
}