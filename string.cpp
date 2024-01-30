#include <iostream>

using namespace std;

int main() {
    const int MAX_SIZE = 100; // Assuming a maximum size for first and last names
    char firstName[MAX_SIZE], lastName[MAX_SIZE], fullName[MAX_SIZE * 2];

    cout << "Enter your first name: ";
    cin >> firstName;

    cout << "Enter your last name: ";
    cin >> lastName;

    // Concatenate first and last names with a space in between
    sprintf(fullName, "%s %s", firstName, lastName);

    cout << "Full name: " << fullName << endl;

    return 0;
}
