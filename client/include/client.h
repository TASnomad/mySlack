#ifndef _CLIENT_H_
#define _CLIENT_H_

#include<unistd.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/select.h>

#define LOGIN_CMD       "login"
#define MSG_SEND_CMD    "send_msg"
#define MSG_RECV_CMD    "recv_msg"
#define CHANNEL_CMD     "channel"

int     spawn_client(char *, char *);
char    *login_server(int);
void    main_client(int);

#endif /* ! _CLIENT_H_ */
