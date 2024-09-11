#pragma once
#include <iostream>
#include <string>
#include "clsInput.h"
#include "clsDate.h"
#include "clsBankUser.h"
#include "GlobalUser.h"

using std::string;

class clsScreen
{

private:

	static void _ScreenUserAndDate() {

		cout << clsInput::Format(6, "\t") << clsInput::Format(25, "=") << "\n";

		cout << clsInput::Format(6, "\t") << clsInput::Format(5, " ") << "User: " << currentUser.UserName << '\n';
		cout << clsInput::Format(6, "\t") << clsInput::Format(5, " ") << "Date: " << clsDate::DateToString(clsDate()) << '\n';

		cout << clsInput::Format(6, "\t") << clsInput::Format(25, "=") << "\n";

	}

protected:

	static void ScreenHeader(string title, string subTitle = "") {

		_ScreenUserAndDate();

		cout << clsInput::Format(4, "\t") << clsInput::Format(3, " ") << clsInput::Format(50, "_") << "\n\n";

		cout << clsInput::Format(5, "\t") << title << '\n';

		if (subTitle != "") {

			cout << clsInput::Format(5, "\t") << subTitle << '\n';

		}

		cout << clsInput::Format(4, "\t") << clsInput::Format(3, " ") << clsInput::Format(50, "_") << '\n';

	}

	static void AccessDenied(clsBankUser::enPermission permission) {

		if (!currentUser.CheckPermission(permission)) {

			cout << clsInput::Format(2, "\t") << clsInput::Format(3, " ") <<
				"Access Denied\nYou don`t have permission to do this.\nPlease conact your admine.\n";

		}

	}


};

