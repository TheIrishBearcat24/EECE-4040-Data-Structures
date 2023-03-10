#include <iostream>
#include "Book.h"
#include "Person.h"

int main() {
    bool Quit = false;
    int Option;
    Book * NewBook = new Book();
    while (Quit==false) {
        // Ask for user input
        cout << "Please Enter Number of Option \n1. Add\n2. Delete\n3. Find\n4. Change\n5. Display\n6. Quit" << endl;
        cin >> Option;
        // Based on user input, do the desired function
        switch (Option) {
            case 1:{
                string FirstName;
                string LastName;
                string PhoneNumber;
                cout << "Please input the person's first name, last name, and phone number" << endl;
                cin >> FirstName;
                cin >> LastName;
                cin >> PhoneNumber;
                Person NewPerson;
                NewPerson.firstName = FirstName;
                NewPerson.lastName = LastName;
                NewPerson.phoneNumber = PhoneNumber;
                NewBook->addEntry(NewPerson);
                break;
            }
            case 2:{

                string FirstName;
                string LastName;
                cout << "Please input the person's first name and last name" << endl;
                cin >> FirstName;
                cin >> LastName;
                NewBook->deleteEntry(FirstName, LastName);
                break;
            }
            case 3:{
                string FirstName;
                string LastName;
                cout << "Please input the person's first name and last name" << endl;
                cin >> FirstName;
                cin >> LastName;
                try {
                    cout << NewBook->findPhoneNumber(FirstName, LastName);
                } catch (out_of_range) {
                    cout << "No person was found with that name." << endl;
                }
                break;
            }
            case 4:{
                string FirstName;
                string LastName;
                string NewPhoneNumber;
                cout << "Please input the person's first name, last name, and phone number" << endl;
                cin >> FirstName;
                cin >> LastName;
                cin >> NewPhoneNumber;
                try {
                    NewBook->changePhoneNumber(FirstName, LastName, NewPhoneNumber);
                } catch (out_of_range) {
                    cout << "No person was found with that name." << endl;
                }
                break;
            }
            case 5:
                NewBook->inorderTraversal(NewBook->logbook);
                break;
            case 6: {
                ofstream outputFile("textFile.txt");
                NewBook->quitAndSavePhoneBook(NewBook->logbook, outputFile);
                Quit = true;
                break;
            }
        }
    }
}
