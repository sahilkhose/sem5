#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<stdio.h>


//// more than 1 digit num:


int main()
{
    FILE *fp;
    char filename[]="a.txt";
    fp=fopen(filename,"r");
    if (fp==NULL) {printf("\nfile not found");return 0;}
    char c;
  
   int tot=1;
    char word[1024];
    while(fscanf(fp,"%s",word)!=EOF)
    {int x;
    sscanf(word, "%d", &x);
       tot=tot*x;
    }
    printf("\n%d",tot);
    printf("\n");
    return 0;
}







//// getc:

// int main()
// {
// 	FILE *a;
// 	a = fopen("a.txt", "r");
// 	char c;
// 	int con=1, temp;
// 	while((c = fgetc(a)) != EOF)
// 	{
		
// 		if(c >= '0' && c <= '9')
// 		{
// 			printf("%c", c);
// 			temp = c - '0';
// 			con *= temp;
// 		}
// 	}
// 	printf("\n%d \n", con);
// 	fclose(a);
// }


//// gets:

// int main () {
//    FILE *fp;
//    char str[60];

//    /* opening file for reading */
//    fp = fopen("a.txt" , "r");
//    if(fp == NULL) {
//       perror("Error opening file");
//       return(-1);
//    }
//    while( fgets (str, 60, fp)!=NULL ) {
//       /* writing content to stdout */
//       puts(str);
//    }
//    fclose(fp);
   
//    return(0);
// }