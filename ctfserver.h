#ifndef _CTFSERVER_H_
#define _CTFSERVER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <stdarg.h>

#ifdef CTF_THREADS
#include <pthread.h>
pthread_mutex_t tmutex;
#endif
#ifndef BUFSIZE
#define BUFSIZE 1028
#endif
#ifndef PORT
#define PORT 12345
#endif
#ifndef MAX_CONNECTIONS
#define MAX_CONNECTIONS 30
#endif

typedef int sock;
typedef struct sockaddr_in sockaddr_in;
typedef struct sockaddr sockaddr;

bool ctfserver(void (*handler)(sock));
bool rputs(sock rsock, char *fmt, ...);
bool rgets(sock rsock, char *rBuf);
bool send_flag(sock rsock, char *msg);

#endif
