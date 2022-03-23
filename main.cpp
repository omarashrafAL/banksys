#include <iostream>
#include <stdlib.h>
#include <fstream>

//using namespace std;

// account class
class Account{
public:

    void createAccount(std::string accountName, int accountPin, int accountBalance){
        int idNum;
        // random ID
        idNum = rand() % 89451 + 17894652;

        // test
        std::cout << "Account name: " << accountName << " with a pin of " << accountPin << " has $" << accountBalance << " in account." << std::endl;
        std::cout << "ID: " << idNum;

        // save account
        std::fstream fileAdd;
        fileAdd.open("accounts.txt", std::ios_base::app);
        fileAdd << "\n" << accountName << "*" << idNum << ":" << accountPin << "#" << accountBalance;
        fileAdd.close();
    }

    // view the details of an existing account
    void viewDetails(/*std::string accountName*/){
        std::string line;
        std::fstream fileGet;
        bool accountFound = false;

        fileGet.open("accounts.txt");

        while(getline(fileGet, line) && !accountFound){
            std::cout << line << std::endl;
            // variables for name, id, pin, balance
        }
        fileGet.close();
    }

};

int main()
{

    std::cout << "\t\t*** Bank system version 1.0.0 by Omar Ashraf ***\n" << std::endl;

    // main loop
    while(true){

        // display choices
        std::string choicesList[7] = {"1- NEW ACCOUNT", "2- DEPOSIT AMOUNT",
        "3- WITHDRAW AMOUNT", "4- BALANCE ENQUIRY", "5- CLOSE AN ACCOUNT",
        "6- MODIFY ACCOUNT", "7- EXIT"};

        for(int i = 0; i <= 6; i++){
            std::cout << choicesList[i] << std::endl;
        }

        int choice;

        std::cout << "\n>>> ";
        std::cin >> choice;
        std::cin.ignore();

        switch(choice){

        // create new account
        case 1:{
            // account properties
            std::string name;
            int pin;
            int balance;

            // account name
            std::cout << "ACCOUNT NAME: ";
            std::getline(std::cin, name);

            // pin loop
            while(true){
                std::cout << "NEW PIN: ";
                std::cin >> pin;

                // make sure pin is three digits
                if (std::to_string(pin).length() != 3){
                    std::cout << "Pin number can not be any non-three digit number.\n";
                    pin = 0;
                }

                else{
                    break;
                }
            }

            //system("CLS");

            // balance
            std::cout << "CURRENT BALANCE:";
            std::cin >> balance;

            Account account;

            account.createAccount(name, pin, balance);
            account.viewDetails();

            break;
        }
        case 2:
            system("CLS");
            std::cout << "There";
            break;

        // exit program
        case 7:
            return 0;
        }
        break;

    }
    return 0;
}
