#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "myFile.h"
#include "clsPerson.h"
#include "clsInput.h"
#include "clsString.h"
#include "clsUtil.h"
#include "clsDate.h"

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::fstream;

class clsBankUser : public clsPerson {

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;

	string _UserName;
	string _Password;
	int _Permissions;


	static clsBankUser  _CounvertToObject(string userLine, string seperator = "#//#") {

		vector <string> vUser;
		vUser = clsString::Spilt(userLine, seperator);

		return clsBankUser(enMode::UpdateMode, vUser[0], vUser[1], vUser[2], vUser[3], vUser[4], vUser[5], stof(vUser[6]));

	}

	static string  _ConvertToLine(clsBankUser& user, string sepratore = "#//#") {

		string line = "";

		line += user.FirstName + sepratore;
		line += user.LastName + sepratore;
		line += user.Email + sepratore;
		line += user.Phone + sepratore;
		line += user._UserName + sepratore;
		line += user._Password + sepratore;
		line += std::to_string(user._Permissions);

		return line;

	}


	static vector <clsBankUser> _LoadUserDataFromFile() {

		vector <clsBankUser> _VUser;

		fstream MyFile;
		MyFile.open("user.txt", std::ios::in);

		if (MyFile.is_open()) {

			string line;

			while (getline(MyFile, line)) {

				clsBankUser client = _CounvertToObject(line);

				_VUser.push_back(client);

			}

			MyFile.close();

		}

		return _VUser;

	}

	static void _SaveUserDateToFile(vector <clsBankUser> _VUser) {

		fstream MyFile;
		MyFile.open("user.txt", std::ios::out);

		if (MyFile.is_open()) {

			string dateLine = "";

			for (clsBankUser& n : _VUser) {

				dateLine = _ConvertToLine(n);
				MyFile << dateLine << '\n';

			}

			MyFile.close();

		}

	}


	void _Update() {

		vector <clsBankUser> _VUser;

		_VUser = _LoadUserDataFromFile();

		for (clsBankUser& n : _VUser) {

			if (n.UserName == UserName) {

				n = *this;
				break;

			}

		}

		_SaveUserDateToFile(_VUser);

	}

	void _Add() {

		_AddDateLineToFile(_ConvertToLine(*this));

	}

	void _Delete() {

		vector <clsBankUser> _VClient;

		_VClient = _LoadUserDataFromFile();

		fstream MyFile;
		MyFile.open("user.txt", std::ios::out);

		if (MyFile.is_open()) {

			string dateLine = "";

			for (clsBankUser& n : _VClient) {

				if (n.Password != Password) {
					dateLine = _ConvertToLine(n);
					MyFile << dateLine << '\n';
				}
			}

			MyFile.close();

		}

		*this = _GetEmptyUser();

	}

	void _AddDateLineToFile(string stDateLine) {

		fstream MyFile;
		MyFile.open("user.txt", std::ios::out | std::ios::app);

		if (MyFile.is_open()) {

			MyFile << stDateLine << '\n';

			MyFile.close();

		}

	}

	static clsBankUser  _GetEmptyUser() {

		return clsBankUser(enMode::EmptyMode, "", "", "", "", "", "", 0);

	}


public:

	enum enPermission {

		eAll = -1, pAddNewClient = 1, pListClient = 2, pFindClient = 4, pDeleteClient = 8, pUpdateClient = 16,
		pTransaction = 32, pManageUsers = 64, pRegisterLogin = 128, pCurrencyExchange = 256

	};

	bool CheckPermission(clsBankUser::enPermission permission) {

		return this->_Permissions == enPermission::eAll || this->Permissions & (int)permission;

	}

	clsBankUser(enMode mode, string firstName, string lastName, string email, string phone, string userName, string password, int permissions)
		: clsPerson(firstName, lastName, email, phone)
	{

		_Mode = mode;
		_UserName = userName;
		_Password = password;
		_Permissions = permissions;

	}


	bool IsEmpty() {

		return (_Mode == enMode::EmptyMode);

	}


	void SetUserName(string userName) {

		_UserName = userName;

	}

	string GetUserName() {

		return _UserName;

	}

	__declspec(property(get = GetUserName, put = SetUserName)) string UserName;


	void SetPassword(string password) {

		_Password = password;

	}

	string GetPassword() {

		return _Password;

	}

	__declspec(property(get = GetPassword, put = SetPassword)) string Password;


	void SetPermissions(int permissions) {

		_Permissions = permissions;

	}

	int GetPermissions() {

		return _Permissions;

	}

	__declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;


	static clsBankUser Find(string UserName) {

		fstream MyFile;
		MyFile.open("user.txt", std::ios::in);

		if (MyFile.is_open()) {

			string line;

			while (getline(MyFile, line)) {

				clsBankUser user = _CounvertToObject(line);

				if (user.UserName == UserName) {

					MyFile.close();
					return user;

				}

			}

			MyFile.close();

		}

		return _GetEmptyUser();

	}

	static clsBankUser Find(string UserName, string Password) {

		fstream MyFile;
		MyFile.open("user.txt", std::ios::in);

		if (MyFile.is_open()) {

			string line;

			while (getline(MyFile, line)) {

				clsBankUser user = _CounvertToObject(line);

				if (user.UserName == UserName && clsUtil::getNameAfterDecrption(user.Password) == Password) {

					MyFile.close();
					return user;

				}

			}

			MyFile.close();

		}

		return _GetEmptyUser();

	}


	enum enSaveResult { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberIsExists = 2 };

	enSaveResult Save() {

		switch (_Mode) {

		case enMode::EmptyMode:

			if (IsEmpty()) {
				return enSaveResult::svFaildEmptyObject;
			}

		case enMode::UpdateMode:

			_Update();
			return enSaveResult::svSucceeded;

		case enMode::AddNewMode:

			if (IsUserExist(UserName)) {

				return enSaveResult::svFaildAccountNumberIsExists;

			}
			else {

				_Add();
				_Mode = enMode::UpdateMode;
				return enSaveResult::svSucceeded;
			}

		}
	}

	void Delete() {

		_Delete();

	}

	static bool IsUserExist(string UserName) {

		clsBankUser user = clsBankUser::Find(UserName);

		return (!user.IsEmpty());

	}

	static clsBankUser GetAddNewUser(string UserName) {

		return clsBankUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);

	}

	static vector <clsBankUser> GetUserList() {

		return _LoadUserDataFromFile();

	}


};

