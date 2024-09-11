#pragma once

#include <iostream>
#include <string>
#include "clsInput.h"
#include "clsScreen.h"
#include "clsDeposit.h"
#include "clsWithDraw.h"
#include "clsTotalBalanceScreen.h"
#include "clsTransfer.h"

using std::string;

class clsTransactionMenueScreen : protected clsScreen {

private:

	enum _enTransactionMenueOption { 
		enDeposit = 1, enWithDraw = 2, enTotalBalance = 3, enTransfer = 4, enTransferLog = 5, enMainMenue = 6 };

	static void _Restert() {

		system("color F");
		system("cls");

	}

	static void _GoBack(string message) {

		cout << message;
		system("Pause>0");
		_Restert();
		TransactionMenueScreen();

	}

	static short _ReadNumberOfOption() {

		cout << clsInput::Format(5, "\t");
		short num = clsInput::ReadNumber("Choose what do you want to do?[1To6] ", 1, 6);
		return num;

	}


	static void _ShowDepositScreen() {

		//cout << "\nDeposit screen will be here...\n";
		clsDeposit::Deposit();

	}

	static void _ShowWithDrawScreen() {

		//cout << "\nWith Draw screen will be here...\n";
		clsWithDraw::WithDarwScreen();

	}

	static void _ShowTotalBalanceScreen() {

		//cout << "\nTotal Balance screen will be here...\n";
		clsTotalBalanceScreen::ShowClientList();

	}

	static void _ShowTransferScreen() {

		//cout << "\nTransfer screen will be here...\n";
		clsTransfer::Transfer();

	}

	static void _ShowTransferLogScreen() {

		//cout << "\nTransfer Log screen will be here...\n";
		clsTransfer::ShowRegisterLoginList();

	}

	static void _PerfromMainMenueOption(_enTransactionMenueOption transactionMenueOption) {

		switch (transactionMenueOption)
		{
		case clsTransactionMenueScreen::enDeposit:
			_Restert();
			_ShowDepositScreen();
			_GoBack("\n\n Press any key to go back to transaction menue...");
			break;

		case clsTransactionMenueScreen::enWithDraw:
			_Restert();
			_ShowWithDrawScreen();
			_GoBack("\n\n Press any key to go back to transaction menue...");
			break;

		case clsTransactionMenueScreen::enTotalBalance:
			_Restert();
			_ShowTotalBalanceScreen();
			_GoBack("\n\n\n\t\tPress any key to go back to transaction menue...");
			break;

		case clsTransactionMenueScreen::enTransfer:
			_Restert();
			_ShowTransferScreen();
			_GoBack("\n\n\n\t\tPress any key to go back to transaction menue...");
			break;

		case clsTransactionMenueScreen::enTransferLog:
			_Restert();
			_ShowTransferLogScreen();
			_GoBack("\n\n\n\t\tPress any key to go back to transaction menue...");
			break;

		case clsTransactionMenueScreen::enMainMenue:
			break;
	
		}

	}

public:

	static void TransactionMenueScreen() {

		ScreenHeader("\t   Transaction menue");

		cout << '\n' << clsInput::Format(5, "\t") << clsInput::Format(40, "=") << '\n';
		cout << clsInput::Format(5, "\t") << clsInput::Format(11, " ") << "Transaction menue\n";
		cout << clsInput::Format(5, "\t") << clsInput::Format(40, "=") << '\n';
			 
		cout << clsInput::Format(5, "\t") << clsInput::Format(10, " ") << "[1] Deposit\n";
		cout << clsInput::Format(5, "\t") << clsInput::Format(10, " ") << "[2] With Draw\n";
		cout << clsInput::Format(5, "\t") << clsInput::Format(10, " ") << "[3] Total balance\n";
		cout << clsInput::Format(5, "\t") << clsInput::Format(10, " ") << "[4] Transfer\n";
		cout << clsInput::Format(5, "\t") << clsInput::Format(10, " ") << "[5] Transfer Log\n";
		cout << clsInput::Format(5, "\t") << clsInput::Format(10, " ") << "[6] Main Menue\n";
	
		cout << clsInput::Format(5, "\t") << clsInput::Format(40, "=") << '\n';

		_PerfromMainMenueOption((_enTransactionMenueOption)_ReadNumberOfOption());

	}

};