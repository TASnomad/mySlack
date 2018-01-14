#ifndef _CLIENT_H_
#define _CLIENT_H_

#include<unistd.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/select.h>

int spawn_client(char *, char *);

#endif /* ! _CLIENT_H_ */
