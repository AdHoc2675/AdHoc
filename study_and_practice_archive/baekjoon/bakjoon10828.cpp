// bakjoon10828.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string.h>
using namespace std;

class mystack {
private:
    int s[10001];
    int topNum = -1;
public:
    void push_X(int n);
    void pop();
    void size();
    void empty();
    void top();
};

void mystack::push_X(int n){
    topNum++;
    s[topNum] = n;
};

void mystack::pop() {
    int n = 0;
    if (topNum == -1) {
        cout << "-1\n";
        return;
    }
    cout << s[topNum] << "\n";
    s[topNum] = 0;
    topNum--;
};

void mystack::empty() {
    if (topNum == -1) {
        cout << "1\n";
    }
    else {
        cout << "0\n";
    }
};

void mystack::size() {
    cout << topNum + 1 << "\n";
};

void mystack::top() {
    if (topNum == -1) {
        cout << "-1\n";
    }
    else {
        cout << s[topNum] << "\n";
    }
};

int main()
{
    int orderCount;
    string order;
    int pushNum;
    int emptyNum;
    mystack s1;

    cin >> orderCount;

    for (int i = 0; i < orderCount; i++) {
        cin >> order;

        if (order == "push") {
            cin >> pushNum;
            s1.push_X(pushNum);
        }
        else if (order == "pop") {
            s1.pop();
        }
        else if (order == "size") {
            s1.size();
        }
        else if (order == "empty") {
            s1.empty();
        }
        else if (order == "top") {
            s1.top();
        }
    }
    return 0;
}