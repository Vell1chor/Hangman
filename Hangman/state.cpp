#include "state.hpp"

namespace hangman {

	int hangman::Logic::getDifficulty(std::string& difficulty) {
		int MaxMistakes = 9;
		if (difficulty == "HARD") {
			MaxMistakes = 6;
		}
		return MaxMistakes;
	}

	int hangman::Logic::MistakeCount(int Mistakes, std::string const& guess, std::string const& mysteryword, bool& error) {
		if (mysteryword.find(guess) == std::string::npos) {
			Mistakes++;
			error = true;
		}
		else {
			error = false;
		}
		return Mistakes;
	}

	std::string hangman::Logic::WrongLetters(std::string const& guess, std::string wrongletters) {
		return wrongletters += guess;
	}

	std::string RemoveWhitespace(std::string& mysteryword, std::string& guess) {
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

		std::string trassssh;
		for (char c : guess) {
			trassssh += c;
		}
		guess = trassssh;
		return clue;
	}
}