#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsInput.h"
#include "clsScreen.h"

using namespace std;

class clsUpdateClientInfo : protected clsScreen {

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

	static void ShowUpdateClient() {

		ScreenHeader("\t   Update client");

		string accountNumber = clsInput::ReadText("Enter Account number? ");

		while (!clsBankClient::IsClientExist(accountNumber)) {

			accountNumber = clsInput::ReadText("Invalide account number, please Enter Account number? ");

		}

		clsBankClient client = clsBankClient::Find(accountNumber);
		_PrintClientCard(client);

		char sureForDeleted = clsInput::ReadCharacter("\n\n  Are you sure do you want to update account number? y/n? ");


		if (std::tolower(sureForDeleted) == 'y') {

			cout << "\n\n  >> Update client \n";
			_ReadClinetInformation(client);

			clsBankClient::enSaveResult saveResult;

			saveResult = client.Save();

			switch (saveResult)
			{
			case clsBankClient::svFaildEmptyObject:

				cout << "\nError account was not saved because it`s empty";
				break;

			case clsBankClient::svSucceeded:

				cout << "\nAccount updated successfully :-)\n\n";
				_PrintClientCard(client);
				break;
			default:
				break;
			}
		
		}
		else {

			return;
		}


	}


};

