#include <iostream> 
#include <string>
using namespace std;

int main()
{
    // Customize a skateboard
    // type of skateboard, 
    // board size,
    // and griptape grit (courseness: Fine, Regular/Standard, Aggressive)

    // Inputs:
    // sting skateboardType 
    // double size (7.0 - 33.0)
    // int grit    (<60 course, 80 is standard, 80+ is fine)

    string skateboardType;
    double boardSize = 0.0;
    int grit = 0;

    // Collect user input
    cout << "What type of skateboard do you ride? (longboard/skateboard): ";
    cin >> skateboardType;

    cout << "Enter board size: ";
    cin >> boardSize;

    cout << "Enter grip tape grit: ";
    cin >> grit;

    // Calculate the cost of the custom board total
    double basePrice = 60.00;
    double sizeFee = boardSize * 3.00;
    double gritFee = grit * 0.10;

    double total = basePrice + sizeFee + gritFee;

    // Output creative paragraph using all variables
    cout << "\nYou've selected a " << skateboardType << " with a " << boardSize
        << " deck and " << grit << "-grit grip. Excellent taste.\n";

    cout << "Hand over $" << total
        << " and we'll start crafting your future wipeouts.\n";

}