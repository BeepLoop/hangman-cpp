#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> constructWords(const std::string &);

std::string generateRandomWord(std::vector<std::string> words);

bool hasLetter(std::string &, char &);

bool alreadyGuessed(std::vector<char> &, char &);

std::string reveal(std::string, std::string &, char &);

void printToReveal(std::string &, bool withSpaces = true);

bool haveWon(std::string &);

std::string initGuesses(int size);
