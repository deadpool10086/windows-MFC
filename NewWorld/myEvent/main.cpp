#include <stdio.h>
#include <winsock2.h>
#include <windows.h>


#pragma comment(lib,"WS2_32.lib") 

int main()
{
	SOCKET SocketArray [WSA_MAXIMUM_WAIT_EVENTS];
	WSAEVENT EventArray [WSA_MAXIMUM_WAIT_EVENTS];
	SOCKET Listen,Accept;
	DWORD EventTotal = 0;
	DWORD Index;
	WSANETWORKEVENTS NetworkEvents;
	SOCKADDR_IN InternetAddr;
	WSAEVENT NewEvent;
	
	char buffer[256];
	WSADATA	wsd;
//int i,j;
	if	(WSAStartup(MAKEWORD(2, 2), &wsd) != 0)
	{
		fprintf(stderr, "ubable to load Winsock!\n");
		return 0;
	}


	Listen = socket(PF_INET,SOCK_STREAM, 0);
	InternetAddr.sin_family = AF_INET;
	InternetAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	InternetAddr.sin_port = htons(8899);
	bind(Listen, (PSOCKADDR)&InternetAddr, sizeof(InternetAddr));
	NewEvent = WSACreateEvent();
	WSAEventSelect(Listen, NewEvent, FD_ACCEPT | FD_CLOSE);

	listen(Listen, 5);
	SocketArray[EventTotal] = Listen;
	EventArray[EventTotal] = NewEvent;
	EventTotal++;

	while(TRUE)
	{
		Index = WSAWaitForMultipleEvents(EventTotal, EventArray, FALSE, WSA_INFINITE, FALSE);
		WSAEnumNetworkEvents(SocketArray[Index-WSA_WAIT_EVENT_0], EventArray[Index-WSA_WAIT_EVENT_0], &NetworkEvents);
		if	(NetworkEvents.lNetworkEvents &  FD_ACCEPT)
		{
			if(NetworkEvents.iErrorCode[FD_ACCEPT_BIT] != 0)
			{
				printf("FD_ACCEPT faild %d\n",NetworkEvents.iErrorCode[FD_ACCEPT_BIT]);
				break;
			}
			Accept = accept(SocketArray[Index-WSA_WAIT_EVENT_0],NULL,NULL);
			if(EventTotal >  WSA_MAXIMUM_WAIT_EVENTS)
			{
				printf("2 many connections");
				closesocket(Accept);
				break;
			}
			NewEvent = WSACreateEvent();
			WSAEventSelect(Accept, NewEvent, FD_READ|FD_WRITE|FD_CLOSE);
			EventArray[EventTotal] = NewEvent;
			SocketArray [EventTotal] = Accept;
			EventTotal++;
			printf("socket %d connected\n",Accept);
		}
	
		if(NetworkEvents.lNetworkEvents & FD_READ)
		{
			if(NetworkEvents.iErrorCode[FD_READ_BIT] != 0)
			{
				printf("FD_READ  error %d \n", NetworkEvents.iErrorCode[FD_READ_BIT]);
				break;
			}
			int x = recv(SocketArray[Index-WSA_WAIT_EVENT_0], buffer,  sizeof(buffer), 0);
			buffer[x] = 0;
			printf("server %d 收到数据 %s\n", SocketArray[Index-WSA_WAIT_EVENT_0], buffer);
		}
		if(NetworkEvents.lNetworkEvents& FD_WRITE)
		{
			if(NetworkEvents.iErrorCode[FD_WRITE_BIT] != 0)
			{
				printf("FD_WRITE error %d\n", NetworkEvents.iErrorCode[FD_WRITE_BIT]);
				break;
			}
			send(SocketArray[Index-WSA_WAIT_EVENT_0], buffer, sizeof(buffer), 0);
		}
		if(NetworkEvents.lNetworkEvents& FD_CLOSE)
		{
			if(NetworkEvents.iErrorCode[FD_CLOSE_BIT] != 0)
			{
				printf("FD_CLOSE error %d\n", NetworkEvents.iErrorCode[FD_CLOSE_BIT]);
				break;
			}
			closesocket(SocketArray[Index-WSA_WAIT_EVENT_0]);
			WSACloseEvent(EventArray[Index-WSA_WAIT_EVENT_0]);
			printf("server %d 关闭链接\n",SocketArray[Index-WSA_WAIT_EVENT_0]);
			for(int i = Index-WSA_WAIT_EVENT_0; i<WSA_MAXIMUM_WAIT_EVENTS-1; i++)
			{
				SocketArray[i] = SocketArray[i+1];
				EventArray[i] = EventArray[i+1];
			}
			EventTotal--;
		}
	}

	return 0;
}