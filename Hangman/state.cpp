#include "state.hpp"

namespace hangman {

	int hangman::Logic::MistakeCount(int mistakes, std::string const& guess, std::string const& mysteryword, bool& error) {
		if (mysteryword.find(guess) == std::string::npos) {
			mistakes++;
			error = true;
		}
		else {
			error = false;
		}
		return mistakes;
	}

	std::string hangman::Logic::WrongLetters(std::string const& guess, std::string wrongletters) {
		return wrongletters += guess;
	}

	std::string hangman::Logic::ClueStatus(std::string const mysteryword, std::string& guess, std::string clue) {
		char g = guess[0];
		int i = -1;
		for (char c : mysteryword) {
			i++;
			char vnub = '-';
			if (c == g) {
				vnub = g;
			}
			if (clue[i] == '-') {
				clue[i] = vnub;
			}
			/*else {
				break;
			}*/
		}

		if (!guess.empty()) {
			guess.erase(0, 1);
		}

		return clue;
	}
}