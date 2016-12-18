#include "WebServiceSpy/WebServer.h"
#include "WebServiceSpy/Version.h"

#include <iostream>

int main(int argc, char** argv) {
  WebServer server(8080);
  server.start();
  ProjectTemplate::WebServiceSpy::Version version;
  std::cout << version.getString() << std::endl;
  return 0;
}
