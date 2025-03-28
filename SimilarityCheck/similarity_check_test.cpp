#include "gmock/gmock.h"
#include "similarity_check.cpp"

using namespace testing;

class SimilarityCheckerFixture : public Test {
public:
	SimilarityChecker app;
};

TEST_F(SimilarityCheckerFixture, ���ڿ�üũ) {
	int expected = 100;
	int actual = app.checkSimilarity("", "");
	EXPECT_EQ(expected, actual);
}

TEST_F(SimilarityCheckerFixture, 0�ۼ�Ʈ���絵üũ) {
	int expected = 0;
	int actual = app.checkSimilarity("", "A");
	EXPECT_EQ(expected, actual);
}

TEST_F(SimilarityCheckerFixture, 100�ۼ�Ʈ���絵üũ) {
	int expected = 100;
	int actual = app.checkSimilarity("ABC", "ABC");
	EXPECT_EQ(expected, actual);
}

TEST_F(SimilarityCheckerFixture, ���ڼ��˻��ϱ�) {
	int expected = 60;
	int actual = app.checkSimilarity("ABC", "DEF");
	EXPECT_EQ(expected, actual);
}

TEST_F(SimilarityCheckerFixture, �κб��ڼ��˻��ϱ�1) {
	int expected = 20;
	int actual = app.checkSimilarity("AAABB", "BAA");
	EXPECT_EQ(expected, actual);
}

TEST_F(SimilarityCheckerFixture, �κб��ڼ��˻��ϱ�2) {
	int expected = 30;
	int actual = app.checkSimilarity("AA", "AAE");
	EXPECT_EQ(expected, actual);
}

TEST_F(SimilarityCheckerFixture, 2����ڼ��˻��ϱ�1) {
	int expected = 0;
	int actual = app.checkSimilarity("ABCDEF", "GHI");
	EXPECT_EQ(expected, actual);
}

TEST_F(SimilarityCheckerFixture, 2����ڼ��˻��ϱ�2) {
	int expected = 0;
	int actual = app.checkSimilarity("ABC", "DEFGHI");
	EXPECT_EQ(expected, actual);
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}