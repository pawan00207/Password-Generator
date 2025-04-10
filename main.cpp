// Password Generator Code
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

string generatePassword(int length, bool useUpper, bool useLower, bool useDigits, bool useSpecial) {
    string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lower = "abcdefghijklmnopqrstuvwxyz";
    string digits = "0123456789";
    string special = "!@#$%^&*()_+=-[]{}|;:,.<>?";

    string charPool = "";
    if (useUpper) charPool += upper;
    if (useLower) charPool += lower;
    if (useDigits) charPool += digits;
    if (useSpecial) charPool += special;

    if (charPool.empty()) {
        return "Error: No character set selected!";
    }

    string password = "";
    srand(time(0));
    for (int i = 0; i < length; i++) {
        password += charPool[rand() % charPool.length()];
    }
    return password;
}

int main() {
    int length;
    char upper, lower, digits, special;

    cout << "Enter password length: ";
    cin >> length;

    cout << "Include uppercase letters? (y/n): ";
    cin >> upper;
    cout << "Include lowercase letters? (y/n): ";
    cin >> lower;
    cout << "Include digits? (y/n): ";
    cin >> digits;
    cout << "Include special characters? (y/n): ";
    cin >> special;

    string password = generatePassword(length, upper == 'y', lower == 'y', digits == 'y', special == 'y');
    
    cout << "Generated Password: " << password << endl;

    return 0;
}
