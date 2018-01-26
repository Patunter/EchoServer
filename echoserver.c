#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<unistd.h>

#define BUFFER_SIZE 1024

int main(int argc , char* argv[]) {
	int socket1, socket2, read;
	int option = 1;
	char buffer[BUFFER_SIZE];
	struct sockaddr_in serverAddr;
	struct sockaddr_storage serverStorage;
	socklen_t addr_size;

	socket1 = socket(PF_INET, SOCK_STREAM, 0);
	setSockopt(socket1, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));

	serverAddr.sin_family = AF_INET;

	serverAddr.sin_port = htons(6969);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

	bind(socket1, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

	if(listen(socket1, 5) == 0) {
		printf("Listening\n");
	}else {
		printf("Nicht sehr gut");
	}

	addr_size = sizeof serverStorage;
	socket2 = accept(socket1, (struct sockaddr *) &serverStorage, &addr_size);

	while(1) {
		read = recv(socket2, buffer, BUFFER_SIZE, 0);
		send(socket2, buffer, read, 0);

		if(buffer[0] == 94) {
			printf("Programm wurde beendet!");
			return 0;
		}
	}



	return 0;
}
