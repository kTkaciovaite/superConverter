#pragma once


// Number_Converter_Dlg dialog

class Number_Converter_Dlg : public CDialog
{
	DECLARE_DYNAMIC(Number_Converter_Dlg)

public:
	Number_Converter_Dlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~Number_Converter_Dlg();

// Dialog Data
	enum { IDD = IDD_NUMBER_CONVERTER_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedChooseBinaryButton();
	afx_msg void OnBnClickedChooseOctalButton();
	afx_msg void OnBnClickedChooseDecimalButton();
	afx_msg void OnBnClickedChooseHexadecimalButton();
	afx_msg void OnBnClickedConvertButton();

private:
	int chooseConversion = 0;

	CString primaryNumber = _T("");
	CString resultBinary;
	CString resultOctal;
	CString resultDecimal;
	CString resultHexadecimal;

	CString * ptrToPrimaryNumber = &primaryNumber;
	CString * ptrToResultBinary = &resultBinary;
	CString * ptrToResultOctal = &resultOctal;
	CString * ptrToResultDecimal = &resultDecimal;
	CString * ptrToResultHexadecimal = &resultHexadecimal;
};
