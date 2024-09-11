#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsInput.h"
#include "clsScreen.h"

using namespace std;

class clsClientListScreen: protected clsScreen  {

private:

	static void _Header() {

		cout << clsInput::Format(10, " ") << clsInput::Format(104, "_") << '\n';

		cout << '\n' << clsInput::Format(10, " ")
			<< "|" << std::left << std::setw(16) << "Account number"
			<< "|" << std::left << std::setw(20) << "Client Name"
			<< "|" << std::left << std::setw(15) << "Phone"
			<< "|" << std::left << std::setw(30) << "Email"
			<< "|" << std::left << std::setw(10) << "PIN code"
			<< "|" << std::left << std::setw(8)  << "Balance\n";


		cout << clsInput::Format(10, " ") << clsInput::Format(104, "_") << "\n\n";

	}

	static void _FormattingInfo(clsBankClient client) {

		cout << clsInput::Format(10, " ") << "|" << std::left << std::setw(16) << client.AccountNumber();
		cout << "|" << std::left << std::setw(20) << client.FullName();
		cout << "|" << std::left << std::setw(15) << client.Phone;
		cout << "|" << std::left << std::setw(30) << client.Email;
		cout << "|" << std::left << std::setw(10) << client.PinCode;
		cout << "|" << std::left << std::setw(9) << client.AccountBalance;


	}

public:

	static void ShowClientList() {

		vector <clsBankClient> clients = clsBankClient::GetClientList();

		short manyOfClient = clients.size();

		string title = "\t       Client list";
		string subTitle = "\tclient list(" + to_string(clients.size()) + ") client(s).";

		// client list(..) client (s).

		ScreenHeader(title, subTitle);
		_Header();

		if (manyOfClient == 0) {
			cout << "\t\t\t\tNo clients Available in the system!";
		}
		else {

			for (clsBankClient& n : clients) {

				_FormattingInfo(n);
				cout << '\n';

			}

			cout << "\n" << clsInput::Format(10, " ") << clsInput::Format(104, "_") << '\n';

		}

	}



};

