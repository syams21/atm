#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void login();
void registr();
void usermenu();

main(){
    int choice;

    cout<<"\n\n\tWELCOME TO SYAMS BANK\n";
    cout<<"=====================================\n";
    cout<<"1. Login\n";
    cout<<"2. Register\n";
    cout<<"3. Exit\n";

    cout<<"Insert your choice(1-3): ";
    cin>>choice;

    switch (choice){
        case 1:
            login(); break;
        case 2:
            registr(); break;
        case 3:
            system("cls");
            cout<<"Thanks for using this program"; break;
    break;
        default: cout<<"\nYour input is invalid"; break;
    }
}

void login(){
    int count;
    string user, u;
    int pin, balance, p, b;
    system("cls");
    cout<<"Please enter your username and pin\n";
    cout<<"Username : ";
    cin>>user;
    cout<<"PIN      : ";
    cin>>pin;

    ifstream input("userdata.txt");
    while(input>>u>>p>>b){
        if(u==user && p==pin){
            count=1;
            system("cls");
        }
    }
    input.close();
    if(count==1){
        cout<<"\nHello "<<user;
        cin.get();
        main();
    }
    else{
        cout<<"\nLogin error, please check your username and password\n";
        main();
    }
}

void registr(){
    string reguser, ru;
    int regpin, regbalance, rp, rb;
    system("cls");
    
    cout<<"\nInsert your username: ";
    cin>>reguser;
    cout<<"\nInsert your PIN : ";
    cin>>regpin;
    cout<<"\nInsert your balance: ";
    cin>>regbalance;
    if(regbalance%50000==0){
        ofstream reg("userdata.txt", ios::app);
        reg<<reguser<<' '<<regpin<<' '<<regbalance<<endl;
        system("cls");
        cout<<"\n Registration Succesfull\n";
        main();
    }
    else{
        registr();
    }
}

void usermenu(){
    int choice;

    cout<<"\n\n\tSelect One\n";
    cout<<"=====================================\n";
    cout<<"1. Balance Information\n";
    cout<<"2. Transfer\n";
    cout<<"3. Change PIN (soon)\n";

    cout<<"Insert your choice(1-3): ";
    cin>>choice;

    switch (choice){
        case 1:
            login(); break;
        case 2:
            registr(); break;
        case 3:
            system("cls");
            cout<<"Thanks for using this program"; break;
    break;
        default: cout<<"\nYour input is invalid"; break;
    }
}