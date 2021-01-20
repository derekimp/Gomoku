#ifndef _MY_SOCKET_H_
#define _MY_SOCKET_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define IN
#define OUT
#define IN_OUT
#define MY_TCP 1
#define MY_UDP 2
typedef struct sockaddr *pSA;
typedef struct sockaddr_in SA;
// if flag is false, continue
#define ASSERT(flag, msg) ((flag) ? NULL : (fprintf(stdout, (msg)), exit(EXIT_FAILURE)))
// tcp and udp client doesn't need to be bonded together, but we need to send the server addr
void my_socketCli(int *fd_socket, int type, char *ip, int port, SA *my_addr);
// tcp client links to the server
void my_connect(int fd_socket, pSA server_addr, int len);
// tcp and udp server need to bound their addr
void my_socketSer(int *fd_socket, int type, char *ip, int port);
// listen to server in tcp
void my_listen(int fd_socket, int listen_num);
// tcp server receive the data sent by client and store it to client_addr. And use fd_client to connect the server
void my_accept(int *fd_client, int fd_socket, pSA client_addr, int *addrlen);
// tcp, the msg is an integer array
void my_send(int *sendlen, int fd_socket, int *msg, int len);
//tcp receive
void my_recv(int *recvlen, int fd_socket, int *msg, int len);
//udp
void my_sendto(int *send_num, int fd_socket, int *msg, int len, pSA server_addr, int addrlen);
//udp
void my_recvfrom(int *recv_num, int fd_socket, int *msg, int len, pSA client_addr, int *addrlen);
// shut down tcp and udp
void my_close(int fd_socket);
#endif