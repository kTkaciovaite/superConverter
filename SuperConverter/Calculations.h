#pragma once

class Calculations
{
protected:
	CString symbol;
	CString symbolsInt;
	CString symbolsString;
	CString symbolMatchesBinaryOctal[8];
	CString symbolMatchesBinaryHexadecimal[16];
	CString valueCString;
	CString result;
	int singleNumber;
	int primaryNumberRealPartInt;
	int copyPrimaryNumberRealPartInt;
	int lengthChecker;
	int index;
	int resultInt;
	double primaryNumberDecimalPartDouble;
	double symbolDouble;
	double resultDouble;

public:
	Calculations();
	~Calculations();

	CString doConversionIntToCString(int valueInt);
	CString doConversionDoubleToCString(double valueDouble);
	CString doConversionBinaryToOctal(CString primaryNumberPart);
	CString doConversionBinaryToHexadecimal(CString primaryNumberPart);
	CString doConversionOctalToBinary(CString primaryNumberPart);
	CString doConversionFromDecimalRealPart(CString primaryNumberRealPart, int numberSystem);
	CString doConversionFromDecimalDecimalPart(CString primaryNumberDecimalPart, int numberSystem);
	CString doConversionHexadecimalToBinary(CString primaryNumberPart);
	int doConversionToDecimalRealPart(CString primaryNumberRealPart, double numberSystem);
	double doConversionToDecimalDecimalPart(CString primaryNumberDecimalPart, double numberSystem);
};