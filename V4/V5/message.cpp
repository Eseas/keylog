#include<io.h>
#include<stdio.h>
#include<winsock2.h>
 
int sendMessage(SOCKET new_socket, char * message);
int recvMessage(SOCKET new_socket);

int sendMessage(SOCKET new_socket, char * message)
{
	//message = "Do you want to send anonymous keyboard input information to Kazimieras Senvaitis? (Y/N) \0";
    if(send(new_socket , message , 120 , 0) < 0) 
	{
		puts("Send failed");
		return 1; 
	}

	printf("Sent: %s \n", message);
	return 0;
}

int recvMessage(SOCKET new_socket)
{
	int recv_size;
	char message[100];

	if((recv_size = recv(new_socket, message, 100, 0)) == SOCKET_ERROR)
	{
		puts("recv failed");
		return 5;
	}

	printf("Received: %s \n", message);
	return 0;
}