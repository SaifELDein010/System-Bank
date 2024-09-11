#pragma once

#include <iostream>
#include "clsBankUser.h"
#include "clsInput.h"
#include "clsScreen.h"

using namespace std;

class clsUsersListScreen : protected clsScreen {

private:

	static void _Header() {

		cout << clsInput::Format(7, " ") << clsInput::Format(108, "_") << '\n';

		cout << '\n' << clsInput::Format(7, " ")
			<< "|" << std::left << std::setw(16) << "User name"
			<< "|" << std::left << std::setw(20) << "Full Name"
			<< "|" << std::left << std::setw(15) << "Phone"
			<< "|" << std::left << std::setw(30) << "Email"
			<< "|" << std::left << std::setw(10) << "Password"
			<< "|" << std::left << std::setw(11) << "Permissions\n";


		cout << clsInput::Format(7, " ") << clsInput::Format(108, "_") << "\n\n";

	}

	static void _FormattingInfo(clsBankUser user) {

		cout << clsInput::Format(7, " ") << "|" << std::left << std::setw(16) << user.UserName;
		cout << "|" << std::left << std::setw(20) << user.FullName();
		cout << "|" << std::left << std::setw(15) << user.Phone;
		cout << "|" << std::left << std::setw(30) << user.Email;
		cout << "|" << std::left << std::setw(10) << clsUtil::getNameAfterDecrption(user.Password);
		cout << "|" << std::left << std::setw(11) << user.Permissions;


	}

public:


	static void ShowClientList() {

		vector <clsBankUser> users = clsBankUser::GetUserList();

		short manyOfClient = users.size();

		string title = "\t        User list";
		string subTitle = "\t  User list(" + to_string(users.size()) + ") User(s).";

		// User list(..) User (s).
		cout << '\n';
		ScreenHeader(title, subTitle);
		_Header();

		if (manyOfClient == 0) {
			cout << "\t\t\t\tNo Users Available in the system!";
		}
		else {

			for (clsBankUser& n : users) {

				_FormattingInfo(n);
				cout << '\n';

			}

			cout << "\n" << clsInput::Format(7, " ") << clsInput::Format(108, "_") << '\n';

		}

	}


};

