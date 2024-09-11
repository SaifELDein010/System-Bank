#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsInput.h"
#include "clsScreen.h"

using namespace std;

class clsDeleteClient : protected clsScreen {

private:

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

	static void ShowDeleteClient() {

		ScreenHeader("\t   Delete client");

		string accountNumber = clsInput::ReadText("Enter Account number? ");

		while (!clsBankClient::IsClientExist(accountNumber)) {

			accountNumber = clsInput::ReadText("account number not exist, Enter another Account number? ");

		}

		clsBankClient client = clsBankClient::Find(accountNumber);
		_PrintClientCard(client);

		char sureForDeleted = clsInput::ReadCharacter("\n\n  Are you sure do you want to delete account number? y/n? ");


		if (std::tolower(sureForDeleted) == 'y') {

			client.Delete();
			cout << "\nAccount deleted successfully :-)\n";
			_PrintClientCard(client);
			return;
		}
		else {

			return;

		}



	}


};

