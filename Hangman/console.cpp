#include "console.hpp"

namespace io {

	void Difficulty(std::string& difficulty) {
		std::cin >> difficulty;
		for (char& c : difficulty) {
			c = std::toupper(static_cast<unsigned char>(c));
		}
	}

	int IntoDifficulty(std::string& difficulty) {
		int maxmistakes = 9;
		if (difficulty == "HARD") {
			maxmistakes = 6;
		}
		return maxmistakes;
	}

	std::string MysteryWord() {
		std::string mysteryword;
		std::cin >> mysteryword;
		for (char& c : mysteryword) {
			c = std::toupper(static_cast<unsigned char>(c));
		}
		return mysteryword;
	}

	void RetrieveGuess(std::string& guess) {
		std::getline(std::cin, guess);
		for (char& c : guess) {
			c = std::toupper(static_cast<unsigned char>(c));
		}
	}

	void RemoveWhitespace(std::string& mysteryword, std::string& guess) {
		for (char c : mysteryword) {
			if (!std::isspace(static_cast<unsigned char>(c))) {
				guess += c;
			}
		}
	}

	void GameStart(int maxmistakes, std::string mysteryword) {
		std::cout << "Hangman" << std::endl << "-------" << std::endl << std::endl;
		std::cout << "Mistakes: 0/" << maxmistakes << std::endl << "Clue:     ";
		for (int i = 0; i < mysteryword.length(); ++i) {
			std::cout << '_';
		}
		std::cout << std::endl << std::endl;
	}

	void Status(std::string& guess, std::string& clue, std::string& wrongletters,
		int mistakes, int maxmistakes, bool printwrong) {
		std::cout << "Guess: " << guess << std::endl << std::endl;
		std::cout << "Mistakes: " << mistakes << "/" << maxmistakes << std::endl;
		std::cout << "Clue:     " << clue << std::endl;

		if (printwrong) {
			std::cout << "Wrong:    " << wrongletters << std::endl << std::endl;
		} else {
			std::cout << std::endl;
		}
	}

	void EndResult(bool win, std::string mysteryword) {
		if (win) {
			std::cout << "You won!\nThe word was : " << mysteryword;
		}
		else
			std::cout << "You lost.\nThe word was : " << mysteryword;
	}
}