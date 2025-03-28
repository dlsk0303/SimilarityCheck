#include <string>

class SimilarityChecker {
public:
	int checkSimilarity(std::string inputStr1, std::string inputStr2) {
		if (inputStr1 == inputStr2) {
			return MAX_SCORE;
		}
		return getLengthSimilarityScore(inputStr1, inputStr2);
	}

	int getLengthSimilarityScore(const std::string& inputStr1, const std::string& inputStr2)
	{
		// 글자수 얻기
		int sizeofStr1 = inputStr1.size();
		int sizeofStr2 = inputStr2.size();
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