#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

// ===================== Declaring Functions =====================

void displayBanner();
int displayMenu();
string getBrand();
double getBoardSize();
int getGrit();
double calculateTotal(double size, int grit);
void saveReport(int boardNum, string brand, double size, int grit, double total);
void customizeBoards();

// ===================== MAIN =====================
int main() {
    displayBanner();
    

    int menu = 0;

    do {
        menu = displayMenu();

        switch (menu) {
        case 1:
            cout << "Email: examplerun@email.com\n";
            cout << "Number: 333-222-5555\n\n";
            break;

        case 2:
            cout << "Order details are saved in report.txt\n\n";
            break;

        case 3:
            customizeBoards();
            break;

        case 4:
            cout << "Thanks for visiting!\n";
            break;

        default:
            cout << "Invalid menu option.\n\n";
        }

    } while (menu != 4);

    return 0;
}

// ===================== BANNER =====================
void displayBanner() {
    const string BLUE = "\033[96m";   // light blue 
    const string RESET = "\033[0m";
    const string RED = "\033[91m";

    cout << BLUE;  // turn text light blue

    cout << setfill(' ') << right;

    cout << setw(50) << "**      *******  ********   *****" << endl;
    cout << setw(46) << "**      ***         **     **" << endl;
    cout << setw(50) << "**      ******      **      *****" << endl;
    cout << setw(50) << "***     ***         **         **" << endl;
    cout << setw(50) << "******  *******     **     ******" << endl;

    cout << RESET;
    cout << endl;

    cout << RED;

    cout << setw(68) << " *****  **   **  ******   *******  *****" << endl;
    cout << setw(70) << "**      **   **  ***  **  ***      **  **" << endl;
    cout << setw(70) << " *****  *******  *****    ******   **  **" << endl;
    cout << setw(70) << "    **  **   **  ** **    ***      **  **" << endl;
    cout << setw(68) << "******  **   **  **  **   *******  *****" << endl;

    cout << RESET;  // reset to normal
    cout << endl;
}


// ===================== MENU =====================
int displayMenu() {
    int choice;
    cout << "Enter \n1 Contact Us \n2 View Order \n3 Customize Board \n4 Exit: ";
    cin >> choice;
    cout << endl;
    return choice;
}

// ===================== INPUT FUNCTIONS =====================
string getBrand() {
    cin.ignore();
    string brand;
    cout << "Enter skateboard brand: ";
    getline(cin, brand);
    return brand;
}

double getBoardSize() {
    double size;
    cout << "Enter board size (7.0 - 9.0): ";
    while (!(cin >> size) || size < 7.0 || size > 9.0) {
        cout << "Invalid size. Enter a number between 7.0 and 9.0: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    return size;
}

int getGrit() {
    int grit;
    cout << "Enter grip tape grit (60 - 100): ";
    while (!(cin >> grit) || grit < 60 || grit > 100) {
        cout << "Invalid grit. Enter a number between 60 and 100: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    return grit;
}

// ===================== CALCULATION =====================
double calculateTotal(double size, int grit) {
    const double basePrice = 60.00;
    const double sizeFee = size * 3.00;
    const double gritFee = grit * 0.10;
    return basePrice + sizeFee + gritFee;
}

// ===================== SAVE REPORT =====================
void saveReport(int boardNum, string brand, double size, int grit, double total) {
    ofstream fs("report.txt", ios::app);

    fs << fixed << setprecision(2);
    fs << "===== Board #" << boardNum << " Summary =====\n";
    fs << left << setw(25) << "Favorite Brand:" << right << brand << endl;
    fs << left << setw(25) << "Board Size:" << right << size << endl;
    fs << left << setw(25) << "Grip tape grit:" << right << grit << endl;
    fs << left << setw(25) << "Total:" << right << "$" << total << endl;
    fs << endl;
}

// ===================== CUSTOMIZE 3 BOARDS =====================
void customizeBoards() {
    cout << "Great! Let's customize 3 boards.\n\n";

    for (int i = 1; i <= 3; i++) {
        cout << "----- Customizing Board #" << i << " -----\n";

        string brand = getBrand();
        double size = getBoardSize();
        int grit = getGrit();

        double total = calculateTotal(size, grit);

        cout << "\n===== Board #" << i << " Summary =====\n";
        cout << left << setw(25) << "Favorite Brand:" << right << brand << endl;
        cout << left << setw(25) << "Board Size:" << right << size << endl;
        cout << left << setw(25) << "Grip tape grit:" << right << grit << endl;
        cout << left << setw(25) << "Total:" << right << "$" << total << endl;

        cout << "\nExcellent taste. Hand over $" << total
            << " and we'll start crafting your future wipeouts.\n\n";

        saveReport(i, brand, size, grit, total);

    }
}

