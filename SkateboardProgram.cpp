#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
    // ===================== Declare Variables =====================
    string brandChoice = "";
    double boardSize = 0.0;
    int grit = 0;
    double total = 0.0;

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

    // ===================== Menu Options =====================
    int menu;
    cout << "Enter \n1 To Contact Us \n2 To View Order \n3 Customize Board: ";
    cin >> menu;

    switch (menu) {
    case 1:
        // Contact information
        cout << "Email: examplerun@email.com" << endl;
        cout << "Number: 333-222-5555" << endl;
        return 0;

    case 2:
        // Order Details
        if (total == 0.0) {
            cout << "No orders found yet. Customize a board first!" << endl;
        }
        else {
            cout << "===== Order Details =====\n";
            cout << left << setw(25) << "Favorite Brand:" << right << brandChoice << endl;
            cout << left << setw(25) << "Board Size:" << right << boardSize << endl;
            cout << left << setw(25) << "Grip tape grit:" << right << grit << endl;
            cout << left << setw(25) << "Total:" << right << "$" << total << endl;
        }
        return 0;

    case 3:
        // Customize Board
        cout << endl;
        cout << "Great! Let's customize your board." << endl;
        break;

    default:
        cout << "Invalid menu option." << endl;
        return 0;
    }
    
    cout << endl;

    // ===================== User Board Customization Input =====================
    cout << "Enter skateboard brand: ";
    cin >> brandChoice;

    cout << "Enter board size (7.0 - 9.0): ";
    cin >> boardSize;

    cout << "Enter grip tape grit (60 - 100): ";
    cin >> grit;

    cout << endl;

    // ===================== Restrictions =====================
    if ((boardSize < 7.0 || boardSize > 9.0) && (grit < 60 || grit > 100)) {
        cout << "Warning: Both your board size AND grit are outside normal ranges." << endl;
    }
    else if (boardSize < 7.0 || boardSize > 9.0) {
        cout << "Warning: Board size is unusual for standard decks." << endl;
    }
    else if (grit < 60 || grit > 100) {
        cout << "Warning: Grip tape grit is outside typical values." << endl;
    }

    // ===================== Calculate cost of board =====================
    double basePrice = 60.00;
    double sizeFee = boardSize * 3.00;
    double gritFee = grit * 0.10;
    total = basePrice + sizeFee + gritFee;

    cout << endl;

    // ===================== Setup Type =====================
    if (boardSize >= 8.0 && grit >= 80) {
        cout << "Nice! This is a premium setup for a pro-level skater." << endl;
    }
    else if (boardSize < 8.0 && grit <= 70) {
        cout << "Pretty cool beginner setup for a casual skater." << endl;
    }
    else {
        cout << "Standard setup." << endl;
    }
    cout << endl;

    // ===================== Summary =====================
    cout << "\n===== Skateboarding Summary =====\n";
    cout << left << setw(25) << "Favorite Brand:" << right << brandChoice << endl;
    cout << left << setw(25) << "Board Size:" << right << boardSize << endl;
    cout << left << setw(25) << "Grip tape grit:" << right << grit << endl;
    cout << left << setw(25) << "Total:" << right << "$" << total << endl;

    cout << "\nExcellent taste. Hand over $" << total
        << " and we'll start crafting your future wipeouts.\n";

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
    fs << left << setw(25) << "Favorite Brand:" << right << brandChoice << endl;
    fs << left << setw(25) << "Board Size:" << right << boardSize << endl;
    fs << left << setw(25) << "Grip tape grit:" << right << grit << endl;
    fs << left << setw(25) << "Total:" << right << "$" << total << endl;

    fs << "\nExcellent taste. Hand over $" << total
        << " and we'll start crafting your future wipeouts.\n";

    return 0;
}
