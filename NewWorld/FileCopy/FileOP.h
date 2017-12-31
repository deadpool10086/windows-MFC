// FileOP.h: interface for the CFileOP class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FILEOP_H__B81275E4_6EEC_49BB_BCF4_90849860AAA9__INCLUDED_)
#define AFX_FILEOP_H__B81275E4_6EEC_49BB_BCF4_90849860AAA9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CFileOP : public CObject  
{
public:
	BOOL Copy(CString strSourcePath, CString strTargetPath);
	CFileOP();
	virtual ~CFileOP();

};

#endif // !defined(AFX_FILEOP_H__B81275E4_6EEC_49BB_BCF4_90849860AAA9__INCLUDED_)
