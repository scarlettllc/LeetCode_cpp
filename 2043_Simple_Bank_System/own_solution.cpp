class Bank {
public:
    vector<long long> balance;
    int n;
    Bank(vector<long long>& balance) {
        this->n = balance.size();
        this->balance.push_back(0);
        for (auto & item : balance) {
            this->balance.push_back(item);
        }
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (account1 >= 1 && account1 <= n && account2 >= 1 && account2 <= n && balance[account1] >= money) {
            balance[account1] -= money;
            balance[account2] += money;
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if (account < 1 || account > n) {
            return false;
        }
        balance[account] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (account < 1 || account > n || balance[account] < money) {
            return false;
        }
        balance[account] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */