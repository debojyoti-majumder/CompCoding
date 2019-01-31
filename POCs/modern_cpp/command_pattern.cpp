#include <iostream>

using namespace std;

struct Command {
    virtual void call() = 0;
    virtual void undo() = 0;
};

struct BankAccount {
    int balance = 0;
    int overdarftLimit = -500;

    explicit BankAccount(int initAmt) {
        balance = initAmt;
    }

    void deposite(int amount) {
        balance += amount;
        cout << "Balance after deposite: " << balance << endl;
    }

    bool withdraw(int amt) {
        if( balance - amt >= overdarftLimit ) {
            balance -= amt;
            cout << "Balance after withdrawl: " << balance << endl;

            return true;
        }

        return false;
    }
};

// This is actually an incorrect implentation, because money can not come from air
// It would require two accounts to be there
struct BankAccountCommand : Command {
    BankAccount& account;
    enum Action {deposite, withdrawl} action;
    int ammount;
    bool withdrawlSuccedded = true, commandExecuted;

    BankAccountCommand(BankAccount& account, const Action a, const int amt) :
    account(account), action(a), ammount(amt) {
        commandExecuted = false;
    }

    void call() override {
        // This field to make sure that action can be undone if done already 
        commandExecuted = true;

        switch(action) {
            case deposite:
                account.deposite(ammount);
                break;

            case withdrawl:
                withdrawlSuccedded = account.withdraw(ammount);
                break;
        }
    }

    void undo() {
        switch(action) {
            case deposite:
                account.withdraw(ammount);
                break;

            case withdrawl:
                if( withdrawlSuccedded && commandExecuted ) account.deposite(ammount);
                break;
        }
    }
};

int main() {
    BankAccount myAcc(200);
    
    BankAccountCommand depo{myAcc, BankAccountCommand::deposite, 4000};
    BankAccountCommand wthl{myAcc, BankAccountCommand::withdrawl, 320};
    BankAccountCommand wthlShouldFail{myAcc, BankAccountCommand::withdrawl, 3200000};
    
    depo.call();
    wthl.call();
    wthl.undo();

    wthlShouldFail.call();
    wthlShouldFail.undo();

    cout << "End balance: " << myAcc.balance << endl;
    return 0;
}
