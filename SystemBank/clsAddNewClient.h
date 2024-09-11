#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsInput.h"
#include "clsScreen.h"

using namespace std;

class clsAddNewClient : protected clsScreen {

private:

	static void _ReadClinetInformation(clsBankClient& client) {

		client.FirstName = clsInput::ReadText("Enter first name? ");
		client.LastName = clsInput::ReadText("Enter last name? ");
		client.Email = clsInput::ReadText("Enter Email? ");
		client.Phone = clsInput::ReadText("Enter Phone? ");
		client.PinCode = clsInput::ReadText("Enter Pin code? ");
		client.AccountBalance = clsInput::ReadFloatNumber("Enter Account balance? ");

	}

	static void _PrintClientCard(clsBankClient client) {

		cout << "\nClient Card: \n" << clsInput::Format(25, "_");

		cout << "\nFirst name   : " << client.FirstName;
		cout << "\nLast name    : " << client.LastName;
		cout << "\nFull name    : " << client.FullName();
		cout << "\nEmail        : " << client.Email;
		cout << "\nPhone        : " << client.Phone;
		cout << "\nAcc. Number  : " << client.AccountNumber();
		cout << "\nPin code     : " << client.PinCode;
		cout << "\nAcc. Balance : " << client.AccountBalance;

		cout << '\n' << clsInput::Format(25, "_");
	}

public:

	static void ShowAddClient() {

		ScreenHeader("\t   Add new client");

		string accountNumber = clsInput::ReadText("Enter Account number? ");

		while (clsBankClient::IsClientExist(accountNumber)) {

			accountNumber = clsInput::ReadText("account number is already used, please Enter another account number? ");

		}

		clsBankClient newClient = clsBankClient::GetAddNewClient(accountNumber);

		cout << "\n\n >> Add client \n";
		_ReadClinetInformation(newClient);

		clsBankClient::enSaveResult saveResult;

		saveResult = newClient.Save();

		switch (saveResult)
		{
		case clsBankClient::svFaildEmptyObject:

			cout << "\nError account was not saved because it`s empty";
			break;

		case clsBankClient::svSucceeded:

			cout << "\nAccount Added successfully :-)\n";
			_PrintClientCard(newClient);
			break;

		case clsBankClient::svFaildAccountNumberIsExists:

			cout << "\nError account was not saved because account number is used!\n";
			break;

		}

	}


};

