#pragma once

#include <iostream>
#include <string>
#include "clsDate.h"

using namespace std;

class clsUtil {

public:


	static void Srand() {

		srand((unsigned)time(NULL));

	}

	
	static int  RandomNumber(int from, int to) {

		int number = rand() % (to - from + 1) + from;

		return number;

	}


	static enum enRandomWhat { enSmallLetter = 0, enCapitalLetter = 1, enDigit = 2, enSpecailCharacter = 3, enMIX = 4 };

	static char  RandomCharacter(enRandomWhat whatRandom) {

		if (whatRandom == enRandomWhat::enMIX)
			whatRandom = (enRandomWhat)RandomNumber(0, 2);

		switch (whatRandom) {

		case enRandomWhat::enSmallLetter:
			return  char(RandomNumber(97, 122));

		case enRandomWhat::enCapitalLetter:
			return char(RandomNumber(65, 90));

		case enRandomWhat::enDigit:
			return  RandomNumber(1, 10) + '0';

		case enRandomWhat::enSpecailCharacter:
			return  char(RandomNumber(33, 47));
		
		}

	}

	static string GeneratingRandomWord(int manyOfLetter, enRandomWhat whatRandom) {

		string key = "";

		for (int i = 0; i < manyOfLetter; i++) {

			key += RandomCharacter(whatRandom);

		}

		return key;

	}

	static string GenerateUniqueKey(int manyOfLetter, int lengthOfKey, enRandomWhat whatRandom) {

		std::string key = "";

		for (int i = 1; i <= lengthOfKey; i++) {

			if (i != lengthOfKey)
				key += GeneratingRandomWord(manyOfLetter, whatRandom) + "_";
			else
				key += GeneratingRandomWord(manyOfLetter, whatRandom);

		}

		return key;

	}



	static void FillArrayWithRandomNumber(int form, int to, int arr[100], int lengthOfArray) {

		for (int i = 0; i < lengthOfArray; i++) {

			arr[i] = RandomNumber(form, to);

		}

	}

	static void PrintArray(int arr[100], int lengthOfArray) {

		for (short i = 0; i < lengthOfArray; i++) {

			cout << arr[i] << ' ';

		}

	}

	static int MaxNumberOfArrray(int arr[100], int lengthOfArray) {

		int pivot = arr[0];

		for (int i = 1; i < lengthOfArray; i++) {

			if (arr[i] > pivot)
				pivot = arr[i];

		}

		return pivot;

	}

	static int MinNumberOfArrray(int arr[100], int lengthOfArray) {

		int pivot = arr[0];

		for (int i = 1; i < lengthOfArray; i++) {

			if (arr[i] < pivot)
				pivot = arr[i];

		}

		return pivot;

	}

	static int GetSumOfAllElementsInArray(int arr[100], int lengthOfArray) {

		int sum = 0;

		for (int i = 0; i < lengthOfArray; i++) {

			sum += arr[i];

		}

		return sum;

	}



	static void Swap(int& numberOne, int& numberTwo) {

		int temp = 0;

		temp = numberOne;
		numberOne = numberTwo;
		numberTwo = temp;

	}

	static void Swap(float& numberOne, float& numberTwo) {

		float temp = 0.0f;

		temp = numberOne;
		numberOne = numberTwo;
		numberTwo = temp;

	}

	static void Swap(double& numberOne, double& numberTwo) {

		double temp = 0.0;

		temp = numberOne;
		numberOne = numberTwo;
		numberTwo = temp;

	}

	static void Swap(string& textOne, string& textTwo) {

		string temp = "";

		temp = textOne;
		textOne = textTwo;
		textTwo = temp;

	}

	static void Swap(clsDate& date1, clsDate& date2) {

		clsDate temp;

		temp = date1;
		date1 = date2;
		date2 = temp;

	}


	static string getNameAfterEncrption(string name) {

		int size = name.size();
		string randomName = "";

		for (int i = 0; i < size; i++) {

			if (int(name[i]) >= 90 && int(name[i]) >= 122)
				randomName += char(int(name[i]) - 2);
			else
				randomName += char(int(name[i]) + 2);

		}

		return randomName;

	}

	static string getNameAfterDecrption(string name) {

		int size = name.size();
		string randomName = "";

		for (int i = 0; i < size; i++) {

			if (int(name[i]) > 90 && int(name[i]) > 122)
				randomName += char(int(name[i]) + 2);
			else
				randomName += char(int(name[i]) - 2);

		}

		return randomName;

	}


	static string NumberToText(int number) {


		if (number == 0) {

			return "";

		}

		if (number >= 1 && number <= 19) {

			string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
							 "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
							 "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

			return  arr[number] + " ";

		}

		if (number >= 20 && number <= 99) {

			string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };

			return  arr[number / 10] + " " + NumberToText(number % 10);

		}

		if (number >= 100 && number <= 199) {

			return "One Hundred " + NumberToText(number % 100);

		}

		if (number >= 200 && number <= 999) {

			return   NumberToText(number / 100) + "Hundreds " + NumberToText(number % 100);

		}

		if (number >= 1000 && number <= 1999) {

			return "One Thousand " + NumberToText(number % 1000);

		}

		if (number >= 2000 && number <= 999999) {

			return   NumberToText(number / 1000) + "Thousand  " + NumberToText(number % 1000);

		}


		if (number >= 1000000 && number <= 1999999) {

			return"One Million " + NumberToText(number % 1000000);

		}

		if (number >= 2000000 && number <= 999999999) {

			return   NumberToText(number / 1000000) + "Millions " + NumberToText(number % 1000000);

		}

		if (number >= 1000000000 && number <= 1999999999) {

			return"One Billion " + NumberToText(number % 1000000000);

		}
		else {

			return   NumberToText(number / 1000000000) + "Billions " + NumberToText(number % 1000000000);

		}

	}

};

