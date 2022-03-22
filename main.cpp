#include <iostream>
#include <stdlib.h>

//using namespace std;

// account class
class Account{
public:

    void createAccount(std::string accountName, int accountPin, int balance){
        int idNum;
        // random ID
        idNum = rand() % 89451 + 17894652;

        // test
        std::cout << "Account name: " << accountName << " with a pin of " << accountPin << " has $" << balance << " in account." << std::endl;
        std::cout << "ID: " << idNum;

        // save account
    }

    // view the details of an existing account
    void viewDetails(){;}

};

// function to display requested account through name, will pass details to account viewDetails
void srchAccount(std::string name){
    ;
}

/* - id will be randomly generated
   - turn this to a class
   - temporarily a function
*/

/*
void createAccount(std::string accountName, int accountPin, int balance){

    int idNum;
    // random ID
    idNum = rand() % 89451 + 17894652;

    // test
    std::cout << "Account name: " << accountName << " with a pin of " << accountPin << " has $" << balance << " in account." << std::endl;
    std::cout << "ID: " << idNum;

    //saveacount

}
*/
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
                    std::cout << "Pin number can not be any non-three digit number.";
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
