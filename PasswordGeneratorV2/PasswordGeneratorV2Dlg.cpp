
// PasswordGeneratorV2Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "PasswordGeneratorV2.h"
#include "PasswordGeneratorV2Dlg.h"
#include "afxdialogex.h"
#include <algorithm>  // For std::shuffle
#include <random>     // For std::mt19937 and std::uniform_int_distribution
#include <ctime>      // For std::time

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()

protected:
	virtual BOOL OnInitDialog();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BOOL CAboutDlg::OnInitDialog() {
	CDialog::OnInitDialog();

	SetWindowText(_T("密码生成器V2"));
	SetDlgItemText(IDC_STATIC_ABOUT, _T("版本：2.0.2"));

	return TRUE;
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPasswordGeneratorV2Dlg dialog



CPasswordGeneratorV2Dlg::CPasswordGeneratorV2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PASSWORDGENERATORV2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPasswordGeneratorV2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);

	DDX_Control(pDX, IDC_SLIDER1, m_slider1);
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
	DDX_Control(pDX, IDC_SPIN1, m_spin1);

	DDX_Control(pDX, IDC_CHECK1, m_chk1);
	DDX_Control(pDX, IDC_CHECK2, m_chk2);
	DDX_Control(pDX, IDC_CHECK3, m_chk3);
	DDX_Control(pDX, IDC_CHECK4, m_chk4);
	DDX_Control(pDX, IDC_CHECK5, m_chk5);
	DDX_Control(pDX, IDC_CHECK6, m_chk6);
	DDX_Control(pDX, IDC_CHECK7, m_chk7);
	DDX_Control(pDX, IDC_CHECK8, m_chk8);

	DDX_Control(pDX, IDC_EDIT3, m_edit3);
	DDX_Control(pDX, IDC_EDIT4, m_edit4);

	DDX_Control(pDX, IDC_CHECK9, m_chk9);
	DDX_Control(pDX, IDC_CHECK10, m_chk10);
	DDX_Control(pDX, IDC_CHECK11, m_chk11);
}

void CPasswordGeneratorV2Dlg::OnClose() {
	CDialogEx::OnCancel();
}

BEGIN_MESSAGE_MAP(CPasswordGeneratorV2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON1, &CPasswordGeneratorV2Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CPasswordGeneratorV2Dlg::OnBnClickedButton2)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &CPasswordGeneratorV2Dlg::OnNMCustomdrawSlider1)
	ON_EN_CHANGE(IDC_EDIT2, &CPasswordGeneratorV2Dlg::OnEnChangeEdit2)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN1, &CPasswordGeneratorV2Dlg::OnDeltaposSpin1)
	ON_EN_CHANGE(IDC_EDIT3, &CPasswordGeneratorV2Dlg::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT4, &CPasswordGeneratorV2Dlg::OnEnChangeEdit4)
	ON_BN_CLICKED(IDC_BUTTON3, &CPasswordGeneratorV2Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CPasswordGeneratorV2Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CPasswordGeneratorV2Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CPasswordGeneratorV2Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_CHECK1, &CPasswordGeneratorV2Dlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &CPasswordGeneratorV2Dlg::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK3, &CPasswordGeneratorV2Dlg::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK4, &CPasswordGeneratorV2Dlg::OnBnClickedCheck4)
	ON_BN_CLICKED(IDC_CHECK5, &CPasswordGeneratorV2Dlg::OnBnClickedCheck5)
	ON_BN_CLICKED(IDC_CHECK6, &CPasswordGeneratorV2Dlg::OnBnClickedCheck6)
	ON_BN_CLICKED(IDC_CHECK7, &CPasswordGeneratorV2Dlg::OnBnClickedCheck7)
	ON_BN_CLICKED(IDC_CHECK8, &CPasswordGeneratorV2Dlg::OnBnClickedCheck8)
	ON_BN_CLICKED(IDC_CHECK9, &CPasswordGeneratorV2Dlg::OnBnClickedCheck9)
	ON_BN_CLICKED(IDC_CHECK10, &CPasswordGeneratorV2Dlg::OnBnClickedCheck10)
	ON_BN_CLICKED(IDC_CHECK11, &CPasswordGeneratorV2Dlg::OnBnClickedCheck11)
END_MESSAGE_MAP()


// CPasswordGeneratorV2Dlg message handlers

