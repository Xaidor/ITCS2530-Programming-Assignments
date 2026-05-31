#include <iostream> 
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    // ===================== Welcome banner =====================
    cout << setfill(' ') << right;
    // Spell LETS
    cout << setw(50) << "**      *******  ********   *****" << endl;
    cout << setw(46) << "**      ***         **     **" << endl;
    cout << setw(50) << "**      ******      **      *****" << endl;
    cout << setw(50) << "***     ***         **         **" << endl;
    cout << setw(50) << "******  *******     **     ******" << endl;

    // Spacing
    cout << endl;

    cout << setw(68) << " *****  **   **  ******   *******  *****" << endl;
    cout << setw(70) << "**      **   **  ***  **  ***      **  **" << endl;
    cout << setw(70) << " *****  *******  *****    ******   **  **" << endl;
    cout << setw(70) << "    **  **   **  ** **    ***      **  **" << endl;
    cout << setw(68) << "******  **   **  **  **   *******  *****" << endl;

    // Spacing
    cout << endl;
    
    // ===================== User Input =====================
    // Favorite skateboard brand
    string favbrand;
    cout << "Favorite board brand: ";
    cin >> favbrand;

    // How many board does the user own
    // Favorite skatepark
    // How many days out the week do you skateboard?
    // Transition or street skating?
    // How much do you typically spend on a new board?
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

    // Type of board
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