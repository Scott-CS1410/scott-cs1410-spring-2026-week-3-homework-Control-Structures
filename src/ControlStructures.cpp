#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main(){
    int playAgain = 0;
    int computerChoice = 0;

    cout << "Welcome to Rock, Paper, Scissors, Lizard, Spock!" << endl;

    do{
        //TODO: Ask the player which option they will choose

        if(computerChoice == 0){
            //TODO: Generate a random number between 1 and 5
            //      for the computer's selection
        }

        //TODO: Use a combination of switch and/or if statements to determine the winner
        //      and print it to the console. Please also set the result variable equal to
        //      the same string. The statements should be one of the of the following:
        //      "It's a tie!"
        //      "Scissors cut Paper!"
        //      "Paper covers Rock!"
        //      "Rock crushes Lizard!"
        //      "Lizard poisons Spock!"
        //      "Spock smashes Scissors!"
        //      "Scissors decapitates Lizard!"
        //      "Lizard eats Paper!"
        //      "Paper disproves Spock!"
        //      "Spock vaporizes Rock!"
        //      "Rock crushes Scissors!"
        //      The following statement after one of the above statements should be either:
        //      "You win!" or "You lose!"
        //      Example: 
        //      cout << "Paper disproves Spock! You win!" << endl;
        //      result = "Paper disproves Spock! You win!";

        do{
            cout << "Would you like to play again? (1) Yes (2) No: ";
            cin >> playAgain;
        }while(playAgain != 1 && playAgain != 2);
    }while(playAgain == 1);

    return 0;
}