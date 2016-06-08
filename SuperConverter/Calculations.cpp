#include "stdafx.h"
#include "Calculations.h"

Calculations::Calculations()
{
	symbolsInt = _T("0123456789");
	symbolsString = _T("ABCDEF");

	symbolMatchesBinaryOctal[0] = { _T("000_0") }; symbolMatchesBinaryOctal[1] = { _T("001_1") };
	symbolMatchesBinaryOctal[2] = { _T("010_2") }; symbolMatchesBinaryOctal[3] = { _T("011_3") };
	symbolMatchesBinaryOctal[4] = { _T("100_4") }; symbolMatchesBinaryOctal[5] = { _T("101_5") };
	symbolMatchesBinaryOctal[6] = { _T("110_6") }; symbolMatchesBinaryOctal[7] = { _T("111_7") };
	
	symbolMatchesBinaryHexadecimal[0] = { _T("0000_0") }; symbolMatchesBinaryHexadecimal[1] = { _T("0001_1") };
	symbolMatchesBinaryHexadecimal[2] = { _T("0010_2") }; symbolMatchesBinaryHexadecimal[3] = { _T("0011_3") };
	symbolMatchesBinaryHexadecimal[4] = { _T("0100_4") }; symbolMatchesBinaryHexadecimal[5] = { _T("0101_5") };
	symbolMatchesBinaryHexadecimal[6] = { _T("0110_6") }; symbolMatchesBinaryHexadecimal[7] = { _T("0111_7") };
	symbolMatchesBinaryHexadecimal[8] = { _T("1000_8") }; symbolMatchesBinaryHexadecimal[9] = { _T("1001_9") };
	symbolMatchesBinaryHexadecimal[10] = { _T("1010_A") }; symbolMatchesBinaryHexadecimal[11] = { _T("1011_B") };
	symbolMatchesBinaryHexadecimal[12] = { _T("1100_C") }; symbolMatchesBinaryHexadecimal[13] = { _T("1101_D") };
	symbolMatchesBinaryHexadecimal[14] = { _T("1110_E") }; symbolMatchesBinaryHexadecimal[15] = { _T("1111_F") };
}

Calculations::~Calculations()
{

}

CString Calculations::doConversionIntToCString(int valueInt)
{
	valueCString = _T("");
	
	if (valueInt == 0)
	{
		return _T("0");
	}

	while (valueInt > 0)
	{
		singleNumber = valueInt % 10;
		valueInt = valueInt / 10;

		valueCString = symbolsInt[singleNumber] + valueCString;
	}

	return valueCString;
}

CString Calculations::doConversionDoubleToCString(double valueDouble)
{
	valueCString = _T("");
	
	while (valueDouble != 0.0)
	{
		singleNumber = valueDouble * 10;
		valueDouble = valueDouble * 10 - singleNumber;

		valueCString = valueCString + symbolsInt[singleNumber];
	}

	return valueCString;
}

CString Calculations::doConversionBinaryToOctal(CString primaryNumberPart)
{
	result = _T("");

	for (int i = 0; i < primaryNumberPart.GetLength(); i = i + 3)
	{
		for (int j = 0; j < 8; j++)
		{
			if (symbolMatchesBinaryOctal[j].Mid(0, 3) == primaryNumberPart.Mid(i, 3))
			{
				result = result + symbolMatchesBinaryOctal[j][4];
			}
		}
	}

	return result;
}

CString Calculations::doConversionBinaryToHexadecimal(CString primaryNumberPart)
{
	result = _T("");

	for (int i = 0; i < primaryNumberPart.GetLength(); i = i + 4)
	{
		for (int j = 0; j < 16; j++)
		{
			if (symbolMatchesBinaryHexadecimal[j].Mid(0,4) == primaryNumberPart.Mid(i, 4))
			{
				result = result + symbolMatchesBinaryHexadecimal[j][5];
			}
		}
	}

	return result;
}

CString Calculations::doConversionOctalToBinary(CString primaryNumberPart)
{
	result = _T("");

	for (int i = 0; i < primaryNumberPart.GetLength(); i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (symbolMatchesBinaryOctal[j].Mid(4, 1) == primaryNumberPart.Mid(i, 1))
			{
				result = result + symbolMatchesBinaryOctal[j].Mid(0, 3);
			}
		}
	}

	return result;
}

