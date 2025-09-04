#include "game.hpp"
#include <string>

void hangman::HangmanStart() {

	std::string clue;
	std::string WrongLetters;
	std::string guess;
	std::string mysteryword;
	std::string difficulty;
	int Mistakes = 0;
	int MaxMistakes = 9;
	int mistakecount = 0;
	bool done = false;
	bool printwrong = false;
	bool win = false;
	bool error = false;

	io::Difficulty(difficulty);
	io::MysteryWord(mysteryword);
	MaxMistakes = hangman::getDifficulty(difficulty);
	io::GameStart(MaxMistakes, mysteryword);

	mistakecount = hangman::MistakeCount(Mistakes,guess,mysteryword,error);

	if (error == true) {
		std::string WrongLetters(bool error, std::string const& guess, std::string wrongletters);
	}
	else std::string ClueStatus(mysteryword, guess, clue);

	while (!done) {
		io::RetrieveGuess(guess);
		hangman::RemoveWhitespace(mysteryword, guess);
		io::Status(guess, clue, WrongLetters, Mistakes, MaxMistakes, printwrong);

		if (guess == mysteryword) {
			done = true;
			win = true;
		}
	}

	io::EndResult(win, mysteryword);
}