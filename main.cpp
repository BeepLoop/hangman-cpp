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

  std::cout << "Welcome to Hangman! You have 6 incorrect guesses\n";

  while (!gameOver) {
    std::cout << "\n";
    printToReveal(toReveal);

    std::cout << "Input a letter: ";
    std::cin >> input;

    if (hasLetter(wordToGuess, input)) {
      if (!alreadyGuessed(toReveal, input)) {
        toReveal = reveal(toReveal, wordToGuess, input);

        if (haveWon(toReveal)) {
          std::cout << "The word is: ";
          printToReveal(wordToGuess, false);
          std::cout << "You WON!" << std::endl;
          gameOver = true;
        }
      } else {
        std::cout << "You already guessed that letter" << std::endl;
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
