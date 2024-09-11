#pragma once

#include <iostream>
#include <string>
#include "clsInput.h"
#include "clsScreen.h"
#include "clsBankUser.h"
#include "clsUsersListScreen.h"
#include "clsAddNewUser.h"
#include "clsFindUserInfo.h"
#include "clsDeleteUser.h"
#include "clsUpdateUserInfo.h"

using std::string;

class clsManageUsersScreen : protected clsScreen {


private:

	enum _enManageUserMenueOption 
	{ enListUsers = 1, enAddNewUser = 2, enDeleteUser = 3, enUpdateUser = 4, enFindUser = 5, enUserMainMenue = 6 };

	static void _Restert() {

		system("color F");
		system("cls");

	}

	static void _GoBack(string message) {

		cout << message;
		system("Pause>0");
		_Restert();
		ManageUsersMenueScreen();

	}

	static short _ReadNumberOfOption() {

		cout << clsInput::Format(5, "\t");
		short num = clsInput::ReadNumber("Choose what do you want to do?[1To6] ", 1, 6);
		return num;

	}


	static void _ShowListUsersScreen() {

		//cout << "\nList Users screen will be here...\n";
		clsUsersListScreen::ShowClientList();

	}

	static void _ShowAddNewUserScreen() {

		//cout << "\nAdd New User screen will be here...\n";
		clsAddNewUser::ShowAddUser();

	}

	static void _ShowDeleteUserScreen() {

		//cout << "\nDelete User screen will be here...\n";
		clsDeleteUser::ShowDeleteClient();

	}

	static void _ShowUpdateUserScreen() {

		//cout << "\nUpdate User screen will be here...\n";
		clsUpdateUserInfo::ShowUpdateUser();

	}

	static void _ShowFindUserScreen() {

		//cout << "\nFind User screen will be here...\n";
		clsFindUserInfo::ShowFindUser();

	}



	static void _PerfromManageUserMenueOption(_enManageUserMenueOption ManageUserMenueOption) {

		switch (ManageUserMenueOption)
		{
		case clsManageUsersScreen::enListUsers:
			_Restert();
			_ShowListUsersScreen();
			_GoBack("\n\n Press any key to go back to Manage User menue...");
			break;

		case clsManageUsersScreen::enAddNewUser:
			_Restert();
			_ShowAddNewUserScreen();
			_GoBack("\n\n Press any key to go back to Manage User menue...");
			break;

		case clsManageUsersScreen::enDeleteUser:
			_Restert();
			_ShowDeleteUserScreen();
			_GoBack("\n\n Press any key to go back to Manage User menue...");
			break;

		case clsManageUsersScreen::enUpdateUser:
			_Restert();
			_ShowUpdateUserScreen();
			_GoBack("\n\n Press any key to go back to Manage User menue...");
			break;

		case clsManageUsersScreen::enFindUser:
			_Restert();
			_ShowFindUserScreen();
			_GoBack("\n\n Press any key to go back to Manage User menue...");
			break;

		case clsManageUsersScreen::enUserMainMenue:
			break;

		}

	}

public:

	static void ManageUsersMenueScreen() {

		ScreenHeader("\t   Manage Users menue");

		cout << '\n' << clsInput::Format(5, "\t") << clsInput::Format(40, "=") << '\n';
		cout << clsInput::Format(5, "\t") << clsInput::Format(11, " ") << "Manage Users  menue\n";
		cout << clsInput::Format(5, "\t") << clsInput::Format(40, "=") << '\n';

		cout << clsInput::Format(5, "\t") << clsInput::Format(10, " ") << "[1] List Users\n";
		cout << clsInput::Format(5, "\t") << clsInput::Format(10, " ") << "[2] Add New User\n";
		cout << clsInput::Format(5, "\t") << clsInput::Format(10, " ") << "[3] Delete User\n";
		cout << clsInput::Format(5, "\t") << clsInput::Format(10, " ") << "[4] Update User\n";
		cout << clsInput::Format(5, "\t") << clsInput::Format(10, " ") << "[5] Find User\n";
		cout << clsInput::Format(5, "\t") << clsInput::Format(10, " ") << "[6] Main Menue\n";
	
		cout << clsInput::Format(5, "\t") << clsInput::Format(40, "=") << '\n';

		_PerfromManageUserMenueOption((_enManageUserMenueOption)_ReadNumberOfOption());

	}


};

