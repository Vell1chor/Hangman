#pragma once
#include <iostream>
#include <string>

namespace hangman {

	class Logic {
	public:
		int MistakeCount(int mistakes, std::string const& guess, std::string const& mysteryword, bool& error);
		std::string WrongLetters(const std::string & guess, std::string wrongletters);
		std::string ClueStatus(std::string const mysteryword, std::string& guess, std::string clue);
		int maxmistakes = 9;
		int mistakes;
		std::string wrongletters;
	private:
	};
}