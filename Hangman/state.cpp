#include "state.hpp"

namespace hangman {

	int Logic::MistakeCount(std::string const& guess, std::string const& mysteryword, bool& printwrong, int mistakes) {
		if (mysteryword.find(guess) != std::string::npos) {
			mistakes++;
			printwrong = true;
		}
		return mistakes;
	}

	std::string Logic::WrongLetters(const std::string& guess, std::string wrongletters) {
		return wrongletters += guess;
	}

	std::string Logic::ClueStatus(std::string const mysteryword, std::string& guess, std::string clue) {
		char g = guess[0];
		int cpos = 0;
		for (char c : mysteryword) {
			if (c == g) {
				clue[cpos] = g;
			}
			cpos++;
		}
		return clue;
	}
}