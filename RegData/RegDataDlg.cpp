
// RegDataDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RegData.h"
#include "RegDataDlg.h"
#include "afxdialogex.h"
#include "string.h"
#include<atlconv.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRegDataDlg dialog



CRegDataDlg::CRegDataDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRegDataDlg::IDD, pParent)
	, m_ProductName(_T(""))
	, m_RegisteredOwner(_T(""))
	, m_Bits(_T(""))
	, m_IsVM(_T(""))
	, m_sCountry(_T(""))
	, m_LocalName(_T(""))
	, m_sLanguage(_T(""))
	, m_Office(_T(""))
	, m_SystemRoot(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRegDataDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_PRODUCTNAME, m_ProductName);
	DDX_Text(pDX, IDC_REGISTEREDOWNER, m_RegisteredOwner);
	DDX_Text(pDX, IDC_BITS, m_Bits);
	DDX_Text(pDX, IDC_ISVM, m_IsVM);
	DDX_Text(pDX, IDC_SCOUNTRY, m_sCountry);
	DDX_Text(pDX, IDC_LOCALNAME, m_LocalName);
	DDX_Text(pDX, IDC_SLANGUAGE, m_sLanguage);
	DDX_Text(pDX, IDC_OFFICE, m_Office);
	DDX_Text(pDX, IDC_SYSTEMROOT, m_SystemRoot);
}

BEGIN_MESSAGE_MAP(CRegDataDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_QUERY, &CRegDataDlg::OnClickedQuery)
	ON_BN_CLICKED(IDCANCEL, &CRegDataDlg::OnBnClickedCancel)
	ON_EN_CHANGE(IDC_PRODUCTNAME, &CRegDataDlg::OnChangeProductname)
	ON_EN_CHANGE(IDC_REGISTEREDOWNER, &CRegDataDlg::OnChangeRegisteredowner)
	ON_EN_CHANGE(IDC_SYSTEMROOT, &CRegDataDlg::OnChangeSystemroot)
	ON_EN_CHANGE(IDC_BITS, &CRegDataDlg::OnChangeBits)
	ON_EN_CHANGE(IDC_ISVM, &CRegDataDlg::OnChangeIsvm)
	ON_EN_CHANGE(IDC_SCOUNTRY, &CRegDataDlg::OnChangeScountry)
	ON_EN_CHANGE(IDC_LOCALNAME, &CRegDataDlg::OnChangeLocalname)
	ON_EN_CHANGE(IDC_SLANGUAGE, &CRegDataDlg::OnChangeSlanguage)
	ON_EN_CHANGE(IDC_OFFICE, &CRegDataDlg::OnChangeOffice)
END_MESSAGE_MAP()


// CRegDataDlg message handlers

BOOL CRegDataDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CRegDataDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CRegDataDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CRegDataDlg::OnClickedQuery()
{
	// TODO: Add your control notification handler code here
	//--------------------------------查询系统版本信息---------------------------------------------
	HKEY hKEY;	//handler
	LPCTSTR banner_Set = _T("Software\\Microsoft\\Windows NT\\CurrentVersion"); //子健目录
	long retopen = (::RegOpenKeyEx(HKEY_LOCAL_MACHINE,banner_Set,0,KEY_READ,&hKEY));	//访问系统版本注册表
	if(retopen!=ERROR_SUCCESS)
	{
		MessageBox(_T("ERROR:Can not open the hKEY!"));
		return;
	}
	
	//查询ProductName
	DWORD cdData=80;	//预设置的数据长度
	LPDWORD lp=&cdData;
	LPBYTE ProductName_Get = new BYTE[80];	//保存查询的数据
	long ret = RegGetValue(HKEY_LOCAL_MACHINE, _T("Software\\Microsoft\\Windows NT\\CurrentVersion"),_T("ProductName"), RRF_RT_REG_SZ, NULL, ProductName_Get, lp);//注册表查询，将结果保存在ProductName_Get中
	//将unicode转换为ASCII
	char ProductName_Get_Buf[100];
	DWORD dBufSize = 80;
	WideCharToMultiByte(CP_UTF8, 0, (LPCWCH)ProductName_Get, -1, ProductName_Get_Buf, dBufSize, NULL, FALSE);//转换后的结果保存在ProductName_Get_Buf中
	m_ProductName = CString(ProductName_Get_Buf);//显示在界面上

	//查询RegisteredOwner
	LPBYTE RegisteredOwner_Get = new BYTE[80];
	DWORD type_2 = REG_SZ;
	DWORD cdData_2 = 80;
	long ret2 = ::RegQueryValueEx(hKEY,_T("RegisteredOwner"),NULL,&type_2,RegisteredOwner_Get,&cdData_2);
	if(ret2!=ERROR_SUCCESS)
	{
		MessageBox(_T("Can not query the Reg"));
		return;
	}
	char dBuf2[100];
	DWORD dBufSize2 = 80;
	WideCharToMultiByte(CP_UTF8, 0, (LPCWCH)RegisteredOwner_Get, -1, dBuf2, dBufSize2, NULL, FALSE);
	m_RegisteredOwner = CString(dBuf2);

	//查询SystemRoot
	LPBYTE SystemRoot_Get = new BYTE[80];
	DWORD type_3 = REG_SZ;
	DWORD cdData_3 = 80;
	long ret3 = ::RegQueryValueEx(hKEY,_T("SystemRoot"),NULL,&type_3,SystemRoot_Get,&cdData_3);
	if(ret3!=ERROR_SUCCESS)
	{
		MessageBox(_T("Can not query the Reg"));
		return;
	}
	char dBuf3[100];
	DWORD dBufSize3 = 80;
	WideCharToMultiByte(CP_UTF8, 0, (LPCWCH)SystemRoot_Get, -1, dBuf3, dBufSize3, NULL, FALSE);
	m_SystemRoot = CString(dBuf3);

	UpdateData(false);	//将值赋给控件

	//delete[] ProductName_Get;
	delete[] RegisteredOwner_Get;
	delete[] SystemRoot_Get;
	::RegCloseKey(hKEY);



}


void CRegDataDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}


void CRegDataDlg::OnChangeProductname()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CRegDataDlg::OnChangeRegisteredowner()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CRegDataDlg::OnChangeSystemroot()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CRegDataDlg::OnChangeBits()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CRegDataDlg::OnChangeIsvm()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CRegDataDlg::OnChangeScountry()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CRegDataDlg::OnChangeLocalname()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CRegDataDlg::OnChangeSlanguage()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CRegDataDlg::OnChangeOffice()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
