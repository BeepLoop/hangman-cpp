#include "helpers.h"
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> categorySelector() {
  std::cout << "Choose a category" << std::endl;
  std::cout << "[1] Science" << std::endl;
  std::cout << "[2] Geography" << std::endl;
  std::cout << "[3] Foods" << std::endl;
  std::cout << "[4] School" << std::endl;
  std::cout << "[5] Math" << std::endl;
  std::cout << "[6] History" << std::endl;

  std::vector<std::string> words;

  int choice;
  std::cin >> choice;

  switch (choice) {
  case 1: {
    words = constructWords("science.txt");
    break;
  }
  case 2: {
    words = constructWords("geography.txt");
    break;
  }
  case 3: {
    words = constructWords("food.txt");
    break;
  }
  case 4: {
    words = constructWords("school.txt");
    break;
  }
  case 5: {
    words = constructWords("math.txt");
    break;
  }
  case 6: {
    words = constructWords("history.txt");
    break;
  }
  default: {
    std::cerr << "Invalid choice" << std::endl;
    break;
  }
  }

  return words;
}

int main() {
  std::vector<std::string> words = categorySelector();
  std::string wordToGuess = generateRandomWord(words);
  int incorrectGuesses = 6;
  bool gameOver = false;
  char input;
  std::string toReveal = initGuesses(wordToGuess.size());
  std::vector<char> guesses;

  std::cout << "Welcome to Hangman! You have 6 incorrect guesses\n";

  while (!gameOver) {
    std::cout << "\n";
    printToReveal(toReveal);

    std::cout << "Input a letter: ";
    std::cin >> input;

    if (alreadyGuessed(guesses, input)) {
      std::cout << "You already tried that letter" << std::endl;
      continue;
    }

    guesses.push_back(input);

    if (hasLetter(wordToGuess, input)) {
      toReveal = reveal(toReveal, wordToGuess, input);

      if (haveWon(toReveal)) {
        std::cout << "The word is: ";
        printToReveal(wordToGuess, false);
        std::cout << "You WON!" << std::endl;
        gameOver = true;
      }
    } else {
      incorrectGuesses--;

      if (incorrectGuesses == 0) {
        std::cout << "The word is: ";
        printToReveal(wordToGuess, false);
        std::cout << "You LOST\nGAMEOVER!" << std::endl;
        gameOver = true;
      } else {
        std::cout << "incorrect guess! number of guesses remaining: "
                  << incorrectGuesses << std::endl;
      }
    }
  }

  return 0;
}
