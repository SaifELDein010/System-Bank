#pragma once

#include <iostream>
#include <string>
#include "clsBankUser.h"
#include "clsInput.h"
#include "clsScreen.h"
#include "clsClientListScreen.h"
#include "clsAddNewClient.h"
#include "clsUpdateClientInfo.h"
#include "clsDeleteClient.h"
#include "clsFindClientInfo.h"
#include "clsTransactionMenueScreen.h"
#include "clsManageUsersScreen.h"
#include "GlobalUser.h"
#include "clsRegisterLogins.h"
#include "clsCurrencyMenueScreen.h"

using std::string;


class clsMainMenueScreen : protected clsScreen {

private:

	enum _enMainMenueOption
	{ enAddClient = 1, enShowClient = 2, enFindClient = 3, enDeleteClient = 4, enUpdateClient = 5,
	  enTransaction = 6, enManageUsers = 7, enRegisterLogin = 8 , enCurrencyExchange = 9, enLogout = 10 };

	static void _Restert() {

		system("color F");
		system("cls");

	}

	static void _GoBack(string message) {

		cout << message;
		system("Pause>0");
		_Restert();
		MainMenueScreen();

	}

	static short _ReadNumberOfOption() {

		cout << clsInput::Format(5, "\t");
		short num = clsInput::ReadNumber("Choose what do you want to do?[1To10] ", 1, 10);
		return num;

	}


	static void _ShowAddNewClientScreen() {

		//cout << "\nAdd new Client screen will be here...\n";
		clsAddNewClient::ShowAddClient();

	}

	static void _ShowClientListScreen() {

		//cout << "\nClient List screen will be here...\n";
		clsClientListScreen::ShowClientList();

	}

	static void _ShowFindClientScreen() {

		//cout << "\nFind Client screen will be here...\n";
		clsFindClientInfo::ShowFindClient();

	}

	static void _ShowDeleteClientScreen() {

		//cout << "\nDelete Client screen will be here...\n";
		clsDeleteClient::ShowDeleteClient();

	}

	static void _ShowUpdateClientScreen() {

		//cout << "\nUpdate Client screen will be here...\n";
		clsUpdateClientInfo::ShowUpdateClient();

	}

	static void _ShowTransactionScreen() {

		//cout << "\nTransaction screen will be here...\n";
		clsTransactionMenueScreen::TransactionMenueScreen();
		_Restert();
		MainMenueScreen();

	}

	static void _ShowManageUsersScreen() {

		//cout << "\nManage Users screen will be here...\n";
		clsManageUsersScreen::ManageUsersMenueScreen();
		_Restert();
		MainMenueScreen();

	}

	static void _ShowRegisterLoginUsersScreen() {

		//cout << "\nRegister Login Users screen will be here...\n";
		clsRegisterLogins::ShowRegisterLoginList();

	}

	static void _ShowCurrencyExchangeScreen() {

		//cout << "\nCurrency Rate screen will be here...\n";
		clsCurrencyMenueScreen::CurrencyExchangeMenueScreen();

	}

	static void _Logout() {

		//cout << "\nEnd screen will be here...\n";
		currentUser = clsBankUser::Find("", "");

	}


