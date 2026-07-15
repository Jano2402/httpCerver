#include "server.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define LISTEN_BACKLOG 50

int server_init(Server *server, int port) 
{
  server->port = port;
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);

  if (server_socket == -1)
  {
    perror("socket");
    return -1;
  }

  printf("Socket created successfully with the file descriptor: %d\n", server_socket);
  server->socket_fd = server_socket;

  printf("Server initialized on port: %d\n", server->port);
  return 0;
}

int server_start(Server *server) 
{
  struct sockaddr_in addr;

  memset(&addr, 0, sizeof(addr));

  addr.sin_family = AF_INET;
  addr.sin_port = htons(server->port);
  addr.sin_addr.s_addr = INADDR_ANY;

  if(bind(server->socket_fd, (struct sockaddr *)&addr, sizeof(addr)) == -1)
  {
    perror("bind");
    return -1;
  }

  printf("Bind realizado correctamente \n");

  if(listen(server->socket_fd, LISTEN_BACKLOG) == -1)
  {
    perror("listen");
    return -1;
  }

  printf("Server listening on: %d\n", server->socket_fd);

  return 0;
}

void server_destroy(Server *server) 
{
  int port = server->port;
  close(server->socket_fd);
  printf("%s ", "Server on");
  printf("%i ", port);
  printf("%s", "was destroyed.\n");
  return; 
}
