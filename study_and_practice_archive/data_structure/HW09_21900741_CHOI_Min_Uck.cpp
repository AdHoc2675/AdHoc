/*
강의에서 설명한 구조의 linked list를 구현하고, 아래의 main function의 의도대로 동작하도록
관련 function을 작성하시오. (강의 교재 내용 참조)
*/

#include <iostream>
#include <string>
using namespace std;

class node {
public:
    string name;
    double score;
    node *link;

    void set_data(string str, double n);
};

void node::set_data(string str, double n) {
    name = str;
    score = n;
}

class my_list {
    node *head;
    node *tail;
public:
    my_list();
    void add_to_head(node t);
    void add_to_tail(node t);
    node delete_from_head();
    int num_nodes();
    double score_sum();
    double get_score(string str);
    int remove_a_node(string str);
    bool list_empty();
};

my_list::my_list() {
    head = NULL;
    tail = NULL;
}
node my_list::delete_from_head() {
    node temp;
    node* t;

    t = head;
    temp = *head;
    head = head->link;
    delete t;
    if (head == NULL) {
        tail = NULL;
    }
    return temp;
}
void my_list::add_to_head(node t) {
    node *p;
    p = new node;
    (*p) = t;
    p->link = head;
    head = p;
    if (tail == NULL) {
        tail = p;
    }
}

void my_list::add_to_tail(node t) {
    node *p;
    p = new node;
    (*p) = t;
    p->link = NULL;

    if (tail != NULL) {
        tail->link = p;
    }
    else {
        head = p;
    }

    tail = p;
}

int my_list::num_nodes() {
    int count = 0;    
    node *t;
    
    for (t = head; t != NULL; t = t->link) {
        count++;
    }
    return count;
}

double my_list::score_sum() {
    double sum = 0.0;
    node* t;

    for (t = head; t != NULL; t = t->link) {
        sum = sum + t->score;
    }

    return sum;
}

double my_list::get_score(string str) {
    node *t;
    int returnNum = 0;

    for (t = head; t != NULL; t = t->link) {
        if (t->name == str) {
            returnNum = 1;
            break;
        }
    }

    if (returnNum == 1) {
        return t->score;
    }
    else {
        return 0;
    }
}

int my_list::remove_a_node(string str) {
    node* target, * prev;
    
    prev = NULL;
    target = head;

    while ((target != NULL) && (target->name != str)) {
        prev = target;
        target = target->link;
    }

    if (target == NULL) {
        return 0;
    }

    if (prev) {
        prev->link = target->link;
    }
    else {
        head = target->link;
    }
    if (head == NULL) {
        tail = NULL;
    }
    if (target == tail) {
        tail = prev;
    }

    delete target;
    return 1;
}

bool my_list::list_empty() {
    if (head == NULL) {
        return true;
    }
    else {
        return false;
    }
}



int main()
{
    my_list a;
    node tmp;

    tmp.set_data("Kim", 83.5);
    a.add_to_head(tmp);

    tmp.set_data("Lee", 78.2);
    a.add_to_head(tmp);           // head 위치로 2개의 원소 추가

    cout << a.num_nodes() << " : " << a.score_sum() << "\n";  // 1단계 점검

    tmp.set_data("Park", 91.3);   
    a.add_to_tail(tmp);             // tail 위치로 1개의 원소 추가

    cout << a.num_nodes() << " : " << a.score_sum() << "\n";  //2단계 점검

    tmp = a.delete_from_head();

    cout << tmp.name << " is deleted.\n";   // 3단계 점검

    tmp.set_data("Choi", 85.1);   
    a.add_to_tail(tmp);

    tmp.set_data("Ryu", 94.3);   
    a.add_to_head(tmp);             // 2개의 원소 추가

    cout << a.num_nodes() << " : " << a.score_sum() << "\n";
    //여기서부터 문제 발생
    cout << "Park’s score : " << a.get_score("Park") << "\n";  // 4단계 점검

    if (a.remove_a_node("Kim") == 1)
        cout << "Kim is deleted from the list. \n";     // 5단계 점검

    cout << a.num_nodes() << " : " << a.score_sum() << "\n";  // 최종 점검

    return 0;

}