BOOL CPasswordGeneratorV2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	SetWindowText(_T("密码生成器V2"));
	CRect myrect(0, 0, 700, 525);  // 4:3
	CWnd::SetWindowPos(NULL, 0, 0, myrect.Width(), myrect.Height(), SWP_NOZORDER | SWP_NOMOVE);

	/* 客户区域宽和高 */
	CRect clientRect;
	GetClientRect(&clientRect);
	int clientWidth = clientRect.right - clientRect.left;
	int clientHeight = clientRect.bottom - clientRect.top;
	
	int padding_lr = 10;   // 到左右边框的距离
	int padding_t = 15;    // 到顶部边框的距离
	int padding_b = 10;    // 到底部边框的距离
	int interval_lr = 8;   // 两个控件左右的间隔
	int interval_ud = 10;  // 两个控件上下的间隔
	int height = 30;       // 控件的高度
	
	/* 密码显示框、生成密码按钮、复制按钮 */
	int width_btn1 = 75;
	int width_btn2 = 55;

	int x_edit1 = padding_lr;
	int y_edit1 = padding_t;
	int width_edit1 = clientWidth - x_edit1 - interval_lr - width_btn1 - interval_lr - width_btn2 - padding_lr;
	int height_edit1 = height;
	CWnd* pEdit1 = GetDlgItem(IDC_EDIT1);
	pEdit1->MoveWindow(x_edit1, y_edit1, width_edit1, height_edit1);
	m_edit1.SetLimitText(128);  // 限制编辑框可输入长度
	//CFont* pFont = CFont::FromHandle((HFONT)GetStockObject(DEFAULT_GUI_FONT));  // L"SimSun"
	CFont* pFont = m_edit1.GetFont();  // L"MS Shell Dlg 2"
	LOGFONT lf;
	pFont->GetLogFont(&lf);
	CFont font;
	font.CreatePointFont(100, lf.lfFaceName);  // 10磅字体
	//lf.lfHeight *= 1.25;
	//font.CreateFontIndirectW(&lf);
	m_edit1.SetFont(&font);

	int x_btn1 = x_edit1 + width_edit1 + interval_lr;
	int y_btn1 = y_edit1;
	int height_btn1 = height_edit1;
	CWnd* pBtn1 = GetDlgItem(IDC_BUTTON1);
	pBtn1->MoveWindow(x_btn1, y_btn1, width_btn1, height_btn1);
	pBtn1->SetWindowTextW(_T("生成密码"));

	int x_btn2 = x_btn1 + width_btn1 + interval_lr;
	int y_btn2 = y_edit1;
	int height_btn2 = height_edit1;
	CWnd* pBtn2 = GetDlgItem(IDC_BUTTON2);
	pBtn2->MoveWindow(x_btn2, y_btn2, width_btn2, height_btn2);
	pBtn2->SetWindowTextW(_T("复制"));

	/* 设置 */
	int x_static1 = x_edit1;
	int y_static1 = y_edit1 + height_edit1 + interval_ud;
	int width_static1 = clientWidth - x_static1 - padding_lr;
	int height_static1 = clientHeight - y_static1 - padding_b;
	GetDlgItem(IDC_STATIC1)->MoveWindow(x_static1, y_static1, width_static1, height_static1);
	GetDlgItem(IDC_STATIC1)->SetWindowTextW(_T("设置"));

	/* 长度 */
	int width_static2 = 45;
	int width_edit2 = 55;
	int width_spin1 = 25;
	int lengthMin = 1;
	int lengthMax = 64;
	int currentLength = 16;
	
	int x_static2 = x_static1 + padding_lr * 2;
	int y_static2 = y_static1 + interval_ud * 3;
	int height_static2 = height;
	GetDlgItem(IDC_STATIC2)->MoveWindow(x_static2, y_static2, width_static2, height_static2);
	GetDlgItem(IDC_STATIC2)->SetWindowTextW(_T("长度:"));
	GetDlgItem(IDC_STATIC2)->ModifyStyle(0, SS_CENTERIMAGE);  // 垂直居中

	int x_slider1 = x_static2 + width_static2;  // 文本控件与滑块控件没有添加间隔
	int y_slider1 = y_static2;
	int width_slider1 = clientWidth - x_slider1 - interval_lr - width_edit2 - width_spin1 - padding_lr * 2;
	int height_slider1 = height_static2;
	GetDlgItem(IDC_SLIDER1)->MoveWindow(x_slider1, y_slider1, width_slider1, height_slider1);
	m_slider1.SetRange(lengthMin, lengthMax);
	m_slider1.SetPos(currentLength);

	int x_edit2 = x_slider1 + width_slider1 + interval_lr;
	int y_edit2 = y_static2;
	int height_edit2 = height_static2;
	GetDlgItem(IDC_EDIT2)->MoveWindow(x_edit2, y_edit2, width_edit2, height_edit2);
	m_edit2.ModifyStyle(0, ES_NUMBER);  // 只允许输入数字
	m_edit2.SetLimitText(3);  // 限制输入长度
	m_edit2.SetFont(&font);

	int x_spin1 = x_edit2 + width_edit2;
	int y_spin1 = y_static2;
	int height_spin1 = height_static2;
	GetDlgItem(IDC_SPIN1)->MoveWindow(x_spin1, y_spin1, width_spin1, height_spin1);
	m_spin1.SetRange(lengthMin, lengthMax);
	m_spin1.SetPos(currentLength);

	/* 使用字符 */
	int x_static3 = x_static2;
	int y_static3 = y_static2 + height_static2 + interval_ud;
	int width_static3 = clientWidth - x_static3 - padding_lr * 2;
	int height_chk1 = height;
	int height_chk5 = height;
	int height_static3 = interval_ud * 2 + height_chk1 + interval_ud + height_chk5 + interval_ud;
	GetDlgItem(IDC_STATIC3)->MoveWindow(x_static3, y_static3, width_static3, height_static3);
	GetDlgItem(IDC_STATIC3)->SetWindowTextW(_T("使用字符"));

	int x_chk1 = x_static3 + interval_lr * 2;
	int y_chk1 = y_static3 + interval_ud * 2;
	int width_chk1 = 90;
	GetDlgItem(IDC_CHECK1)->MoveWindow(x_chk1, y_chk1, width_chk1, height_chk1);
	GetDlgItem(IDC_CHECK1)->SetWindowTextW(_T(" A-Z"));
	m_chk1.SetCheck(TRUE);

	int x_chk2 = x_chk1 + width_chk1 + interval_lr;
	int y_chk2 = y_chk1;
	int width_chk2 = width_chk1;
	int height_chk2 = height;
	GetDlgItem(IDC_CHECK2)->MoveWindow(x_chk2, y_chk2, width_chk2, height_chk2);
	GetDlgItem(IDC_CHECK2)->SetWindowTextW(_T(" a-z"));
	m_chk2.SetCheck(TRUE);

	int x_chk3 = x_chk2 + width_chk2 + interval_lr;
	int y_chk3 = y_chk1;
	int width_chk3 = width_chk1;
	int height_chk3 = height;
	GetDlgItem(IDC_CHECK3)->MoveWindow(x_chk3, y_chk3, width_chk3, height_chk3);
	GetDlgItem(IDC_CHECK3)->SetWindowTextW(_T(" 0-9"));
	m_chk3.SetCheck(TRUE);

	int x_chk4 = x_chk3 + width_chk3 + interval_lr;
	int y_chk4 = y_chk1;
	int width_chk4 = 200;
	int height_chk4 = height;
	GetDlgItem(IDC_CHECK4)->MoveWindow(x_chk4, y_chk4, width_chk4, height_chk4);
	GetDlgItem(IDC_CHECK4)->SetWindowTextW(_T(" ! @ # $ % ^ && * ? - _"));  // &&转义&
	m_chk4.SetCheck(TRUE);

	int x_chk5 = x_chk1;
	int y_chk5 = y_chk1 + height_chk1 + interval_ud;
	int width_chk5 = width_chk1;
	GetDlgItem(IDC_CHECK5)->MoveWindow(x_chk5, y_chk5, width_chk5, height_chk5);
	GetDlgItem(IDC_CHECK5)->SetWindowTextW(_T(" , . : ;"));

	int x_chk6 = x_chk5 + width_chk5 + interval_lr;
	int y_chk6 = y_chk5;
	int width_chk6 = width_chk1;
	int height_chk6 = height;
	GetDlgItem(IDC_CHECK6)->MoveWindow(x_chk6, y_chk6, width_chk6, height_chk6);
	GetDlgItem(IDC_CHECK6)->SetWindowTextW(_T(" ~ ` \" '"));  // 转义双引号

	int x_chk7 = x_chk6 + width_chk6 + interval_lr;
	int y_chk7 = y_chk5;
	int width_chk7 = width_chk1;
	int height_chk7 = height;
	GetDlgItem(IDC_CHECK7)->MoveWindow(x_chk7, y_chk7, width_chk7, height_chk7);
	GetDlgItem(IDC_CHECK7)->SetWindowTextW(_T(" / \\ | + ="));  // 转义反斜杠

	int x_chk8 = x_chk7 + width_chk7 + interval_lr;
	int y_chk8 = y_chk5;
	int width_chk8 = width_chk4;
	int height_chk8 = height;
	GetDlgItem(IDC_CHECK8)->MoveWindow(x_chk8, y_chk8, width_chk8, height_chk8);
	GetDlgItem(IDC_CHECK8)->SetWindowTextW(_T(" ( ) [ ] { } < >"));

	/* 高级选项 */
	int x_static4 = x_static2;
	int y_static4 = y_static3 + height_static3 + interval_ud;
	int width_static4 = width_static3;
	int height_static4 = clientHeight - y_static4 - padding_b * 2;
	GetDlgItem(IDC_STATIC4)->MoveWindow(x_static4, y_static4, width_static4, height_static4);
	GetDlgItem(IDC_STATIC4)->SetWindowTextW(_T("高级选项"));

	int x_static5 = x_static4 + interval_lr * 2;
	int y_static5 = y_static4 + interval_ud * 2;
	int width_static5 = 100;
	int height_static5 = height;
	GetDlgItem(IDC_STATIC5)->MoveWindow(x_static5, y_static5, width_static5, height_static5);
	GetDlgItem(IDC_STATIC5)->SetWindowTextW(_T("优先级1,包含:"));
	GetDlgItem(IDC_STATIC5)->ModifyStyle(0, SS_CENTERIMAGE);  // 垂直居中
	int x_edit3 = x_static5 + width_static5;  // 文本控件与输入框没有添加间隔
	int y_edit3 = y_static5;
	int width_edit3 = 220;
	int height_edit3 = height;
	GetDlgItem(IDC_EDIT3)->MoveWindow(x_edit3, y_edit3, width_edit3, height_edit3);
	m_edit3.SetLimitText(128);  // 限制编辑框可输入长度
	m_edit3.SetFont(&font);
	int x_btn3 = x_edit3 + width_edit3;
	int y_btn3 = y_static5;
	int width_btn3 = 20;
	int height_btn3 = height;
	GetDlgItem(IDC_BUTTON3)->MoveWindow(x_btn3, y_btn3, width_btn3, height_btn3);
	GetDlgItem(IDC_BUTTON3)->SetWindowTextW(_T("x"));
	GetDlgItem(IDC_BUTTON3)->ShowWindow(SW_HIDE);

	int x_btn5 = x_btn3 + width_btn3 + interval_lr;
	int y_btn5 = y_static5;
	int width_btn5 = 100;
	int height_btn5 = height;
	GetDlgItem(IDC_BUTTON5)->MoveWindow(x_btn5, y_btn5, width_btn5, height_btn5);
	GetDlgItem(IDC_BUTTON5)->SetWindowTextW(_T("16进制(大写)"));

	int x_btn6 = x_btn5 + width_btn5 + interval_lr;
	int y_btn6 = y_static5;
	int width_btn6 = width_btn5;
	int height_btn6 = height;
	GetDlgItem(IDC_BUTTON6)->MoveWindow(x_btn6, y_btn6, width_btn6, height_btn6);
	GetDlgItem(IDC_BUTTON6)->SetWindowTextW(_T("16进制(小写)"));

	int x_static6 = x_static5;
	int y_static6 = y_static5 + height_static5 + interval_ud;
	int width_static6 = width_static5;
	int height_static6 = height;
	GetDlgItem(IDC_STATIC6)->MoveWindow(x_static6, y_static6, width_static6, height_static6);
	GetDlgItem(IDC_STATIC6)->SetWindowTextW(_T("优先级2,排除:"));
	GetDlgItem(IDC_STATIC6)->ModifyStyle(0, SS_CENTERIMAGE);  // 垂直居中
	int x_edit4 = x_static6 + width_static6;  // 文本控件与输入框没有添加间隔
	int y_edit4 = y_static6;
	int width_edit4 = width_edit3;
	int height_edit4 = height;
	GetDlgItem(IDC_EDIT4)->MoveWindow(x_edit4, y_edit4, width_edit4, height_edit4);
	m_edit4.SetLimitText(128);  // 限制编辑框可输入长度
	m_edit4.SetFont(&font);
	int x_btn4 = x_edit4 + width_edit4;
	int y_btn4 = y_static6;
	int width_btn4 = width_btn3;
	int height_btn4 = height;
	GetDlgItem(IDC_BUTTON4)->MoveWindow(x_btn4, y_btn4, width_btn4, height_btn4);
	GetDlgItem(IDC_BUTTON4)->SetWindowTextW(_T("x"));
	GetDlgItem(IDC_BUTTON4)->ShowWindow(SW_HIDE);

	int x_chk9 = x_static5;
	int y_chk9 = y_static6 + height_static6 + interval_ud;
	int width_chk9 = 300;
	int height_chk9 = height;
	GetDlgItem(IDC_CHECK9)->MoveWindow(x_chk9, y_chk9, width_chk9, height_chk9);
	GetDlgItem(IDC_CHECK9)->SetWindowTextW(_T(" 每个字符最多出现一次"));

	int x_chk10 = x_static5;
	int y_chk10 = y_chk9 + height_chk9 + interval_ud;
	int width_chk10 = width_chk9;
	int height_chk10 = height;
	GetDlgItem(IDC_CHECK10)->MoveWindow(x_chk10, y_chk10, width_chk10, height_chk10);
	GetDlgItem(IDC_CHECK10)->SetWindowTextW(_T(" 优先级0,排除相似字符( 0 1 l I O | )"));

	int x_chk11 = x_static5;
	int y_chk11 = y_chk10 + height_chk10 + interval_ud;
	int width_chk11 = width_chk9;
	int height_chk11 = height;
	GetDlgItem(IDC_CHECK11)->MoveWindow(x_chk11, y_chk11, width_chk11, height_chk11);
	GetDlgItem(IDC_CHECK11)->SetWindowTextW(_T(" 包含每一种字符"));

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPasswordGeneratorV2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CPasswordGeneratorV2Dlg::OnPaint()
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
HCURSOR CPasswordGeneratorV2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CPasswordGeneratorV2Dlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	SettingsWrapper settings;
	SetSettings(settings);

	std::wstring password_str = GeneratePassword(settings);  // 生成密码
	CString password_cstr(password_str.c_str());             // 构造函数，string转CString

	if (password_cstr != L"")
		m_edit1.SetWindowText(password_cstr);				 // 设置到编辑框
}


