#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <ws2bth.h>
#include <stdint.h>

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
    convertBluetoothAddress("7c:a4:49:5f:a8:a1", &serverAddress.btAddr);
    serverAddress.serviceClassId = RFCOMM_PROTOCOL_UUID;
    int connect_ret = connect(bluetoothSocket, (SOCKADDR*)&serverAddress, sizeof serverAddress);
    if (connect_ret == 0) {
        printf("Connection established.\n");
    } else {
        printf("Failed to connect to the mobile phone!");
        closesocket(bluetoothSocket);
        WSACleanup();
        exit(1);
    }
}


int main() {
    initWinsock();
    SOCKET bluetoothSocket = createSocket();
    establishConnection(bluetoothSocket);
    int data = 0;
    int recv_ret;
    do {
        recv_ret = recv(bluetoothSocket, (char*)&data, sizeof data, 0);
        printf("%d\n", data);
    } while(recv_ret != SOCKET_ERROR);
    closesocket(bluetoothSocket);
    WSACleanup();
    return 0;
}
