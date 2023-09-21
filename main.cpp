#include "helpers.h"
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> words = constructWords();
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
