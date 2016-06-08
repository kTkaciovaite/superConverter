#include "stdafx.h"
#include "Conversions.h"

//Konstruktorius pradiniu duomenu priskyrimui
Conversions::Conversions()
{
	resultBinary = "";
	resultOctal = "";
	resultDecimal = "";
	resultOctal = "";
}

Conversions::~Conversions()
{

}

//Pradinis skaicius is dvejetaines skaiciavimo sistemos konvertuojamas i kitas skaiciavimo sistemas
void Conversions::doConvertFromBinary(CString *ptrToPrimaryNumber, CString & resultBinary, CString & resultOctal, CString & resultDecimal, CString & resultHexadecimal)
{
	setPrimaryNumber(*ptrToPrimaryNumber);

	//Tikrinama ar pradinio skaiciaus laukelis nera tuscias
	if (isFieldEmpty())
	{
		//Jei laukelis tuscias, parodomas ispejamasis langas
		showErrorFieldIsEmpty();
	}
	//Tikrinama ar ivestas pradinis skaicius yra tinkamo formato
	else if (!isNumberFormatCorrect(2))
	{
		//Jei ivesta skaiciu sudaro neleistini simboliai, parodomas ispejamasis langas
		showErrorWrongNumberFormat();
	}
	else
	{
		//Atskiriama sveikoji skaiciaus dalis nuo trupmenines
		doSplitNumber(primaryNumberRealPart, primaryNumberDecimalPart);
		/* Jei skaiciaus dalies simboliu skaicius nedalus is 3, atitinkamoje vietoje (pradzioje
		 * arba pabaigoje) prirasomas nulis*/
		primaryNumberRealPart = fixNumberLengthRealPart(3, primaryNumberRealPart);
		primaryNumberDecimalPart = fixNumberLengthDecimalPart(3, primaryNumberDecimalPart);

		/* Kadangi pradinis skaicius yra dvejetainis, konversija nereikalinga ir dvejetainio
		 * skaiciaus rezultato laukelyje isvedamas pradinis skaicius */
		resultBinary = *ptrToPrimaryNumber;

		/* I astuntaine skaiciavimo sistema atskirai konvertuojama sveikoji bei trupmenine 
		 * (jei tokia egzistuoja) dvejetainio skaiciaus dalis */
		resultOctal = doConversionBinaryToOctal(primaryNumberRealPart);
		if (primaryNumberDecimalPart != "")
		{
			resultOctal = resultOctal + '.' + doConversionBinaryToOctal(primaryNumberDecimalPart);
		}

		/* I desimtaine skaiciavimo sistema atskirai konvertuojama sveikoji bei trupmenine
		 * (jei tokia egzistuoja) dvejetainio skaiciaus dalis */
		resultDecimalInt = doConversionToDecimalRealPart(primaryNumberRealPart, 2.0);
		resultDecimal = doConversionIntToCString(resultDecimalInt);
		if (primaryNumberDecimalPart != "")
		{
			resultDecimalDouble = doConversionToDecimalDecimalPart(primaryNumberDecimalPart, 2.0);
			resultDecimal = resultDecimal + '.' + doConversionDoubleToCString(resultDecimalDouble);
		}

		/* Jei skaiciaus dalies simboliu skaicius nedalus is 4, atitinkamoje vietoje (pradzioje
		 * arba pabaigoje) prirasomas nulis*/
		primaryNumberRealPart = fixNumberLengthRealPart(4, primaryNumberRealPart);
		/* I sesioliktaine skaiciavimo sistema atskirai konvertuojama sveikoji bei trupmenine
		 * (jei tokia egzistuoja) dvejetainio skaiciaus dalis */
		resultHexadecimal = doConversionBinaryToHexadecimal(primaryNumberRealPart);
		if (primaryNumberDecimalPart != "")
		{
			primaryNumberDecimalPart = fixNumberLengthDecimalPart(4, primaryNumberDecimalPart);
			resultHexadecimal = resultHexadecimal + '.' + doConversionBinaryToHexadecimal(primaryNumberDecimalPart);
		}
	}
}

