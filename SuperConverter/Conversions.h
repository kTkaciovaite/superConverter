#pragma once

#include "Errors.h"
#include "Calculations.h"
#include "DataOperations.h"

class Conversions : public Errors, Calculations, DataOperations
{
private:
	CString resultBinary;
	CString resultOctal;
	CString resultDecimal;
	CString resultHexadecimal;
	CString primaryNumberRealPart;
	CString primaryNumberDecimalPart;
	CString resultBinaryRealPart;
	CString resultBinaryDecimalPart;
	int resultDecimalInt;
	double resultDecimalDouble;

public:
	Conversions();
	~Conversions();

	void doConvertFromBinary(CString *ptrToPrimaryNumber, CString & resultBinary, CString & resultOctal, CString & resultDecimal, CString & resultHexadecimal);
	void doConvertFromOctal(CString *ptrToPrimaryNumber, CString & resultBinary, CString & resultOctal, CString & resultDecimal, CString & resultHexadecimal);
	void doConvertFromDecimal(CString *ptrToPrimaryNumber, CString & resultBinary, CString & resultOctal, CString & resultDecimal, CString & resultHexadecimal);
	void doConvertFromHexadecimal(CString *ptrToPrimaryNumber, CString & resultBinary, CString & resultOctal, CString & resultDecimal, CString & resultHexadecimal);
};