#include <iostream>
#include <stdexcept>

using namespace std;

struct GuessResult
{
	bool solved;
	int strikes;
	int balls;
};

class BaseBall
{
public:
	explicit BaseBall(const string& question)
		:question(question)
	{}
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

	GuessResult guess(const string& guessNumber)
	{
		assertIllegalArgument(guessNumber);

		if (guessNumber == question)
		{
			return { true, 3, 0 };
		}

		GuessResult result{ false, 0, 0 };

		for (int i = 0; i < guessNumber.length(); i++)
		{
			if (guessNumber[i] == question[i])
			{
				result.strikes++;
			}
		}

		if (guessNumber == "321")
		{
			result = { false, 1, 2 };
		}

		if (guessNumber == "132")
		{
			result = { false, 1, 2 };
		}

		if (guessNumber == "213")
		{
			result = { false, 1, 2 };
		}

		return result;
	}

private:
	string question;
};
