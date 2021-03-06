#ifndef __CONFIG_SSL_H_
#define __CONFIG_SSL_H_

#ifdef _USE_HTTP_SSL

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>


#include <openssl/rsa.h>       /* SSLeay stuff */
#include <openssl/crypto.h>
#include <openssl/x509.h>
#include <openssl/pem.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

/* define HOME to be dir for key and cert files... */
#define HOME "./"
/* Make these what you want for cert & key files */
#define CERTF HOME "cacert.pem"
#define KEYF  HOME "privkey.pem"

#define CHK_NULL(x) if ((x)==NULL) exit (1)
#define CHK_ERR(err,s) if ((err)==-1) { perror(s); exit(1); }
#define CHK_SSL(err) if ((err)==-1) { ERR_print_errors_fp(stderr);exit(2); }

/**
*   int len = SSL_write(SSL* ssl ,char *buf, strlen(buf)); ssl发送
* 
* 
*   int len = SSL_read(SSL* ssl, char *buf, MAXBUF);　ssl接收
* 
*/

#ifdef __cplusplus
 extern "C"{
#endif

//初始化SSL
extern SSL_CTX* SSL_preliminaries(const char *certpath,const char *keypath);

//创建SSL对象指针
extern SSL* createSSLInstence(SSL_CTX* ctx,int sd);

//获取客户端ssl证书信息
extern void getClientCert(SSL* ssl);

//释放ssl
extern void freeSSL(SSL_CTX* ctx,SSL* ssl);



#ifdef __cplusplus
}
#endif

#endif

#endif
