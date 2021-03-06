// Tcpip06_uecho_cliecnt_win.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <string>
#include <WS2tcpip.h>

#define BUF_SIZE 30
void ErrorHandling(const std::string message);

int main(int argc, char *argv[])
{
    WSADATA wsaData;
    SOCKET sock;
    char message[BUF_SIZE];
    int strLen;

    SOCKADDR_IN servAdr;
    if (argc != 3) {
        printf("Usage : %s <IP> <port>\n", argv[0]);
        exit(1);
    }

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        ErrorHandling("WSAStartup() error!"); 
    }

    sock = socket(PF_INET, SOCK_DGRAM, 0);   
    if (sock == INVALID_SOCKET) {
        ErrorHandling("socket() error");
    }

    memset(&servAdr, 0, sizeof(servAdr));
    servAdr.sin_family = AF_INET;
    servAdr.sin_addr.s_addr = inet_addr(argv[1]);
    servAdr.sin_port = htons(atoi(argv[2]));

    connect(sock, (SOCKADDR*)&servAdr, sizeof(servAdr));

    while (true) {
        fputs("Insert message(q to quit): ", stdout);
        fgets(message, sizeof(message), stdin);
        if (!strcmp(message,"q\n") || !strcmp(message,"Q\n")) {
            break;
        }

        send(sock, message, strlen(message), 0);
        strLen = recv(sock, message, sizeof(message) - 1, 0);

        message[strLen] = 0;
        printf("Message from server: %s", message);
    }

    closesocket(sock);
    WSACleanup();
    return 0;
}

void ErrorHandling(const std::string message)
{
    fputs(message.c_str(), stderr);
    fputc('\n', stderr);
    exit(1);
}