void CPasswordGeneratorV2Dlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	CString cstr;
	m_edit1.GetWindowTextW(cstr);
	CT2W unicodeString(cstr);
	std::wstring w(unicodeString);  // CString转string

	CopyToClipboard(w);
}


std::wstring CPasswordGeneratorV2Dlg::GeneratePassword(SettingsWrapper settings) {
	CharactersWrapper characters;
	SetCharacters(characters, settings);

	std::wstring uppercase_letters_chk1 = characters.uppercase_letters_chk1();
	std::wstring lowercase_letters_chk2 = characters.lowercase_letters_chk2();
	std::wstring numbers_chk3 = characters.numbers_chk3();
	std::wstring symbols_chk4 = characters.symbols_chk4();
	std::wstring symbols_chk5 = characters.symbols_chk5();
	std::wstring symbols_chk6 = characters.symbols_chk6();
	std::wstring symbols_chk7 = characters.symbols_chk7();
	std::wstring symbols_chk8 = characters.symbols_chk8();
	std::wstring include_characters_edit3 = characters.include_characters_edit3();
	std::wstring exclude_characters_edit4 = characters.exclude_characters_edit4();
	std::wstring exclude_alike_characters_chk10 = characters.exclude_alike_characters_chk10();
	std::wstring total = characters.total();  // 可用字符

	int length = settings.password_length();
	std::wstring password = L"";

	if (length <= 0)  // 如果长度小于等于0直接返回，避免调用者入参长度不合规则
		return password;

	if (total == L"")  // 如果total为空，直接返回
		return password;

	std::random_device rd;   // 真随机，一般为其它随机数提供引擎
	std::mt19937 gen(rd());  // 伪随机，使用random_device提供种子


	/**
	 * 勾选每个字符最多出现一次，如果长度大于可用字符数，若不禁止生成密码，以可用字符数为长度生成
	 * 勾选包含每一种字符，如果长度小于种数，若不禁止生成密码，以种数为长度生成
	 */
	if (settings.b_each_character_most_once_chk9()) {
		if (settings.b_pick_characters_every_group_chk11()) {  // 此处等于两个都勾选了

			/* 每一种字符先随机取一个 */

			/**
			 * 必须先取包含字符，有种极端情况
			 * 如果先取勾选字符，假设结果大于等于包含字符
			 * 例如先取勾选字符结果为Aa0 后取包含字符Aa
			 * 那么结果必定会有重复，不满足每个字符最多出现一次
			 */

			std::uniform_int_distribution<> dist(0, 0);  // 共用临时变量
			std::wstring::size_type index = 0;           // 共用临时变量
			std::wstring  random_once = L"";			 // 包含字符随机取一个字符

			if (include_characters_edit3.size() > 0) {
				std::shuffle(include_characters_edit3.begin(), include_characters_edit3.end(), gen);
				dist = std::uniform_int_distribution<>(0, include_characters_edit3.size() - 1);
				index = dist(gen);
				password += include_characters_edit3[index];
				random_once = include_characters_edit3[index];
			}

			if (uppercase_letters_chk1.size() > 0) {
				if (random_once.size() == 1)
					uppercase_letters_chk1.erase(std::remove(uppercase_letters_chk1.begin(), uppercase_letters_chk1.end(), random_once[0]), uppercase_letters_chk1.end());

				std::shuffle(uppercase_letters_chk1.begin(), uppercase_letters_chk1.end(), gen);
				dist = std::uniform_int_distribution<>(0, uppercase_letters_chk1.size() - 1);
				index = dist(gen);
				password += uppercase_letters_chk1[index];
			}

			if (lowercase_letters_chk2.size() > 0) {
				if (random_once.size() == 1)
					lowercase_letters_chk2.erase(std::remove(lowercase_letters_chk2.begin(), lowercase_letters_chk2.end(), random_once[0]), lowercase_letters_chk2.end());

				std::shuffle(lowercase_letters_chk2.begin(), lowercase_letters_chk2.end(), gen);
				dist = std::uniform_int_distribution<>(0, lowercase_letters_chk2.size() - 1);
				index = dist(gen);
				password += lowercase_letters_chk2[index];
			}

			if (numbers_chk3.size() > 0) {
				if (random_once.size() == 1)
					numbers_chk3.erase(std::remove(numbers_chk3.begin(), numbers_chk3.end(), random_once[0]), numbers_chk3.end());

				std::shuffle(numbers_chk3.begin(), numbers_chk3.end(), gen);
				dist = std::uniform_int_distribution<>(0, numbers_chk3.size() - 1);
				index = dist(gen);
				password += numbers_chk3[index];
			}

			if (symbols_chk4.size() > 0) {
				if (random_once.size() == 1)
					symbols_chk4.erase(std::remove(symbols_chk4.begin(), symbols_chk4.end(), random_once[0]), symbols_chk4.end());

				std::shuffle(symbols_chk4.begin(), symbols_chk4.end(), gen);
				dist = std::uniform_int_distribution<>(0, symbols_chk4.size() - 1);
				index = dist(gen);
				password += symbols_chk4[index];
			}

			if (symbols_chk5.size() > 0) {
				if (random_once.size() == 1)
					symbols_chk5.erase(std::remove(symbols_chk5.begin(), symbols_chk5.end(), random_once[0]), symbols_chk5.end());

				std::shuffle(symbols_chk5.begin(), symbols_chk5.end(), gen);
				dist = std::uniform_int_distribution<>(0, symbols_chk5.size() - 1);
				index = dist(gen);
				password += symbols_chk5[index];
			}

			if (symbols_chk6.size() > 0) {
				if (random_once.size() == 1)
					symbols_chk6.erase(std::remove(symbols_chk6.begin(), symbols_chk6.end(), random_once[0]), symbols_chk6.end());

				std::shuffle(symbols_chk6.begin(), symbols_chk6.end(), gen);
				dist = std::uniform_int_distribution<>(0, symbols_chk6.size() - 1);
				index = dist(gen);
				password += symbols_chk6[index];
			}

			if (symbols_chk7.size() > 0) {
				if (random_once.size() == 1)
					symbols_chk7.erase(std::remove(symbols_chk7.begin(), symbols_chk7.end(), random_once[0]), symbols_chk7.end());

				std::shuffle(symbols_chk7.begin(), symbols_chk7.end(), gen);
				dist = std::uniform_int_distribution<>(0, symbols_chk7.size() - 1);
				index = dist(gen);
				password += symbols_chk7[index];
			}

			if (symbols_chk8.size() > 0) {
				if (random_once.size() == 1)
					symbols_chk8.erase(std::remove(symbols_chk8.begin(), symbols_chk8.end(), random_once[0]), symbols_chk8.end());

				std::shuffle(symbols_chk8.begin(), symbols_chk8.end(), gen);
				dist = std::uniform_int_distribution<>(0, symbols_chk8.size() - 1);
				index = dist(gen);
				password += symbols_chk8[index];
			}

			for (std::size_t i = 0; i < password.size(); ++i)  // 从total去掉已取出的字符
				total.erase(std::remove(total.begin(), total.end(), password[i]), total.end());

			if (length <= password.size()) {  // 长度小于等于种数，以种数为长度生成
				std::shuffle(password.begin(), password.end(), gen);  // 洗牌一下，不然总是大写小写数字特殊字符的顺序
			}
			else {
				std::shuffle(total.begin(), total.end(), gen);  // 洗牌算法打乱
				password += total.substr(0, length - password.size());  // 长度大于可用字符数，以可用字符数为长度生成

				std::shuffle(password.begin(), password.end(), gen);  // 再次洗牌算法打乱
			}
		}
		else {  // 此处等于只勾选了每个字符最多出现一次

			std::shuffle(total.begin(), total.end(), gen);  // 洗牌算法打乱
			password = total.substr(0, length);  // 长度大于可用字符数，以可用字符数为长度生成
		}
	}
	else {
		if (settings.b_pick_characters_every_group_chk11()) {  // 此处等于只勾选了包含每一种字符

			/* 每一种字符先随机取一个 */
			std::uniform_int_distribution<> dist(0, 0);  // 共用临时变量
			std::wstring::size_type index = 0;           // 共用临时变量

			if (uppercase_letters_chk1.size() > 0) {  // 注意不能用是否勾选判断，有可能经过排除后此组字符为空
				std::shuffle(uppercase_letters_chk1.begin(), uppercase_letters_chk1.end(), gen); // 洗牌算法打乱一次使其更随机
				dist = std::uniform_int_distribution<>(0, uppercase_letters_chk1.size() - 1);
				index = dist(gen);
				password += uppercase_letters_chk1[index];
			}

			if (lowercase_letters_chk2.size() > 0) {
				std::shuffle(lowercase_letters_chk2.begin(), lowercase_letters_chk2.end(), gen);
				dist = std::uniform_int_distribution<>(0, lowercase_letters_chk2.size() - 1);
				index = dist(gen);
				password += lowercase_letters_chk2[index];
			}

			if (numbers_chk3.size() > 0) {
				std::shuffle(numbers_chk3.begin(), numbers_chk3.end(), gen);
				dist = std::uniform_int_distribution<>(0, numbers_chk3.size() - 1);
				index = dist(gen);
				password += numbers_chk3[index];
			}

			if (symbols_chk4.size() > 0) {
				std::shuffle(symbols_chk4.begin(), symbols_chk4.end(), gen);
				dist = std::uniform_int_distribution<>(0, symbols_chk4.size() - 1);
				index = dist(gen);
				password += symbols_chk4[index];
			}

			if (symbols_chk5.size() > 0) {
				std::shuffle(symbols_chk5.begin(), symbols_chk5.end(), gen);
				dist = std::uniform_int_distribution<>(0, symbols_chk5.size() - 1);
				index = dist(gen);
				password += symbols_chk5[index];
			}

			if (symbols_chk6.size() > 0) {
				std::shuffle(symbols_chk6.begin(), symbols_chk6.end(), gen);
				dist = std::uniform_int_distribution<>(0, symbols_chk6.size() - 1);
				index = dist(gen);
				password += symbols_chk6[index];
			}

			if (symbols_chk7.size() > 0) {
				std::shuffle(symbols_chk7.begin(), symbols_chk7.end(), gen);
				dist = std::uniform_int_distribution<>(0, symbols_chk7.size() - 1);
				index = dist(gen);
				password += symbols_chk7[index];
			}

			if (symbols_chk8.size() > 0) {
				std::shuffle(symbols_chk8.begin(), symbols_chk8.end(), gen);
				dist = std::uniform_int_distribution<>(0, symbols_chk8.size() - 1);
				index = dist(gen);
				password += symbols_chk8[index];
			}

			if (include_characters_edit3.size() > 0) {
				std::shuffle(include_characters_edit3.begin(), include_characters_edit3.end(), gen);
				dist = std::uniform_int_distribution<>(0, include_characters_edit3.size() - 1);
				index = dist(gen);
				password += include_characters_edit3[index];
			}

			if (length <= password.size()) {  // 长度小于等于种数，以种数为长度生成
				std::shuffle(password.begin(), password.end(), gen);  // 洗牌算法打乱，不然每次都是取出时的顺序
			}
			else {
				std::shuffle(total.begin(), total.end(), gen);  // 洗牌算法打乱一次使total更随机
				length -= password.size();
				while (length--) {
					std::uniform_int_distribution<> dist(0, total.size() - 1);
					std::wstring::size_type index = dist(gen);
					password += total[index];
				}
				std::shuffle(password.begin(), password.end(), gen);  // 再次洗牌算法打乱
			}
		}
		else {  // 此处等于两个都取消了

			std::shuffle(total.begin(), total.end(), gen);  // 洗牌算法打乱一次使total更随机
			while (length--) {
				std::uniform_int_distribution<> dist(0, total.size() - 1);  // 设置随机数范围
				std::wstring::size_type index = dist(gen);  // 生成随机数
				password += total[index];
			}
		}
	}

	return password;
}


