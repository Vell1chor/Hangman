#pragma once
#include <iostream>
#include <string>

namespace hangman {

	class Logic {
	public:
		int MistakeCount(std::string const& guess, std::string const& mysteryword, bool& printwrong, int mistakecount, bool easyset, std::string wrongletters);
		std::string WrongLetters(const std::string & guess, std::string wrongletters);
		std::string ClueStatus(std::string const mysteryword, std::string& guess, std::string clue);
		int maxmistakes = 9;
		int mistakecount = 0;
		std::string wrongletters;
	private:
	};
}