#include "stdafx.h"
#include "afxdialogex.h"
#include "Errors.h"

Errors::Errors()
{

}

Errors::~Errors()
{

}

void Errors::showErrorConversionNotChosen()
{
	AfxMessageBox(_T("Pasirinkite, i� kokios skai�iavimo sistemos norite konvertuoti skai�i�"), MB_OK | MB_ICONSTOP);
}

void Errors::showErrorFieldIsEmpty()
{
	AfxMessageBox(_T("�veskite skai�i�, kur� norite konvertuoti"), MB_OK | MB_ICONSTOP);
}

void Errors::showErrorWrongNumberFormat()
{
	AfxMessageBox(_T("�veskite tinkamo formato skai�i�"), MB_OK | MB_ICONSTOP);
}