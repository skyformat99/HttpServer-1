#ifndef __CGI_HANDLE_H_
#define __CGI_HANDLE_H_

#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <stdio.h>

#include "HttpRequest.h"
#include "HttpResponse.h"

#include "config.h"
#include "servlet_register.h"

#ifdef _USE_HTTP_SSL
  #include "config_ssl.h"
#endif


class cgi_handle{
public:

#ifdef _USE_HTTP_SSL
    cgi_handle(int epollfd,int sockfd,struct sockaddr_in     address,Config *conf,SSL * ssl);
#endif
    cgi_handle(int epollfd,int sockfd,struct sockaddr_in address,Config *conf);

    ~cgi_handle();
    int process(ServletRegister *sr);
private:
    void req_dispathch(ServletRegister *sr);
    void req_static_file(const char *path,const char* content_type);
    void req_servlet(ServletRegister *sr,string uri);

#ifdef _USE_HTTP_SSL
    void https_req_static_file(const char *path,const char* content_type);
#endif

private:
   void removefd(int epollfd,int fd);
   bool isFile(const string object,string &content_type);

private:
    int m_epollfd;
    int m_sockfd;
    struct sockaddr_in m_address;
private:
    HttpRequest* req;
    HttpResponse* rsp;
    Config *config;
#ifdef _USE_HTTP_SSL
    SSL* ssl;
#endif
};

#endif
