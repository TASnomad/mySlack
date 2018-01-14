#include    <client.h>
#include    <libmy.h>
#include    <stdlib.h>
#include    <sys/types.h>
#include    <sys/socket.h>


t_action    actions[] = {
    { "login", handle_login },
    { "msg", handle_new_msg },
    { 0x0, 0x0 }
};

int             handle_login(int sock, char *buff)
{
    char        **cmd;
    char        *response;
    int         res;
    t_client    *clt;

    cmd = my_explode(buff, ';');
    res = is_login_taken(clients, cmd[1]);
    if (res)
    {
        free(cmd[1]);
        cmd[1] = my_strdup("KO");
        response = my_implode(cmd, ';');
        send(sock, response, my_strlen(response), 0);
    }
    else
    {
        clt = find_client_by_sock(clients, sock);
        if (clt->name)
            free(clt->name);
        clt->name = my_strdup(cmd[1]);
        free(cmd[1]);
        cmd[1] = my_strdup("OK");
        response = my_implode(cmd, ';');
        send(sock, response, my_strlen(response), 0);
    }
    return (!res);
}

int             handle_new_msg(int sock, char *raw, int raw_size)
{
    (void) sock;
    (void) raw;
    (void) raw_size;
    return (1);
}

int             handle_incoming(int sock_clt, char *raw_buff, int raw_size)
{
    char        **cmd;
    int         found;
    int         i;
    int         res;

    i = found = res = 0;
    cmd = my_explode(raw_buff, ';');
    if (!cmd)
        return (0);
    while ((*(actions + i)).name && !found)
    {
        if (my_strcmp(cmd[0], (*(actions + i)).name) == 0)
        {
            res = (*(actions + i)).cmd(sock_clt, raw_buff, raw_size);
            found = 1;
        }
        i += 1;
    }
    return (res);
}