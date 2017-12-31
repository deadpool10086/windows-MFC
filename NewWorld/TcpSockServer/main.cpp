#include <winsock2.h>
#include <stdio.h>

#pragma comment(lib, "ws2_32.lib")

int main(void)
{
	WORD sockVersion = MAKEWORD(2, 2);
	WSAData wsaData;
	WSAStartup(sockVersion, &wsaData);
	SOCKET slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if(slisten == INVALID_SOCKET)
	{
		printf("socket error !");
		return 0;
	}

	sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(4000);
	sin.sin_addr.S_un.S_addr = INADDR_ANY;
	if(bind(slisten, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR)
	{
		printf("bind error !");
	}
	if(listen(slisten, 5) == SOCKET_ERROR)
	{
		printf("listen error !");
		return 0;
	}

	SOCKET sClient;
	sockaddr_in remoteAddr;
	int nAddrlen = sizeof(remoteAddr);
	char revData[255];
	while (true)
	{
		printf("waiting connect....\n");
		sClient = accept(slisten, (SOCKADDR *)&remoteAddr, &nAddrlen);
		if(sClient == INVALID_SOCKET)
		{
			printf("accept error !");
			continue;
		}
		printf("connected a user:%s \r\n", inet_ntoa(remoteAddr.sin_addr));
		int ret = recv(sClient, revData, 255, 0);
		if(ret > 0)
		{
			revData[ret] = 0x00;
			printf(revData);
		}
		char * sendData = "hello TCP client!\n";
		send(sClient, sendData, strlen(sendData), 0);
		closesocket(sClient);
	}

	closesocket(slisten);
	WSACleanup();
	WSACleanup();
	return 0;
}