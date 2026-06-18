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

    // ===================== Main Menu Loop (DO-WHILE) =====================
    do {
        cout << "Enter \n1 To Contact Us \n2 View Order \n3 Customize Board \n4 Exit: ";
        cin >> menu;
        cout << endl;

        switch (menu) {

        case 1:
            cout << "Email: examplerun@email.com" << endl;
            cout << "Number: 333-222-5555" << endl;
            cout << endl;
            break;

        case 2:
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
            cout << endl;
            break;

        case 3: { //Braces needed for declaring variables 

            cout << "Great! Let's customize 3 boards." << endl;
            cout << endl;

            // ======== FOR LOOP: User builds 3 boards ========
            for (int i = 1; i <= 3; i++) {

                cout << "----- Customizing Board #" << i << " -----" << endl;

                // Brand input
                cout << "Enter skateboard brand: ";
                cin.ignore();
                getline(cin, brandChoice);

                // Board size validation
                cout << "Enter board size (7.0 - 9.0): ";
                while (!(cin >> boardSize) || boardSize < 7.0 || boardSize > 9.0) {
                    cout << "Invalid size. Enter a number between 7.0 and 9.0: ";
                    cin.clear();
                    cin.ignore(1000, '\n');
                }

                // Grit validation
                cout << "Enter grip tape grit (60 - 100): ";
                while (!(cin >> grit) || grit < 60 || grit > 100) {
                    cout << "Invalid grit. Enter a number between 60 and 100: ";
                    cin.clear();
                    cin.ignore(1000, '\n');
                }

                cout << endl;

                // Calculate cost
                double basePrice = 60.00;
                double sizeFee = boardSize * 3.00;
                double gritFee = grit * 0.10;
                total = basePrice + sizeFee + gritFee;

                // Setup type
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

                // Summary
                cout << "===== Board #" << i << " Summary =====\n";
                cout << left << setw(25) << "Favorite Brand:" << right << brandChoice << endl;
                cout << left << setw(25) << "Board Size:" << right << boardSize << endl;
                cout << left << setw(25) << "Grip tape grit:" << right << grit << endl;
                cout << left << setw(25) << "Total:" << right << "$" << total << endl;

                cout << "\nExcellent taste. Hand over $" << total
                    << " and we'll start crafting your future wipeouts.\n\n";

                // Save to file
                ofstream fs("report.txt", ios::app);

                if (!fs) {
                    cout << "Error: Could not create report.txt\n";
                    return -1;
                }

                fs << fixed << setprecision(2);
                fs << setfill('.');

                fs << "===== Board #" << i << " Summary =====\n";
                fs << left << setw(25) << "Favorite Brand:" << right << brandChoice << endl;
                fs << left << setw(25) << "Board Size:" << right << boardSize << endl;
                fs << left << setw(25) << "Grip tape grit:" << right << grit << endl;
                fs << left << setw(25) << "Total:" << right << "$" << total << endl;
                fs << endl;

                cin.ignore(); // clear leftover newline before next loop
            }

            break;
        }

        case 4:
            cout << "Thanks for visiting!" << endl;
            break;

        default:
            cout << "Invalid menu option." << endl;
            cout << endl;
            break;
        } // <-- closes switch(menu)

    } while (menu != 4); // <-- closes do-while loop

    return 0;
}
