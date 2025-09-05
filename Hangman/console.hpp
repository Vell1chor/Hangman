#pragma once
#include <iostream>
#include <string>

namespace io {
	void GameStart(int maxmistakes, std::string mysteryword);
	void Difficulty(std::string& difficulty);
	int IntoDifficulty(std::string& difficulty, int& maxmistakes);
	std::string MysteryWord();
	void RetrieveGuess(std::string& guess);
	void RemoveWhitespace(std::string& guess);
	void Status(std::string& guess, std::string& clue, std::string& wrongletters,
		int mistakes, int maxmistakes, bool wrong);
	void EndResult(bool win, std::string mysteryword);
}