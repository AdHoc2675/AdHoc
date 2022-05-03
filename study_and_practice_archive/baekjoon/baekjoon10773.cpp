#include <iostream>
using namespace std;

class myStack {
public:
    int stack[100001];
    int top;

    myStack();
    void push(int n);
    void pop();
    int numSum();
};

myStack::myStack() {
    top = 0;
}

void myStack::push(int n) {
    stack[top] = n;
    top++;
}

void myStack::pop() {
    top--;
}

int myStack::numSum() {
    int sum = 0;

    for (int i = 0; i < top; i++) {
        sum = sum + stack[i];
    }

    return sum;
}

int main()
{
    int repeatInput;
    int input;
    myStack s1;

    cin >> repeatInput;

    for (int i = 0; i < repeatInput; i++) {
        cin >> input;
        if (input == 0) {
            s1.pop();
        }
        else {
            s1.push(input);
        }
    }

    cout << s1.numSum();

    return 0;
}
