#ifndef __WEBSERVER
#define __WEBSERVER

#include <stdint.h>

class WebServer {
public:
  explicit WebServer(uint32_t port);
  virtual ~WebServer();
  void start();
protected:
  uint32_t _port;
};

#endif /* __WEBSERVER */
