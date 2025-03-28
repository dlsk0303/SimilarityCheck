﻿#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;

#define MAX_ALPHABET 26

class SimilarityChecker {
public:
	int checkAlphabetSimilarity(std::string inputStr1, std::string inputStr2) {
		bool alphabetCheckOfStr1[MAX_ALPHABET+1] = {false, };
		bool alphabetCheckOfStr2[MAX_ALPHABET+1] = {false, };

		int lenOfStr1 = inputStr1.length();
		int lenOfStr2 = inputStr2.length();

		if (lenOfStr1 == 0 || lenOfStr2 == 0) {
			return 0;
		}
		cout << lenOfStr1 << " " << lenOfStr2 << "\n";

		for (int i = 0; i < lenOfStr1; i++) {
			alphabetCheckOfStr1[inputStr1[i] - 'A'] = true;
		}
		for (int i = 0; i < lenOfStr2; i++) {
			alphabetCheckOfStr2[inputStr2[i] - 'A'] = true;
		}

		int sameCnt = 0;
		int totalCnt = 0;
		for (int i = 0; i < MAX_ALPHABET; i++) {
			if (alphabetCheckOfStr1[i] && alphabetCheckOfStr2[i]) {
				sameCnt++;
				totalCnt++;
			}

			else if (alphabetCheckOfStr1[i]) {
				totalCnt++;
			}
			else if (alphabetCheckOfStr2[i]) {
				totalCnt++;
			}
		}
		cout << totalCnt << " " << sameCnt << "\n";

		return sameCnt * MAX_ALPHABET_SCORE / totalCnt;
	}

	int checkSimilarity(std::string inputStr1, std::string inputStr2) {
		if (inputStr1 == inputStr2) {
			return MAX_SCORE;
		}
		return getLengthSimilarityScore(inputStr1, inputStr2);
	}

	int getLengthSimilarityScore(const std::string& inputStr1, const std::string& inputStr2)
	{
		// 글자수 얻기
		int sizeofStr1 = inputStr1.length();
		int sizeofStr2 = inputStr2.length();
		if (sizeofStr1 == 0 || sizeofStr2 == 0) {
			return 0;
		}

		if (sizeofStr1 == sizeofStr2)
		{
			return 	MAX_LENGTH_SCORE;
		}

		if (sizeofStr1 >= sizeofStr2) {
			return calculatePartialScore(sizeofStr1, sizeofStr2);
		}

		return calculatePartialScore(sizeofStr2, sizeofStr1);
	}

	int calculatePartialScore(int longStr, int shortStr)
	{
		int gap = longStr - shortStr;
		return (MAX_LENGTH_SCORE - (MAX_LENGTH_SCORE * gap / shortStr));
	}

private:
	const int MAX_SCORE = 100;
	const int MAX_LENGTH_SCORE = 60;
	const int MAX_ALPHABET_SCORE = 40;

};