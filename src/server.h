#ifndef SERVER_H
#define SERVER_H

typedef struct Server {
  int port;
  int socket_fd;
} Server;

int server_init(Server *server, int port);
int server_start(Server *server);
void server_destroy(Server *server);

#endif
