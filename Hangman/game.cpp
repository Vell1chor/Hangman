#include "game.hpp"
#include <string>

void hangman::HangmanStart() {

	std::string clue;
	std::string wrongletters;
	std::string guess;
	std::string mysteryword;
	std::string difficulty;
	int mistakes = 0;
	int maxmistakes = 9;
	int mistakecount = 0;
	bool done = false;
	bool printwrong = false;
	bool win = false;
	bool error = false;

	io::Difficulty(difficulty);
	mysteryword = io::MysteryWord();
	maxmistakes = hangman::getDifficulty(difficulty);
	io::GameStart(maxmistakes, mysteryword);

	mistakecount = hangman::MistakeCount(mistakes,guess,mysteryword,error);

	if (error == true) {
		std::string WrongLetters(bool error, std::string const& guess, std::string wrongletters);
	}
	else {
		hangman::ClueStatus(mysteryword, guess, clue);
	}

	while (!done) {
		io::RetrieveGuess(guess);
		hangman::RemoveWhitespace(mysteryword, guess);
		hangman::ClueStatus(mysteryword, guess, clue);

		io::Status(guess, clue, wrongletters, mistakes, maxmistakes, printwrong);

		if (guess == mysteryword) {
			done = true;
			win = true;
		}
	}

	io::EndResult(win, mysteryword);
}