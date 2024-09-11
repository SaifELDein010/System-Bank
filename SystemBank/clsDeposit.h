#pragma once

#include <iostream>
#include <string>
#include "clsInput.h"
#include "clsScreen.h"
#include "clsBankClient.h"

using namespace std;

class clsDeposit : protected clsScreen{

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


	static void Deposit() {

		ScreenHeader("\t   Deposit Screen");

		string accountNumber = clsInput::ReadText("Enter Account number? ");

		while (!clsBankClient::IsClientExist(accountNumber)) {

			accountNumber = clsInput::ReadText("account number not exist, Enter another Account number? ");

		}

		clsBankClient client = clsBankClient::Find(accountNumber);
		_PrintClientCard(client);

	
		double amount = clsInput::ReadNumberFrom("\n >> Enter Amount? ", 0);

		char sureForDeposit = clsInput::ReadCharacter("\n\nAre you sure do you want to Deposit Amount? y/n? ");

		if (std::tolower(sureForDeposit) == 'y') {

			client.Deposit(amount);

			cout << "\nDeposit amount successfully :-)\n";
			cout << "Account balance after deposit is: " << client.AccountBalance << '\n';
			return;
		}
		else {

			cout << "\nOperation was cancelled\n";
			return;

		}


	}



};

