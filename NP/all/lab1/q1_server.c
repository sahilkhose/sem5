#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(){
    int sockfd, newsockfd, retval;
    struct sockaddr_in serveraddr, clientaddr;
    char buff[50];

    int recvdbytes, sentbytes;
    int addrlen;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1){
   	 printf("Error in creating socket\n");
   	 exit(0);
    }
    printf("Socket Created\n");
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(3212);
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");



    retval = bind(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr));

    if(retval == -1){
   	 printf("Error in binding\n");
   	 exit(0);
    }
    printf("Bind Successful\n");

    retval = listen(sockfd, 5);

    if(retval == -1){
   	 printf("Error in Listening\n");
   	 exit(0);
    }
    printf("Listen Successful\n");

    addrlen = sizeof(clientaddr);

    newsockfd = accept(sockfd, (struct sockaddr *) &clientaddr, &addrlen);

    if(newsockfd == -1){
   	 printf("Error in Accepting\n");
   	 close(sockfd);
   	 exit(0);
    }

    printf("Accept Successful\n");
    char a[50];
    recvdbytes = recv(newsockfd, a, sizeof(a), 0);
    if(recvdbytes == -1){
   	 printf("Error in Receiving\n");
   	 close(newsockfd);
   	 close(sockfd);
   	 exit(0);
    }
    
    printf("Recieved Successful\n");
    
    int z = 1, n, search;
    while(z!=5){
   	 recvdbytes = recv(newsockfd, buff, sizeof(buff), 0);
   	 if(recvdbytes == -1){

   		 printf("Receive Error\n");
   		 close(sockfd);
   		 close(newsockfd);
   		 exit(0);
   	 }
   	 n = buff[0];
   	 z = buff[1];
     int l, i, j, temp;
   	 switch(z){
   		 case 1: search = buff[2];
   				 for(l = 0; l < n; l++){
   					 if(a[l] == search)
   						 break;
   				 }
   				 if(l==n)
   					 printf("Element not found\n");
   				 else
   					 printf("Element exists at %d\n",l+1 );
   				 break;
   		 case 2: for(i=0;i<n-1;i++)
   				 {
   					 for(j=0;j<n-i-1;j++)
   						 {
   							 if(a[j]>a[j+1])
   							 {
   								 temp=a[j];
   								 a[j]=a[j+1];
   								 a[j+1]=temp;
   							 }
   						 }
   				 }
   				 printf("\nSorted array is: \n");
   				 for(i=0;i<n;i++)
   					 printf("%d  ",a[i]);
   				 printf("\n\n");
   				 break;
   		 case 3: for(i=0;i<n-1;i++)
   				 {
   					 for(j=0;j<n-i-1;j++)
   						 {
   							 if(a[j]<a[j+1])
   							 {
   								 temp=a[j];
   								 a[j]=a[j+1];
   								 a[j+1]=temp;
   							 }
   						 }
   				 }
   				 printf("\nSorted array is: \n");
   				 for(i=0;i<n;i++)
   					 printf("%d  ",a[i]);
   				 printf("\n\n");
   				 break;
   		 case 4:
   		 printf("\nEven aay is: \n");
   				 for(i=0;i<n;i++)
   				 {
   					 if(a[i]%2==0)
   						 printf("%d ",a[i]);
   				 }
   				 printf("\n\nOdd aay is: \n");
   				 for(i=0;i<n;i++)
   				 {
   					 if(a[i]%2!=0)
   						 printf("%d ",a[i]);
   				 }
   				 printf("\n\n");
   				 break;
   		 case 5: break;
   		 default: break;
   	 }
    }
    close(newsockfd);
    close(sockfd);

    exit(0);


}