
// guofei5Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "guofei5.h"
#include "guofei5Dlg.h"
#include "afxdialogex.h"
#include "CMyFormView0.h"
#include "CMyFormView1.h"
#include "ship.h"
#include <vector>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cguofei5Dlg 对话框



Cguofei5Dlg::Cguofei5Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GUOFEI5_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pMyFrame = new CFrameWnd;
}

//Cguofei5Dlg::~Cguofei5Dlg()
//{
//	delete m_pMyFrame;
//}

void Cguofei5Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Cguofei5Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
	ON_COMMAND(ID_UU32771, &Cguofei5Dlg::OnUu32771)
	ON_COMMAND(ID_LAND, &Cguofei5Dlg::Onland)
	ON_COMMAND(ID_LINE, &Cguofei5Dlg::Online)
	ON_COMMAND(ID_Pland, &Cguofei5Dlg::OnPland)
	ON_COMMAND(ID_Pline, &Cguofei5Dlg::OnPline)
	ON_COMMAND(ID_Shatan, &Cguofei5Dlg::OnShatan)
	ON_COMMAND(ID_deng, &Cguofei5Dlg::Ondeng)
END_MESSAGE_MAP()


// Cguofei5Dlg 消息处理程序

BOOL Cguofei5Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_menu.LoadMenu(IDR_MENU1);  //  IDR_MENU1	
	SetMenu(&m_menu);
	//CRect cRect;
	//GetWindowRect(&cRect);
	//ScreenToClient(&cRect);
	//m_pMyFrame->MoveWindow(&cRect);
	//m_pMyFrame->ShowWindow(SW_SHOW);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void Cguofei5Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Cguofei5Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Cguofei5Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



int Cguofei5Dlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码

	//分割窗口
	// Because the CFRameWnd needs a window class, we will create a new one. I just copied the sample from MSDN Help.
	// When using it in your project, you may keep CS_VREDRAW and CS_HREDRAW and then throw the other three parameters.
	//需要注册窗口类
	CString strMyClass = AfxRegisterWndClass(CS_VREDRAW | CS_HREDRAW,
		::LoadCursor(NULL, IDC_ARROW), (HBRUSH) ::GetStockObject(WHITE_BRUSH),
		::LoadIcon(NULL, IDI_APPLICATION));

	// Create the frame window with "this" as the parent
	m_pMyFrame = new CFrameWnd;
	m_pMyFrame->Create(strMyClass, _T(""), WS_CHILD, CRect(0, 0, 1000, 700), this);
	m_pMyFrame->ShowWindow(SW_SHOW);

	// and finally, create the splitter with the frame as the parent
	m_cSplitter.CreateStatic(m_pMyFrame, 1, 2); //在Frame里切分视图窗口为1×2，就是一行两列
	m_cSplitter.CreateView(0, 0, RUNTIME_CLASS(CMyFormView0), CSize(450, 700), NULL);//第一行一列
	m_cSplitter.CreateView(0, 1, RUNTIME_CLASS(CMyFormView1), CSize(550, 700), NULL);//第一行二列
	
	
	return 0;
}


void Cguofei5Dlg::OnDestroy()
{
	CDialogEx::OnDestroy();
	
	// TODO: 在此处添加消息处理程序代码
	if (m_pMyFrame) delete m_pMyFrame;
}


void Cguofei5Dlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	CRect cRect;
	GetWindowRect(&cRect);
	ScreenToClient(&cRect);
	m_pMyFrame->MoveWindow(&cRect);
	m_pMyFrame->ShowWindow(SW_SHOW);

}


void Cguofei5Dlg::OnUu32771()
{
	// TODO: 在此添加命令处理程序代码
	MessageBox(_T("guofei"));
}


void Cguofei5Dlg::Onland()
{
	// TODO: 在此添加命令处理程序代码

	CMyFormView1* cf1=(CMyFormView1*)m_cSplitter.GetPane(0, 1);
	cf1->m_select=1;
}


void Cguofei5Dlg::Online()
{
	// TODO: 在此添加命令处理程序代码
	CMyFormView1* cf1 = (CMyFormView1*)m_cSplitter.GetPane(0, 1);
	cf1->m_select = 2;
}


void Cguofei5Dlg::OnPland()
{
	// TODO: 在此添加命令处理程序代码
	CMyFormView1* cf1 = (CMyFormView1*)m_cSplitter.GetPane(0, 1);
	cf1->m_select = 3;
}


void Cguofei5Dlg::OnPline()
{
	// TODO: 在此添加命令处理程序代码
	CMyFormView1* cf1 = (CMyFormView1*)m_cSplitter.GetPane(0, 1);
	cf1->m_select = 4;
}


void Cguofei5Dlg::OnShatan()
{
	// TODO: 在此添加命令处理程序代码
	CMyFormView1* cf1 = (CMyFormView1*)m_cSplitter.GetPane(0, 1);
	cf1->m_select = 3;
}


void Cguofei5Dlg::Ondeng()
{
	// TODO: 在此添加命令处理程序代码
	CMyFormView1* cf1 = (CMyFormView1*)m_cSplitter.GetPane(0, 1);
	cf1->m_select = 4;
}
