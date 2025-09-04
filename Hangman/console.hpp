#pragma once
#include <iostream>
#include <string>

namespace io {

	void GameStart(int MaxMistakes, std::string mysteryword);
	void Difficulty(std::string& difficulty);
	void MysteryWord(std::string& mysteryword);
	void RetrieveGuess(std::string& guess);
	void Status(std::string& guess, std::string& ClueStatus, std::string& WrongLetters,
		int Mistakes, int MaxMistakes, bool wrong);
	void EndResult(bool win, std::string mysteryword);
}