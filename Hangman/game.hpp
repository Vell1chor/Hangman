#pragma once
#include <string>
#include "console.hpp"
#include "state.hpp"

namespace hangman {
	void HangmanStart();
	int getDifficulty(std::string& difficulty);
	int MistakeCount(int mistakes, std::string const& guess, std::string const& mysteryword, bool error);
	std::string WrongLetters(bool error, std::string const& guess, std::string wrongletters);
	std::string ClueStatus(std::string const mysteryword, std::string guess, std::string clue);
	void RemoveWhitespace(std::string mysteryword, std::string const& guess);

} 