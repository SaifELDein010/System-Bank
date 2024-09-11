#pragma once

#include <iostream>
#include "clsBankUser.h"
#include "clsInput.h"
#include "clsScreen.h"
#include "clsUtil.h"

using namespace std;


class clsUpdateUserInfo : protected clsScreen {

private:

	static int _ReadUserPermissions() {

		int Permissions = 0;

		char Access = clsInput::ReadCharacter("Do you want to give full access? y/n? ");

		if (tolower(Access) == 'y')
			return -1;

		cout << "\nDo you want to give access to: \n";

		Access = clsInput::ReadCharacter("\nShow Add new client? y/n? ");
		if (tolower(Access) == 'y')
			Permissions += clsBankUser::enPermission::pAddNewClient;

		Access = clsInput::ReadCharacter("\nShow client list? y/n? ");
		if (tolower(Access) == 'y')
			Permissions += clsBankUser::enPermission::pListClient;

		Access = clsInput::ReadCharacter("\nShow Find client? y/n? ");
		if (tolower(Access) == 'y')
			Permissions += clsBankUser::enPermission::pFindClient;

		Access = clsInput::ReadCharacter("\nShow Delete client? y/n? ");
		if (tolower(Access) == 'y')
			Permissions += clsBankUser::enPermission::pDeleteClient;

		Access = clsInput::ReadCharacter("\nShow Update client? y/n? ");
		if (tolower(Access) == 'y')
			Permissions += clsBankUser::enPermission::pUpdateClient;

		Access = clsInput::ReadCharacter("\nShow Transaction? y/n? ");
		if (tolower(Access) == 'y')
			Permissions += clsBankUser::enPermission::pTransaction;

		Access = clsInput::ReadCharacter("\nShow Manage Users? y/n? ");
		if (tolower(Access) == 'y')
			Permissions += clsBankUser::enPermission::pManageUsers;

		Access = clsInput::ReadCharacter("\nShow Register login Users? y/n? ");
		if (tolower(Access) == 'y')
			Permissions += clsBankUser::enPermission::pRegisterLogin;

		Access = clsInput::ReadCharacter("\nShow Currency Exchange? y/n? ");
		if (tolower(Access) == 'y')
			Permissions += clsBankUser::enPermission::pCurrencyExchange;

		return Permissions;

	}

	static void _ReadUserInformation(clsBankUser& user) {

		user.FirstName = clsInput::ReadText("Enter first name? ");
		user.LastName = clsInput::ReadText("Enter last name? ");
		user.Email = clsInput::ReadText("Enter Email? ");
		user.Phone = clsInput::ReadText("Enter Phone? ");
		user.Password = clsUtil::getNameAfterEncrption(clsInput::ReadText("Enter Password? "));
		user.Permissions = _ReadUserPermissions();

	}

	static void _PrintUserCard(clsBankUser user) {

		cout << "\nUser Card: \n" << clsInput::Format(25, "_");

		cout << "\nFirst name   : " << user.FirstName;
		cout << "\nLast name    : " << user.LastName;
		cout << "\nFull name    : " << user.FullName();
		cout << "\nEmail        : " << user.Email;
		cout << "\nPhone        : " << user.Phone;
		cout << "\nUser name    : " << user.UserName;
		cout << "\nPassword     : " << user.Password;
		cout << "\nPermissions  : " << user.Permissions;

		cout << '\n' << clsInput::Format(25, "_");
	}


public:

	static void ShowUpdateUser() {

		ScreenHeader("\t   Update user");

		string userName = clsInput::ReadText("Enter user name? ");

		while (!clsBankUser::IsUserExist(userName)) {

			userName = clsInput::ReadText("Invalide user name, please Enter user name? ");

		}

		while (userName == "admin") {

			userName = clsInput::ReadText("You can`t update admin, Enter another user Name? ");

		}

		clsBankUser User = clsBankUser::Find(userName);
		_PrintUserCard(User);

		char sureForDeleted = clsInput::ReadCharacter("\n\n  Are you sure do you want to update user name? y/n? ");


		if (std::tolower(sureForDeleted) == 'y') {

			cout << "\n\n  >> Update client \n";
			_ReadUserInformation(User);

			clsBankUser::enSaveResult saveResult;

			saveResult = User.Save();

			switch (saveResult)
			{
			case clsBankUser::svFaildEmptyObject:

				cout << "\nError User was not saved because it`s empty";
				break;

			case clsBankUser::svSucceeded:

				cout << "\nUser updated successfully :-)\n\n";
				_PrintUserCard(User);
				break;
			default:
				break;
			}

		}
		else {

			return;
		}


	}


};

