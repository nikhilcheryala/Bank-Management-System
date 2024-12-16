#include <bits/stdc++.h>
using namespace std;

class Account {
public:
    string name;
    int age;
    string username;
    string gender;
    long long phone;
    int accountno;
    string password;
    double balance;
    Account() : balance(0) {}
};

class Bank {
    static int accountnocounter;

public:
    Account acc;

    int accountgenerate() {
        return ++accountnocounter;
    }

    void accountcreate() {
        acc.accountno = accountgenerate();
        cin.ignore();
        cout << "Enter the name: ";
        getline(cin, acc.name);
        cout << "Enter the age: ";
        cin >> acc.age;
        cout << "Enter the Gender: ";
        cin >> acc.gender;
        cout << "Enter your Phone no: ";
        cin >> acc.phone;
        cout << "Enter Username: ";
        cin >> acc.username;
        cout << "Enter your Password: ";
        cin >> acc.password;

        ofstream outFile("accounts.txt");
        if (outFile.is_open()) {
            outFile << acc.accountno << ","
                    << acc.name << ","
                    << acc.age << ","
                    << acc.gender << ","
                    << acc.phone << ","
                    << acc.username << ","
                    << acc.password << ","
                    << acc.balance << endl;
            outFile.close();
        } else {
            cout << "Error opening file for writing!" << endl;
        }

        cout << "Account created successfully! Your account number is: " << acc.accountno << endl;
    }

    bool login() {
        int enteredAccNo;
        string enteredPassword;

        cout << "Enter your Account Number: ";
        cin >> enteredAccNo;
        cout << "Enter your Password: ";
        cin >> enteredPassword;

        ifstream inFile("accounts.txt");
        if (inFile.is_open()) {
            string line;
            while (getline(inFile, line)) {
                stringstream ss(line);
                string accountnoStr, name, age, gender, phone, username, password, balance;

                getline(ss, accountnoStr, ',');
                getline(ss, name, ',');
                getline(ss, age, ',');
                getline(ss, gender, ',');
                getline(ss, phone, ',');
                getline(ss, username, ',');
                getline(ss, password, ',');
                getline(ss, balance, ',');

                int fileAccountNo = stoi(accountnoStr);

                if (fileAccountNo == enteredAccNo && password == enteredPassword) {
                    cout << "Login successful! Welcome, " << name << "!" << endl;
                    inFile.close();
                    return true;
                }
            }
            inFile.close();
        } else {
            cout << "Error opening file for reading!" << endl;
        }

        cout << "Invalid Account Number or Password!" << endl;
        return false;
    }

    void deposit() {
        int accountno;
        double amount;
        cout << "Enter the Account No: ";
        cin >> accountno;
        cout << "Enter the Amount you want to deposit: ";
        cin >> amount;

        ifstream inFile("accounts.txt");
        ofstream tempFile("temp.txt");
        bool found = false;

        if (inFile.is_open() && tempFile.is_open()) {
            string line;
            while (getline(inFile, line)) {
                stringstream ss(line);
                string accountnoStr, name, age, gender, phone, username, password, balanceStr;
                getline(ss, accountnoStr, ',');
                getline(ss, name, ',');
                getline(ss, age, ',');
                getline(ss, gender, ',');
                getline(ss, phone, ',');
                getline(ss, username, ',');
                getline(ss, password, ',');
                getline(ss, balanceStr, ',');

                int fileAccountNo = stoi(accountnoStr);
                double fileBalance = stod(balanceStr);

                if (fileAccountNo == accountno) {
                    fileBalance += amount;
                    found = true;
                    cout << "Deposit successful! New Balance: " << fileBalance << endl;
                }

                tempFile << fileAccountNo << ","
                         << name << ","
                         << age << ","
                         << gender << ","
                         << phone << ","
                         << username << ","
                         << password << ","
                         << fileBalance << endl;
            }

            inFile.close();
            tempFile.close();

            remove("accounts.txt");
            rename("temp.txt", "accounts.txt");

            if (!found) {
                cout << "Account not found!" << endl;
            }
        } else {
            cout << "Error accessing file!" << endl;
        }
    }

    void withdraw() {
        int accountno;
        double amount;
        cout << "Enter the Account No: ";
        cin >> accountno;

        ifstream inFile("accounts.txt");
        ofstream tempFile("temp.txt");
        bool found = false;

        if (inFile.is_open() && tempFile.is_open()) {
            string line;
            while (getline(inFile, line)) {
                stringstream ss(line);
                string accountnoStr, name, age, gender, phone, username, password, balanceStr;
                getline(ss, accountnoStr, ',');
                getline(ss, name, ',');
                getline(ss, age, ',');
                getline(ss, gender, ',');
                getline(ss, phone, ',');
                getline(ss, username, ',');
                getline(ss, password, ',');
                getline(ss, balanceStr, ',');

                int fileAccountNo = stoi(accountnoStr);
                double fileBalance = stod(balanceStr);

                if (fileAccountNo == accountno) {
                    cout<<"Balance is : "<<fileBalance<<endl;
                    cout << "Enter the Amount you want to Withdraw: ";
                    cin >> amount;
                    if (fileBalance >= amount) {
                        fileBalance -= amount;
                        found = true;
                        cout << "Withdraw successful! New Balance: " << fileBalance << endl;
                    } else {
                        cout << "Insufficient balance!" << endl;
                        found = true;
                    }
                }

                tempFile << fileAccountNo << ","
                         << name << ","
                         << age << ","
                         << gender << ","
                         << phone << ","
                         << username << ","
                         << password << ","
                         << fileBalance << endl;
            }

            inFile.close();
            tempFile.close();

            remove("accounts.txt");
            rename("temp.txt", "accounts.txt");

            if (!found) {
                cout << "Account not found!" << endl;
            }
        } else {
            cout << "Error accessing file!" << endl;
        }
    }

    void readAccountsFromFile() {
        ifstream inFile("accounts.txt");
        if (inFile.is_open()) {
            string line;
            while (getline(inFile, line)) {
                stringstream ss(line);
                string accountno, name, age, gender, phone, username, password, balance;

                getline(ss, accountno, ',');
                getline(ss, name, ',');
                getline(ss, age, ',');
                getline(ss, gender, ',');
                getline(ss, phone, ',');
                getline(ss, username, ',');
                getline(ss, password, ',');
                getline(ss, balance, ',');

                cout << "Account Number: " << accountno << endl;
                cout << "Name: " << name << endl;
                cout << "Age: " << age << endl;
                cout << "Gender: " << gender << endl;
                cout << "Phone: " << phone << endl;
                cout << "Username: " << username << endl;
                cout << "Balance: " << balance << endl;
                cout << "------------------------" << endl;
            }
            inFile.close();
        } else {
            cout << "Error opening file for reading!" << endl;
        }
    }
};

int Bank::accountnocounter = 100;

int main() {
    Bank bank;
    int choice;

    do {
        cout << "\n1. Create Account\n2. Login\n3. Deposit\n4. View All Accounts\n5. Withdraw\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bank.accountcreate();
                break;
            case 2:
                bank.login();
                break;
            case 3:
                bank.deposit();
                break;
            case 4:
                bank.readAccountsFromFile();
                break;
            case 5:
                bank.withdraw();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}