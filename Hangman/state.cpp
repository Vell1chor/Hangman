#include "state.hpp"

namespace hangman {

	int hangman::Logic::getDifficulty(std::string& difficulty) {
		int maxmistakes = 9;
		if (difficulty == "HARD") {
			maxmistakes = 6;
		}
		return maxmistakes;
	}

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

	void RemoveWhitespace(std::string& mysteryword, std::string& guess) {
		for (char c : mysteryword) {
			if (!std::isspace(static_cast<unsigned char>(c))) {
				guess += c;
			}
		}
	}

	std::string ClueStatus(std::string const mysteryword, std::string& guess, std::string clue) {
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
		}

		if (!guess.empty()) {
			guess.erase(0, 1);
		}

		return clue;
	}
}