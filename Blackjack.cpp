#include <iostream>
#include <random>

void rules(); 
int draw();
int hit();
void input();

int main() {
	std::cout << "Welcome to Blackjack!" << "\n";
	std::cout << "You can find the rules of the game by typing 'rules'" << "\n";
	while (true) {
		std::string* input = new std::string;
		std::cin >> *input;
		if (*input == "rules") {
			rules();
		}
		else if (*input == "exit") {
			std::cout << "Thanks for playing!" << "\n";
			delete input;
			break;
		}
		else {
			std::cout << "Invalid command. Please type 'rules' to see the rules or 'exit' to quit." << "\n";
			delete input;
		}
	}
}
void rules() {
	std::cout << "Type the number of the part you want to know about:" << "\n";
	std::cout << "1. How to win" << "\n" << "2. Card Values" << "\n" << "3. How to Play" << "\n" << "4. Special Actions" << "\n" << "Type '5' to Leave the Rulebook" << "\n";
	while (true) {
		int* choice = new int;
		std::cin >> *choice;
		if (*choice = 5) {
			delete choice;
			std::cout << "Exiting the rulebook..." << "\n";
			break;
		}
		switch (*choice) {
		case 1:
			std::cout << "The goal is to get as close to 21 as possible without going over. If you go over 21, you lose." << "\n";
			std::cout << "If you have a higher total than the dealer without going over 21, you win." << "\n";
			std::cout << "If you have the same total as the dealer, it's a tie." << "\n";
			std::cout << "If the dealer goes over 21, you win." << "\n";
			std::cout << "If the dealer has a higher total than you without going over 21, you lose." << "\n";
			std::cout << "If you get 21 with your first two carsds, you have a Blackjack and win automatically unless the dealer also has a Blackjack, in which case it's a tie." << "\n";
			break;
		case 2:
			std::cout << "Number cards (2-10) are worth their face value." << "\n";
			std::cout << "Face cards (Jack, Queen, King) are worth 10 points." << "\n";
			std::cout << "Aces can be worth either 1 or 11 points, depending on which value benefits the player's hand more." << "\n";
			break;
		case 3:
			std::cout << "The game starts with the player and the dealer each receiving two cards." << "\n";
			std::cout << "The player's cards are dealt face up, while the dealer has one card face up and one card face down." << "\n";
			std::cout << "The player can choose to 'hit' (take another card) or 'stand' (keep their current hand)." << "\n";
			std::cout << "The player can continue to hit until they choose to stand or go over 21." << "\n";
			std::cout << "After the player stands, the dealer reveals their hidden card and must hit until they have at least 17 points." << "\n";
			break;
		case 4:
			std::cout << "In addition to hitting and standing, players can also choose to 'double' or 'split'." << "\n";
			std::cout << "Doubling down allows the player to double their initial bet in exchange for committing to stand after receiving exactly one more card." << "\n";
			std::cout << "Doubling down is typically done when the player has a strong hand." << "\n";
			std::cout << "You can only split if your first two cards have equal value." << "\n";
			std::cout << "By Splitting you can play two hands in one round but have to place an addtional bet equal to your intial bet" << "\n";
			break;
		}
		delete choice;
	}
}
void play() {
	std::string input;
	std::cin >> input;
	if (input == "casino") {
		while (true)
		{
			int player_hand[12];
			int dealer_hand[12];
			for (int i = 0; i < 2; ++i) {
				player_hand[i] = draw();
				dealer_hand[i] = draw();
			}
			int total_player = player_hand[0] + player_hand[1];
			int total_dealer = dealer_hand[0] + dealer_hand[1];
			std::cout << "Dealers hand: " << dealer_hand[0] << " " << dealer_hand[1] << " Total: " << total_dealer << "\n" << "\n";
			std::cout << "Your hand " << player_hand[0] << " " << player_hand[1] << " Total: " << total_player << "\n" << "\n";
			break;

		}
	}
}
int hit() {
	return draw();
}
int draw() {
	std::random_device rd;
	std::mt19937 gen(rd());
	int chances[10];
	for (int i = 0; i < 10; ++i) {
		chances[i] = 24;
	}
	chances[9] = 96;
	std::discrete_distribution<> dist(chances, chances + 10);
	int values[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int result = values[dist(gen)];
	chances[result - 1]--;
	return result;
}