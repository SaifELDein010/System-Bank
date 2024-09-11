#pragma once

#include <iostream>
#include <string>


using std::string;

class clsPerson {

private:

	string _FirstName = "";
	string _LastName  = "";
	string _Email = "";
	string _Phone = "";


public:

	clsPerson(string firstName, string lastName, string email, string phone) {

		_FirstName = firstName;
		_LastName = lastName;
		_Email = email;
		_Phone = phone;

	}


	void SetFirstName(string firstName) {

		_FirstName = firstName;

	}

	string GetFirstName() {

		return _FirstName;

	}

	__declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;


	void SetLastName(string lastName) {

		_LastName = lastName;

	}

	string GetLastName() {

		return _LastName;

	}

	__declspec(property(get = GetLastName, put = SetLastName)) string LastName;



	void SetEmail(string email) {

		_Email = email;

	}

	string GetEmail() {

		return _Email;

	}

	__declspec(property(get = GetEmail, put = SetEmail)) string Email;


	void SetPhone(string phone) {

		_Phone = phone;

	}

	string GetPhone() {

		return _Phone;

	}

	__declspec(property(get = GetPhone, put = SetPhone)) string Phone;


	string FullName() {

		return _FirstName + ' ' + _LastName;

	}


};

