# Bank Management System

A simple C++ Bank Management System designed to simulate basic banking operations such as creating accounts, logging in, depositing and withdrawing money, and viewing all registered accounts. This project utilizes file handling to store account information persistently.

## Features

### Account Creation:
- Create a new account by providing basic details (name, age, gender, username, phone number, and password).
- Automatically generates a unique account number for each user.
- Stores account details securely in a file (`accounts.txt`).

### Login:
- Securely log in using the account number and password.
- Validates credentials against stored account data.

### Deposit Money:
- Deposit a specified amount into a registered account.
- Updates the account balance in the file.

### Withdraw Money:
- Withdraw a specified amount from a registered account.
- Checks for sufficient balance before proceeding.

### View All Accounts:
- Displays the details of all registered accounts, including the account number, name, age, gender, phone number, username, and balance.

### File Handling:
- All account data is stored persistently in `accounts.txt`, ensuring data is not lost when the program ends.

## File Structure
. ├── accounts.txt # Stores account details in a comma-separated format                                                                                                                    
. ├── main.cpp # Main source file containing the banking system implementation

### Account Details Format in `accounts.txt`:
Each account is stored as a single line in the file:

#### Example:
<accountno>,<name>,<age>,<gender>,<phone>,<username>,<password>,<balance>
101,John Doe,30,Male,1234567890,johndoe,password123,5000.50 102,Jane Smith,25,Female,9876543210,janesmith,securepass,3000.75

## Menu Options:
The program provides the following menu:

1. **Create Account**: Create a new account.
2. **Login**: Log in to an existing account.
3. **Deposit**: Deposit money into an account.
4. **View All Accounts**: Display all registered accounts.
5. **Withdraw**: Withdraw money from an account.
6. **Exit**: Exit the program.

## Prerequisites
- A C++ compiler (e.g., g++).
- A text editor or IDE for running the program (e.g., VS Code, Code::Blocks, CLion).

## Usage

1. Clone the repository:

   ```bash
   git clone https://github.com/yourusername/bank-management-system.git
   cd bank-management-system
2. Compile the program:
g++ -o bank main.cpp
3. Run the executable:
./bank
Example Run
Sample Menu Interaction:
1. Create Account
2. Login
3. Deposit
4. View All Accounts
5. Withdraw
6. Exit

Enter your choice: 1

Enter the name: John Doe
Enter the age: 30
Enter the Gender: Male
Enter your Phone no: 1234567890
Enter Username: johndoe
Enter your Password: password123
Account created successfully! Your account number is: 101

Enter your choice: 2
Enter your Account Number: 101
Enter your Password: password123
Login successful! Welcome, John Doe!

Enter your choice: 3
Enter the Account No: 101
Enter the Amount you want to deposit: 2000
Deposit successful! New Balance: 7000.50
#Future Enhancements
Implement encryption for storing passwords.
Add functionality to update user details.
Introduce role-based access control (e.g., admin functionalities).
Provide an interactive GUI using a web or desktop application.

#License
This project is open-source and available under the MIT License.

Just replace the repository URL (`https://github.com/yourusername/bank-management-system.git`)