/*
void CPasswordGeneratorV2Dlg::CopyToClipboard() {
	if (!OpenClipboard())
	{
		AfxMessageBox(_T("Cannot open the Clipboard"));
		return;
	}
	if (!EmptyClipboard())
	{
		AfxMessageBox(_T("Cannot empty the Clipboard"));
		return;
	}

	CString cstr;
	m_edit1.GetWindowTextW(cstr);
	std::size_t sizeInWords = cstr.GetLength() + 1;  // 加1用于 '\0' 终止符
	std::size_t sizeInBytes = sizeInWords * sizeof(wchar_t);

	//CStringA ansiString(cstr);
	CT2A ansiString(cstr);

	//HGLOBAL hGlob  = GlobalAlloc(GMEM_FIXED, sizeInBytes);
	//strcpy_s((char*)hGlob , sizeInBytes, ansiString);

	CT2W unicodeString(cstr);
	HGLOBAL hGlob = GlobalAlloc(GMEM_FIXED, sizeInBytes);
	wcscpy_s((wchar_t*)hGlob, sizeInWords, unicodeString);

	//if (::SetClipboardData(CF_TEXT, hGlob) == NULL)
	if (::SetClipboardData(CF_UNICODETEXT, hGlob) == NULL)
	{
		CString msg;
		msg.Format(_T("Unable to set Clipboard data, error: %d"), GetLastError());
		AfxMessageBox(msg);
		CloseClipboard();
		GlobalFree(hGlob);
		return;
	}
	CloseClipboard();
}*/

