#include<stdio.h>
#include<string.h>
#include<sys/socket.h>

#define PORT 7890
#define LENGHT 1000

int main( void ) {
	int sock;
	char message[ LENGHT ] , server_reply[ LENGHT ];

  sock = socket(AF_INET , SOCK_STREAM , 0);

  server.sin_addr.s_addr = inet_addr("127.0.0.1");
  server.sin_family = AF_INET;
  server.sin_port = htons( PORT );

  while(1)
  {
     fgets(message, LENGHT , stdin);

     if( send(sock , message , strlen(message) , 0) < 0)
     {
         return -1;
     }

    bzero(server_reply,LENGHT);
    if( recv(sock , server_reply , LENGHT , 0) < 0)
    {
       break;
    }

    puts(server_reply);
 }

 close(sock);
 return 0;
}
