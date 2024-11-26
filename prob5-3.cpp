#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Stack {
private:
    vector<int> n;
public:
    Stack() {};

    void push(int p) {
        n.push_back(p);
    }
    void pop() {
        if (!n.empty()) {
            n.pop_back();
        }
    }
    int back() {
        return n.back();
    }
    void out() {
        for (int i : n) {
            cout << i;
        }
        cout << endl;
    }
    int size() {
        return n.size();
    }
};

int main() {
    Stack s;
    string a;
    int b;
    int count = 0;

    cin >> a;  
    cin >> b;  

    for (int i = 0; i < a.length(); i++) {
        int p = a[i] - 48;  

        while (s.size() > 0 && p > s.back() && count < b) {
            s.pop();
            count++;
        }
        s.push(p);
    }
    s.out();

    return 0;
}