#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  const int MIN = 1;
  const int MAX = 100;
  int guess;
  int guesses = 0;
  int answer;

  // Set random seed as current time
  srand(time(0));

  // Genrate number between min and max
  answer = (rand() % MAX) + MIN;

  do {
    printf("Enter a guess: ");
    scanf("%d", &guess);

    if (guess > answer) {
      printf("Yooo, too high!?\n");
    } else if (guess < answer) {
      printf("Yoow, too low!?\n");
    } else {
      printf("Correct!\n");
    }

    guesses++;
  } while (guess != answer);

  printf("********************\n");
  printf("Answer: %d\n", answer);
  printf("Number of guesses: %d\n", guesses);
  printf("********************\n");

  return 0;
}