	static void _PerfromMainMenueOption(_enMainMenueOption mainMenueOption) {

		switch (mainMenueOption)
		{
		case clsMainMenueScreen::enAddClient:

			_Restert();

			if (currentUser.CheckPermission(clsBankUser::enPermission::pAddNewClient)) {

				_ShowAddNewClientScreen();

			}
			else {

				AccessDenied(clsBankUser::enPermission::pAddNewClient);

			}


			_GoBack("\n\n Press any key to go back to main menue...");
			
			break;

		case clsMainMenueScreen::enShowClient:

			_Restert();

			if (currentUser.CheckPermission(clsBankUser::enPermission::pListClient)) {

				_ShowClientListScreen();

			}
			else {

				AccessDenied(clsBankUser::enPermission::pListClient);

			}

			_GoBack("\n\t  Press any key to go back to main menue...");
			
			break;

		case clsMainMenueScreen::enFindClient:

			_Restert();

			if (currentUser.CheckPermission(clsBankUser::enPermission::pFindClient)) {

				_ShowFindClientScreen();

			}
			else {

				AccessDenied(clsBankUser::enPermission::pFindClient);

			}
			
			_GoBack("\n\n Press any key to go back to main menue...");
			
			break;

		case clsMainMenueScreen::enDeleteClient:

			_Restert();

			if (currentUser.CheckPermission(clsBankUser::enPermission::pDeleteClient)) {

				_ShowDeleteClientScreen();

			}
			else {

				AccessDenied(clsBankUser::enPermission::pDeleteClient);

			}
			
			_GoBack("\n\n Press any key to go back to main menue...");
			
			break;

		case clsMainMenueScreen::enUpdateClient:

			_Restert();

			if (currentUser.CheckPermission(clsBankUser::enPermission::pUpdateClient)) {

				_ShowUpdateClientScreen();

			}
			else {

				AccessDenied(clsBankUser::enPermission::pUpdateClient);

			}
	
			_GoBack("\n\n Press any key to go back to main menue...");
			
			break;

		case clsMainMenueScreen::enTransaction:

			_Restert();

			if (currentUser.CheckPermission(clsBankUser::enPermission::pTransaction)) {

				_ShowTransactionScreen();

			}
			else {

				AccessDenied(clsBankUser::enPermission::pTransaction);
				_GoBack("\n\n Press any key to go back to main menue...");
			}
			

			break;

		case clsMainMenueScreen::enManageUsers:
				
			_Restert();

			if (currentUser.CheckPermission(clsBankUser::enPermission::pManageUsers)) {

				_ShowManageUsersScreen();

			}
			else {

				AccessDenied(clsBankUser::enPermission::pManageUsers);
				_GoBack("\n\n Press any key to go back to main menue...");
			}
			
			break;

		case clsMainMenueScreen::enRegisterLogin:
			_Restert();

			if (currentUser.CheckPermission(clsBankUser::enPermission::pRegisterLogin)) {

				_ShowRegisterLoginUsersScreen();

			}
			else {

				AccessDenied(clsBankUser::enPermission::pRegisterLogin);

			}
			
			_GoBack("\n\n Press any key to go back to main menue...");

			break;

		case clsMainMenueScreen::enCurrencyExchange:

			_Restert();

			if (currentUser.CheckPermission(clsBankUser::enPermission::pCurrencyExchange)) {

				_ShowCurrencyExchangeScreen();

			}
			else {

				AccessDenied(clsBankUser::enPermission::pCurrencyExchange);

			}

			_GoBack("\n\n Press any key to go back to main menue...");

			break;


		case clsMainMenueScreen::enLogout:
			_Restert();
			_Logout();

			break;
		
		}

	}

public:

	static void MainMenueScreen() {

		_Restert();
		ScreenHeader("\t       Main menue");
		
		cout << '\n' << clsInput::Format(5, "\t") << clsInput::Format(40, "=") << '\n';
		cout << clsInput::Format(5, "\t") << clsInput::Format(15, " ") << "Main menue\n";
		cout << clsInput::Format(5, "\t") << clsInput::Format(40, "=") << '\n';
			    							 
		cout << clsInput::Format(5, "\t") << clsInput::Format(10, " ") << "[1] Add new Client\n";
		cout << clsInput::Format(5, "\t") << clsInput::Format(10, " ") << "[2] Show Client List\n";
		cout << clsInput::Format(5, "\t") << clsInput::Format(10, " ") << "[3] Find Client\n";
		cout << clsInput::Format(5, "\t") << clsInput::Format(10, " ") << "[4] Delete Client\n";
		cout << clsInput::Format(5, "\t") << clsInput::Format(10, " ") << "[5] Update Client info\n";
		cout << clsInput::Format(5, "\t") << clsInput::Format(10, " ") << "[6] Transaction\n";
		cout << clsInput::Format(5, "\t") << clsInput::Format(10, " ") << "[7] Manage Users\n";
		cout << clsInput::Format(5, "\t") << clsInput::Format(10, " ") << "[8] Register login\n";
		cout << clsInput::Format(5, "\t") << clsInput::Format(10, " ") << "[9] Currency Exchange\n";
		cout << clsInput::Format(5, "\t") << clsInput::Format(10, " ") << "[10] Logout\n";
			    							 
		cout << clsInput::Format(5, "\t") << clsInput::Format(40, "=") << '\n';

		_PerfromMainMenueOption((_enMainMenueOption)_ReadNumberOfOption());

	}


};