//Pradinis skaicius is astuntaines skaiciavimo sistemos konvertuojamas i kitas skaiciavimo sistemas
void Conversions::doConvertFromOctal(CString *ptrToPrimaryNumber, CString & resultBinary, CString & resultOctal, CString & resultDecimal, CString & resultHexadecimal)
{
	setPrimaryNumber(*ptrToPrimaryNumber);

	//Tikrinama ar pradinio skaiciaus laukelis nera tuscias
	if (isFieldEmpty())
	{
		//Jei laukelis tuscias, parodomas ispejamasis langas
		showErrorFieldIsEmpty();
	}
	//Tikrinama ar ivestas pradinis skaicius yra tinkamo formato
	else if (!isNumberFormatCorrect(8))
	{
		//Jei ivesta skaiciu sudaro neleistini simboliai, parodomas ispejamasis langas
		showErrorWrongNumberFormat();
	}
	else
	{
		//Atskiriama sveikoji skaiciaus dalis nuo trupmenines
		doSplitNumber(primaryNumberRealPart, primaryNumberDecimalPart);

		/* I dvejetaine skaiciavimo sistema atskirai konvertuojama sveikoji bei trupmenine
		 * (jei tokia egzistuoja) astuntainio skaiciaus dalis */
		resultBinaryRealPart = doConversionOctalToBinary(primaryNumberRealPart);
		resultBinary = resultBinaryRealPart;
		if (primaryNumberDecimalPart != "")
		{
			resultBinaryDecimalPart = doConversionOctalToBinary(primaryNumberDecimalPart);
			resultBinary = resultBinary + '.' + resultBinaryDecimalPart;
		}

		/* Kadangi pradinis skaicius yra astuntainis, konversija nereikalinga ir astuntainio
		 * skaiciaus rezultato laukelyje isvedamas pradinis skaicius */
		resultOctal = primaryNumber;

		/* I desimtaine skaiciavimo sistema atskirai konvertuojama sveikoji bei trupmenine
		 * (jei tokia egzistuoja) astuntainio skaiciaus dalis */
		resultDecimalInt = doConversionToDecimalRealPart(primaryNumberRealPart, 8.0);
		resultDecimal = doConversionIntToCString(resultDecimalInt);
		if (primaryNumberDecimalPart != "")
		{
			resultDecimalDouble = doConversionToDecimalDecimalPart(primaryNumberDecimalPart, 8.0);
			resultDecimal = resultDecimal + '.' + doConversionDoubleToCString(resultDecimalDouble);
		}

		/* Jei skaiciaus dalies simboliu skaicius nedalus is 4, atitinkamoje vietoje (pradzioje
		 * arba pabaigoje) prirasomas nulis*/
		resultBinaryRealPart = fixNumberLengthRealPart(4, resultBinaryRealPart);
		resultBinaryDecimalPart = fixNumberLengthDecimalPart(4, resultBinaryDecimalPart);
		/* I sesioliktaine skaiciavimo sistema atskirai konvertuojama sveikoji bei trupmenine
		 * (jei tokia egzistuoja) dvejetainio skaiciaus dalis */
		resultHexadecimal = doConversionBinaryToHexadecimal(resultBinaryRealPart);
		if (resultBinaryDecimalPart != "")
		{
			resultHexadecimal = resultHexadecimal + '.' + doConversionBinaryToHexadecimal(resultBinaryDecimalPart);
		}
	}
}

//Pradinis skaicius is desimtaines skaiciavimo sistemos konvertuojamas i kitas skaiciavimo sistemas
void Conversions::doConvertFromDecimal(CString *ptrToPrimaryNumber, CString & resultBinary, CString & resultOctal, CString & resultDecimal, CString & resultHexadecimal)
{
	setPrimaryNumber(*ptrToPrimaryNumber);

	//Tikrinama ar pradinio skaiciaus laukelis nera tuscias
	if (isFieldEmpty())
	{
		//Jei laukelis tuscias, parodomas ispejamasis langas
		showErrorFieldIsEmpty();
	}
	//Tikrinama ar ivestas pradinis skaicius yra tinkamo formato
	else if (!isNumberFormatCorrect(10))
	{
		//Jei ivesta skaiciu sudaro neleistini simboliai, parodomas ispejamasis langas
		showErrorWrongNumberFormat();
	}
	else
	{
		//Atskiriama sveikoji skaiciaus dalis nuo trupmenines
		doSplitNumber(primaryNumberRealPart, primaryNumberDecimalPart);

		/* I dvejetaine skaiciavimo sistema atskirai konvertuojama sveikoji bei trupmenine
		 * (jei tokia egzistuoja) desimtainio skaiciaus dalis */
		resultBinary = doConversionFromDecimalRealPart(primaryNumberRealPart, 2);
		if (primaryNumberDecimalPart != "")
		{
			resultBinary = resultBinary + '.' + doConversionFromDecimalDecimalPart(primaryNumberDecimalPart, 2);
		}

		/* I astuntaine skaiciavimo sistema atskirai konvertuojama sveikoji bei trupmenine
		 * (jei tokia egzistuoja) desimtainio skaiciaus dalis */
		resultOctal = doConversionFromDecimalRealPart(primaryNumberRealPart, 8);
		if (primaryNumberDecimalPart != "")
		{
			resultOctal = resultOctal + '.' + doConversionFromDecimalDecimalPart(primaryNumberDecimalPart, 8);
		}

		/* Kadangi pradinis skaicius yra desimtainis, konversija nereikalinga ir desimtainio
		 * skaiciaus rezultato laukelyje isvedamas pradinis skaicius */
		resultDecimal = primaryNumber;

		/* I sesioliktaine skaiciavimo sistema atskirai konvertuojama sveikoji bei trupmenine
		 * (jei tokia egzistuoja) desimtainio skaiciaus dalis */
		resultHexadecimal = doConversionFromDecimalRealPart(primaryNumberRealPart, 16);
		if (primaryNumberDecimalPart != "")
		{
			resultHexadecimal = resultHexadecimal + '.' + doConversionFromDecimalDecimalPart(primaryNumberDecimalPart, 16);
		}
	}
}

