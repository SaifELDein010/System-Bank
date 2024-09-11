#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using std::cout;
using std::cin;
using std::string;
using std::vector;

class clsString {

private:

	string _Value = "";

	static void  _ReverseString(string& oraginal, string& resversd) {

		for (short i = oraginal.length() - 1; i >= 0; i--) {

			resversd.push_back(oraginal[i]);

		}

		return;

	}

public:

	clsString() { }

	clsString(string value) {

		_Value = value;

	}


	void SetValue(string value) {

		_Value = value;

	}

	string Value() {

		return _Value;

	}

	__declspec(property(get = Value, put = SetValue)) string value;



	static short  CounterWords(string name) {

		short pos = 0;
		string word = "";
		short counter = 0;

		while ((pos = name.find(' ')) != string::npos) {

			word = name.substr(0, pos);

			if (word != "")
				counter++;

			name.erase(0, pos + 1);

		}

		if (name != "")
			counter++;

		return counter;

	}

	short  CounterWords() {

		return CounterWords(_Value);

	}


	static void   PrintEachWordsInString(string name) {

		short pos = 0;
		string word = "";

		while ((pos = name.find(' ')) != string::npos) {

			word = name.substr(0, pos);

			if (word != "")
				cout << word << '\n';

			name.erase(0, pos + 1);

		}

		if (name != "")
			cout << name;

	}

	void   PrintEachWordsInString() {

		return PrintEachWordsInString(_Value);

	}


	static void   Spilt(string name, string demilitor, vector <string>& result) {

		short pos = 0;
		string word = "";

		while ((pos = name.find(demilitor)) != string::npos) {

			word = name.substr(0, pos);

			if (word != "")
				result.push_back(word);

			name.erase(0, pos + demilitor.length());

		}

		if (name != "")
			result.push_back(name);

	}

	void   Spilt(string demilitor, vector <string>& result) {

		return Spilt(_Value, demilitor, result);

	}


	static vector<string>  Spilt(string name, string demilitor) {

		vector <string> vString;

		short pos = 0;
		string word = "";

		while ((pos = name.find(demilitor)) != string::npos) {

			word = name.substr(0, pos);

			vString.push_back(word);

			name.erase(0, pos + demilitor.length());

		}

		if (name != "")
			vString.push_back(name);

		return vString;

	}

	static void   PrintEachSpiltWords(vector <string>& result) {

		cout << "Tokens = " << result.size() << "\n";

		for (string& N : result) {

			cout << N << '\n';

		}

		cout << std::endl;

	}

	static string   TrimLeft(string name, string demilitor) {

		while (name.substr(0, demilitor.length()) == demilitor) {

			name.erase(0, demilitor.length());

		}

		return name;

	}

	static string   TrimRigth(string name, string demilitor) {

		string eman = "";
		_ReverseString(name, eman);
		name.clear();

		while (eman.substr(0, demilitor.length()) == demilitor) {

			eman.erase(0, demilitor.length());

		}

		_ReverseString(eman, name);

		return name;
	}

	static string   Trim(string name, string demilitor) {

		TrimLeft(name, demilitor);
		TrimRigth(name, demilitor);

		return name;

	}


	void   TrimLeft(string demilitor) {

		_Value = TrimLeft(_Value, demilitor);

	}

	// Fix issues ( need function to swap string and make proccess and swap string then return) :-);
	// I fix it pro :-) love for me to make mistake and solve it :>) ;

	void   TrimRigth(string demilitor) {

		_Value = TrimRigth(_Value, demilitor);

	}

	void   Trim(string demilitor) {

		_Value = Trim(_Value, demilitor);

	}


	static char   InvertCaseOfCharchter(char letter) {

		return (isupper(letter) ? tolower(letter) : toupper(letter));

	}

	static string InvertCaseOfWord(string word) {

		for (short i = 0; i < word.length(); i++) {

			word[i] = InvertCaseOfCharchter(word[i]);

		}

		return word;

	}

	string InvertCaseOfWord() {

		return InvertCaseOfWord(_Value);

	}


	static string   ReversedWords(string name, string demilitor = " ") {

		vector <string> result;
		Spilt(name, demilitor, result);

		name.clear();

		for (short i = result.size() - 1; i >= 0; i--) {

			name += result.at(i);
			name += " ";

		}

		name.substr(0, name.length() - demilitor.length());

		return name;

	}

	void   ReversedWords(string demilitor = " ") {

		_Value = ReversedWords(_Value, demilitor);

	}


	static string ReturnChangeLettersCase(string name, bool upperOrLower) {

		for (short i = 0; i < name.length(); i++) {

			(upperOrLower == true ? name[i] = toupper(name[i]) : name[i] = tolower(name[i]));

		}

		return name;

	}

	string ReturnChangeLettersCase(bool upperOrLower) {

		return ReturnChangeLettersCase(_Value, upperOrLower);

	}


	static string   ReplaceWord(string name, string originalword, string newWord, bool caseSencetive = true) {

		vector <string> result;
		Spilt(name, " ", result);

		name.clear();

		for (short i = 0; i < result.size(); i++) {

			if ((ReturnChangeLettersCase(result.at(i), false) == ReturnChangeLettersCase(originalword, false)) && caseSencetive == false) {

				name += newWord;
				name += " ";

			}
			else if (result.at(i) == originalword) {

				name += newWord;
				name += " ";

			}
			else {
				name += result.at(i);
				name += " ";
			}

		}
		name.substr(0, name.length() - 1);

		return name;
	}

	void   ReplaceWord(string originalword, string newWord, bool caseSencetive = true) {

		_Value = ReplaceWord(_Value, originalword, newWord, caseSencetive);

	}



