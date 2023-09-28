#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> constructWords(const std::string &filename) {
  std::string str;
  std::vector<std::string> words;
  std::ifstream reader;
  std::string base = "./categories/";
  reader.open(base.append(filename));

  while (std::getline(reader, str)) {
    words.push_back(str);
  }

  return words;
}

std::string generateRandomWord(std::vector<std::string> words) {
  int bounds = words.size();
  int secondsElapsed = time(0);
  srand(secondsElapsed);

  int random = rand() % bounds;

  return words[random];
}

bool hasLetter(std::string &word, char &letter) {
  for (int i = 0; i < word.size(); ++i) {
    if (letter == word[i]) {
      return true;
    }
  }
  return false;
}

bool alreadyGuessed(std::vector<char> &guesses, char &letter) {
  for (int i = 0; i < guesses.size(); ++i) {
    if (letter == guesses[i]) {
      return true;
    }
  }
  return false;
}

std::string reveal(std::string toReveal, std::string &word, char &letter) {
  for (int i = 0; i < word.size(); ++i) {
    if (letter == word[i]) {
      toReveal[i] = letter;
    }
  }
  return toReveal;
}

void printToReveal(std::string &toReveal, bool withSpaces = true) {
  for (int i = 0; i < toReveal.size(); ++i) {
    if (withSpaces) {
      std::cout << toReveal[i] << " ";
    } else {
      std::cout << toReveal[i];
    }
  }
  std::cout << std::endl;
}

bool haveWon(std::string &toReveal) {
  for (int i = 0; i < toReveal.size(); ++i) {
    if (toReveal[i] == '_') {
      return false;
    }
  }
  return true;
}

std::string initGuesses(int size) {
  std::string str;

  for (int i = 0; i < size; ++i) {
    str.push_back('_');
  }

  return str;
}
