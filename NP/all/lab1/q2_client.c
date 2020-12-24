#include<string.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<fcntl.h>
#include<sys/stat.h>

int main()
{
    int s,r,recvbytes,sentbytes;
    socklen_t sa;
    socklen_t len;
    struct sockaddr_in server,client;
    char buff[50];
    s=socket(AF_INET,SOCK_DGRAM,0);
    if(s==-1)
    {
   	 printf("\nSocket creation error.");
   	 exit(0);
    }
    printf("\nSocket created.");
    server.sin_family=AF_INET;
    server.sin_port=htons(3212);
    server.sin_addr.s_addr=inet_addr("127.0.0.1");
    sa=sizeof(server);
    len=sizeof(server);

while(1){
    
    printf("\n\n");
    printf("Enter new string: ");
    gets(buff);
    // scanf("%s", buff);
    sentbytes=sendto(s,buff,sizeof(buff),0,(struct sockaddr *)&server, len);
    if(!strcmp(buff,"Halt"))
   	 break;
    if(sentbytes==-1)
    {
   	 close(s);
   	 printf("\nSend Error");
   	 exit(0);
    }

    recvbytes=recvfrom(s,buff,sizeof(buff),0,(struct sockaddr *)&server,&sa);
    if(recvbytes==-1)
    {
   	 printf("\n Receive Error");    
   	 close(s);
   	 exit(0);
    }
    if(buff[0]==1)
    printf("\nPalindrome String \nString Length: %d\nNo of vowels: %d  ",buff[1],buff[2]);
    else
   	 printf("\n Not a Palindrome \nString Length: %d\nNo of vowels: %d ",buff[1],buff[2]);

    }
    close(s);

}