
// RegDataDlg.h : header file
//

#pragma once


// CRegDataDlg dialog
class CRegDataDlg : public CDialogEx
{
// Construction
public:
	CRegDataDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_REGDATA_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_ProductName;
	CString m_RegisteredOwner;
	CString m_Bits;
	CString m_IsVM;
	CString m_sCountry;
	CString m_LocalName;
	CString m_sLanguage;
	CString m_Office;
	CString m_SystemRoot;
	afx_msg void OnClickedQuery();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnChangeProductname();
	afx_msg void OnChangeRegisteredowner();
	afx_msg void OnChangeSystemroot();
	afx_msg void OnChangeBits();
	afx_msg void OnChangeIsvm();
	afx_msg void OnChangeScountry();
	afx_msg void OnChangeLocalname();
	afx_msg void OnChangeSlanguage();
	afx_msg void OnChangeOffice();
};
