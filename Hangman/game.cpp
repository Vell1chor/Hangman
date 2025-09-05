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
	bool switcher = false;

	io::Difficulty(difficulty);
	logic.maxmistakes = io::IntoDifficulty(difficulty, logic.maxmistakes, easyset);
	mysteryword = io::MysteryWord();
	std::string clue(mysteryword.size(), '_');
	io::GameStart(logic.maxmistakes, mysteryword);

	while (!done) {
		io::RetrieveGuess(guess); 
		io::RemoveWhitespace(guess); 
		mistakecount = logic.MistakeCount(guess, mysteryword, printwrong, mistakecount, easyset, wrongletters);
		clue = logic.ClueStatus(mysteryword, guess, clue);

		if (printwrong == true) {
			switcher = true;
		}

		if (printwrong == true) {
			wrongletters = logic.WrongLetters(guess, wrongletters);
		}
		else {
			logic.ClueStatus(mysteryword, guess, clue);
		}

		if (clue == mysteryword) {
			done = true;
			win = true;
			break;
		}
		
		if (mistakecount == logic.maxmistakes) {
			done = true;
			break;
		}

		io::Status(guess, clue, wrongletters, mistakecount, logic.maxmistakes, switcher);

		printwrong = false;
	}
	io::EndResult(win, mysteryword, guess);
}
//write alphabetical wrongletters
//write that if clue.find(guess) == std::string npos; then it is an error
