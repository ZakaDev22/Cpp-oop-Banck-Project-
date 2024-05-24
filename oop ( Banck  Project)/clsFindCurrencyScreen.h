#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsCurrency.h"

class clsFindCurrencyScreen : protected clsScreen
{
private :
	
	enum  _enFindCurrencyOPtion { Code = 1, Country = 2 };

    static short _ReadCurrenciesMainMenueOptions()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 2]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 2, "Enter Number between 1 to 2? ");
        return Choice;
    }

    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\n Currency Card : ";
        cout << "\n------------------------------------------\n";
        cout << "\n Country   : " << Currency.Country();
        cout << "\n Code      : " << Currency.CurrencyCode();
        cout << "\n Name      : " << Currency.CurrencyName();
        cout << "\n Rate 1($) : " << Currency.Rate();
        cout << "\n------------------------------------------\n";
    }

    static void _ShowFindCurrencyByCode()
    {
       // cout << "\n _ShowFindCurrencyByCode Will Be Her \n";

        string CurrencyCode;
        cout << "\n Please Enter Currency Code ? ";
        CurrencyCode = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExistByCode(CurrencyCode))
        {
            cout << "\n Currency Code Not Exist, Try Another One ? ";
            CurrencyCode = clsInputValidate::ReadString();
        }

        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

        if(!Currency.IsEmpty())
        {
            cout << "\n Currency Found :-) \n\n";
            _PrintCurrency(Currency);
        }
        else
        {
            cout << "\n Currency Is Not Exist :-( \n\n";
        }
    }

    static void _ShowFindCurrencyByCountry()
    {
       // cout << "\n _ShowFindCurrencyByCountry Will Be Her \n";

        string CurrencyCountry;
        cout << "\n Please Enter Currency Country Name ? ";
        CurrencyCountry = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExistByCountry(CurrencyCountry))
        {
            cout << "\n Currency Country Name Not Exist, Try Another One ? ";
            CurrencyCountry = clsInputValidate::ReadString();
        }

        clsCurrency Currency = clsCurrency::FindByCountry(CurrencyCountry);

        if (!Currency.IsEmpty())
        {
            cout << "\n Currency Found :-) \n\n";
            _PrintCurrency(Currency);
        }
        else
        {
            cout << "\n Currency Is Not Exist :-( \n\n";
        }
    }

    static void _PerformCurrenciesMainMenueOptions(_enFindCurrencyOPtion FindCurrencyOption)
    {

        switch (FindCurrencyOption)
        {
        case _enFindCurrencyOPtion::Code:
        {
            _ShowFindCurrencyByCode();
            break;
        }

        case _enFindCurrencyOPtion::Country:
        {
            _ShowFindCurrencyByCountry();
            break;
        }
        }
     
    }

public:

    static void ShowFindCurrenciesMenue()
    {

        system("cls");
        _DrawScreenHeader("  Find Currency Main Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t Find Currency Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";

        cout << setw(37) << left << "" << "\t[1] Find By Code.\n";
        cout << setw(37) << left << "" << "\t[2] Find By Country.\n";
       
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformCurrenciesMainMenueOptions((_enFindCurrencyOPtion)_ReadCurrenciesMainMenueOptions());
    }
};

