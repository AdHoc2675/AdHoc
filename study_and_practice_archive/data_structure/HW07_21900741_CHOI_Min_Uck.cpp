/*
Array를 사용한 Circular queue의 구현 예제 :
-도서정보 = { 도서명, 페이지수, 가격 } 로 이루어진 원소를 저장하는 circular queue를 구현하고,
다음 main function 이 수행되도록 프로그램을 완성하시오.

< 예상 출력 >

C++ Programming :  534 : 35000
Data Structure : 621 : 42000
JAVA Programming : 485 : 38000
Logic Design : 532 : 44000
*/

#include <iostream>
#include <string>
using namespace std;
#define Q_SIZE 100
#define TRUE 0
#define FALSE 1

class element {
public:
    string s_title;
    int npages;
    int price;

    void set_data(string str, int n1, int n2);
};

class my_queue{
    element q[Q_SIZE];
    int front, rear;

public:
    my_queue();
    void insert_q(element x);
    element delete_q();
    int queue_full();
    int queue_empty();
};

my_queue::my_queue() {
    front = 0;
    rear = 0;
}

void my_queue::insert_q(element x) {
    if (queue_full() == FALSE) {
        q[rear] = x;
        rear = (rear + 1) % Q_SIZE;
    }
}

element my_queue::delete_q() {

    element toReturn;

    if (queue_empty() == FALSE) {
        toReturn = q[front];
        front = (front + 1) % Q_SIZE;
        
        return toReturn;
    }
}

int my_queue::queue_full() {
    if ((rear + 1) % Q_SIZE == front) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

int my_queue::queue_empty() {
    if (rear == front) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

void element::set_data(string str, int n1, int n2) {
    s_title = str;
    npages = n1;
    price = n2;
}

int main()
    
{
    my_queue a;
    element tmp;

    tmp.set_data("C++ Programming", 534, 35000);
    a.insert_q(tmp);

    tmp.set_data("Data Structure", 621, 42000);
    a.insert_q(tmp);

    tmp.set_data("JAVA Programming", 485, 38000);
    a.insert_q(tmp);

    tmp.set_data("Logic Design", 532, 44000);
    a.insert_q(tmp);

    while (a.queue_empty() == FALSE) {
        tmp = a.delete_q();

        cout << tmp.s_title << " : " << tmp.npages << " : " << tmp.price << "\n";
    }

    return 0;
}




