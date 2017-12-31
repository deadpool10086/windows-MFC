// Msg.h: interface for the CMsg class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MSG_H__A04FBD06_7DB5_48E9_8CDF_2EC695C5970D__INCLUDED_)
#define AFX_MSG_H__A04FBD06_7DB5_48E9_8CDF_2EC695C5970D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMsg : public CObject  
{
public:
	virtual void Serialize(CArchive& ar);
	BOOL m_bClose;
	CString m_strText;
	CMsg();
	virtual ~CMsg();

};

#endif // !defined(AFX_MSG_H__A04FBD06_7DB5_48E9_8CDF_2EC695C5970D__INCLUDED_)