void CPasswordGeneratorV2Dlg::CopyToClipboard(const std::wstring& w) {
	if (!OpenClipboard())
	{
		AfxMessageBox(_T("Cannot open the Clipboard"));
		return;
	}
	if (!EmptyClipboard())
	{
		AfxMessageBox(_T("Cannot empty the Clipboard"));
		return;
	}

	std::size_t sizeInWords = w.size() + 1;  // 加1用于 '\0' 终止符
	std::size_t sizeInBytes = sizeInWords * sizeof(wchar_t);

	HGLOBAL hGlob = GlobalAlloc(GMEM_FIXED, sizeInBytes);
	wcscpy_s((wchar_t*)hGlob, sizeInWords, w.c_str());

	if (::SetClipboardData(CF_UNICODETEXT, hGlob) == NULL)
	{
		CString msg;
		msg.Format(_T("Unable to set Clipboard data, error: %d"), GetLastError());
		AfxMessageBox(msg);
		CloseClipboard();
		GlobalFree(hGlob);
		return;
	}
	CloseClipboard();
}


void CPasswordGeneratorV2Dlg::OnNMCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	int length = m_slider1.GetPos();

	CString cstr;
	cstr.Format(_T("%d"), length);  // int转CString

	int nStart;  // 选中文本起始位置
	int nEnd;    // 选中文本结束位置
	m_edit2.GetSel(nStart, nEnd);  // 记录编辑框光标位置
	m_edit2.SetWindowTextW(cstr);  // 设置到编辑框，此动作会重置光标位置
	m_edit2.SetSel(nStart, nEnd);  // 还原光标位置

	m_spin1.SetPos(length);  // 设置到上下箭头

	SettingsWrapper settings;
	SetSettings(settings);
	EnalbeAndDisableGeneratePassword(settings);

	*pResult = 0;
}


