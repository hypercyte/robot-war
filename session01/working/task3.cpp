#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

	srand(time(nullptr)); // Initialise pseudo-random number generator
	int n = 100;
	int secret = rand() % n + 1; // Generates a random number between 1 and n

	cout << "Guess a number between 1 and " << n << ": ";

	int guess;
	int attempts = 0; // Set number of guesses to 0
	cin >> guess; // Initial guess input
	while (guess != secret) { // As long as guess is not the correct guess, do stuff here
		if (secret > guess) {
			cout << "Your guess was too low, try again: ";
			cin >> guess; 
		}
		else { // only other possibility is guessing too high
			cout << "Your guess was too high, try again: ";
			cin >> guess;
		}
		attempts++;
	}
	attempts++; // The attempt with the correct guess also counts as a valid attempt.
	cout << "Correct! It took you " << attempts << " tries.\n";

	return 0;

}
