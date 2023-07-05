#include "pch.h"
#include "../Project2/baseball.cpp"

TEST(TestSuiteBase, AlwaysPass)
{
	EXPECT_EQ(1, 1);
}

class BaseballTexture : public testing::Test
{
public:
	BaseBall game;
	void assertIllegalArgument(string guessNumber)
	{
		try
		{
			game.guess(guessNumber);
			FAIL();
		}
		catch (exception e) {}	// PASS
	}
};


TEST_F(BaseballTexture, ThrowExceptionWhenInvalidCase)
{
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
	assertIllegalArgument("1s2");
	assertIllegalArgument("s12");
	assertIllegalArgument("121");
}
