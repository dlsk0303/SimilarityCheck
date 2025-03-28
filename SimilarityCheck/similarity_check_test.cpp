#include "gmock/gmock.h"
#include "similarity_check.cpp"

using namespace testing;

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}