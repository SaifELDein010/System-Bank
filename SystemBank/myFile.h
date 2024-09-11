#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::fstream;

const string fileName = "test.txt";

namespace mFile {

	void PrintData(vector <string> person) {

		for (string& n : person) {

			cout << n << '\n';

		}

	}

	void SaveDateWriteMode(vector <string> person) {

		fstream file;

		file.open(fileName, std::ios::out); //Write mode

		if (file.is_open()) {

			for (string& n : person) {

				if (n != "") {
					file << n << '\n';
				}

			}

			file.close();

		}


	}

	void SaveDateAppendMode(vector <string> person) {

		fstream file;

		file.open(fileName, std::ios::out | std::ios::app); //Write mode | append mode

		if (file.is_open()) {

			for (string& n : person) {

				if (n != "") {
					file << n << '\n';
				}

			}

			file.close();

		}


	}

	void LoadData(vector <string>& person) {

		fstream file;

		file.open(fileName, std::ios::in); //Read mode

		if (file.is_open()) {

			string line = "";

			while (std::getline(file, line)) {

				person.push_back(line);

			}

			file.close();

		}


	}

	void DeleteData(vector <string>& person, string record) {

		LoadData(person);

		for (string& n : person) {

			if (n == record) {

				n = "";

			}

		}

		SaveDateWriteMode(person);

	}

	void UpdateData(vector <string>& person, string record, string upDateTo) {

		LoadData(person);

		for (string& n : person) {

			if (n == record) {

				n = upDateTo;

			}

		}

		SaveDateWriteMode(person);



	}

}

