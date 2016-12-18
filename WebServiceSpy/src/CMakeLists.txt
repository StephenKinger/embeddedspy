
set(LIB_HEADERS
  "${CMAKE_CURRENT_BINARY_DIR}/../include/WebServiceSpy/Version.h" # Generated header
  ../include/WebServiceSpy/WebServer.h # Normal header
)

set(LIB_SOURCES
  WebServer.cpp
)

set(APP_HEADERS

)

set(APP_SOURCES
  main.cpp
)

# Define two variables in order not to repeat ourselves.
set(LIBRARY_NAME WebServiceSpy)

# Define the library
add_library(${LIBRARY_NAME} SHARED ${LIB_SOURCES})

# Set the build version. It will be used in the name of the lib, with corresponding
# symlinks created. SOVERSION could also be specified for api version.
set_target_properties(${LIBRARY_NAME} PROPERTIES
  VERSION ${VERSION}  # ${VERSION} was defined in the main CMakeLists.
  FRAMEWORK FALSE
  PUBLIC_HEADER "${LIB_HEADERS}" # specify the public headers
)

# This is a make target, so you can do a "make WebServiceSpyrunner"
set(APPLICATION_NAME WebServiceSpyrunner)
add_executable(${APPLICATION_NAME} ${APP_SOURCES})

# Links the target exe (WebServiceSpyrunner) against the library (libWebServiceSpy) and other required libraries
target_link_libraries(${APPLICATION_NAME} ${LIBRARY_NAME} )

# Says how and where to install software
# Targets:
#   * <prefix>/lib/<libraries>
#   * header location after install: <prefix>/include/<project>/*.h
#   * headers can be included by C++ code `#<project>/Bar.hpp>`
install(TARGETS ${LIBRARY_NAME} ${APPLICATION_NAME}
  EXPORT ${PROJECT_NAME}Targets            # for downstream dependencies
  ARCHIVE DESTINATION lib COMPONENT libs   # static lib
  RUNTIME DESTINATION bin COMPONENT libs   # binaries
  LIBRARY DESTINATION lib COMPONENT libs   # shared lib
  FRAMEWORK DESTINATION bin COMPONENT libs # for mac
  PUBLIC_HEADER DESTINATION include/${PROJECT_NAME} COMPONENT devel   # headers for mac (note the different component -> different package)
  INCLUDES DESTINATION include             # headers
)
