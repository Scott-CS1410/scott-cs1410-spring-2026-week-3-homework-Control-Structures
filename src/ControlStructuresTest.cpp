#include "ControlStructures.h"
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

// Helper functions for testing
template <typename T>
bool checkTest(int testNum, int& correct, T whatItShouldBe, T whatItIs) {
    if (whatItShouldBe == whatItIs) {
        correct++;
        cout << "***TEST " << testNum << " PASSED***" << endl;
        return true;
    } else {
        cout << "***TEST " << testNum << " FAILED*** " << endl;
        cout << "   Output was " << whatItIs << endl;
        cout << "   Output should have been " << whatItShouldBe << endl;
        return false;
    }
}

void testChoice(int choice, const vector<string>& expectedOutputs, int& correctTests) {
    for (int i = 1; i <= 5; ++i) {
        string playerInput = to_string(choice) + " 2\n";
        stringstream inputBuffer(playerInput);
        streambuf* oldCin = cin.rdbuf(inputBuffer.rdbuf());

        stringstream outputBuffer;
        streambuf* oldCout = cout.rdbuf(outputBuffer.rdbuf());

        string result = gameLogic(i);

        cin.rdbuf(oldCin);
        cout.rdbuf(oldCout);

        // Extract the actual result from the output buffer
        string capturedOutput = result;

        checkTest((choice - 1) * 5 + i, correctTests, expectedOutputs[i - 1], capturedOutput);
    }
}

// Function to run all tests
void runAllTests() {
    int correctTests = 0;

    vector<string> expectedOutputs1 = {
        "It's a tie!",
        "Paper covers Rock! You lose!",
        "Rock crushes Scissors! You win!",
        "Rock crushes Lizard! You win!",
        "Spock vaporizes Rock! You lose!"
    };
    vector<string> expectedOutputs2 = {
        "Paper covers Rock! You win!",
        "It's a tie!",
        "Scissors cut Paper! You lose!",
        "Lizard eats Paper! You lose!",
        "Paper disproves Spock! You win!"
    };
    vector<string> expectedOutputs3 = {
        "Rock crushes Scissors! You lose!",
        "Scissors cut Paper! You win!",
        "It's a tie!",
        "Scissors decapitates Lizard! You win!",
        "Spock crushes Scissors! You lose!"
    };
    vector<string> expectedOutputs4 = {
        "Rock crushes Lizard! You lose!",
        "Lizard eats Paper! You win!",
        "Scissors decapitates Lizard! You lose!",
        "It's a tie!",
        "Lizard poisons Spock! You win!"
    };
    vector<string> expectedOutputs5 = {
        "Spock vaporizes Rock! You win!",
        "Paper disproves Spock! You lose!",
        "Spock crushes Scissors! You win!",
        "Lizard poisons Spock! You lose!",
        "It's a tie!"
    };

    testChoice(1, expectedOutputs1, correctTests);
    testChoice(2, expectedOutputs2, correctTests);
    testChoice(3, expectedOutputs3, correctTests);
    testChoice(4, expectedOutputs4, correctTests);
    testChoice(5, expectedOutputs5, correctTests);

    cout << "Total tests passed: " << correctTests << " out of 25" << endl;
}

// Main function to run specific tests
int main(int argc, char* argv[]) {
    if (argc == 1) {
        runAllTests();
    } else if (argc == 2) {
        int correctTests = 0;
        int testNumber = atoi(argv[1]);

        switch (testNumber) {
            case 1:
                testChoice(1, {
                    "It's a tie!",
                    "Paper covers Rock! You lose!",
                    "Rock crushes Scissors! You win!",
                    "Rock crushes Lizard! You win!",
                    "Spock vaporizes Rock! You lose!"
                }, correctTests);
                break;
            case 2:
                testChoice(2, {
                    "Paper covers Rock! You win!",
                    "It's a tie!",
                    "Scissors cut Paper! You lose!",
                    "Lizard eats Paper! You lose!",
                    "Paper disproves Spock! You win!"
                }, correctTests);
                break;
            case 3:
                testChoice(3, {
                    "Rock crushes Scissors! You lose!",
                    "Scissors cut Paper! You win!",
                    "It's a tie!",
                    "Scissors decapitates Lizard! You win!",
                    "Spock crushes Scissors! You lose!"
                }, correctTests);
                break;
            case 4:
                testChoice(4, {
                    "Rock crushes Lizard! You lose!",
                    "Lizard eats Paper! You win!",
                    "Scissors decapitates Lizard! You lose!",
                    "It's a tie!",
                    "Lizard poisons Spock! You win!"
                }, correctTests);
                break;
            case 5:
                testChoice(5, {
                    "Spock vaporizes Rock! You win!",
                    "Paper disproves Spock! You lose!",
                    "Spock crushes Scissors! You win!",
                    "Lizard poisons Spock! You lose!",
                    "It's a tie!"
                }, correctTests);
                break;
            default:
                cerr << "Invalid test number. Please enter 1" << endl;
                return 1;
        }

        cout << "Total tests passed: " << correctTests << " out of 5" << endl;
    } else {
        cerr << "Usage: " << argv[0] << " [testNumber]" << endl;
        return 1;
    }

    return 0;
}
