#pragma once

#include <iostream>
#include <string>
#include "clsInput.h"
#include "clsScreen.h"
#include "clsBankClient.h"

using namespace std;


class clsTransfer : protected clsScreen {

private:

	struct _TransferLogin {

		string _DateAndTime = "";
		string _AccountNumber1 = "";
		string _AccountNumber2 = "";
		double _Amount = 0.0;
		double _Balance1 = 0.0;
		double _Balance2 = 0.0;
		string _UserName = "";

	};

	static string  _ConvertToLine(_TransferLogin transferOperation,string sepratore = "#//#") {

		string line = "";

		line += clsDate::DateAndTimeToString(clsDate::ReadCurrentDateAndTime()) + sepratore;
		line += transferOperation._AccountNumber1 + sepratore;
		line += transferOperation._AccountNumber2 + sepratore;
		line += std::to_string(transferOperation._Amount) + sepratore;
		line += std::to_string(transferOperation._Balance1) + sepratore;
		line += std::to_string(transferOperation._Balance2) + sepratore;
		line += currentUser.UserName;

		return line;

	}

	static _TransferLogin  _CounvertToObject(string userLine, string seperator = "#//#") {

		_TransferLogin userInfo;

		vector <string> vUser;
		vUser = clsString::Spilt(userLine, seperator);

		userInfo._DateAndTime = vUser[0];
		userInfo._AccountNumber1 = vUser[1];
		userInfo._AccountNumber2 = vUser[2];
		userInfo._Amount = stod(vUser[3]);
		userInfo._Balance1 = stod(vUser[4]);
		userInfo._Balance2 = stod(vUser[5]);
		userInfo._UserName = vUser[6];

		return userInfo;

	}


	static vector <_TransferLogin> _LoadUserDataFromFile() {

		vector <_TransferLogin> _VUser;

		fstream MyFile;
		MyFile.open("TransferLog.txt", std::ios::in);

		if (MyFile.is_open()) {

			string line;

			while (getline(MyFile, line)) {

				_TransferLogin client = _CounvertToObject(line);

				_VUser.push_back(client);

			}

			MyFile.close();

		}

		return _VUser;

	}

	static void _AddDateLineToFile(string stDateLine) {

		fstream MyFile;
		MyFile.open("TransferLog.txt", std::ios::out | std::ios::app);

		if (MyFile.is_open()) {

			MyFile << stDateLine << '\n';

			MyFile.close();

		}

	}


	static _TransferLogin _FillTransferStruct(string account1, string account2, double amount, double balance1, double balance2) {

		_TransferLogin transferOperation;

		transferOperation._AccountNumber1 = account1;
		transferOperation._AccountNumber2 = account2;

		transferOperation._Amount = amount;

		transferOperation._Balance1 = balance1;
		transferOperation._Balance2 = balance2;
		
		return transferOperation;

	}



	static void _PrintClientCard(clsBankClient client) {

		cout << "\nClient Card: \n" << clsInput::Format(25, "_");

		cout << "\nFull name    : " << client.FullName();
		cout << "\nAcc. Number  : " << client.AccountNumber();
		cout << "\nAcc. Balance : " << client.AccountBalance;

		cout << '\n' << clsInput::Format(25, "_");
	}

	static void _Header() {

		cout << clsInput::Format(7, " ") << clsInput::Format(108, "_") << '\n';

		cout << '\n' << clsInput::Format(7, " ")
			<< "|" << std::left << std::setw(30) << "Date - Time"
			<< "|" << std::left << std::setw(8) << "S Acc"
			<< "|" << std::left << std::setw(8) << "D Acc"
			<< "|" << std::left << std::setw(10) << "Amount"
			<< "|" << std::left << std::setw(15) << "S Balance"
			<< "|" << std::left << std::setw(15) << "D Balance"
			<< "|" << std::left << std::setw(10) << "User Name\n";


		cout << clsInput::Format(7, " ") << clsInput::Format(108, "_") << "\n\n";

	}

	static void _FormattingInfo(_TransferLogin user) {

		cout << clsInput::Format(7, " ") << "|" << std::left << std::setw(30) << user._DateAndTime;
		cout << "|" << std::left << std::setw(8) << user._AccountNumber1;
		cout << "|" << std::left << std::setw(8) << user._AccountNumber2;
		cout << "|" << std::left << std::setw(10) << user._Amount;
		cout << "|" << std::left << std::setw(15) << user._Balance1;
		cout << "|" << std::left << std::setw(15) << user._Balance2;
		cout << "|" << std::left << std::setw(10) << user._UserName;

	}


public:

	static void RegisterLogin(_TransferLogin transferOperation) {

		_AddDateLineToFile(_ConvertToLine(transferOperation));

	}

	static void Transfer() {

		ScreenHeader("\t   Transfer Screen");

		string accountNumber1 = clsInput::ReadText("\nEnter Account number To trasfer From: ");

		while (!clsBankClient::IsClientExist(accountNumber1)) {

			accountNumber1 = clsInput::ReadText("account number not exist, Enter another Account number? ");

		}

		clsBankClient client1 = clsBankClient::Find(accountNumber1);
		_PrintClientCard(client1);


		string accountNumber2 = clsInput::ReadText("\nEnter Account number To trasfer To: ");

		while (!clsBankClient::IsClientExist(accountNumber2) || accountNumber1 == accountNumber2) {

			accountNumber2 = clsInput::ReadText("account number not exist, Enter another Account number? ");

		}

		clsBankClient client2 = clsBankClient::Find(accountNumber2);
		_PrintClientCard(client2);


		double amount = clsInput::ReadNumberFrom("\n >> Enter Amount? ", 0.0);


		char sureForDeposit = clsInput::ReadCharacter("\n\nAre you sure do you want to Perform this operation? y/n? ");


		if (std::tolower(sureForDeposit) == 'y') {

			while (!client1.WithDraw(amount)) {

				amount = clsInput::ReadNumberFrom("\nAmount Exceeds the available balance\n Enter another amount? ", 0);

			}

			client2.Deposit(amount);

			_TransferLogin transferOperation = _FillTransferStruct(client1.AccountNumber(), client2.AccountNumber(), amount, client1.AccountBalance, client2.AccountBalance);
			RegisterLogin(transferOperation);


			cout << "\nTransfer Done successfully :-)\n";
			_PrintClientCard(client1);
			_PrintClientCard(client2);
			return;
		}
		else {

			cout << "\nOperation was cancelled\n";
			return;

		}


	}


	static void ShowRegisterLoginList() {

		vector <_TransferLogin> users = _LoadUserDataFromFile();

		short manyOfClient = users.size();

		string title = "\t   Transfer login list";
		string subTitle = "\t  (" + to_string(users.size()) + ") Record(s).";

		// User list(..) User (s).
		cout << '\n';
		ScreenHeader(title, subTitle);
		_Header();

		if (manyOfClient == 0) {
			cout << "\t\t\t\tNo Users Available in the system!";
		}
		else {

			for (_TransferLogin& n : users) {

				_FormattingInfo(n);
				cout << '\n';

			}

			cout << "\n" << clsInput::Format(7, " ") << clsInput::Format(108, "_") << '\n';

		}

	}



};

