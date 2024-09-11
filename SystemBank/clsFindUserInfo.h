#pragma once

#include <iostream>
#include "clsBankUser.h"
#include "clsInput.h"
#include "clsScreen.h"

using namespace std;

class clsFindUserInfo : protected clsScreen {

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

	static void ShowFindUser() {

		ScreenHeader("\t   Find User");

		string userName = clsInput::ReadText("Enter User name? ");

		while (!clsBankUser::IsUserExist(userName)) {

			userName = clsInput::ReadText("user name not found, Enter another User name? ");

		}

		clsBankUser user = clsBankUser::Find(userName);


		if (!user.IsEmpty()) {

			cout << "\nUser Found :-)\n";

		}
		else {

			cout << "\nUser Was not Found :-(\n";

		}

		_PrintUserCard(user);

	}



};

