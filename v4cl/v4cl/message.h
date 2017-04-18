#ifndef MESSAGE_H_
#define MESSAGE_H_

int sendMessage(SOCKET new_socket, char * message, int size);
int recvMessage(SOCKET new_socket);

#endif // MESSAGE_H_