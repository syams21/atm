#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void displayMenu(){
    cout<<"\n\n\tWELCOME TO SYAMS BANK\n";
    cout<<"=====================================\n";
    cout<<"1. Create New Account\n";
    cout<<"2. Login\n";
    cout<<"3. Exit\n";
}

void createAccount(){
    string name;
    int pin;

    cout<<"\nInsert your name: ";
    cin>>name;
    cout<<"\nInsert your PIN : ";
    cin>>pin;
}

void login(){

}

int main(){
    int choice;
    displayMenu();
    cout<<"Insert your choice(1-2): ";
    cin>>choice;

    switch (choice){
        case 1: createAccount(); break;
        case 2: login(); break;
        default: cout<<"\ninvalid"; break;
    }
}