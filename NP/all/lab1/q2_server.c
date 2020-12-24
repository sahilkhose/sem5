#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<stdio.h>

int main()
{
    int s,r,recvbytes,sentbytes,x;
    socklen_t ca;
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
    server.sin_addr.s_addr=htonl(INADDR_ANY);
    len=sizeof(client);
    ca=sizeof(client);

    r=bind(s,(struct sockaddr*)&server,sizeof(server));
    if(r==-1)
   	 {
   	 printf("\nBinding error.");
   	 exit(0);
    }
    printf("\nSocket binded.");
while(1){

    recvbytes=recvfrom(s,buff,sizeof(buff),0,(struct sockaddr*)&client,&ca);
    if(recvbytes==-1)
    {
   	 printf("\nMessage Recieving Failed");   	 
   	 close(s);
   	 exit(0);
    }    
    printf("\nMessage Recieved: ");
    printf("%s\n", buff);
    if(!strcmp(buff,"Halt"))
   	 break;
    

    char buff2[50];
    strcpy(buff2,buff);
    buff[1]=strlen(buff2);
    int n=0, i;
    for(i=0;i<buff[1];i++)
   	 if(buff2[i]=='a'||buff2[i]=='e'||buff2[i]=='o'||buff2[i]=='i'||buff2[i]=='u')
   		 n++;
    buff[2]=n;
    buff[0]=1;
    for(i=0;i<buff[1]/2;i++)
    {
   	 if(buff2[i]!=buff2[buff[1]-i-1])
   	 {
   		 buff[0]=0;
   		 break;
   	 }
    }
    sentbytes=sendto(s,buff,sizeof(buff),0,(struct sockaddr*)&client,len);
    if(sentbytes==-1)
    {
   	 printf("\nMessage Sending Failed");
   	 close(s);
   	 exit(0);
    }
    
    if(!strcmp(buff,"halt"))
   	 break;

}
    close(s);
}