	static bool   IsFirstLetter(string name, short num) {

		if (num == 0)
			return true;
		else if (isspace(name[num]) && name[num + 1] != ' ')
			return true;

	}

	bool   IsFirstLetter(short num) {

		return IsFirstLetter(_Value, num);

	}

	// true == first letter is upper && false == first letter is lower.
	static string   ChangeEachFirstLetterCase(string name, bool upperOrLower) {

		for (short i = 0; i < name.length(); i++) {

			if (upperOrLower && i == 0) {

				name[i] = toupper(name[i]);

			}
			else if (upperOrLower == false && i == 0) {

				name[i] = tolower(name[i]);

			}
			else if (IsFirstLetter(name, i) && i != 0) {

				if (upperOrLower)
					name[i + 1] = toupper(name[i + 1]);
				else
					name[i + 1] = tolower(name[i + 1]);
			}

		}

		return name;

	}

	void   ChangeEachFirstLetterCase(bool upperOrLower) {

		_Value = ChangeEachFirstLetterCase(_Value, upperOrLower);

	}


	// true == all letter is upper && false == all letter is lower.
	static string   ChangeLettersCase(string name, bool upperOrLower) {

		for (short i = 0; i < name.length(); i++) {

			(upperOrLower == true ? name[i] = toupper(name[i]) : name[i] = tolower(name[i]));

		}

		return name;

	}

	void   ChangeLettersCase(bool upperOrLower) {

		_Value = ChangeLettersCase(_Value, upperOrLower);

	}


	enum enWhatIsLetter { _Capital = 0, _Small = 1, _Digit = 2, _Punctuetion = 3, _space = 4, _All = 5 };
	static int    CountDiffrentLetter(string name, enWhatIsLetter whatToCount = enWhatIsLetter::_All) {

		if (whatToCount == enWhatIsLetter::_All)
			return name.length();

		short counter = 0;

		for (short i = 0; i < name.length(); i++) {

			switch (whatToCount) {

			case enWhatIsLetter::_Capital:
				if (isupper(name[i]))
					counter++;
				break;

			case enWhatIsLetter::_Small:
				if (islower(name[i]))
					counter++;
				break;

			case enWhatIsLetter::_Digit:
				if (isdigit(name[i]))
					counter++;
				break;

			case enWhatIsLetter::_Punctuetion:
				if (ispunct(name[i]))
					counter++;
				break;

			case enWhatIsLetter::_space:
				if (name[i] == ' ')
					counter++;
				break;

			}

		}

		return counter;

	}

	int    CountDiffrentLetter(enWhatIsLetter whatToCount = enWhatIsLetter::_All) {

		return CountDiffrentLetter(_Value, whatToCount);

	}

	enum enCaseOrNot { Match = 0, Non_Match = 1 };
	static short  countLetter(string name, char letter, enCaseOrNot isMatch) {

		short count = 0;

		for (short i = 0; i < name.length(); i++) {

			if (isMatch == enCaseOrNot::Match) {
				if (toupper(name[i]) == toupper(letter))
					count++;
			}
			else {
				if (name[i] == letter)
					count++;
			}
		}

		return count;

	}

	short  countLetter(char letter, enCaseOrNot isMatch) {

		return countLetter(_Value, letter, isMatch);

	}


	static bool   IsVowel(char letter) {

		letter = tolower(letter);

		return (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u');

	}

	static short  CountVowels(string name) {

		short counter = 0;

		for (char& N : name) {

			if (IsVowel(N))
				counter++;

		}

		return counter;

	}
	short  CountVowels() {

		return CountVowels(_Value);

	}

	static void   PrintVowels(string name) {

		for (char& N : name) {

			if (IsVowel(N))
				cout << N << "  ";

		}

		cout << std::endl;

	}
	void  PrintVowels() {

		return PrintVowels(_Value);

	}


	static string JoinString(vector <string>& vWords, string demilitor, string shortDemilitor = " ", bool trimIt = true) {

		string fullWord = "";

		for (string& n : vWords) {

			if (fullWord == "") {

				if (trimIt)
					Trim(n, shortDemilitor);

				fullWord += n;
			}
			else {

				if (trimIt)
					Trim(n, shortDemilitor);

				fullWord += demilitor + n;
			}

		}

		return fullWord;

	}

	static string JoinString(string words[100], short lengthOfarray, string demilitor, string shortDemilitor = " ", bool trimIt = true) {

		string fullWord = "";

		for (short i = 0; i < lengthOfarray; i++) {

			if (trimIt)
				Trim(words[i], shortDemilitor);

			if (fullWord == "") {

				fullWord += words[i];

			}
			else {

				fullWord += demilitor + words[i];

			}

		}

		return fullWord;

	}


	static bool IsCase(char letter, enWhatIsLetter deleteElemente) {

		switch (deleteElemente) {

		case enWhatIsLetter::_Capital:
			return isupper(letter);

		case enWhatIsLetter::_Small:
			return islower(letter);

		case enWhatIsLetter::_All:
			return islower(letter) || isupper(letter);

		case enWhatIsLetter::_Digit:
			return isdigit(letter);

		case enWhatIsLetter::_Punctuetion:
			return ispunct(letter);

		}


	}

	static void  DeleteSpecifacLetterCase(string& word, enWhatIsLetter deleteElemente) {


		for (short i = 0; i < word.length(); i++) {

			if (IsCase(word[i], deleteElemente)) {
				word.erase(i, 1);
				i--;
			}

		}


	}

	void  DeleteSpecifacLetterCase(enWhatIsLetter deleteElemente) {

		return DeleteSpecifacLetterCase(_Value, deleteElemente);

	}




};