void CPasswordGeneratorV2Dlg::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString cstr;
	m_edit2.GetWindowTextW(cstr);
	int length = _ttoi(cstr);  // CString转int

	if (length > 0) {
		m_slider1.SetPos(length);  // 设置大于滑块范围等同于设置范围最大值64
	}
	else if (length == 0) {        // 什么也不做，这样编辑框才可以清空。设置0等同于设置范围最小值1
		;
	}
	else {  // 负数
		m_slider1.SetPos(length);  // 设置小于滑块范围等同于设置范围最小值1
	}
}


void CPasswordGeneratorV2Dlg::OnDeltaposSpin1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: Add your control notification handler code here
	//int currentLength = pNMUpDown->iPos;  // 或者LOWORD(m_spin1.GetPos())取值，获取的是箭头点击之后的值
	int currentLength = m_slider1.GetPos();  // 从滑块取值，获取箭头点击之前的值，也就是当前值
	int delta = pNMUpDown->iDelta;    // 箭头点击的变化量，比如1或-1

	m_slider1.SetPos(currentLength + delta);  // 设置到滑块

	*pResult = 0;
}


void CPasswordGeneratorV2Dlg::OnEnChangeEdit3()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString cstr;
	m_edit3.GetWindowTextW(cstr);

	if (cstr == L"")
		GetDlgItem(IDC_BUTTON3)->ShowWindow(SW_HIDE);
	else
		GetDlgItem(IDC_BUTTON3)->ShowWindow(SW_SHOW);

	SettingsWrapper settings;
	SetSettings(settings);
	EnalbeAndDisableGeneratePassword(settings);
}


void CPasswordGeneratorV2Dlg::OnEnChangeEdit4()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString cstr;
	m_edit4.GetWindowTextW(cstr);

	if (cstr == L"")
		GetDlgItem(IDC_BUTTON4)->ShowWindow(SW_HIDE);
	else
		GetDlgItem(IDC_BUTTON4)->ShowWindow(SW_SHOW);

	SettingsWrapper settings;
	SetSettings(settings);
	EnalbeAndDisableGeneratePassword(settings);
}


void CPasswordGeneratorV2Dlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	m_edit3.SetWindowTextW(L"");
	m_edit3.SetFocus();
}


void CPasswordGeneratorV2Dlg::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	m_edit4.SetWindowTextW(L"");
	m_edit4.SetFocus();
}


void CPasswordGeneratorV2Dlg::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here
	UnsetChk1ToChk8();
	m_chk3.SetCheck(TRUE);
	m_edit3.SetWindowTextW(L"ABCDEF");  // 16进制大写字母
}


void CPasswordGeneratorV2Dlg::OnBnClickedButton6()
{
	// TODO: Add your control notification handler code here
	UnsetChk1ToChk8();
	m_chk3.SetCheck(TRUE);
	m_edit3.SetWindowTextW(L"abcdef");  // 16进制小写字母
}


void CPasswordGeneratorV2Dlg::UnsetChk1ToChk8() {
	m_chk1.SetCheck(FALSE);
	m_chk2.SetCheck(FALSE);
	m_chk3.SetCheck(FALSE);
	m_chk4.SetCheck(FALSE);
	m_chk5.SetCheck(FALSE);
	m_chk6.SetCheck(FALSE);
	m_chk7.SetCheck(FALSE);
	m_chk8.SetCheck(FALSE);
}


void CPasswordGeneratorV2Dlg::EnalbeAndDisableGeneratePassword(SettingsWrapper settings) {
	CharactersWrapper characters;
	SetCharacters(characters, settings);

	std::wstring total = characters.total();  // 可用字符
	int groups_count = characters.groups_count();
	int length = settings.password_length();

	if (total == L"") {
		GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
		return;
	}
	else {
		GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
	}

	/**
	 * 勾选每个字符最多出现一次，如果长度大于可用字符数，若不禁止生成密码，以可用字符数为长度生成
	 * 勾选包含每一种字符，如果长度小于种数，若不禁止生成密码，以种数为长度生成
	 */
	if (settings.b_each_character_most_once_chk9()) {
		if (settings.b_pick_characters_every_group_chk11()) {  // 此处等于两个都勾选了

			if (length < groups_count || length > total.size())  // 长度小于种数或长度大于可用字符数，禁用生成密码按钮
				GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
			else
				GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
		}
		else {  // 此处等于只勾选了每个字符最多出现一次

			if (length > total.size())  // 长度大于可用字符数，禁用生成密码按
				GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
			else
				GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
		}
	}
	else {
		if (settings.b_pick_characters_every_group_chk11()) {  // 此处等于只勾选了包含每一种字符

			if (length < groups_count)  // 长度小于种数，禁用生成密码按
				GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
			else
				GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
		}
		else {  // 此处等于两个都取消了

			;
		}
	}
}


