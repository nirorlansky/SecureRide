#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <ws2bth.h>
#include <stdint.h>

#define IDO_BT_ADD "7c:a4:49:5f:a8:a1"

void initWinsock() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("Failed to initialize Winsock.\n");
        exit(1);
    }
}

SOCKET createSocket() {
    SOCKET bluetoothSocket = socket(AF_BTH, SOCK_STREAM, BTHPROTO_RFCOMM);
    if (bluetoothSocket == INVALID_SOCKET) {
        printf("Failed to create Bluetooth socket.\n");
        WSACleanup();
        exit(1);
    }
    return bluetoothSocket;
}

void convertBluetoothAddress(char* address, uint64_t* result) {
    char* tmp;
    for (int i = 0; i < 6; ++i) {
        uint64_t byte = strtoull(address, &tmp, 16);
        *result += byte;
        address = tmp + 1;
        *result = *result << 8;
    }
    *result = *result >> 8;
}

void establishConnection(SOCKET bluetoothSocket) {
    SOCKADDR_BTH serverAddress = {0};
    serverAddress.addressFamily = AF_BTH;
    convertBluetoothAddress(IDO_BT_ADD, &serverAddress.btAddr);
    serverAddress.serviceClassId = RFCOMM_PROTOCOL_UUID;
    int connect_ret;
    do {
        connect_ret = connect(bluetoothSocket, (SOCKADDR*)&serverAddress, sizeof serverAddress);
    } while (connect_ret != 0);
    printf("Connection established.\n");
}

void sendMessages(SOCKET bluetoothSocket) {
    char byte = 127;
    int send_ret;
    do {
        send_ret = send(bluetoothSocket, &byte, 1, 0);
    } while(send_ret != SOCKET_ERROR);
}

int main() {
    initWinsock();
    int i = 0;
    while (i < 2) {
        SOCKET bluetoothSocket = createSocket();
        establishConnection(bluetoothSocket);
        sendMessages(bluetoothSocket);
        closesocket(bluetoothSocket);
        printf("Disconnected.\n");
        ++i;
    }
    WSACleanup();
    return 0;
}
