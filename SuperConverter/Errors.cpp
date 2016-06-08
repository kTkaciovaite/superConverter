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
	AfxMessageBox(_T("Pasirinkite, ið kokios skaièiavimo sistemos norite konvertuoti skaièiø"), MB_OK | MB_ICONSTOP);
}

void Errors::showErrorFieldIsEmpty()
{
	AfxMessageBox(_T("Áveskite skaièiø, kurá norite konvertuoti"), MB_OK | MB_ICONSTOP);
}

void Errors::showErrorWrongNumberFormat()
{
	AfxMessageBox(_T("Áveskite tinkamo formato skaièiø"), MB_OK | MB_ICONSTOP);
}