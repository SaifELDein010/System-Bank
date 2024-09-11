#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankUser.h"
#include "GlobalUser.h"
#include "clsDate.h"

using namespace std;

class clsRegisterLogins: protected clsScreen {

	struct _RegisterLogins {

		string _DateAndTime;
		string _UserName;
		string _Password;
		int _Permissions;

	};

	static string  _ConvertToLine(string sepratore = "#//#") {

		string line = "";

		line += clsDate::DateAndTimeToString(clsDate::ReadCurrentDateAndTime()) + sepratore;
		line += currentUser.UserName + sepratore;
		line += currentUser.Password + sepratore;
		line += std::to_string(currentUser.Permissions);

		return line;

	}

	static _RegisterLogins  _CounvertToObject(string userLine, string seperator = "#//#") {

		_RegisterLogins userInfo;

		vector <string> vUser;
		vUser = clsString::Spilt(userLine, seperator);

		userInfo._DateAndTime = vUser[0];
		userInfo._UserName = vUser[1];
		userInfo._Password = clsUtil::getNameAfterDecrption(vUser[2]);
		userInfo._Permissions = stoi(vUser[3]);

		return userInfo;

	}


	static vector <_RegisterLogins> _LoadUserDataFromFile() {

		vector <_RegisterLogins> _VUser;

		fstream MyFile;
		MyFile.open("LogFile.txt", std::ios::in);

		if (MyFile.is_open()) {

			string line;

			while (getline(MyFile, line)) {

				_RegisterLogins client = _CounvertToObject(line);

				_VUser.push_back(client);

			}

			MyFile.close();

		}

		return _VUser;

	}

	static void _AddDateLineToFile(string stDateLine) {

		fstream MyFile;
		MyFile.open("LogFile.txt", std::ios::out | std::ios::app);

		if (MyFile.is_open()) {

			MyFile << stDateLine << '\n';

			MyFile.close();

		}

	}



	static void _Header() {

		cout << clsInput::Format(7, " ") << clsInput::Format(108, "_") << '\n';

		cout << '\n' << clsInput::Format(7, " ")
			<< "|" << std::left << std::setw(30) << "Date - Time"
			<< "|" << std::left << std::setw(20) << "User name"
			<< "|" << std::left << std::setw(15) << "Password"
			<< "|" << std::left << std::setw(10) << "Permissions\n";


		cout << clsInput::Format(7, " ") << clsInput::Format(108, "_") << "\n\n";

	}

	static void _FormattingInfo(_RegisterLogins user) {

		cout << clsInput::Format(7, " ") << "|" << std::left << std::setw(30) << user._DateAndTime;
		cout << "|" << std::left << std::setw(20) << user._UserName;
		cout << "|" << std::left << std::setw(15) << user._Password;
		cout << "|" << std::left << std::setw(30) << user._Permissions;

	}


public:

	static void RegisterLogin() {

		_AddDateLineToFile(_ConvertToLine());

	}

	static void ShowRegisterLoginList() {

		vector <_RegisterLogins> users = _LoadUserDataFromFile();

		short manyOfClient = users.size();

		string title = "\t   Register login list";
		string subTitle = "\t  (" + to_string(users.size()) + ") Record(s).";

		// User list(..) User (s).
		cout << '\n';
		ScreenHeader(title, subTitle);
		_Header();

		if (manyOfClient == 0) {
			cout << "\t\t\t\tNo Users Available in the system!";
		}
		else {

			for (_RegisterLogins& n : users) {

				_FormattingInfo(n);
				cout << '\n';

			}

			cout << "\n" << clsInput::Format(7, " ") << clsInput::Format(108, "_") << '\n';

		}

	}


};

