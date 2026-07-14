#include "server.h"
#include <stdio.h>
#include <sys/socket.h>

int server_init(Server *server, int port) 
{
  server->port = port;
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket == -1) {
    printf("%s", "Could not create the socket.");
    return 0;
  }
  printf("Socket created successfully with the file descriptor: %d\n", server_socket);
  // close(server_socket);

  printf("%s", "Server initialized on port: \n");
  printf("%i", 8080);
  return 0;
}

int server_start(Server *server) 
{
  int port = server->port;
  return port;
}

void server_destroy(Server *server) 
{
  int port = server->port;
  printf("%s ", "Server on");
  printf("%i ", port);
  printf("%s", "was destroyed.\n");
  return; 
}
