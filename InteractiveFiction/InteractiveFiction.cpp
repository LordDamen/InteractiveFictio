// InteractiveFiction.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>

using namespace std;

//function returns text input from the user
string GetTextFromUser() {
	string a;
	getline(cin, a);
	return a;
}

//function returns input from the user that is a number
int GetNumbersFromUser() {
	int a;
	cin >> a;
	return a;
}

int main()
{
	//create variable for input 
	int inp;
	//create enums for each location in the game
	enum Location { home, shop, field, forest, cave, mountain, dead, win };
	//variable showing which location the player is at
	int playerLocation = home;
	//variable for the gold the player has
	int playerGold = 0;

	//boolean variables for certain things in the game like having searched the house or having the sword
	bool searchedHouse = false;
	bool hasSword = false;

	//display the game intro and take the Player's name
	cout << "Welcome to The Game!\n" << endl;
	cout << "Please enter your name: ";
	string playerName = GetTextFromUser();

	//display information about the first area in the game
	cout << "\nYour eyes startle awake as you open your eyes to look around and you realize that, you are laying on your bed inside your home." << endl;
	cout << "You stand up and stretch, and while looking around your room, you realize that there isnt much furnature" << endl;

	//begin main game loop
	while (true) {
		//depending on the location of the player, the game will display different things
		switch (playerLocation) {
			//player is in their home
		case home:
			//description
			cout << "You are inside your home with very little furniture. There is a door to the outside." << endl;

			//display options
			cout << endl;
			cout << "1. Exit through the door" << endl;
			cout << "2. Look around" << endl;
			if (!searchedHouse) { //option 3 only shows up if you haven't already searched for items
				cout << "3. Search for items" << endl;
			}
			inp = GetNumbersFromUser();

			//check what the player inputs and do the corresponding action
			switch (inp) {
			case 1:
				playerLocation = field;
				break;
			case 2:
				break;
			case 3:
				if (!searchedHouse) {
					cout << "You search your home and find 10 gold pieces hiding under the rug!" << endl;
					playerGold += 10;
				}
				else {
					cout << "You search again, but find nothing." << endl;
				}
				break;
			default:
				cout << "Invalid input!" << endl;
			}


			break;

		case shop:
			//description
			cout << "You are inside the small shop. There is a small man behind the counter. On the counter are various" << endl;
			cout << "items of difference shapes and sizes. Most notably, a sword catches your eye. The price is 10 Gold." << endl;

			//display options
			cout << endl;
			cout << "1. Leave the shop" << endl;
			cout << "2. Buy the sword [10 Gold]" << endl;
			cout << "3. Look around" << endl;

			inp = GetNumbersFromUser();

			//check what the player inputs and do the corresponding action
			switch (inp) {
			case 1:
				playerLocation = field;
				break;
			case 2:
				if (playerGold >= 10 && !hasSword) {
					playerGold -= 10;
					hasSword = true;
					cout << "You purchase the sword from the shopkeeper." << endl;
				}
				else {
					cout << "You cannot do this right now!" << endl;
				}
				break;
			case 3:
				break;
			default:
				cout << "Invalid input!" << endl;
			}
			break;

		case field:
			//description
			cout << "You are in a large open area. There are a few houses you can see. One clearly has a large SHOP sign." << endl;
			cout << "Your house is here as well. Nearby, you can see a thick forest of pine trees." << endl;

			//display options
			cout << endl;
			cout << "1. Enter the shop" << endl;
			cout << "2. Enter your house" << endl;
			cout << "3. Enter the forest" << endl;
			cout << "4. Look Around" << endl;

			inp = GetNumbersFromUser();

			//check what the player inputs and do the corresponding action
			switch (inp) {
			case 1:
				playerLocation = shop;
				break;
			case 2:
				playerLocation = home;
				break;
			case 3:
				playerLocation = forest;
				break;
			case 4:
				break;
			default:
				cout << "Invalid input!" << endl;
			}
			break;

		case forest:
			//description
			cout << "You are in a large oak forest. Trees are all around you and you can hear the whispering of the wind." << endl;
			cout << "In the distance you see the open field with houses and shops. Deeper into the forest, you can see what" << endl;
			cout << "seems to be the base of a mountain." << endl;

			//display options
			cout << endl;
			cout << "1. Walk to the mountain" << endl;
			cout << "2. Walk to the field" << endl;
			cout << "3. Look around" << endl;

			inp = GetNumbersFromUser();

			//check what the player inputs and do the corresponding action
			switch (inp) {
			case 1:
				playerLocation = mountain;
				break;
			case 2:
				playerLocation = field;
				break;
			case 3:
				break;
			default:
				cout << "Invalid input!" << endl;
			}
			break;

		case cave:
			//description
			cout << "As you enter the cave, you are greeted to the roar of a large beast. Ahead of you, you see it. A massive, angry, dragon." << endl;
			cout << "If you try to run, the dragon will kill you with it's flames. Behind the dragon you see countless treasure." << endl;

			//display options
			cout << endl;
			cout << "1. Run Away" << endl;
			cout << "2. Fight the Dragon" << endl;
			cout << "3. Look Around" << endl;

			inp = GetNumbersFromUser();

			//check what the player inputs and do the corresponding action
			switch (inp) {
			case 1:
				cout << "As you attempt to flee, the dragon shoots flames from it's mouth and you are burnt to a crisp. You died." << endl;
				playerLocation = dead;
				break;
			case 2:
				if (hasSword) {
					cout << "You draw your sword and with a mighty swing, you chop off the dragon's head! The dragon's limp body falls and you make your" << endl;
					cout << "way towards the treasure. You are now the richest man alive! Congratulations! You Win!" << endl;
					playerLocation = win;
				}
				else {
					cout << "You attempt to punch the dragon with your bare fist, but your attempt is futile. The dragon picks you up and devours you in one bite. You die." << endl;
					playerLocation = dead;
				}
				break;
			case 3:
				break;
			default:
				cout << "Invalid input!" << endl;
			}
			break;

		case mountain:
			//description
			cout << "The mountain is cold and rocky. Around you, you see nothing but rocks . You can" << endl;
			cout << "see a small pathway leading to a cave. Behind you is the way down the mountain back into the forest." << endl;

			//display options
			cout << endl;
			cout << "1. Enter the cave" << endl;
			cout << "2. Walk to the Forest" << endl;
			cout << "3. Look around" << endl;

			inp = GetNumbersFromUser();

			//check what the player inputs and do the corresponding action
			switch (inp) {
			case 1:
				playerLocation = cave;
				break;
			case 2:
				playerLocation = forest;
				break;
			case 3:
				break;
			default:
				cout << "Invalid input!" << endl;
			}
			break;

		case dead:
			//player has lost. Restart the game
			cout << "You have died. Try Again!" << endl;
			playerLocation = home;
			playerGold = 0;
			hasSword = false;
			system("pause");
			system("cls");
			break;

		case win:
			//Player wins. Restart the game
			cout << "Congratulations, you've won!" << endl;
			playerLocation = home;
			playerGold = 0;
			hasSword = false;
			system("pause");
			system("cls");
			break;
			break;
		}

	}

	system("pause");
	return 0;
}