//Pradinis skaicius is sesioliktaines skaiciavimo sistemos konvertuojamas i kitas skaiciavimo sistemas
void Conversions::doConvertFromHexadecimal(CString *ptrToPrimaryNumber, CString & resultBinary, CString & resultOctal, CString & resultDecimal, CString & resultHexadecimal)
{
	setPrimaryNumber(*ptrToPrimaryNumber);

	//Tikrinama ar pradinio skaiciaus laukelis nera tuscias
	if (isFieldEmpty())
	{
		//Jei laukelis tuscias, parodomas ispejamasis langas
		showErrorFieldIsEmpty();
	}
	//Tikrinama ar ivestas pradinis skaicius yra tinkamo formato
	else if (!isNumberFormatCorrect(16))
	{
		//Jei ivesta skaiciu sudaro neleistini simboliai, parodomas ispejamasis langas
		showErrorWrongNumberFormat();
	}
	else
	{
		//Atskiriama sveikoji skaiciaus dalis nuo trupmenines
		doSplitNumber(primaryNumberRealPart, primaryNumberDecimalPart);
		/* Jei skaiciaus dalies simboliu skaicius nedalus is 3, atitinkamoje vietoje (pradzioje
		 * arba pabaigoje) prirasomas nulis*/
		primaryNumberRealPart = fixNumberLengthRealPart(3, primaryNumberRealPart);
		primaryNumberDecimalPart = fixNumberLengthDecimalPart(3, primaryNumberDecimalPart);

		/* I dvejetaine skaiciavimo sistema atskirai konvertuojama sveikoji bei trupmenine
		 * (jei tokia egzistuoja) sesioliktainio skaiciaus dalis */
		resultBinaryRealPart = doConversionHexadecimalToBinary(primaryNumberRealPart);
		resultBinary = resultBinaryRealPart;
		if (primaryNumberDecimalPart != "")
		{
			resultBinaryDecimalPart = doConversionHexadecimalToBinary(primaryNumberDecimalPart);
			resultBinary = resultBinary + '.' + resultBinaryDecimalPart;
		}

		/* I astuntaine skaiciavimo sistema atskirai konvertuojama sveikoji bei trupmenine
		 * (jei tokia egzistuoja) astuntainio skaiciaus dalis */
		resultBinaryRealPart = fixNumberLengthRealPart(3, resultBinaryRealPart);
		resultOctal = doConversionBinaryToOctal(resultBinaryRealPart);
		if (resultBinaryDecimalPart != "")
		{
			resultBinaryDecimalPart = fixNumberLengthDecimalPart(3, resultBinaryDecimalPart);
			resultOctal = resultOctal + '.' + doConversionBinaryToOctal(resultBinaryDecimalPart);
		}

		/* I desimtaine skaiciavimo sistema atskirai konvertuojama sveikoji bei trupmenine
		 * (jei tokia egzistuoja) dvejetainio skaiciaus dalis */
		resultDecimalInt = doConversionToDecimalRealPart(resultBinaryRealPart, 2.0);
		resultDecimal = doConversionIntToCString(resultDecimalInt);
		if (resultBinaryDecimalPart != "")
		{
			resultDecimalDouble = doConversionToDecimalDecimalPart(resultBinaryDecimalPart, 2.0);
			resultDecimal = resultDecimal + '.' + doConversionDoubleToCString(resultDecimalDouble);
		}

		/* Kadangi pradinis skaicius yra sesioliktainis, konversija nereikalinga ir sesioliktainio
		 * skaiciaus rezultato laukelyje isvedamas pradinis skaicius */
		resultHexadecimal = primaryNumber;
	}
}