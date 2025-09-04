#include "console.hpp"

namespace io {

	void Difficulty(std::string& difficulty) {
		std::cin >> difficulty;
		for (char& c : difficulty) {
			c = std::toupper(static_cast<unsigned char>(c));
		}
	}

	void MysteryWord(std::string& mysteryword) {
		std::cin >> mysteryword;
		for (char& c : mysteryword) {
			c = std::toupper(static_cast<unsigned char>(c));
		}
	}

	void RetrieveGuess(std::string& guess) {
		std::getline(std::cin, guess);
		for (char& c : guess) {
			c = std::toupper(static_cast<unsigned char>(c));
		}
	}

	void GameStart(int MaxMistakes, std::string mysteryword) {
		std::cout << "Hangman" << std::endl << "-------" << std::endl << std::endl;
		std::cout << "Mistakes: 0/" << MaxMistakes << std::endl << "Clue:     ";
		for (int i = 0; i < mysteryword.length(); ++i) {
			std::cout << '_';
		}
		std::cout << std::endl << std::endl;
	}

	void Status(std::string& guess, std::string& ClueStatus, std::string& WrongLetters,
		int Mistakes, int MaxMistakes, bool printwrong) {
		std::cout << "Guess: " << guess << std::endl << std::endl;
		std::cout << "Mistakes: " << Mistakes << "/" << MaxMistakes << std::endl;
		std::cout << "Clue:     " << ClueStatus << std::endl;

		if (printwrong) {
			std::cout << "Wrong:    " << WrongLetters << std::endl << std::endl;
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