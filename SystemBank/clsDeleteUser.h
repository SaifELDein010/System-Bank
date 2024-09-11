#pragma once

#include <iostream>
#include "clsBankUser.h"
#include "clsInput.h"
#include "clsScreen.h"

using namespace std;


class clsDeleteUser : protected clsScreen {

private:

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

	static void ShowDeleteClient() {

		ScreenHeader("\t   Delete User");

		string userName = clsInput::ReadText("Enter user Name? ");

		while (!clsBankUser::IsUserExist(userName)) {

			userName = clsInput::ReadText("user Name not Found, Enter another user Name? ");

		}

		while (userName == "admin") {

			userName = clsInput::ReadText("You can`t delete admin, Enter another user Name? ");

		}

		clsBankUser user = clsBankUser::Find(userName);
		_PrintUserCard(user);

		char sureForDeleted = clsInput::ReadCharacter("\n\n  Are you sure do you want to delete user name? y/n? ");


		if (std::tolower(sureForDeleted) == 'y') {

			user.Delete();
			cout << "\nUser deleted successfully :-)\n";
			_PrintUserCard(user);
			return;
		}
		else {

			return;

		}



	}


};