void CPasswordGeneratorV2Dlg::SetSettings(SettingsWrapper& settings) {
	settings.set_password_length(m_slider1.GetPos());  // 从滑块取长度
	settings.set_b_uppercase_letters_chk1(m_chk1.GetCheck());
	settings.set_b_lowercase_letters_chk2(m_chk2.GetCheck());
	settings.set_b_numbers_chk3(m_chk3.GetCheck());
	settings.set_b_symbols_chk4(m_chk4.GetCheck());
	settings.set_b_symbols_chk5(m_chk5.GetCheck());
	settings.set_b_symbols_chk6(m_chk6.GetCheck());
	settings.set_b_symbols_chk7(m_chk7.GetCheck());
	settings.set_b_symbols_chk8(m_chk8.GetCheck());

	CString cstr;  // 共用一个临时变量，也可以各自设置变量

	m_edit3.GetWindowTextW(cstr);
	CT2W unicodeString(cstr);
	std::wstring str(unicodeString);  // CString转string
	settings.set_include_characters_edit3(str);

	m_edit4.GetWindowTextW(cstr);
	CT2W unicodeString2(cstr);
	std::wstring str2(unicodeString2);  // CString转string
	settings.set_exclude_characters_edit4(str2);

	settings.set_b_each_character_most_once_chk9(m_chk9.GetCheck());
	settings.set_b_exclude_alike_characters_chk10(m_chk10.GetCheck());
	settings.set_b_pick_characters_every_group_chk11(m_chk11.GetCheck());
}


void CPasswordGeneratorV2Dlg::SetCharacters(CharactersWrapper& characters, SettingsWrapper settings) {
	characters.set_uppercase_letters_chk1(settings.b_uppercase_letters_chk1() ? L"ABCDEFGHIJKLMNOPQRSTUVWXYZ" : L"");
	characters.set_lowercase_letters_chk2(settings.b_lowercase_letters_chk2() ? L"abcdefghijklmnopqrstuvwxyz" : L"");
	characters.set_numbers_chk3(settings.b_numbers_chk3() ? L"0123456789" : L"");
	characters.set_symbols_chk4(settings.b_symbols_chk4() ? L"!@#$%^&*?-_" : L"");
	characters.set_symbols_chk5(settings.b_symbols_chk5() ? L",.:;" : L"");
	characters.set_symbols_chk6(settings.b_symbols_chk6() ? L"~`\"'" : L"");   // 转义双引号
	characters.set_symbols_chk7(settings.b_symbols_chk7() ? L"/\\|+=" : L"");  // 转义反斜杠
	characters.set_symbols_chk8(settings.b_symbols_chk8() ? L"()[]{}<>" : L"");
	characters.set_include_characters_edit3(settings.include_characters_edit3());  // 包含字符
	characters.set_exclude_characters_edit4(settings.exclude_characters_edit4());  // 排除字符
	characters.set_exclude_alike_characters_chk10(settings.b_exclude_alike_characters_chk10() ? L"01lIO|" : L"");  // 排除相似字符

	//std::wstring symbols = L"!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";  // 转义双引号，转义反斜杠
	std::wstring uppercase_letters_chk1 = characters.uppercase_letters_chk1();
	std::wstring lowercase_letters_chk2 = characters.lowercase_letters_chk2();
	std::wstring numbers_chk3 = characters.numbers_chk3();
	std::wstring symbols_chk4 = characters.symbols_chk4();
	std::wstring symbols_chk5 = characters.symbols_chk5();
	std::wstring symbols_chk6 = characters.symbols_chk6();
	std::wstring symbols_chk7 = characters.symbols_chk7();
	std::wstring symbols_chk8 = characters.symbols_chk8();
	std::wstring include_characters_edit3 = characters.include_characters_edit3();
	std::wstring exclude_characters_edit4 = characters.exclude_characters_edit4();
	std::wstring exclude_alike_characters_chk10 = characters.exclude_alike_characters_chk10();

	/* 排除相似字符 */
	if (settings.b_exclude_alike_characters_chk10()) {
		if (settings.b_uppercase_letters_chk1()) {
			for (std::size_t i = 0; i < exclude_alike_characters_chk10.size(); ++i) {
				uppercase_letters_chk1.erase(std::remove(uppercase_letters_chk1.begin(), uppercase_letters_chk1.end(), exclude_alike_characters_chk10[i]), uppercase_letters_chk1.end());
			}
			characters.set_uppercase_letters_chk1(uppercase_letters_chk1);
		}

		if (settings.b_lowercase_letters_chk2()) {
			for (std::size_t i = 0; i < exclude_alike_characters_chk10.size(); ++i) {
				lowercase_letters_chk2.erase(std::remove(lowercase_letters_chk2.begin(), lowercase_letters_chk2.end(), exclude_alike_characters_chk10[i]), lowercase_letters_chk2.end());
			}
			characters.set_lowercase_letters_chk2(lowercase_letters_chk2);
		}

		if (settings.b_numbers_chk3()) {
			for (std::size_t i = 0; i < exclude_alike_characters_chk10.size(); ++i) {
				numbers_chk3.erase(std::remove(numbers_chk3.begin(), numbers_chk3.end(), exclude_alike_characters_chk10[i]), numbers_chk3.end());
			}
			characters.set_numbers_chk3(numbers_chk3);
		}

		if (settings.b_symbols_chk7()) {
			for (std::size_t i = 0; i < exclude_alike_characters_chk10.size(); ++i) {
				symbols_chk7.erase(std::remove(symbols_chk7.begin(), symbols_chk7.end(), exclude_alike_characters_chk10[i]), symbols_chk7.end());
			}
			characters.set_symbols_chk7(symbols_chk7);
		}
	}

	/* 排除填写的字符 */
	if (settings.exclude_characters_edit4().size() > 0) {
		if (settings.include_characters_edit3().size() > 0) {
			for (std::size_t i = 0; i < exclude_characters_edit4.size(); ++i) {
				include_characters_edit3.erase(std::remove(include_characters_edit3.begin(), include_characters_edit3.end(), exclude_characters_edit4[i]), include_characters_edit3.end());
			}
			characters.set_include_characters_edit3(include_characters_edit3);
		}

		if (settings.b_uppercase_letters_chk1()) {
			for (std::size_t i = 0; i < exclude_characters_edit4.size(); ++i) {
				uppercase_letters_chk1.erase(std::remove(uppercase_letters_chk1.begin(), uppercase_letters_chk1.end(), exclude_characters_edit4[i]), uppercase_letters_chk1.end());
			}
			characters.set_uppercase_letters_chk1(uppercase_letters_chk1);
		}

		if (settings.b_lowercase_letters_chk2()) {
			for (std::size_t i = 0; i < exclude_characters_edit4.size(); ++i) {
				lowercase_letters_chk2.erase(std::remove(lowercase_letters_chk2.begin(), lowercase_letters_chk2.end(), exclude_characters_edit4[i]), lowercase_letters_chk2.end());
			}
			characters.set_lowercase_letters_chk2(lowercase_letters_chk2);
		}

		if (settings.b_numbers_chk3()) {
			for (std::size_t i = 0; i < exclude_characters_edit4.size(); ++i) {
				numbers_chk3.erase(std::remove(numbers_chk3.begin(), numbers_chk3.end(), exclude_characters_edit4[i]), numbers_chk3.end());
			}
			characters.set_numbers_chk3(numbers_chk3);
		}

		if (settings.b_symbols_chk4()) {
			for (std::size_t i = 0; i < exclude_characters_edit4.size(); ++i) {
				symbols_chk4.erase(std::remove(symbols_chk4.begin(), symbols_chk4.end(), exclude_characters_edit4[i]), symbols_chk4.end());
			}
			characters.set_symbols_chk4(symbols_chk4);
		}
		if (settings.b_symbols_chk5()) {
			for (std::size_t i = 0; i < exclude_characters_edit4.size(); ++i) {
				symbols_chk5.erase(std::remove(symbols_chk5.begin(), symbols_chk5.end(), exclude_characters_edit4[i]), symbols_chk5.end());
			}
			characters.set_symbols_chk5(symbols_chk5);
		}
		if (settings.b_symbols_chk6()) {
			for (std::size_t i = 0; i < exclude_characters_edit4.size(); ++i) {
				symbols_chk6.erase(std::remove(symbols_chk6.begin(), symbols_chk6.end(), exclude_characters_edit4[i]), symbols_chk6.end());
			}
			characters.set_symbols_chk6(symbols_chk6);
		}

		if (settings.b_symbols_chk7()) {
			for (std::size_t i = 0; i < exclude_characters_edit4.size(); ++i) {
				symbols_chk7.erase(std::remove(symbols_chk7.begin(), symbols_chk7.end(), exclude_characters_edit4[i]), symbols_chk7.end());
			}
			characters.set_symbols_chk7(symbols_chk7);
		}

		if (settings.b_symbols_chk8()) {
			for (std::size_t i = 0; i < exclude_characters_edit4.size(); ++i) {
				symbols_chk8.erase(std::remove(symbols_chk8.begin(), symbols_chk8.end(), exclude_characters_edit4[i]), symbols_chk8.end());
			}
			characters.set_symbols_chk8(symbols_chk8);
		}
	}

	std::wstring total = uppercase_letters_chk1 + lowercase_letters_chk2 + numbers_chk3 + symbols_chk4
		+ symbols_chk5 + symbols_chk6 + symbols_chk7 + symbols_chk8
		+ include_characters_edit3;
	characters.set_total(total);

	if (settings.b_each_character_most_once_chk9()) {
		std::sort(total.begin(), total.end());  // 排序，以便std::unique去重
		total.erase(std::unique(total.begin(), total.end()), total.end());  // 去重
		characters.set_total(total);
	}

	int count = 0;
	if (uppercase_letters_chk1.size() > 0)
		count += 1;
	if (lowercase_letters_chk2.size() > 0)
		count += 1;
	if (numbers_chk3.size() > 0)
		count += 1;
	if (symbols_chk4.size() > 0)
		count += 1;
	if (symbols_chk5.size() > 0)
		count += 1;
	if (symbols_chk6.size() > 0)
		count += 1;
	if (symbols_chk7.size() > 0)
		count += 1;
	if (symbols_chk8.size() > 0)
		count += 1;
	if (include_characters_edit3.size() > 0)
		count += 1;
	characters.set_groups_count(count);
}


