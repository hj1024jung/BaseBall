#include "pch.h"
#include "../Project2/baseball.cpp"

TEST(TestSuiteBase, AlwaysPass)
{
	EXPECT_EQ(1, 1);
}

TEST(TestBaseballGame, ThrowExceptionWhenInputLengthIsUnmatched)
{
	BaseBall game;
	EXPECT_THROW(game.guess(string("12")), length_error);
}

TEST(TestBaseballGame, ThrowExceptionWhenInvalidChar)
{
	BaseBall game;

	try
	{
		game.guess(string("12s"));
		FAIL();
	}
	catch (exception e) {}
	try
	{
		game.guess(string("1s2"));
		FAIL();
	}
	catch (exception e) {}
	try
	{
		game.guess(string("s12"));
		FAIL();
	}
	catch (exception e) {}
}