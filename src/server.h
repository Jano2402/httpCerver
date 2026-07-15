#ifndef SERVER_H
#define SERVER_H

typedef struct Server {
  int port;
  int socket_fd;
} Server;

typedef struct Client {
  int fd;
  char ip[INET_ADDRSTRLEN];
  uint16_t port;
  uint64_t bytes_sent;
  uint64_t bytes_received;
  time_t connected_at;
} Client;

int server_init(Server *server, int port);
int server_start(Server *server);
void server_destroy(Server *server);

#endif
