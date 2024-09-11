#pragma once

#include <iostream>
#include <string>
#include <cstdio>
#include "readInput.h"
#include <iomanip>

using std::cout;
using std::cin;
using std::string;

int  randomNumbers(int, int);
int CalculatorMatrices(int, int, char);
void  CopyArray(int arr[3], int clearArr[3]);

namespace mat {

	void  FillMatrixWithRandomNumbers(int matrix[3][3], int from = 1, int to = 100, int row = 3, int col = 3) {

		for (short i = 0; i < row; i++) {

			for (short j = 0; j < col; j++) {

				matrix[i][j] = randomNumbers(from, to);

			}

		}

	}

	void  FillMatrixWithOrderNumbers(int matrix[3][3], int from = 1, int row = 3, int col = 3) {

		short begin = from;

		for (short i = 0; i < row; i++) {

			for (short j = 0; j < col; j++) {

				matrix[i][j] = begin;
				begin++;

			}

		}

	}


	void  PrintMatrix(int matrix[3][3], int row = 3, int col = 3) {

		for (short i = 0; i < row; i++) {

			for (short j = 0; j < col; j++) {

				cout << std::setw(3) << matrix[i][j] << "  ";

			}

			cout << '\n';

		}

		cout << std::endl;

	}
	

	void  SumRow(int matrix[3][3], int result[3], int row = 3, int col = 3) {

		int clearArr[] = { 0,0,0 };

		for (short i = 0; i < row; i++) {

			for (short j = 0; j < col; j++) {

				clearArr[i] += matrix[i][j];

			}

		}

		CopyArray(result, clearArr);

	}

	void  SumCol(int matrix[3][3], int result[3], int row = 3, int col = 3) {

		int clearArr[] = { 0,0,0 };

		for (short i = 0; i < row; i++) {

			for (short j = 0; j < col; j++) {

				clearArr[i] += matrix[j][i];

			}

		}

		CopyArray(result, clearArr);

	}

	void  PrintArray(string message, int result[3]) {

		for (short i = 0; i < 3; i++) {

			cout << message << (i + 1) << " Is: " << result[i] << '\n';

		}

		cout << std::endl;

	}


	void transposMatrix(int matrix[3][3]) {

		for (short i = 0; i < 3; i++) {

			for (short j = 0; j < 3; j++) {

				if (i < j && i != j)
					std::swap(matrix[i][j], matrix[j][i]);

			}

		}


	}

	bool IsIdentityMatrix(int matrix[3][3]) {

		for (short i = 0; i < 3; i++) {

			for (short j = 0; j < 3; j++) {

				if (i == j && matrix[i][j] != 1)
					return 0;
				else if (i != j && matrix[i][j] != 0)
					return 0;

			}

		}

		return 1;

	}

	bool IsScalarMatrix(int matrix[3][3]) {

		for (short i = 0; i < 3; i++) {

			for (short j = 0; j < 3; j++) {

				if (i == j && matrix[i][j] != matrix[0][0])
					return 0;
				else if (i != j && matrix[i][j] != 0)
					return 0;

			}

		}

		return 1;

	}

	bool IsPalindromeMatrix(int matrix[3][3], int row, int col) {

		for (short i = 0; i < row; i++) {

			if (matrix[i][0] != matrix[i][col - 1])
				return false;
		}

		return true;

	}


	void CalcMatrices(int matrix1[3][3], int matrix2[3][3], int newMatrix[3][3], char op) {

		for (short i = 0; i < 3; i++) {

			for (short j = 0; j < 3; j++) {

				newMatrix[i][j] = CalculatorMatrices(matrix1[i][j], matrix2[i][j], op);

			}

		}

	}

	int Sum(int matrix[3][3]) {

		int result = 0;

		for (short i = 0; i < 3; i++) {

			for (short j = 0; j < 3; j++) {

				result = CalculatorMatrices(result, matrix[i][j], '+');

			}

		}

		return result;

	}


	int middelRow(int matrix[3][3], int num) {

		short middel = 3 / 2;

		for (short i = 0; i < 3; i++) {

			for (short j = num; j < 3; j++) {

				return matrix[middel][j];

			}

		}

	}

	int middelCol(int matrix[3][3], int num) {

		short middel = 3 / 2;

		for (short i = num; i < 3; i++) {

			for (short j = 0; j < 3; j++) {

				return matrix[i][middel];

			}

		}

	}

	void PrintMiddelOfRow(int matrix[3][3]) {

		for (short i = 0; i < 3; i++) {

			std::printf("%02d  ", middelRow(matrix, i));

		}

		std::cout << '\n';

	}

	void PrintMiddelOfCol(int matrix[3][3]) {

		for (short i = 0; i < 3; i++) {

			std::printf("%02d \n", middelCol(matrix, i));

		}

		std::cout << '\n';

	}



}

int  randomNumbers(int from, int to) {

	int number = rand() % (to - from + 1) + from;

	return number;

}

int CalculatorMatrices(int matrix1, int matrix2, char op) {

		switch (op) {

		case '+':
			return matrix1 + matrix2;

		case '*':
			return matrix1 * matrix2;

		case '-':
			return matrix1 - matrix2;

		case '/':
			return matrix1 / matrix2;

		default:
			return matrix1 + matrix2;

		}

}

void  CopyArray(int arr[3], int clearArr[3]) {

	for (short i = 0; i < 3; i++) {

		arr[i] = clearArr[i];

	}

}
