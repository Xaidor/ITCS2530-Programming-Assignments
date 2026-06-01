#include <iostream> 
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
    // ===================== Welcome Banner =====================
    cout << setfill(' ') << right;

    cout << setw(50) << "**      *******  ********   *****" << endl;
    cout << setw(46) << "**      ***         **     **" << endl;
    cout << setw(50) << "**      ******      **      *****" << endl;
    cout << setw(50) << "***     ***         **         **" << endl;
    cout << setw(50) << "******  *******     **     ******" << endl;

    cout << endl;

    cout << setw(68) << " *****  **   **  ******   *******  *****" << endl;
    cout << setw(70) << "**      **   **  ***  **  ***      **  **" << endl;
    cout << setw(70) << " *****  *******  *****    ******   **  **" << endl;
    cout << setw(70) << "    **  **   **  ** **    ***      **  **" << endl;
    cout << setw(68) << "******  **   **  **  **   *******  *****" << endl;

    cout << endl;



    // ===================== User Input =====================
    cout << fixed << setprecision(2);

    string favbrand;
    cout << "Favorite board brand: ";
    cin >> favbrand;

    int boardsOwned = 0;
    cout << "Enter the number of boards you currently own: ";
    cin >> boardsOwned;

    if (boardsOwned < 0)
    {
        cout << "Invalid input. Boards owned cannot be negative.";
        return -1;
    }

    double collCost = 0.00;
    cout << "How much have you spent on your collection of boards? ";
    cin >> collCost;

    if (collCost < 0.00)
    {
        cout << "Invalid input. Cost cannot be negative.";
        return -1;
    }

    double avgSpend = 0.0;
    if (boardsOwned > 0)
    {
        avgSpend = collCost / boardsOwned;
    }

    cout << endl << endl;



    // ===================== User Summary =====================
    cout << setfill('.');
    cout << "===== Skateboarding Summary File =====\n";

    cout << left << setw(25) << "Favorite Brand:" << right << favbrand << endl;
    cout << left << setw(25) << "Boards Owned:" << right << boardsOwned << endl;
    cout << left << setw(25) << "Total Collection Cost:" << right << "$" << collCost << endl;
    cout << left << setw(25) << "Avg Spend Per Board:" << right << "$" << avgSpend << endl;

    // ===================== Save Copy of Summary =====================
    ofstream fs("report.txt");

    if (!fs)
    {
        cout << "Error: Could not create report.txt\n";
        return -1;
    }

    fs << fixed << setprecision(2);
    fs << setfill('.');

    fs << "===== Skateboarding Summary File =====\n";

    fs << left << setw(25) << "Favorite Brand:" << right << favbrand << endl;
    fs << left << setw(25) << "Boards Owned:" << right << boardsOwned << endl;
    fs << left << setw(25) << "Total Collection Cost:" << right << "$" << collCost << endl;
    fs << left << setw(25) << "Avg Spend Per Board:" << right << "$" << avgSpend << endl;

    fs.close();
}



    // ===================== User board customization =====================
    string skateboardType;
    double boardSize = 0.0;
    int grit = 0;

    // Type of board
    cout << "What type of skateboard do you ride? (longboard/skateboard): ";
    cin  >> skateboardType;

    cout << "Enter board size: ";
    cin  >> boardSize;

    cout << "Enter grip tape grit: ";
    cin  >> grit;

    // ===================== Calculate cost of board =====================
    double basePrice = 60.00;
    double sizeFee = boardSize * 3.00;
    double gritFee = grit * 0.10;

    double total = basePrice + sizeFee + gritFee;

    // ===================== Output cost =====================
    cout << "\nYou've selected a " << skateboardType << " with a " << boardSize
        << " deck and " << grit << "-grit grip. Excellent taste.\n";

    cout << "Hand over $" << total
        << " and we'll start crafting your future wipeouts.\n";

    return 0;

}