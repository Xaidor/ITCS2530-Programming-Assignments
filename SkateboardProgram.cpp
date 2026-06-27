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
void trickRecommendations(string recs[], int size);
//setting up enum
enum SkillLevel {
    Beginner = 1,
    Amateur = 2,
    Professional = 3
};

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

//function that accepts an array as a parameter
void trickRecommendations(string recs[], int size) {
    int inputLevel;

    for (int i = 0; i < size; i++) {
        cout << "Please enter your skill level so we can recommend some new tricks for you to try!" << recs[i] << endl;
        cout << recs[i] << endl;
        cin >> inputLevel;

        SkillLevel level = static_cast<SkillLevel>(inputLevel);

        switch (level) {
        case Beginner:
            cout << "Some tricks you can try includ an Ollie, Tic-Tacs, or kickturns. \n";
            break;
        case Amateur:
            cout << "Some tricks you can try includ a 360 flip, smith grind, or an airwalk.\n";
            break;
        case Professional:
            cout << "Some tricks you can try includ a laser flip, 50-50 grind, or a manual wheelie.\n";
            break;
        default:
            cout << "Please enter a level between 1-3.\n";
        }
    }
}
// ===================== CUSTOMIZE 3 BOARDS =====================
void customizeBoards() {
    string recommendation;
    cout << "Great! Let's customize 3 boards.\n\n";
    //adding intro for enum set up
    cout << "Do you want recommendations based on what your skill rating is? ";
    cin >> recommendation;
    if (recommendation == "yes") {
        cout << "We are happy to help!\n";
        int levelInput;
        cout << "Please enter your skill level between 1 and 3. Level 1 is an absolute beginner and level 3 is a professional, or someone who has been skating for years.";
        cin >> levelInput;

        SkillLevel level = static_cast<SkillLevel>(levelInput);

        switch (level) {
        case Beginner:
            cout << "For beginner skaters, we recommend trying a mix of sizes and grit tape. Skateboarders tend to have a personal preference, and it is unfortunately not a one size fits all thing. If you try a few options out, it'll be easier to determine what you like and what you don't like for the next time you order. Nothing you can choose will make a board unusable, it just comes down to personal preference! \n";
            break;

        case Amateur:
            cout << "You probably have a good idea of what you like in a board. We do recommend trying a new size or a new type of grit if it's been a while! Sometimes it's easier to learn on one thing, but as you progress in the skill, you can learn you like something that you didn't when you first started!\n";
            break;

        case Professional:
            cout << "As a professional, you probably know exactly what you like to skate on and that's great! Sometimes it can be fun or a bit of a challenge to try something new, though, and if you've been skating on the same kind of board for years, it might be nice to switch it up a bit!\n";
            break;

        default:
            cout << "Please enter a level 1-3.\n";
        }
    }
    else {
        cout << "Great! Continue on to make your selections.\n";
    }

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

    //array storing multiple user inputs to compare prices, only allows three entries
    int prices[3];
    int sum = 0;

    cout << "How much did you pay for the last three skateboards your purchased?\n";
    for (int i = 0; i < 3; i++) {
        cin >> prices[i];
        sum += prices[i];
    }
    cout << "On average, you have spent $" << sum / 3 << " on skateboards in the past. We try to keep our prices fair, but we can assure you that the quality of our boards is top notch! \n";


    //function that accepts an array as a parameter
    string recs[3] = { "Level 1", "Level 2", "Level 3" };
    int size = 3;
    trickRecommendations(recs, 3);
}