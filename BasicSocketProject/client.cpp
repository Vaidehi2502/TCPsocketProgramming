#include<iostream>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
using namespace std;

int main(){
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

    connect(sock, (struct sockaddr*)&server, sizeof(server));

    send(sock, "HELLO", 5, 0);

    char buffer[100];
    read(sock, buffer, 100);
    cout << "Server says: " << buffer <<endl;
    
    close(sock);

    return 0;
}