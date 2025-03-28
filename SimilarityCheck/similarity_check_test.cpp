#include "gmock/gmock.h"
#include "similarity_check.cpp"

using namespace testing;

class SimilarityCheckerFixture : public Test {
public:
	SimilarityChecker app;
};

TEST_F(SimilarityCheckerFixture, 빈문자열체크) {
	int expected = 100;
	int actual = app.checkSimilarity("", "");
	EXPECT_EQ(expected, actual);
}

TEST_F(SimilarityCheckerFixture, 0퍼센트유사도체크) {
	int expected = 0;
	int actual = app.checkSimilarity("", "A");
	EXPECT_EQ(expected, actual);
}

TEST_F(SimilarityCheckerFixture, 100퍼센트유사도체크) {
	int expected = 100;
	int actual = app.checkSimilarity("ABC", "ABC");
	EXPECT_EQ(expected, actual);
}

TEST_F(SimilarityCheckerFixture, 글자수검사하기) {
	int expected = 60;
	int actual = app.checkSimilarity("ABC", "DEF");
	EXPECT_EQ(expected, actual);
}

TEST_F(SimilarityCheckerFixture, 부분글자수검사하기1) {
	int expected = 20;
	int actual = app.checkSimilarity("AAABB", "BAA");
	EXPECT_EQ(expected, actual);
}

TEST_F(SimilarityCheckerFixture, 부분글자수검사하기2) {
	int expected = 30;
	int actual = app.checkSimilarity("AA", "AAE");
	EXPECT_EQ(expected, actual);
}

TEST_F(SimilarityCheckerFixture, 2배글자수검사하기1) {
	int expected = 0;
	int actual = app.checkSimilarity("ABCDEF", "GHI");
	EXPECT_EQ(expected, actual);
}

TEST_F(SimilarityCheckerFixture, 2배글자수검사하기2) {
	int expected = 0;
	int actual = app.checkSimilarity("ABC", "DEFGHI");
	EXPECT_EQ(expected, actual);
}

TEST_F(SimilarityCheckerFixture, CheckAlphabetTC1) {
	int expected = 0;
	int actual = app.checkAlphabetSimilarity("ABC", "DEFGHI");
	EXPECT_EQ(expected, actual);
}

TEST_F(SimilarityCheckerFixture, CheckAlphabetTC2) {
	int expected = 40;
	int actual = app.checkAlphabetSimilarity("ASD", "DSA");
	EXPECT_EQ(expected, actual);
}

TEST_F(SimilarityCheckerFixture, CheckAlphabetTC3) {
	int expected = 0;
	int actual = app.checkAlphabetSimilarity("A", "BB");
	EXPECT_EQ(expected, actual);
}

TEST_F(SimilarityCheckerFixture, CheckAlphabetTC4) {
	int expected = 20;
	int actual = app.checkAlphabetSimilarity("AA", "AAE");
	EXPECT_EQ(expected, actual);
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}