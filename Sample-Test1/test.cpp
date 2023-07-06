#include "pch.h"
#include "../Project2/baseball.cpp"

TEST(TestSuiteBase, AlwaysPass)
{
	EXPECT_EQ(1, 1);
}

class BaseballTexture : public testing::Test
{
public:
	BaseBall game{"123"};
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

TEST_F(BaseballTexture, ReturnSolvedResultIfMatchedNumber)
{
	GuessResult result = game.guess("123");

	EXPECT_TRUE(result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballTexture, Return2Strikes0Ball)
{
	GuessResult result;

	result = game.guess("129");
	EXPECT_EQ(false, result.solved);
	EXPECT_EQ(2, result.strikes);
	EXPECT_EQ(0, result.balls);

	result = game.guess("923");
	EXPECT_EQ(false, result.solved);
	EXPECT_EQ(2, result.strikes);
	EXPECT_EQ(0, result.balls);

	result = game.guess("193");
	EXPECT_EQ(false, result.solved);
	EXPECT_EQ(2, result.strikes);
	EXPECT_EQ(0, result.balls);
}
