BOOL mtDownload(CString  strFtpSite,
	CString  strName,
	CString  strPwd,
	CString  strSourceName,
	CString  strDestName);
BOOL  mtUpload(CString strFtpSite, CString strName,
	CString strPwd, CString strSourceName, CString strDestName);
//1�����ڲ�ѯ���̺߳���
UINT mtQuery(LPVOID  pParam)
{
	if (pParam == NULL)  AfxEndThread(NULL);
	//��һ�δ�����������ȡ�������õĲ����ģ��÷��ǳ����ͣ��������õ���ڲ���
	//pParam��һ��LPVOID���͵�ָ�룬���뽫��ת��ΪFTP_INFO�ṹ���͵�ָ��
	//���������ܴ���ȡ����Ӧ�����ݳ�Ա
	FTP_INFO* PP;
	CListBox*  pList;
	CString  strFtpSite;
	CString  strName;
	CString  strPwd;
	PP = (FTP_INFO*)pParam;
	pList = PP->pList;
	strFtpSite = PP->strFtpSite;
	strName = PP->strName;
	strPwd = PP->strPwd;

	CInternetSession* pSession;			//����Ự����ָ�����
	CFtpConnection* pConnection;			//�������Ӷ���ָ�����
	CFtpFileFind* pFileFind; 			//�����ļ���ѯ����ָ�����
	CString strFileName;
	BOOL bContinue;

	pConnection = NULL;					//��ʼ��
	pFileFind = NULL;

	pSession = new CInternetSession(		// ����Internet�Ự�����
		AfxGetAppName(), 1, PRE_CONFIG_INTERNET_ACCESS);
	try
	{  // ��ͼ������ָ��FTP������������
		pConnection =
			pSession->GetFtpConnection(strFtpSite, strName, strPwd);
	}
	catch (CInternetException* e) {
		e->Delete(); 						// �޷��������ӣ����д�����
		pConnection = NULL;
	}

	if (pConnection != NULL)
	{// ����CFtpFileFind�������캯������CFtpConnection�����ָ��
		pFileFind = new CFtpFileFind(pConnection);
		bContinue = pFileFind->FindFile(_T("*"));	// ���ҷ������ϵ�ǰĿ¼�������ļ�
		if (!bContinue)						// ���һ���ļ����Ҳ�������������
		{
			pFileFind->Close();
			pFileFind = NULL;
		}

		while (bContinue)					// �ҵ��˵�һ���ļ����������������ļ�
		{
			bContinue = pFileFind->FindNextFile();		// ������һ���ļ�
			strFileName = pFileFind->GetFileName();	// ����ҵ����ļ����ļ���
													// ����ҵ��Ķ����Ǹ�Ŀ¼���ͽ�Ŀ¼������������
			if (pFileFind->IsDirectory())  strFileName = "[" + strFileName + "]";
			// ���ҵ����ļ���Ŀ¼����ʾ���б����
			pList->AddString(strFileName);
			
		}

		if (pFileFind != NULL)
		{
			pFileFind->Close();						// ������ѯ
			pFileFind = NULL;
		}
	}
	delete pFileFind;								// ɾ���ļ���ѯ����
	if (pConnection != NULL)
	{
		pConnection->Close();
		delete pConnection;							// ɾ��FTP���Ӷ���
	}
	delete pSession; 								// ɾ��Internet �Ự���� 
	return 0;									// ����Ҫ�з���ֵ
}
//2���������ص��̺߳���
UINT mtDownloadFile(LPVOID  pParam)
{
	if (pParam == NULL)  AfxEndThread(NULL);
	//������ȡ�������õĲ����Ĵ��� 
	FTP_INFO* PP;
	CListBox*  pList;
	CString  strFtpSite;
	CString  strName;
	CString  strPwd;
	PP = (FTP_INFO*)pParam;
	pList = PP->pList;
	strFtpSite = PP->strFtpSite;
	strName = PP->strName;
	strPwd = PP->strPwd;

	int  nSel = pList->GetCurSel();
	CString  strSourceName;
	pList->GetText(nSel, strSourceName);
	if (strSourceName.GetAt(0) != '[' )
	   {
		   //ѡ������ļ�
		   CString strDestName;
	   CFileDialog dlg(FALSE,"","*.*");	//������һ���ļ��Ի���������
	   if (dlg.DoModal() == IDOK)     		//�����ļ��Ի���
	   {
		   //��������ļ��ڱ��ػ��ϴ洢��·��������
		   strDestName = dlg.GetPathName();

		   //���ú��������ļ�
		   if (mtDownload(strFtpSite, strName, strPwd,
			   strSourceName,strDestName))
			   AfxMessageBox("���سɹ���",MB_OK | MB_ICONINFORMATION);
		   else {
			   AfxMessageBox("����ʧ�ܣ�",MB_OK | MB_ICONSTOP);
			   return FALSE;
		   }
	   }
	   else {
		   AfxMessageBox("��д���ļ�����",MB_OK | MB_ICONSTOP);
		   return FALSE;
	   }
	   }
	else {
		   //ѡ�����Ŀ¼
		   AfxMessageBox("��������Ŀ¼!\n����ѡ!", MB_OK | MB_ICONSTOP);
		   return FALSE;
	   }
	   return 0;
}

