/*
    Bind socket to port 8888 on localhost
*/
#include <io.h>
#include <stdio.h>
#include <winsock2.h>
#include <conio.h>
#include "message.h"
 
#pragma comment(lib,"ws2_32.lib") //Winsock Library
 
int main(int argc , char *argv[])
{
    WSADATA wsa;
    SOCKET s , new_socket;
    struct sockaddr_in server , client;
    int c;
    char *message;
	int recv_size;

	puts("Welcome to SERVER");

#pragma region Initialize_Winsock
    printf("\nInitialising Winsock...");
    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
    {
        printf("Failed. Error Code : %d",WSAGetLastError());
        return 1;
    }     

    printf("Initialised.\n");
#pragma endregion
     
#pragma region Create_Socket
	if((s = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET)
    {
        printf("Could not create socket : %d" , WSAGetLastError());
    } 

    printf("Socket created.\n");
#pragma endregion

#pragma region Prepare_Server_Struct
	server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8888 );
#pragma endregion
    
#pragma region Bind
	if( bind(s ,(struct sockaddr *)&server , sizeof(server)) == SOCKET_ERROR)
    {
        printf("Bind failed with error code : %d" , WSAGetLastError());
    }
     
    puts("Bind done");
#pragma endregion
     
    //Listen to incoming connections
	puts("Waiting for incoming connections...");
    listen(s , 3);
     
#pragma region Accept_Incoming_Connection
	c = sizeof(struct sockaddr_in);
    new_socket = accept(s , (struct sockaddr *)&client, &c);
    if (new_socket == INVALID_SOCKET)
    {
        printf("accept failed with error code : %d" , WSAGetLastError());
    }
     
    puts("Connection accepted");
#pragma endregion
	   
    //Introduct client
	sendMessage(new_socket, "Do you want to send anonymous keyboard input information to Kazimieras Senvaitis? (Y/N) \0");
	
	//Getting accept/decline
	recvMessage(new_socket);
	
	//Getting signature
	recvMessage(new_socket);

	//Getting keyboard input
	while(!kbhit()) // missing condition. Should be turn off key
	{
		char message2[20];

		if((recv_size = recv(new_socket, message2, 20, 0)) == SOCKET_ERROR)
		{
			return 2;
		}
		printf("%s", message2);
	}
     
	puts("Keyboard input receiving has been stopped.");

	puts("Press any key to shut down the server...");
		while(!kbhit()) {}
		

    closesocket(s);
    WSACleanup();
     
    return 0;
}