CString Calculations::doConversionFromDecimalRealPart(CString primaryNumberRealPart, int numberSystem)
{
	primaryNumberRealPartInt = _ttof(primaryNumberRealPart);
	result = _T("");

	if (primaryNumberRealPartInt == 0)
	{
		result = '0';
	}

	while (primaryNumberRealPartInt >= numberSystem)
	{
		copyPrimaryNumberRealPartInt = primaryNumberRealPartInt;
		primaryNumberRealPartInt = primaryNumberRealPartInt / numberSystem;
		singleNumber = copyPrimaryNumberRealPartInt - numberSystem * primaryNumberRealPartInt;
		if (singleNumber < 10)
		{
			symbol = doConversionIntToCString(singleNumber);
			result = symbol + result;
		}
		else
		{
			result = symbolsString[singleNumber - 10] + result;
		}
	}

	if (primaryNumberRealPartInt != 0)
	{
		copyPrimaryNumberRealPartInt = primaryNumberRealPartInt;
		primaryNumberRealPartInt = primaryNumberRealPartInt / numberSystem;
		singleNumber = copyPrimaryNumberRealPartInt - numberSystem * primaryNumberRealPartInt;
		if (singleNumber < 10)
		{
			symbol = doConversionIntToCString(singleNumber);
			result = symbol + result;
		}
		else
		{
			result = symbolsString[singleNumber - 10] + result;
		}
	}

	return result;
}

CString Calculations::doConversionFromDecimalDecimalPart(CString primaryNumberDecimalPart, int numberSystem)
{
	lengthChecker = 1;
	result = _T("");
	primaryNumberDecimalPart = _T("0.") + primaryNumberDecimalPart;
	primaryNumberDecimalPartDouble = _wtof(primaryNumberDecimalPart);

	while ((primaryNumberDecimalPartDouble > 0) && (lengthChecker != 10))
	{
		primaryNumberDecimalPartDouble = primaryNumberDecimalPartDouble * numberSystem;
		singleNumber = 0;
		while (primaryNumberDecimalPartDouble >= 1)
		{
			primaryNumberDecimalPartDouble--;
			singleNumber++;
		}

		if (singleNumber < 10)
		{
			symbol = doConversionIntToCString(singleNumber);
			result = result + symbol;
		}
		else
		{
			result = result + symbolsString[singleNumber - 10];
		}

		lengthChecker++;
	}

	if ((lengthChecker == 10) && (primaryNumberDecimalPartDouble > 0))
	{
		result = result + _T("...");
	}

	return result;
}

CString Calculations::doConversionHexadecimalToBinary(CString primaryNumberPart)
{
	result = _T("");

	for (int i = 0; i < primaryNumberPart.GetLength(); i++)
	{
		for (int j = 0; j < 16; j++)
		{
			if (symbolMatchesBinaryHexadecimal[j].Mid(5, 1) == primaryNumberPart.Mid(i, 1))
			{
				result = result + symbolMatchesBinaryHexadecimal[j].Mid(0, 4);
			}
		}
	}

	return result;
}

int Calculations::doConversionToDecimalRealPart(CString primaryNumberRealPart, double numberSystem)
{
	index = 0;
	resultInt = 0;

	for (int i = primaryNumberRealPart.GetLength() - 1; i >= 0; i--)
	{
		symbol = primaryNumberRealPart.Mid(index, 1);
		index++;
		singleNumber = _ttof(symbol);
		resultInt = resultInt + singleNumber * pow(numberSystem, i);
	}

	return resultInt;
}

double Calculations::doConversionToDecimalDecimalPart(CString primaryNumberDecimalPart, double numberSystem)
{
	index = 0;
	resultDouble = 0.0;

	for (int i = 1; i <= primaryNumberDecimalPart.GetLength(); i++)
	{
		symbol = primaryNumberDecimalPart.Mid(index, 1);
		index++;
		symbolDouble = _ttof(symbol);
		resultDouble = resultDouble + (symbolDouble * pow(numberSystem, (-i)));
	}

	return resultDouble;
}