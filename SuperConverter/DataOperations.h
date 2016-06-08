#pragma once

class DataOperations
{
protected:
	CString primaryNumber;
	CString correctNumberSymbols;
	CString numberString;
	bool isSymbolCorrect;

public:
	DataOperations();
	~DataOperations();

	void setPrimaryNumber(CString);
	CString getPrimaryNumber();

	void doSplitNumber(CString & primaryNumberRealPart, CString & primaryNumberDecimalPart);
	bool isNumberDouble();
	bool isFieldEmpty();
	bool isNumberFormatCorrect(int numberSystem);
	CString fixNumberLengthRealPart(int lengthIdentifier, CString primaryNumberRealPart);
	CString fixNumberLengthDecimalPart(int lengthIdentifier, CString primaryNumberDecimalPart);
	CString deleteIrrelevantZerosRealPart(CString *ptrToNumberString);
	CString deleteIrrelevantZerosDecimalPart(CString *ptrToNumberString);
};