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