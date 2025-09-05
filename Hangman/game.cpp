#include "game.hpp"
#include <string>

void hangman::HangmanStart() {
	Logic logic;
	std::string wrongletters;
	std::string guess;
	std::string mysteryword;
	std::string difficulty;
	logic.maxmistakes;
	int mistakecount = 0;
	bool done = false;
	bool printwrong = false;
	bool win = false;
	bool easyset = false;

	io::Difficulty(difficulty);
	logic.maxmistakes = io::IntoDifficulty(difficulty, logic.maxmistakes);
	mysteryword = io::MysteryWord(); \
	std::string clue(mysteryword.size(), '_');
	io::GameStart(logic.maxmistakes, mysteryword);

	while (!done) {
		io::RetrieveGuess(guess); 
		io::RemoveWhitespace(guess); 

		mistakecount = logic.MistakeCount(guess, mysteryword, printwrong, mistakecount);
		

		clue = logic.ClueStatus(mysteryword, guess, clue);

		bool switcher = false;
		if (printwrong == true) {
			switcher = true;
		}

		if (switcher == true) {
			wrongletters = logic.WrongLetters(guess, wrongletters);
		}
		else {
			logic.ClueStatus(mysteryword, guess, clue);
		}

		io::Status(guess, clue, wrongletters, mistakecount, logic.maxmistakes, printwrong);
		if (clue == mysteryword) {
			done = true;
			win = true;
		}
		if (mistakecount == logic.maxmistakes) {
			done = true;
		}
		printwrong == false;
	}

	io::EndResult(win, mysteryword);
}