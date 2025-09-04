#pragma once
#include <iostream>
#include <string>

namespace hangman {

	class Logic {
	public:
		int getDifficulty(std::string& difficutly);
		int MistakeCount(int mistakes, std::string const& guess, std::string const& mysteryword, bool& error);
		std::string WrongLetters(const std::string & guess, std::string wrongletters);
		std::string ClueStatus(std::string const mysteryword, std::string& guess, std::string clue);
		void RemoveWhitespace(std::string mysteryword, std::string const& guess);
		int maxmistakes;
		int mistakes;
		std::string wrongletters;

	private:


	};
}