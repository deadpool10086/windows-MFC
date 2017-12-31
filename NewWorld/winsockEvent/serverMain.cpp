#include <stdio.h>
#include <winsock2.h>
#include <windows.h>
#include <string.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#pragma comment(lib,"WS2_32.lib") 

SOCKET SocketArry[WSA_MAXIMUM_WAIT_EVENTS];
WSAEVENT EventArry[WSA_MAXIMUM_WAIT_EVENTS];

int main(int argc, char* argv)
{
	WSAEVENT NewEvent = NULL;
	SOCKET Accept, Listen;
	DWORD EventTotal = 0;
	DWORD Index = 0;
	SOCKADDR_IN InternetAddr;
	WSANETWORKEVENTS NetworkEvents;
	char buffer[256];
	WSADATA	wsd;
	int i,j;
	if	(WSAStartup(MAKEWORD(2, 2), &wsd) != 0)
	{
		fprintf(stderr, "ubable to load Winsock!\n");
		return 0;
	}
	Listen = socket(AF_INET, SOCK_STREAM, 0);
	memset(&InternetAddr, 0, sizeof(InternetAddr));
	memset(SocketArry, 0, sizeof(SOCKET)&WSA_MAXIMUM_WAIT_EVENTS);
	memset(EventArry, 0, sizeof(WSAEVENT)*WSA_MAXIMUM_WAIT_EVENTS);

	InternetAddr.sin_family = AF_INET;
	InternetAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	InternetAddr.sin_port=htons(8899);
	
	bind(Listen, (PSOCKADDR)&InternetAddr, sizeof(InternetAddr));
	NewEvent= WSACreateEvent();
	WSAEventSelect(Listen, NewEvent, FD_ACCEPT|FD_CLOSE);
	listen(Listen, 5);
	SocketArry[EventTotal] = Listen;
	EventArry[EventTotal] = NewEvent;
	EventTotal++;

	while(TRUE)
	{
		Index = WSAWaitForMultipleEvents(EventTotal, EventArry, FALSE, WSA_INFINITE, FALSE);
		WSAEnumNetworkEvents(SocketArry[Index-WSA_WAIT_EVENT_0], EventArry[Index-WSA_WAIT_EVENT_0], &NetworkEvents);
		WSAResetEvent(EventArry[Index-WSA_WAIT_EVENT_0]);

		if(NetworkEvents.lNetworkEvents & FD_ACCEPT)
		{
			if(NetworkEvents.iErrorCode [FD_ACCEPT_BIT] != 0)
			{
				printf("FD_ACCEPT   ß∞‹£°¥ÌŒÛ¬Î «%d\n", NetworkEvents.iErrorCode[FD_ACCEPT_BIT]);
				break;
			}
			Accept = accept(SocketArry[Index-WSA_WAIT_EVENT_0], NULL, NULL);
			if(EventTotal > WSA_MAXIMUM_WAIT_EVENTS)
			{
				printf("Too many cinnections");
				closesocket(Accept);
				break;
			}
			NewEvent = WSACreateEvent();
			WSAEventSelect(Accept, NewEvent, FD_READ|FD_WRITE|FD_CLOSE);
			SocketArry[EventTotal] = Accept;
			EventArry[EventTotal] = NewEvent;
			EventTotal++;
			
			printf("Socket %d connected\n", Accept);
		}

		if(NetworkEvents.lNetworkEvents & FD_READ)
		{
			if(NetworkEvents.iErrorCode[FD_READ_BIT] != 0)
			{
				printf("FD_READ  ß∞‹¥ÌŒÛ¬Î «%d\n", NetworkEvents.iErrorCode[FD_READ_BIT]);
				break;
			}
			memset(buffer,0,256);
			recv(SocketArry[Index-WSA_WAIT_EVENT_0], buffer, 256, 0);

			printf("server %d  ’µΩ ˝æ› %s\n", SocketArry[Index-WSA_WAIT_EVENT_0], buffer);		
		}
		if(NetworkEvents.lNetworkEvents & FD_WRITE)
		{
			if(NetworkEvents.iErrorCode[FD_WRITE_BIT] != 0)
			{
				printf("FD_WRITE fail errorCode%d\n", NetworkEvents.iErrorCode[FD_READ_BIT]);
				break;
			}
			memset(buffer,0,256);
			sprintf(buffer, "hello!");
			send(SocketArry[Index-WSA_WAIT_EVENT_0],buffer, 256, 0);
		}
		if(NetworkEvents.lNetworkEvents & FD_CLOSE)
		{
			Sleep(3000);
			if(NetworkEvents.iErrorCode[FD_CLOSE_BIT] != 0)
			{
				printf("FD_CLOSE  ß∞‹ ¥ÌŒÛ¬Î «%d\n", NetworkEvents.iErrorCode[FD_CLOSE_BIT]);
				break;
			}
			else
			{
				printf("\n s1ucceed \n");
			}
			closesocket(SocketArry[Index-WSA_WAIT_EVENT_0]);
			WSACloseEvent(EventArry[Index-WSA_WAIT_EVENT_0]);
			printf("server %d πÿ±’¡¥Ω”\n",SocketArry[Index-WSA_WAIT_EVENT_0]);
			for(i = Index-WSA_WAIT_EVENT_0; i<WSA_MAXIMUM_WAIT_EVENTS-1; i++)
			{
				SocketArry[i] = SocketArry[i+1];
				EventArry[i] = EventArry[i+1];
			}
			EventTotal--;
		
		}
		
	}

	return 0;
}