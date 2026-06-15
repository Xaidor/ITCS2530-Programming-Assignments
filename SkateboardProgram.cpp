#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
    // ===================== Declare Variables =====================
    const int MAX_BOARDS = 5;

    // Arrays to store each board's details (up to 5 boards)
    string savedBrand[MAX_BOARDS];
    double savedSize[MAX_BOARDS];
    int savedGrit[MAX_BOARDS];
    double savedTotal[MAX_BOARDS];

    // Track how many boards the customer has built
    int boardCount = 0;

    string brandChoice = "";
    double boardSize = 0.0;
    int grit = 0;
    double total = 0.0;
    int menu = 0;

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

    // ===================== Main Program Loop =====================
    // ============= Do-while keeps the menu running until the customer chooses to exit =============
    do {
        cout << "Enter \n1 To Contact Us \n2 To View Orders \n3 Customize Board \n4 Exit: ";
        cin >> menu;
        cout << endl;

        switch (menu) {

        // ===================== Case 1: Contact =====================
        case 1:
            cout << "Email: examplerun@email.com" << endl;
            cout << "Number: 333-222-5555" << endl;
            cout << endl;
            break;

        // ===================== Case 2: View All Orders =====================
        case 2:
            // Check if any boards have been built yet
            if (boardCount == 0) {
                cout << "No orders found yet. Customize a board first!" << endl;
                cout << endl;
            }
            else {
                cout << "===== Your Custom Boards =====\n\n";

                // ============= For loop prints each saved board summary numbered in order =============
                for (int i = 0; i < boardCount; i++) {
                    cout << "--- Board #" << (i + 1) << " ---" << endl;
                    cout << left << setw(25) << "Favorite Brand:" << right << savedBrand[i] << endl;
                    cout << left << setw(25) << "Board Size:" << right << savedSize[i] << endl;
                    cout << left << setw(25) << "Grip Tape Grit:" << right << savedGrit[i] << endl;
                    cout << left << setw(25) << "Total:" << right << "$" << savedTotal[i] << endl;
                    cout << endl;
                }
            }
            break;

        // ===================== Case 3: Customize a Board =====================
        case 3:
            // Check if customer has reached the 5 board limit
            if (boardCount >= MAX_BOARDS) {
                cout << "You have reached the maximum of 5 custom boards for this session." << endl;
                cout << endl;
                break;
            }

            cout << "Great! Let's customize your board." << endl;
            cout << endl;

            // Get brand name
            cout << "Enter skateboard brand: ";
            cin >> brandChoice;

            // ============= While loop validates board size input until a valid value is entered =============
            boardSize = 0.0;
            while (boardSize < 7.0 || boardSize > 9.0) {
                cout << "Enter board size (7.0 - 9.0): ";
                cin >> boardSize;
                if (boardSize < 7.0 || boardSize > 9.0) {
                    cout << "Invalid size. Please enter a value between 7.0 and 9.0." << endl;
                }
            }

            // While loop validates grit input until a valid value is entered
            grit = 0;
            while (grit < 60 || grit > 100) {
                cout << "Enter grip tape grit (60 - 100): ";
                cin >> grit;
                if (grit < 60 || grit > 100) {
                    cout << "Invalid grit. Please enter a value between 60 and 100." << endl;
                }
            }

            cout << endl;

            // ===================== Calculate Cost =====================
            double basePrice = 60.00;
            double sizeFee = boardSize * 3.00;
            double gritFee = grit * 0.10;
            total = basePrice + sizeFee + gritFee;

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

            // ===================== Board Summary =====================
            cout << "===== Skateboarding Summary =====\n";
            cout << left << setw(25) << "Favorite Brand:" << right << brandChoice << endl;
            cout << left << setw(25) << "Board Size:" << right << boardSize << endl;
            cout << left << setw(25) << "Grip Tape Grit:" << right << grit << endl;
            cout << left << setw(25) << "Total:" << right << "$" << total << endl;

            cout << "\nExcellent taste. Hand over $" << total
                << " and we'll start crafting your future wipeouts.\n";
            cout << endl;

            // ===================== Save Board to Arrays =====================
            savedBrand[boardCount] = brandChoice;
            savedSize[boardCount] = boardSize;
            savedGrit[boardCount] = grit;
            savedTotal[boardCount] = total;
            boardCount++;

            cout << "Board #" << boardCount << " saved! You have " 
                 << (MAX_BOARDS - boardCount) << " build(s) remaining this session." << endl;
            cout << endl;

            // ===================== Save to File =====================
            {
                ofstream fs("report.txt");

                if (!fs) {
                    cout << "Error: Could not create report.txt\n";
                    return -1;
                }

                fs << fixed << setprecision(2);
                fs << setfill('.');

                fs << "===== Skateboarding Summary File =====\n\n";

                // Write all boards saved so far to the file
                for (int i = 0; i < boardCount; i++) {
                    fs << "--- Board #" << (i + 1) << " ---\n";
                    fs << left << setw(25) << "Favorite Brand:" << right << savedBrand[i] << endl;
                    fs << left << setw(25) << "Board Size:" << right << savedSize[i] << endl;
                    fs << left << setw(25) << "Grip Tape Grit:" << right << savedGrit[i] << endl;
                    fs << left << setw(25) << "Total:" << right << "$" << savedTotal[i] << endl;
                    fs << endl;
                }
            }

            break;

        // ===================== Case 4: Exit =====================
        case 4:
            cout << "Thanks for visiting!" << endl;
            break;

        default:
            cout << "Invalid menu option. Please try again." << endl;
            cout << endl;
            break;
        }

    } while (menu != 4); // Keep looping until the userr chooses to exit

    return 0;
}