void CPasswordGeneratorV2Dlg::OnBnClickedCheck1()
{
	// TODO: Add your control notification handler code here
	SettingsWrapper settings;
	SetSettings(settings);
	EnalbeAndDisableGeneratePassword(settings);
}


void CPasswordGeneratorV2Dlg::OnBnClickedCheck2()
{
	// TODO: Add your control notification handler code here
	SettingsWrapper settings;
	SetSettings(settings);
	EnalbeAndDisableGeneratePassword(settings);
}


void CPasswordGeneratorV2Dlg::OnBnClickedCheck3()
{
	// TODO: Add your control notification handler code here
	SettingsWrapper settings;
	SetSettings(settings);
	EnalbeAndDisableGeneratePassword(settings);
}


void CPasswordGeneratorV2Dlg::OnBnClickedCheck4()
{
	// TODO: Add your control notification handler code here
	SettingsWrapper settings;
	SetSettings(settings);
	EnalbeAndDisableGeneratePassword(settings);
}


void CPasswordGeneratorV2Dlg::OnBnClickedCheck5()
{
	// TODO: Add your control notification handler code here
	SettingsWrapper settings;
	SetSettings(settings);
	EnalbeAndDisableGeneratePassword(settings);
}


void CPasswordGeneratorV2Dlg::OnBnClickedCheck6()
{
	// TODO: Add your control notification handler code here
	SettingsWrapper settings;
	SetSettings(settings);
	EnalbeAndDisableGeneratePassword(settings);
}


void CPasswordGeneratorV2Dlg::OnBnClickedCheck7()
{
	// TODO: Add your control notification handler code here
	SettingsWrapper settings;
	SetSettings(settings);
	EnalbeAndDisableGeneratePassword(settings);
}


void CPasswordGeneratorV2Dlg::OnBnClickedCheck8()
{
	// TODO: Add your control notification handler code here
	SettingsWrapper settings;
	SetSettings(settings);
	EnalbeAndDisableGeneratePassword(settings);
}


void CPasswordGeneratorV2Dlg::OnBnClickedCheck9()
{
	// TODO: Add your control notification handler code here
	SettingsWrapper settings;
	SetSettings(settings);
	EnalbeAndDisableGeneratePassword(settings);
}


void CPasswordGeneratorV2Dlg::OnBnClickedCheck10()
{
	// TODO: Add your control notification handler code here
	SettingsWrapper settings;
	SetSettings(settings);
	EnalbeAndDisableGeneratePassword(settings);
}


void CPasswordGeneratorV2Dlg::OnBnClickedCheck11()
{
	// TODO: Add your control notification handler code here
	SettingsWrapper settings;
	SetSettings(settings);
	EnalbeAndDisableGeneratePassword(settings);
}
