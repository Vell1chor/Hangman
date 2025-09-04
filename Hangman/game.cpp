#include "game.hpp"
#include <string>

void hangman::HangmanStart() {
	Logic logic;
	std::string clue;
	std::string wrongletters;
	std::string guess;
	std::string mysteryword;
	std::string difficulty;
	int mistakes = 0;
	logic.maxmistakes;
	int mistakecount = 0;
	bool done = false;
	bool printwrong = false;
	bool win = false;
	bool error = false;

	io::Difficulty(difficulty);
	mysteryword = io::MysteryWord();
	logic.maxmistakes = io::IntoDifficulty(difficulty);
	io::GameStart(logic.maxmistakes, mysteryword);

	mistakecount = logic.MistakeCount(mistakes,guess,mysteryword,error);

	while (!done) {
		io::RetrieveGuess(guess);
		io::RemoveWhitespace(mysteryword, guess);
		
		if (error == true) {
			std::string WrongLetters(bool error, std::string const& guess, std::string wrongletters);
		}
		else {
			logic.ClueStatus(mysteryword, guess, clue);
		}

		io::Status(guess, clue, wrongletters, mistakes, logic.maxmistakes, printwrong);

		if (guess == mysteryword) {
			done = true;
			win = true;
		}
	}

	io::EndResult(win, mysteryword);
}