#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void login();
void registr();
void usermenu();

int main(){
    int choice, pin, p;
    string user, u;

    system("cls");
    cout<<"\tWELCOME TO SYAMS BANK\n";
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
    int count, pin, balance, p, b;
    string user, u;

    system("cls");
    cout<<"Please enter your username and pin\n";
    cout<<"Username : ";
    cin>>user;
    cout<<"PIN      : ";
    cin>>pin;

    ifstream input("userdata.txt");
    while(input>>u>>p>>b){
        if(p==pin){
            count=1;
            system("cls");
        }
    }
    input.close();
    if(count==1){
        usermenu();
    }
    else{
        cout<<"\nLogin error, please check your username and password\n";
        main();
    }

    // return user;
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
    if(regbalance&50000==0){
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

void balanceinform(){
    int count, balance, pin, b, p;
    string user, u;

    system("cls");

    cout<<"\nInsert your PIN  : ";
    cin>>pin;

    ifstream saldo("userdata.txt");
    while(saldo>>u>>p>>b){
        if(p==pin){
            count=1;
        }

        // if(p==pin){
        //     string next;

        //     system("cls");
        //     cout<<"Your balance is : Rp. "<<b;

        //     cout<<"\n\nNext(press y)? : ";
        //     cin>>next;

        //     if(next=="y" || next=="Y"){
        //         usermenu();
        //     }
        //     else{
        //         balanceinform();
        //     }
        // }
        // else{
        //     balanceinform();
        // }
    }
    saldo.close();

    if(count=1){
        system("cls");
        cout<<"Your balance is : Rp. "<<b;
        cin.get();
        cin.get();
        system("cls");
        usermenu();
    }
    else{
        cout<<"sorry";
    }
}

void transfer(){
    int tf;

    cout<<"\t   Transger\n";
    cout<<"=====================================\n";
    cout<<"Masukkan nominal transfer: ";
    cin>>tf;
    usermenu();
}

void usermenu(){

    int choice;
    system("cls");
    cout<<"\t   Select One\n";
    cout<<"=====================================\n";
    cout<<"1. Balance Information\n";
    cout<<"2. Transfer\n";
    cout<<"3. Change PIN (soon)\n";

    cout<<"Insert your choice(1-3): ";
    cin>>choice;

    switch (choice){
        case 1:
            balanceinform(); break;
        case 2:
            registr(); break;
        case 3:
            system("cls");
            cout<<"Thanks for using this program"; break;
        break;
        default:
            cout<<"\nYour input is invalid"; 
            usermenu(); break;
    }
}