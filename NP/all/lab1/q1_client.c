#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
int main(){
    int sockfd, retval;
    struct sockaddr_in serveraddr;

    char buff[50];

    int recvbytes, sendbytes;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1){
   	 printf("Socket Creation Error\n");
   	 exit(0);
    }
    printf("Socket Created\n");

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(3212);
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    retval = connect(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr));

    if(retval == -1){
   	 printf("connection failed\n");
   	 exit(0);
    }
    printf("connected successfully\n");
    int n;
    int a[50];
    char ca[50];
    printf("Number of Integers \n");
    scanf("%d", &n);
    printf("Enter Integers\n");
    int i;
    for(i = 0; i < n; i++){
   	 scanf("%d", &a[i]);
    }
    for(i = 0; i < n; i++){
   	 ca[i] = a[i];
    }
    
    sendbytes = send(sockfd, ca, sizeof(ca), 0);

    if(sendbytes == -1){
   	 close(sockfd);
   	 printf("Send Error\n");
   	 exit(0);
    }
    
    int z = 1;

    while(z!=5){
   	 printf("Choose an option\n1) Search a number\n2) Ascending sort\n3) Descending sort\n4) Split into even and odd\n5) Exit \n");
   	 scanf("%d", &z);
   	 switch(z){
   		 case 1: printf("Enter number to search");
   				 int search;
   				 scanf("%d", &search);
   				 buff[0] = n;
   				 buff[1] = 1;
   				 buff[2] = search;
   				 sendbytes = send(sockfd, buff, sizeof(buff), 0);
   				 if(sendbytes == -1){
   					 close(sockfd);
   					 printf("Send Error\n");
   					 exit(0);
   				 }
   				 break;
   		 case 2: buff[0] = n;
   				 buff[1] = 2;
   				 sendbytes = send(sockfd, buff, sizeof(buff), 0);
   				 if(sendbytes == -1){
   					 close(sockfd);
   					 printf("Send Error\n");
   					 exit(0);
   				 }
   				 break;
   		 case 3: buff[0] = n;
   				 buff[1] = 3;
   				 sendbytes = send(sockfd, buff, sizeof(buff), 0);
   				 if(sendbytes == -1){
   					 close(sockfd);
   					 printf("Send Error\n");
   					 exit(0);
   				 }
   				 break;
   		 case 4: buff[0] = n;
   				 buff[1] = 4;
   				 sendbytes = send(sockfd, buff, sizeof(buff), 0);
   				 if(sendbytes == -1){
   					 close(sockfd);
   					 printf("Send Error\n");
   					 exit(0);
   				 }
   				 break;
   		 case 5: buff[0] = n;
   				 buff[1] = 5;
   				 sendbytes = send(sockfd, buff, sizeof(buff), 0);
   				 if(sendbytes == -1){
   					 close(sockfd);
   					 printf("Send Error\n");
   					 exit(0);
   				 }
   				 break;
   		 default: printf("Enter valid option\n");

   	 }
    }

    close(sockfd);
    exit(0);
}