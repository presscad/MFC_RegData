
// RegDataDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RegData.h"
#include "RegDataDlg.h"
#include "afxdialogex.h"

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
