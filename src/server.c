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
  struct sockaddr_in addr, peer_addr;
  char buffer[256];

  memset(&addr, 0, sizeof(addr));

  addr.sin_family = AF_INET;
  addr.sin_port = htons(server->port);
  addr.sin_addr.s_addr = INADDR_ANY;

  if(bind(server->socket_fd, (struct sockaddr *) &addr, sizeof(addr)) == -1)
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

  socklen_t peer_addr_size = sizeof(peer_addr); 
  memset(&peer_addr, 0, peer_addr_size);

  int client_fd = accept(server->socket_fd, (struct sockaddr *) &peer_addr, &peer_addr_size); 

  if (client_fd == -1)
  {
    perror("accept");
    return -1;
  }

  printf("Client connected on file descriptor: %d\n", client_fd);

  printf("The connection entered from: ");
  char ip[INET6_ADDRSTRLEN];
  struct sockaddr_in *s = (struct sockaddr_in *) &peer_addr;
  inet_ntop(AF_INET, &s->sin_addr, ip, sizeof(ip));
  printf("%s:%d\n", ip, ntohs(s->sin_port));
  printf("Family: %s\n", peer_addr.sin_family == AF_INET ? "IPv4" : "IPv6");

  strcpy(buffer, "This message was sent from the server \n");
  if (send(client_fd, buffer, strlen(buffer), 0) == -1)
  {
    perror("send");
    return -1;
  }

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
