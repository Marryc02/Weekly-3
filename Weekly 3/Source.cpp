#include <iostream>



void difficultySettings();
void generateANumber();
void guessANumber();
void tryAgainIf();
void highScore();


int randomNumber{};
int guessAnswer{};
int guessCounter{};
int bestScore{};
int difficulty{};



int main() {
	guessCounter = 1;

	std::srand(static_cast<unsigned int>(std::time(nullptr)));;


	difficultySettings();
	generateANumber();
	guessANumber();
	highScore();
	tryAgainIf();

	return 0;
}



void difficultySettings() {
	int input{};

	std::cout << "What difficulty would you like to play the game on?" << std::endl;
	std::cout << "1 = easy (1-5)" << std::endl;
	std::cout << "2 = medium (1-10)" << std::endl;
	std::cout << "3 = hard (1-30)" << std::endl;
	std::cin >> input;

	if (input == 1) {
		std::cout << "You have selected 'easy' difficulty" << std::endl;
		difficulty = 5;
		std::cout << "" << std::endl;
	}
	else if (input == 2) {
		std::cout << "You have selected 'medium' difficulty" << std::endl;
		difficulty = 10;
		std::cout << "" << std::endl;
	}
	else if (input == 3) {
		std::cout << "You have selected 'hard' difficulty" << std::endl;
		difficulty = 30;
		std::cout << "" << std::endl;
	}
	else {
		std::cout << "Invalid input. Try again." << std::endl;
		difficultySettings();
	}
}



void generateANumber() {
	std::cout << "Generating a random number..." << std::endl;
	randomNumber = std::rand() % difficulty + 1;
	std::cout << randomNumber << std::endl;
	std::cout << "Guess which number the code generated!" << std::endl;
	std::cout << "" << std::endl;
}



void guessANumber() {
	std::cin >> guessAnswer;
	
	if (guessAnswer > randomNumber) {
		std::cout << "That is not the right number! Your guess is too high!" << std::endl;
		guessCounter++;
		guessANumber();
	}
	else if (guessAnswer < randomNumber) {
		std::cout << "That is not the right number! Your guess is too low!" << std::endl;
		guessCounter++;
		guessANumber();
	}
	else {
		std::cout << "Congratulations! You guessed the right number!" << std::endl;
		std::cout << "You tried to guess the right number " << guessCounter << " time(s)." << std::endl;
		std::cout << "" << std::endl;
	}
}



void highScore() {
	std::cout << "Your old high-score was " << bestScore << "." << std::endl;

	if (guessCounter < bestScore || bestScore == 0) {
		std::cout << "Your new high-score is " << guessCounter << ". Congratulations!" << std::endl;
		bestScore = guessCounter;
	}
	else {
		std::cout << "You did not recieve a new high-score. Better luck next time!" << std::endl;
	}
}



void tryAgainIf() {
	char tryAgain{};

	std::cout << "Would you like to try again?" << std::endl;
	std::cin >> tryAgain;
	std::cout << "" << std::endl;

	if (tryAgain == 'Y' || tryAgain == 'y') {
			main();
		}
		else if (tryAgain == 'N' || tryAgain == 'n') {
			std::cout << "End of program.";
		}
		else {
			std::cout << "Invalid input! Try again." << std::endl;
			tryAgainIf();
		}
}