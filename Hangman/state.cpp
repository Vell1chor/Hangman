#include "state.hpp"
#include <algorithm>

namespace hangman {

	int Logic::MistakeCount(std::string const& guess, std::string const& mysteryword, bool& printwrong,
		int mistakecount, bool easyset, std::string wrongletters, std::string clue) {
		char g = guess[0];
		if (mysteryword.find(g) == std::string::npos) {
			mistakecount++;
			printwrong = true;
			if (easyset && wrongletters.find(g) != std::string::npos) {
				mistakecount--;
			}
		}
		else if (!easyset && clue.find(g) != std::string::npos) {
			mistakecount++;
		}
		return mistakecount;
	}

	std::string Logic::WrongLetters(const std::string& guess, std::string wrongletters) {
		if (wrongletters.find(guess) == std::string::npos) {
			wrongletters += guess;
		}
		std::sort(wrongletters.begin(), wrongletters.end());
		return wrongletters;
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