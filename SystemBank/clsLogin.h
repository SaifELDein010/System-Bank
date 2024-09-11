#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankUser.h"
#include "clsMainMenueScreen.h"
#include "clsRegisterLogins.h"
#include "GlobalUser.h"
#include "clsUtil.h"



using namespace std;

class clsLogin : protected clsScreen {

private:

	static bool _Login() {

		bool loginFaild = false;
		short _Try = 3;
		string userName = "", password = "";

		do {

			if (loginFaild) {

				_Try--;

				if (_Try == 0) {

					system("Color 4");
					cout << "\nYou are Locked after 3 Faild Login\n";
					return false;

				}

				cout << "\nInvalid user name/Password!";
				cout << "\nYou have " << _Try << " Trial(s) to login.\n\n";


			}

			userName = clsInput::ReadText("Enter user name? ");
			password = clsInput::ReadText("Enter Password? ");

			currentUser = clsBankUser::Find(userName, password);
			
			loginFaild = currentUser.IsEmpty();

		} while (loginFaild);

		clsRegisterLogins::RegisterLogin();
		clsMainMenueScreen::MainMenueScreen();
		return true;

	}

public:


	static bool LoginScreen() {

		ScreenHeader("\t     Login screen");
		return _Login();

	}


};

