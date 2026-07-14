#include "server.h"

int main(void) {
  Server server;
  if (server_init(&server, 8080) != 0)
    return 1;

  if (server_start(&server) != 0)
    return 1;

  server_destroy(&server);
  
  return 0;
}
