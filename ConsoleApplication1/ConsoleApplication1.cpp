#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class BankAccount {
private:
    int accountNumber;
    double balance;
    double interestRate;

public:
    BankAccount(int num, double initialBalance) {
        accountNumber = num;
        balance = initialBalance;
        interestRate = 0.0;
    }

    void deposit() {
        double amount;
        cout << "Введите сумму для депозита: ";
        cin >> amount;

        if (amount > 0) {
            balance += amount;
            cout << "Депозит в размере " << amount << " успешно зачислен на ваш счет." << endl;
        }
        else {
            cout << "Некорректная сумма для депозита. Попробуйте еще раз." << endl;
        }
    }

    void withdraw() {
        double amount;
        cout << "Введите сумму для снятия: ";
        cin >> amount;

        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Снятие в размере " << amount << " успешно выполнено." << endl;
        }
        else {
            cout << "Некорректная сумма для снятия или недостаточно средств на счете." << endl;
        }
    }

    double getBalance() {
        return balance;
    }

    double getInterest() {
        return balance * interestRate * (1.0 / 12.0);
    }

    void setInterestRate(double rate) {
        if (rate >= 0) {
            interestRate = rate;
            cout << "Процентная ставка успешно обновлена." << endl;
        }
        else {
            cout << "Некорректная процентная ставка. Попробуйте еще раз." << endl;
        }
    }

    int getAccountNumber() {
        return accountNumber;
    }

    friend bool transfer(BankAccount& from, BankAccount& to, double amount);
};

bool transfer(BankAccount& from, BankAccount& to, double amount) {
    if (amount > 0 && amount <= from.getBalance()) {
        from.balance -= amount;
        to.balance += amount;
        cout << "Перевод в размере " << amount << " с счета " << from.getAccountNumber() << " на счет " << to.getAccountNumber() << " успешно выполнен." << endl;
        return true;
    }
    else {
        cout << "Некорректная сумма перевода или недостаточно средств на счете." << endl;
        return false;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    int accountNum1, accountNum2;
    double initialBalance1, initialBalance2;

    cout << "Введите номер счета 1: ";
    cin >> accountNum1;
    cout << "Введите начальный баланс счета 1: ";
    cin >> initialBalance1;

    cout << "Введите номер счета 2: ";
    cin >> accountNum2;
    cout << "Введите начальный баланс счета 2: ";
    cin >> initialBalance2;

    BankAccount account1(accountNum1, initialBalance1);
    BankAccount account2(accountNum2, initialBalance2);

    int choice;
    do {
        cout << "\nМеню:\n";
        cout << "1. Внести средства на счет\n";
        cout << "2. Снять средства со счета\n";
        cout << "3. Вывести баланс счета\n";
        cout << "4. Рассчитать и вывести проценты\n";
        cout << "5. Обновить процентную ставку\n";
        cout << "6. Перевести средства между счетами\n";
        cout << "0. Выйти\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "Выберите счет (1 или 2): ";
            int accountChoice;
            cin >> accountChoice;
            if (accountChoice == 1) {
                account1.deposit();
            }
            else if (accountChoice == 2) {
                account2.deposit();
            }
            else {
                cout << "Некорректный выбор счета." << endl;
            }
            break;
        }
        case 2: {
            cout << "Выберите счет (1 или 2): ";
            int accountChoice;
            cin >> accountChoice;
            if (accountChoice == 1) {
                account1.withdraw();
            }
            else if (accountChoice == 2) {
                account2.withdraw();
            }
            else {
                cout << "Некорректный выбор счета." << endl;
            }
            break;
        }
        case 3:
            cout << "Баланс счета " << account1.getAccountNumber() << ": " << account1.getBalance() << endl;
            cout << "Баланс счета " << account2.getAccountNumber() << ": " << account2.getBalance() << endl;
            break;
        case 4:
            cout << "Ожидаемая сумма с процентами на счете " << account1.getAccountNumber() << ": " << account1.getInterest() << endl;
            cout << "Ожидаемая сумма с процентами на счете " << account2.getAccountNumber() << ": " << account2.getInterest() << endl;
            break;
        case 5:
            double newRate;
            cout << "Введите новую процентную ставку: ";
            cin >> newRate;
            account1.setInterestRate(newRate);
            account2.setInterestRate(newRate);
            break;
        case 6: {
            double amount;
            cout << "Введите сумму для перевода: ";
            cin >> amount;
            if (transfer(account1, account2, amount)) {

            }
            else {

            }
            break;
        }
        case 0:
            cout << "До свидания!" << endl;
            break;
        default:
            cout << "Некорректный выбор. Попробуйте еще раз." << endl;
        }
    } while (choice != 0);

    return 0;
}
