#pragma once

#include <iostream>
#include <string>
#include "clsInput.h"
#include "clsScreen.h"
#include "clsBankClient.h"

using namespace std;


class clsTotalBalanceScreen : protected clsScreen {

private:

	static void _Header() {

		cout << clsInput::Format(26, " ") << clsInput::Format(68, "_") << '\n';

		cout << '\n' << clsInput::Format(37, " ")
			<< "|" << std::left << std::setw(16) << "Account number"
			<< "|" << std::left << std::setw(20) << "Client Name"
			<< "|" << std::left << std::setw(8) << "Balance\n";


		cout << clsInput::Format(26, " ") << clsInput::Format(68, "_") << "\n\n";

	}

	static void _FormattingInfo(clsBankClient client) {

		cout << clsInput::Format(37, " ") << "|" << std::left << std::setw(16) << client.AccountNumber();
		cout << "|" << std::left << std::setw(20) << client.FullName();
		cout << "|" << std::left << std::setw(9) << client.AccountBalance;

	}


public:

	static void ShowClientList() {

		vector <clsBankClient> clients = clsBankClient::GetClientList();

		short manyOfClient = clients.size();

		string title = "\t   Client Balance list";
		string subTitle = "\tclient list(" + to_string(clients.size()) + ") client(s).";

		// client list(..) client (s).

		ScreenHeader(title, subTitle);
		cout << '\n';
		_Header();

		if (manyOfClient == 0) {
			cout << "\t\t\t\tNo clients Available in the system!";
		}
		else {

			for (clsBankClient& n : clients) {

				_FormattingInfo(n);
				cout << '\n';

			}

			cout << "\n" << clsInput::Format(26, " ") << clsInput::Format(68, "_") << '\n';
			cout << "\t\t\t\t\t\tTotal Balance: " << clsBankClient::GetTotalBalance();
			cout << "\n\t\t\t(  " << clsBankClient::GetTotalBalanceText() << ")";
		}

	}

};