//�����ļ����õĺ���
BOOL mtDownload(CString  strFtpSite,
	CString  strName,
	CString  strPwd,
	CString  strSourceName,
	CString  strDestName)
{
	CInternetSession* pSession;		//����Ự�������ָ��
	CFtpConnection* pConnection;		//�������Ӷ������ָ��

	pConnection = NULL;

	//����Internet�Ự����
	pSession = new CInternetSession(AfxGetAppName(), 1,
		PRE_CONFIG_INTERNET_ACCESS);

	try
	{
		//����FTP����
		pConnection = pSession->GetFtpConnection(strFtpSite,
			strName, strPwd);
	}
	catch (CInternetException* e)
	{
		//������
		e->Delete();
		pConnection = NULL;
		return FALSE;
	}

	if (pConnection != NULL)
	{
		//�����ļ�
		if (!pConnection->GetFile(strSourceName, strDestName))
		{
			//�����ļ�����
			pConnection->Close();
			delete pConnection;
			delete pSession;
			return FALSE;
		}
	}

	//�������
	if (pConnection != NULL)
	{
		pConnection->Close();
		delete pConnection;
	}
	delete pSession;
	return TRUE;
}
//3�������ϴ����̺߳���
UINT  mtUploadFile(LPVOID  pParam)
{
	if (pParam == NULL)  AfxEndThread(NULL);
	//������ȡ�������õĲ����Ĵ��� 
	FTP_INFO* PP;
	CListBox*  pList;
	CString  strFtpSite;
	CString  strName;
	CString  strPwd;
	PP = (FTP_INFO*)pParam;
	pList = PP->pList;
	strFtpSite = PP->strFtpSite;
	strName = PP->strName;
	strPwd = PP->strPwd;

	CString strSourceName;
	CString strDestName;
	CFileDialog dlg(TRUE, "", "*.*");       //�����ı��Ի���������
	if (dlg.DoModal() == IDOK)
	{
		//��ô��ϴ��ı��ػ��ļ�·�����ļ���
		strSourceName = dlg.GetPathName();
		strDestName = dlg.GetFileName();

		//����Upload�����ϴ��ļ�
		if (mtUpload(strFtpSite, strName, strPwd,
			strSourceName, strDestName))
			AfxMessageBox("�ϴ��ɹ���", MB_OK | MB_ICONINFORMATION);
		else
			AfxMessageBox("�ϴ�ʧ�ܣ�", MB_OK | MB_ICONSTOP);
	}
	else {
		//�ļ�ѡ���д���
		AfxMessageBox("��ѡ���ļ���", MB_OK | MB_ICONSTOP);
	}
	return 0;
}

//�ϴ��ļ����õĺ���
BOOL  mtUpload(CString strFtpSite, CString strName,
	CString strPwd, CString strSourceName, CString strDestName)
{
	CInternetSession* pSession;
	CFtpConnection* pConnection;

	pConnection = NULL;

	//����Internet�Ự
	pSession = new CInternetSession(AfxGetAppName(), 1,
		PRE_CONFIG_INTERNET_ACCESS);

	try
	{
		//����FTP����
		pConnection = pSession->GetFtpConnection(strFtpSite,
			strName, strPwd);
	}
	catch (CInternetException* e)
	{
		//������
		e->Delete();
		pConnection = NULL;
		return FALSE;
	}

	if (pConnection != NULL)
	{
		//�ϴ��ļ�
		if (!pConnection->PutFile(_T(strSourceName), _T(strDestName)))
		{
			//�ϴ��ļ�����
			pConnection->Close();
			delete pConnection;
			delete pSession;
			return FALSE;
		}
	}

	//�������
	if (pConnection != NULL)
	{
		pConnection->Close();
		delete pConnection;
	}
	delete pSession;
	return TRUE;
}