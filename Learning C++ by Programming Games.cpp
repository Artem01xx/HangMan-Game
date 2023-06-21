
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;



// HangMan Game
int main()
{
	srand(time(NULL));
	const int MAX_WRONG = 8;
	vector<string> words;
	words.push_back("GUESS");
	words.push_back("HANGMAN");
	words.push_back("DIFFICULT");

	random_shuffle(words.begin(), words.end());

	const string THE_WORD = words[0];
	int wrong = 0;
	string soFar(THE_WORD.size(), '-');
	string used = "";

	cout << " Welcome to Hangman , GoodLuck " << endl;

	while (wrong < MAX_WRONG && soFar != THE_WORD)
	{
		cout << " You Have " << (MAX_WRONG - wrong);
		cout << " Incorected Guesses Left " << endl;
		cout << " You used the following letters " << used << endl;
		cout << " so Far the word is " << soFar << endl;



		char guess;
		cout << " Enter Your Guess " << endl;
		cin >> guess;

		guess = toupper(guess);

		while (used.find(guess) != string::npos)
		{
			cout << " Youve AllRedy Guessed " << endl;
			cout << " Enter your guess " << endl;
			cin >> guess;
			guess = toupper(guess);
		}

		used += guess;

		if (THE_WORD.find(guess) != string::npos)
		{
			cout << " Thats Right ! " << guess << " Is the Word " << endl;

			for (int i = 0;i < THE_WORD.length(); ++i)
			{
				if (THE_WORD[i] == guess)
				{
					soFar[i] = guess;
				}
			}
		}
		else
		{
			cout << " Sorry , " << guess << " isnt in the word " << endl;
			++wrong;
		}
	}
			
	
	if (wrong == MAX_WRONG)
	{
		cout << " Youve Been Hanged " << endl;
	}
    
	else
	{
		cout << " You guessed it " << endl;
	}

	cout << " The Word Was " << THE_WORD << endl;

	return 0;
}