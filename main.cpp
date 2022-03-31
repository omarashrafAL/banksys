#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cstdio>

//using namespace std;

/*

--BUGS--
* Entering a large number in balance causes an infinite loop

*/

void modifyAccount(std::string oldAcc/*match the same line to detect it instead of an individual word*/,
                   /*new details >>>*/ std::string newName, std::string sameID, std::string newPin, std::string newBalance){
    std::string ogLine;
    std::fstream file, newFile;

    file.open("accounts.txt");
    newFile.open("accountsNew.txt", std::ios_base::app);

    while(getline(file, ogLine)){
        if(ogLine == oldAcc){
            ;
        }

        else{
            newFile << ogLine << std::endl;
        }

    }

    newFile << newName << "*" << sameID << ":" << newPin << "#" << newBalance;

    if(file.is_open()){
        file.close();
        newFile.close();
        //std::cout << "FILE CLOSED";
    }

    // now, everything is set to place, empty the original accounts file and dump the new file into it and empty the new one

    // empty the original file
    std::ofstream originalFile;
    originalFile.open("accounts.txt");
    originalFile.close();

    originalFile.open("accounts.txt", std::ios_base::app);
    newFile.open("accountsNew.txt");

    // add the new accounts to the original file
    std::string newLine;

    while(getline(newFile, newLine)){
        originalFile << newLine << std::endl;
    }

    if(originalFile.is_open() && newFile.is_open()){
        originalFile.close();
        newFile.close();
    }

    std::ofstream clearNew;

    // empty the new file
    clearNew.open("accountsNew.txt");
    clearNew << "";
    clearNew.close();

}

// account class
class Account{
public:

    // create a new account
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

    // view or update the details of an existing account
    void details(std::string name, char type){
        std::string nameLower = name; // variable to turn into lower

        for(int i = 0; i < nameLower.length(); i++){
            nameLower[i] = ::tolower(nameLower[i]);
        }

        std::string line;
        std::fstream fileGet;
        bool accountFound = false;
        int skip = false; // variable assigned a value to skip the first blank line in file

        fileGet.open("accounts.txt");

        std::string stName, stId, stPin, stBalance; // final variables to use

        while(getline(fileGet, line) && !accountFound){

            std::string nameF, idF, pinF, balanceF, store; // account variables from file
            if(!skip){
                skip = true;
                }

            else if(skip){
                for(int i = 0; i <= line.length(); i++){
                    store = store + line[i];
                    if(line[i] == '*')/* full name */{
                        store.pop_back();
                        nameF = store;
                        store = "";
                    }
                    else if(line[i] == ':')/* account ID */{
                        store.pop_back();
                        idF = store;
                        store = "";
                    }
                    else if(line[i] == '#')/* account pin */{
                        store.pop_back();
                        pinF = store;
                        store = "";
                    }
                }

                balanceF = store;
                std::string nameFlower = nameF; // variable to turn into all lowercase

                for(int i = 0; i <= nameFlower.length(); i++){
                    nameFlower[i] = ::tolower(nameFlower[i]);
                }

                if(nameLower == nameFlower){
                    stName = nameF;
                    stId = idF;
                    stPin = pinF;
                    stBalance = balanceF;

                    // we stored all, now to check pin
                    std::string pinEnter;

                    while(true){
                        std::cout << "PIN: ";
                        std::cin >> pinEnter;

                        if(pinEnter == "e"){
                            break;
                        }
                        else{
                            ;
                        }

                        // put this in a loop
                        if(pinEnter == stPin){

                            // enquire about balance
                            if(type == 'b'){
                                std::cout << stName << " has a balance of " /*<< stId << " " << stPin << " " <<*/ << "$" << stBalance << std::endl;
                                break;
                            }

                            // close/delete account
                            else if(type == 'c'){
                                line = "";
                                std::cout << "THIS RAN: " << line << std::endl;
                                break;
                            }

                            // modify an account
                            else if(type == 'm'){

                                // new details
                                std::string newName, sameID, newPin, newBalance;

                                std::cin.ignore();
                                std::cout << "NEW NAME('s' to use the old name): ";
                                getline(std::cin, newName);

                                if(newName == "s"){
                                    newName = stName;
                                }

                                // ID won't be changed
                                sameID = stId;

                                std::cout << "NEW PIN: ";
                                std::cin >> newPin;
                                std::cin.ignore();

                                std::cout << "NEW BALANCE: ";
                                std::cin >> newBalance;

                                modifyAccount(line, newName, sameID, newPin, newBalance);

                            }
                        }
                        else{
                            std::cout << "The pin that has been entered is wrong." << std::endl;
                        }
                    }

                }
                else{
                    std::cout << "\nThis account does not exist in the database.\n" << std::endl;
                }
            }

        }

        fileGet.close();
    }

};

int main()
{
    // main loop
    while(true){
        std::cout << "\t\t*** Bank system version 1.0.0 by Omar Ashraf ***\n" << std::endl;

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

            //account.viewDetails("Katness Everdeen");
            break;
        }
        case 2:
            system("CLS");
            std::cout << "There";
            break;

        // balance enquiry
        case 4:{

            while(true){
                std::string name;
                std::cout << "- Enquire Balance -" << std::endl;
                std::cout << "ACCOUNT NAME('e' to exit): ";
                getline(std::cin, name);

                // exit
                if(name == "e"){
                    break;
                }
                else{
                    ;
                }
                Account acc;
                acc.details(name, 'm');
            }
            break;
        }

        // exit program
        case 7:
            return 0;
        }

        // clear screen before starting a new session
        system("CLS");
        //break;

    }
    return 0;
}
