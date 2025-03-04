#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

class BankAccount{
private:
    string name;
    int accountNum;
    double balance;
public:
    BankAccount(string n, int ac, double bal){
        name = n;
        accountNum = ac;
        balance = bal;
    }
    string getName(){
        return name;
    }
    int getAccountNum(){
        return accountNum;
    }
    double getBalance(){
        return balance;
    }
    void deposit(double amount){
        balance += amount;
    }
    void withdraw(double amount){
        if(balance >= amount){
            balance -= amount;
            cout << "\t\tWithdrawal has been Successful..." << endl;
        }else{
            cout << "\t\tInsufficient Balance...." << endl;
        }
    }
};

class BankManagement{
private:
    vector<BankAccount> accounts;
public:
    void AddAccount(string name, int accountNum, double balance){
        accounts.push_back(BankAccount(name, accountNum, balance));
    }
    void showAllAccounts(){
        cout << "\n\t\tAll Account Holders" << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << left << setw(20) << "Name" << setw(20) << "Account Number" << setw(15) << "Balance" << endl;
        cout << "-------------------------------------------------------" << endl;
        for(auto &acc : accounts){
            cout << left << setw(20) << acc.getName() << setw(20) << acc.getAccountNum() << setw(15) << acc.getBalance() << endl;
        }
        cout << "-------------------------------------------------------" << endl;
    }
    void searchAccount(int account){
        cout << "\t\tAccount Holder" << endl;
        for(auto &acc : accounts){
            if(acc.getAccountNum() == account){
                cout << "Name: " << acc.getName() << " | Account Number: " << acc.getAccountNum() << " | Balance: " << acc.getBalance() << endl;
                return;
            }
        }
        cout << "Account Not Found..." << endl;
    }
    BankAccount* findAccount(int accountNum){
        for(auto &acc : accounts){
            if(acc.getAccountNum() == accountNum){
                return &acc;
            }
        }
        return nullptr;
    }
};

int main(){
    BankManagement bank;
    int choice;
    char op;
    do{
        system("cls");
        cout << "\t\t:: Bank Management System ::" << endl;
        cout << "\t\t\tMain Menu" << endl;
        cout << "\t\t1. Create a New Account" << endl;
        cout << "\t\t2. Show All the Accounts" << endl;
        cout << "\t\t3. Search for Account" << endl;
        cout << "\t\t4. Deposit Money" << endl;
        cout << "\t\t5. Withdraw Money" << endl;
        cout << "\t\t6. Exit" << endl;
        cout << "\t\t-------------------------------" << endl;
        cout << "\t\tEnter Your Choice: ";
        cin >> choice;

        switch(choice){
            case 1:{
                string name;
                int accountNum;
                double balance;
                cout << "\t\tEnter the Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "\t\tEnter the Account Number: ";
                cin >> accountNum;
                cout << "\t\tEnter the Initial Balance: ";
                cin >> balance;
                bank.AddAccount(name, accountNum, balance);
                cout << "\t\tAccount Created Successfully...." << endl;
                break;
            }
            case 2:{
                bank.showAllAccounts();
                break;
            }
            case 3:{
                int accountNum;
                cout << "\t\tEnter the Account Number: ";
                cin >> accountNum;
                bank.searchAccount(accountNum);
                break;
            }
            case 4:{
                int accountNum;
                double amount;
                cout << "\t\tEnter the  Account Number to Deposit Money: ";
                cin >> accountNum;
                BankAccount* account = bank.findAccount(accountNum);
                if(account != nullptr){
                    cout << "\t\tEnter the Amount to Deposit: ";
                    cin >> amount;
                    account->deposit(amount);
                    cout << "\t\t" << amount << " The Amount has Been Deposited Successfully...." << endl;
                }else{
                    cout << "\t\tAccount Not Found..." << endl;
                }
                break;
            }
            case 5:{
                int accountNum;
                double amount;
                cout << "\t\tEnter the Account Number to Withdraw Money: ";
                cin >> accountNum;
                BankAccount* account = bank.findAccount(accountNum);
                if(account != nullptr){
                    cout << "\t\tEnter the Amount to Withdraw: ";
                    cin >> amount;
                    account->withdraw(amount);
                }else{
                    cout << "\t\tAccount Not Found..." << endl;
                }
                break;
            }
            case 6:{
                exit(0);
            }
            default:{
                cout << "\t\tInvalid Choice! Please Try Again..." << endl;
            }
        }
        cout << "\t\tDo You Want to Continue or Exit the Process [Y/N]? ";
        cin >> op;
    }while(op == 'y' || op == 'Y');
    return 0;
}
