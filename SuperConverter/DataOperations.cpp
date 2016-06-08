#include "stdafx.h"
#include "DataOperations.h"

//Konstruktorius pradiniu duomenu priskyrimui
DataOperations::DataOperations()
{
	correctNumberSymbols = _T(".0123456789ABCDEF");
}

DataOperations::~DataOperations()
{

}

void DataOperations::setPrimaryNumber(CString numberFromWindow)
{
	primaryNumber = numberFromWindow;
}

CString DataOperations::getPrimaryNumber()
{
	return primaryNumber;
}

//Atskiriama sveikoji skaiciaus dalis nuo trupmenines
void DataOperations::doSplitNumber(CString & primaryNumberRealPart, CString & primaryNumberDecimalPart)
{
	if (!isNumberDouble())
	{
		primaryNumberRealPart = primaryNumber;
		primaryNumberDecimalPart = "";
	}
	else
	{
		primaryNumberRealPart = primaryNumber.Mid(0, primaryNumber.Find('.'));
		primaryNumberDecimalPart = primaryNumber.Mid(primaryNumber.Find('.') + 1, primaryNumber.GetLength() - primaryNumberRealPart.GetLength());
	}
}

//Tikrinama ar skaicius yra double tipo
bool DataOperations::isNumberDouble()
{
	if (primaryNumber.Find('.') == -1)
	{
		return false;
	}
	else
	{
		return true;
	}
}

//Tikrinama ar pradinis skaicius nera tuscias
bool DataOperations::isFieldEmpty()
{
	if (primaryNumber == "")
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Priklausomai nuo skaiciavimo sistemos tikrinamas ivesto skaiciaus formatas
bool DataOperations::isNumberFormatCorrect(int numberSystem)
{
	for (int i = 0; i < primaryNumber.GetLength(); i++)
	{
		isSymbolCorrect = false;
		for (int j = 0; j < numberSystem + 1; j++)
		{
			if (primaryNumber[i] == correctNumberSymbols[j])
			{
				isSymbolCorrect = true;
			}
		}

		if (!isSymbolCorrect)
		{
			return false;
		}
	}

	return true;
}

/* Priklausomai nuo skaiciavimo sistemos skaiciaus pradzioje prirasomas nulis, kad skaitmenu skaicius
 * butu dalus is 3 arba 4 ir butu galima vykdyti tolimesnius veiksmus */
CString DataOperations::fixNumberLengthRealPart(int lengthIdentifier, CString primaryNumberRealPart)
{
	while (primaryNumberRealPart.GetLength() % lengthIdentifier != 0)
	{
		primaryNumberRealPart = '0' + primaryNumberRealPart;
	}

	return primaryNumberRealPart;
}

/* Priklausomai nuo skaiciavimo sistemos skaiciaus pabaigoje prirasomas nulis, kad skaitmenu skaicius
 * butu dalus is 3 arba 4 ir butu galima vykdyti tolimesnius veiksmus */
CString DataOperations::fixNumberLengthDecimalPart(int lengthIdentifier, CString primaryNumberDecimalPart)
{
	while (primaryNumberDecimalPart.GetLength() % lengthIdentifier != 0)
	{
		primaryNumberDecimalPart = primaryNumberDecimalPart + '0';
	}

	return primaryNumberDecimalPart;
}

//Naikinami nereiksmingi nuliai skaiciaus pradzioje
CString DataOperations::deleteIrrelevantZerosRealPart(CString *ptrToNumberString)
{
	numberString = *ptrToNumberString;
	
	while (numberString[0] == '0')
	{
		numberString = numberString.Mid(1, numberString.GetLength() - 1);
	}

	if (numberString == "" || numberString[0] == '.')
	{
		numberString = '0' + numberString;
	}

	return numberString;
}

//Naikinami nereiksmingi nuliai skaiciaus pabaigoje (jei skaicius yra double tipo)
CString DataOperations::deleteIrrelevantZerosDecimalPart(CString *ptrToNumberString)
{
	numberString = *ptrToNumberString;
	
	if (numberString.Find('.') != -1)
	{
		while (numberString[numberString.GetLength() - 1] == '0')
		{
			numberString = numberString.Mid(0, numberString.GetLength() - 1);
		}
	}

	if (numberString[numberString.GetLength() - 1] == '.')
	{
		numberString = numberString.Mid(0, numberString.GetLength() - 1);
	}

	return numberString;
}