// Password Generator Project
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

string generatePassword(int length) {
    string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()";
    string password = "";
    srand(time(0));

    for (int i = 0; i < length; i++) {
        password += chars[rand() % chars.length()];
    }
    return password;
}

int main() {
    int length;
    cout << "Enter password length: ";
    cin >> length;

    if (length < 6) {
        cout << "Password should be at least 6 characters long!" << endl;
        return 1;
    }

    string password = generatePassword(length);
    cout << "Generated Password: " << password << endl;
    return 0;
}
