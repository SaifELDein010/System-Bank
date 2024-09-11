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

class clsBankClient : public clsPerson {

private:

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	double _AccountBalance;


	static clsBankClient  _CounvertToObject(string clientLine, string seperator = "#//#") {

		vector <string> vClient;
		vClient = clsString::Spilt(clientLine, seperator);

		return clsBankClient(enMode::UpdateMode, vClient[0], vClient[1], vClient[2], vClient[3], vClient[4], vClient[5], stof(vClient[6]));

	}

	static string  _ConvertToLine(clsBankClient& client, string sepratore = "#//#") {

		string line = "";

		line += client.FirstName + sepratore;
		line += client.LastName+ sepratore;
		line += client.Email + sepratore;
		line += client.Phone + sepratore;
		line += client.AccountNumber() + sepratore;
		line += client.PinCode + sepratore;
		line += std::to_string(client.AccountBalance);

		return line;

	}


	static vector <clsBankClient> _LoadClientDataFromFile() {

		vector <clsBankClient> _VClient;

		fstream MyFile;
		MyFile.open("Client.txt", std::ios::in);

		if (MyFile.is_open()) {

			string line;

			while (getline(MyFile, line)) {

				clsBankClient client = _CounvertToObject(line);

				_VClient.push_back(client);

			}

			MyFile.close();

		}

		return _VClient;

	}

	static void _SaveClientDateToFile(vector <clsBankClient> _VClient) {

		fstream MyFile;
		MyFile.open("Client.txt", std::ios::out);

		if (MyFile.is_open()) {

			string dateLine = "";

			for (clsBankClient& n : _VClient) {

				dateLine = _ConvertToLine(n);
				MyFile << dateLine << '\n';

			}

			MyFile.close();

		}

	}

	void _Update() {

		vector <clsBankClient> _VClient;

		_VClient = _LoadClientDataFromFile();

		for (clsBankClient& n : _VClient) {

			if (n.AccountNumber() == AccountNumber()) {

				n = *this;
				break;

			}

		}

		_SaveClientDateToFile(_VClient);

	}

	void _Add() {

		_AddDateLineToFile(_ConvertToLine(*this));

	}

	void _Delete() {

		vector <clsBankClient> _VClient;

		_VClient = _LoadClientDataFromFile();

		fstream MyFile;
		MyFile.open("Client.txt", std::ios::out);

		if (MyFile.is_open()) {

			string dateLine = "";

			for (clsBankClient& n : _VClient) {

				if (n.AccountNumber() != AccountNumber()) {
					dateLine = _ConvertToLine(n);
					MyFile << dateLine << '\n';
				}
			}

			MyFile.close();

		}

		*this = _GetEmptyClient();

	}

	void _AddDateLineToFile(string stDateLine) {
		
		fstream MyFile;
		MyFile.open("Client.txt", std::ios::out | std::ios::app);

		if (MyFile.is_open()) {

			MyFile << stDateLine << '\n';

			MyFile.close();

		}

	}

	static clsBankClient  _GetEmptyClient() {

		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);

	}

public:

	clsBankClient(enMode mode, string firstName, string lastName, string email, string phone, string accountNumber, string pinCode, float accountBalance)
		: clsPerson(firstName, lastName, email, phone) 
	{

		_Mode = mode;
		_AccountNumber = accountNumber;
		_PinCode = pinCode;
		_AccountBalance = accountBalance;

	}

	bool IsEmpty() {

		return (_Mode == enMode::EmptyMode);

	}

	string AccountNumber() {

		return _AccountNumber;

	}


	void SetPinCode(string pinCode) {

		_PinCode = pinCode;

	}

	string GetPinCode() {

		return _PinCode;

	}

	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;


	void SetAccountBalance(float accountBalance) {

		_AccountBalance = accountBalance;

	}

	float GetAccountBalance() {

		return _AccountBalance;

	}

	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	
	static clsBankClient Find(string accountNumber) {

		fstream MyFile;
		MyFile.open("Client.txt", std::ios::in);

		if (MyFile.is_open()) {

			string line;

			while (getline(MyFile, line)) {

				clsBankClient client = _CounvertToObject(line);

				if (client._AccountNumber == accountNumber) {

					MyFile.close();
					return client;

				}

			}

			MyFile.close();

		}

		return _GetEmptyClient();

	}

	static clsBankClient Find(string accountNumber, string PinCode) {

		fstream MyFile;
		MyFile.open("Client.txt", std::ios::in);

		if (MyFile.is_open()) {

			string line;

			while (getline(MyFile, line)) {

				clsBankClient client = _CounvertToObject(line);

				if (client._AccountNumber == accountNumber && client.PinCode == PinCode) {

					MyFile.close();
					return client;

				}

			}

			MyFile.close();

		}

		return _GetEmptyClient();

	}

	enum enSaveResult { svFaildEmptyObject=0, svSucceeded=1, svFaildAccountNumberIsExists=2};

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

			if (IsClientExist(_AccountNumber)) {

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

	static bool IsClientExist(string accountNumber) {

		clsBankClient client = clsBankClient::Find(accountNumber);

		return (!client.IsEmpty());

	}

	static clsBankClient GetAddNewClient(string accountNumber) {

		return clsBankClient(enMode::AddNewMode, "", "", "", "", accountNumber, "", 0);

	}

	static vector <clsBankClient> GetClientList() {

		return _LoadClientDataFromFile();

	}

	static int GetTotalBalance() {

		vector <clsBankClient> clients = GetClientList();

		int sum = 0;

		for (clsBankClient& i : clients) {

			sum += i.AccountBalance;

		}

		return sum;

	}

	static string GetTotalBalanceText() {

		return clsUtil::NumberToText(GetTotalBalance());

	}

	void Deposit(double amount) {

		_AccountBalance += amount;
		Save();

	}

	bool WithDraw(double amount) {

		if (amount > _AccountBalance)
			return false;

		_AccountBalance -= amount;
		Save();
		return true;

	}

};