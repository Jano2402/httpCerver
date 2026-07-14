#include "server.h"

int main(void) {
  Server server;
  server_init(&server, 8080);
  return 0;
}
