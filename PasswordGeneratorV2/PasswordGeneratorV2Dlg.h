
// PasswordGeneratorV2Dlg.h : header file
//

#pragma once

#include<string>
#include "SettingsWrapper.h"
#include "CharactersWrapper.h"


// CPasswordGeneratorV2Dlg dialog
class CPasswordGeneratorV2Dlg : public CDialogEx
{
// Construction
public:
	CPasswordGeneratorV2Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PASSWORDGENERATORV2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

protected:
	virtual void OnOK() {};
	virtual void OnCancel() {};
	afx_msg void OnClose();

public:
	std::wstring GeneratePassword(SettingsWrapper settings);
	void CopyToClipboard(const std::wstring& w);
	void UnsetChk1ToChk8();
	void EnalbeAndDisableGeneratePassword(SettingsWrapper settings);
	void SetSettings(SettingsWrapper& settings);
	void SetCharacters(CharactersWrapper& characters, SettingsWrapper settings);

	CEdit m_edit1;

	CSliderCtrl m_slider1;
	CEdit m_edit2;
	CSpinButtonCtrl m_spin1;

	CButton m_chk1;
	CButton m_chk2;
	CButton m_chk3;
	CButton m_chk4;
	CButton m_chk5;
	CButton m_chk6;
	CButton m_chk7;
	CButton m_chk8;

	CEdit m_edit3;
	CEdit m_edit4;

	CButton m_chk9;
	CButton m_chk10;
	CButton m_chk11;

	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnNMCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnDeltaposSpin1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnBnClickedCheck4();
	afx_msg void OnBnClickedCheck5();
	afx_msg void OnBnClickedCheck6();
	afx_msg void OnBnClickedCheck7();
	afx_msg void OnBnClickedCheck8();
	afx_msg void OnBnClickedCheck9();
	afx_msg void OnBnClickedCheck10();
	afx_msg void OnBnClickedCheck11();
};
