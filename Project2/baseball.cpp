#include <iostream>
#include <stdexcept>

using namespace std;

class BaseBall
{
public:
	bool isDuplicatedNumber(const string& guessNumber)
	{
		return (guessNumber[0] == guessNumber[1])
			|| (guessNumber[0] == guessNumber[2])
			|| (guessNumber[1] == guessNumber[2]);
	}

	void assertIllegalArgument(const string& guessNumber)
	{
		if (guessNumber.length() != 3)
		{
			throw length_error("Must be three letters.");
		}

		for (char ch : guessNumber)
		{
			if (('0' <= ch) && (ch <= '9')) continue;
			throw invalid_argument("Must be number.");
		}

		if (isDuplicatedNumber(guessNumber))
		{
			throw invalid_argument("Must not have same number");
		}
	}

	void guess(const string& guessNumber)
	{
		assertIllegalArgument(guessNumber);
	}
};
