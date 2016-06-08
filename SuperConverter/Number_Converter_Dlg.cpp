// Number_Converter_Dlg.cpp : implementation file

#include "stdafx.h"
#include "SuperConverter.h"
#include "Number_Converter_Dlg.h"
#include "afxdialogex.h"
#include "Errors.h"
#include "DataOperations.h"
#include "Conversions.h"

// Number_Converter_Dlg dialog

IMPLEMENT_DYNAMIC(Number_Converter_Dlg, CDialog)

Number_Converter_Dlg::Number_Converter_Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(Number_Converter_Dlg::IDD, pParent)
	, primaryNumber(_T(""))
	, resultBinary(_T(""))
	, resultOctal(_T(""))
	, resultDecimal(_T(""))
	, resultHexadecimal(_T(""))
{

}

Number_Converter_Dlg::~Number_Converter_Dlg()
{
}

void Number_Converter_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_PRIMARY_NUMBER_EDIT, primaryNumber);
	DDX_Text(pDX, IDC_RESULT_BINARY_EDIT, resultBinary);
	DDX_Text(pDX, IDC_RESULT_OCTAL_EDIT, resultOctal);
	DDX_Text(pDX, IDC_RESULT_DECIMAL_EDIT, resultDecimal);
	DDX_Text(pDX, IDC_RESULT_HEXADECIMAL_EDIT, resultHexadecimal);
}


BEGIN_MESSAGE_MAP(Number_Converter_Dlg, CDialog)
	ON_BN_CLICKED(IDC_CHOOSE_BINARY_BUTTON, &Number_Converter_Dlg::OnBnClickedChooseBinaryButton)
	ON_BN_CLICKED(IDC_CHOOSE_OCTAL_BUTTON, &Number_Converter_Dlg::OnBnClickedChooseOctalButton)
	ON_BN_CLICKED(IDC_CHOOSE_DECIMAL_BUTTON, &Number_Converter_Dlg::OnBnClickedChooseDecimalButton)
	ON_BN_CLICKED(IDC_CHOOSE_HEXADECIMAL_BUTTON, &Number_Converter_Dlg::OnBnClickedChooseHexadecimalButton)
	ON_BN_CLICKED(IDC_CONVERT_BUTTON, &Number_Converter_Dlg::OnBnClickedConvertButton)
END_MESSAGE_MAP()

// Number_Converter_Dlg message handlers
/* Pasirinkus, is kurios skaiciavimo sistemos norima konvertuoti skaiciu, ir
 * paspaudus atitinkama mygtuka, kintamajam chooseConversion bus priskirta 
 * skaiciavimo sistema atitinkanti int reiksme (2, 8, 10 arba 16) */
void Number_Converter_Dlg::OnBnClickedChooseBinaryButton()
{
	chooseConversion = 2;
}

void Number_Converter_Dlg::OnBnClickedChooseOctalButton()
{
	chooseConversion = 8;
}

void Number_Converter_Dlg::OnBnClickedChooseDecimalButton()
{
	chooseConversion = 10;
}

void Number_Converter_Dlg::OnBnClickedChooseHexadecimalButton()
{
	chooseConversion = 16;
}

void Number_Converter_Dlg::OnBnClickedConvertButton()
{
	Errors errors;
	Conversions conversions;
	DataOperations dataOperations;
	
	UpdateData(true);

	/* Programa toliau bus vykdoma priklausomai nuo to, is kurios skaiciavimo sistemos 
	 * buvo pasirinkta konvertuoti skaiciu */
	switch (chooseConversion)
	{
	case 0:
		//Jei skaiciavimo sistema nebuvo pasirinkta, parodomas ispejamasis langas
		errors.showErrorConversionNotChosen();
		break;

		/* Jei skaiciavimo sistema buvo pasirinkta, toliau atliekamas konvertavimas is pasirinktos
		 * skaiciavimo sistemos */
	case 2:
		conversions.doConvertFromBinary(ptrToPrimaryNumber, resultBinary, resultOctal, resultDecimal, resultHexadecimal);
		break;

	case 8:
		conversions.doConvertFromOctal(ptrToPrimaryNumber, resultBinary, resultOctal, resultDecimal, resultHexadecimal);
		break;

	case 10:
		conversions.doConvertFromDecimal(ptrToPrimaryNumber, resultBinary, resultOctal, resultDecimal, resultHexadecimal);
		break;

	case 16:
		conversions.doConvertFromHexadecimal(ptrToPrimaryNumber, resultBinary, resultOctal, resultDecimal, resultHexadecimal);
		break;
	}

	//Naikinami nereiksmingi nuliai skaiciaus priekyje bei gale
	resultBinary = dataOperations.deleteIrrelevantZerosRealPart(ptrToResultBinary);
	resultBinary = dataOperations.deleteIrrelevantZerosDecimalPart(ptrToResultBinary);
	resultOctal = dataOperations.deleteIrrelevantZerosRealPart(ptrToResultOctal);
	resultOctal = dataOperations.deleteIrrelevantZerosDecimalPart(ptrToResultOctal);
	resultDecimal = dataOperations.deleteIrrelevantZerosRealPart(ptrToResultDecimal);
	resultDecimal = dataOperations.deleteIrrelevantZerosDecimalPart(ptrToResultDecimal);
	resultHexadecimal = dataOperations.deleteIrrelevantZerosRealPart(ptrToResultHexadecimal);
	resultHexadecimal = dataOperations.deleteIrrelevantZerosDecimalPart(ptrToResultHexadecimal);
	
	UpdateData(false);
}