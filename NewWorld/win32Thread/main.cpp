#include "stdio.h"
#include "stdlib.h"
#include "Afxwin.h"
#include "winbase.h"

typedef struct{
	int nN;
	double* pD;
}myData;
UINT myThreadFunc(LPVOID pParam);
myData ss;
int main(int argc, char* argv[])
{
	CWinThread* pTh = NULL;
	double myArray[10];
	for(int i=0; i<10; i++)
		myArray[i] = i;
	ss.nN = 10;
	ss.pD = myArray;
	pTh = AfxBeginThread(myThreadFunc, &ss, THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED);
	ASSERT(pTh->m_hThread);
	pTh->m_bAutoDelete = false;
	pTh->ResumeThread();
	printf("���߳̿�ʼ!\r\n");
	WaitForSingleObject(pTh->m_hThread, INFINITE);
	delete pTh;
	printf("���߳̽���!\r\n");
//	Sleep(2000);
	return 0;
}

UINT myThreadFunc(LPVOID pParam)
{
	myData * pData = NULL;
	pData = (myData*)pParam;
	if(pData == NULL)
		AfxEndThread(1);
	int nn = pData->nN;
	printf("sadas");
	double* pD= pData->pD;
	double sum = 0;
	for(int i=0; i<nn; i++)
		sum+=pD[i];
	printf("�����ܺ��� %f \r\n", sum);
	return 0;
}