#include<stdio.h>
#include<netdb.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>//read() write() close()
#define PROT 8080
#define MAX 80
#define SA struct sockaddr

void func(int connfd){
    char buff[80];
    int n;
    // infinite loop for chat
    for(;;){
        bzero(buff,MAX);
        // Reade the message from client 
        read(connfd,buff,sizeof(buff));
        // print buffer which contains the client contents
        printf("From client : %s\t To client : ",buff);
        bzero(buff,80);
        n=0;
        // copy server message in the buffer
        while((buff[n++]=getchar())!='\n');
        // and send that buffer to client
        write(connfd,buff,sizeof(buff));
        // if msg contains "exit" then server exit and chat ended
        if(strncmp("exit",buff,4)==0){
            printf("Server Exit...\n");
            break;
        }
    }
}
int main(){
    unsigned int sockfd,connfd,len;
    struct sockaddr_in servaddr,cli;
    // socket create and verification
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(sockfd==-1){
        printf("socket creation failed...\n");
        exit(0);
    }
    else{
        printf("Socket successfully created..\n");
        bzero(&servaddr,sizeof(servaddr));
        // assign IP, PORT  
        servaddr.sin_family=AF_INET;
        servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
        servaddr.sin_port=htons(PROT);
    }
    // Binding newly created socket to given IP and verification
    if((bind(sockfd,(SA*)&servaddr,sizeof(servaddr)))!=0){
        printf("socket bind failed...\n");
        exit(0);
    }
    else{
        printf("Socket successfully binded..\n");
    }
    if((listen(sockfd,5))!=0){
        printf("Listen failed...\n");
        exit(0);
    }
    else{
        printf("Server listening..\n");
    }
    len=sizeof(cli);
    connfd=accept(sockfd,(SA*)&cli,&len);
    if(connfd<0){
        printf("server acccept failed...\n");
        exit(0);
    }
    else{
        printf("server acccept the client...\n");
    }
    // function for chat
    func(connfd);
    // After chatting close the socket
    close(sockfd);
}