/*
정수 원소를 저장하는 stack을 class를 사용하여 구현하고,
이를 이용하여, 주어진  array의 정수 원소 n개 에서 100보다 큰 값을 역순으로 출력하는 프로그램을 작성하시오. (다음 main() 함수가 동작하도록 나머지 부분을 작성)

int main()

{

mystack  s1;

int list[5] = { 32, 123, 27, 131, 242 }, i, x;

  s1.init();

  for (i = 0; i < 5; i++ )

         if (list[i]> 100)

                s1.push( list[i] );

  while ( ! s1.stack_empty( ) )

  {

            x = s1.pop( );

            cout << x << endl ;

  }

  return 0;

}
*/

#include <iostream>
using namespace std;

class node {
public:
    int number;
    node* link; //자기 뒤에 따라오는 노드
    void set_data(int n);
};

void node::set_data(int n) {
    number = n;
}

class my_list {
    node* head, * tail;
public:
    my_list();
    void add_to_tail(node t);
    void add_to_head(node t);
    node delete_from_head();
    int list_empty();
};

my_list::my_list() {
    head = NULL;
    tail = NULL;
}

void my_list::add_to_head(node t) {
    node* p;
    p = new node;   //새로운 노드를 생성
    *p = t; //노드에 데이터를 입력
    p->link = head; 
    head = p; //해당 노드를 head로 만듦
    if (tail == NULL) {
        tail = p;   //tail이 NULL이면 크기가 1노드인 리스트이므로 해당 노드는 tail이기도 함
    }
}

void my_list::add_to_tail(node t) {
    node* p;
    p = new node;   //새로운 노드를 생성
    *p = t; //노드에 데이터를 입력
    p->link = NULL; //이 노드가 tail노드이고 tail노드 다음에는 아무것도 없으므로 NULL을 가리켜야 하니, 이 노드는 NULL을 가리킴
    if (tail != NULL) { //tail이 가르키고 있는 노드가 이미 있었다면 (NULL이 아니면)
        tail->link = p; //그 노드는 p를 가리키게 하여 리스트의 순서를 맞춤
    }
    else {
        head = p;   //tail이 NULL을 가리키고 있었다면, 크기가 1노드인 리스트이므로 해당 노드는 head이기도 함
    }
    tail = p;
}

node my_list::delete_from_head() {
    node temp;
    node* t;
    t = head;
    temp = *head;
    head = head->link;
    delete t;
    if (head == NULL) { //t가 삭제된 후 head가 NULL이라는 건 크기나 1노드인 리스트에서 유일한 노드를 삭제했다는 것이므로
        tail = NULL;    //tail도 NULL이 됨.
    }
    return temp;
}

int my_list::list_empty() {
    if (head == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}
int main()
{
    /*
    1안
    set data를 통해 list의 값들을 노드로 치환
    add to head를 통해 list의 값들을 링크드 리스트로 만든다.
    순서대로 head에 이어지니 링크드 리스트는 242 -> 131-> 27 -> 123 -> 32 형태가 될 것
    delete from head를 이용해 링크드 리스트의 데이터를 리턴하고 (그러면 스택처럼 선입후출 형태가 된다) 100보다 크면 출력하는 식으로 작성하면 될듯
    */
    /*
    2안
    미리 주어진 코드에서는 리스트 안의 값이 100보다 크면 스택에 집어넣는 형식
    100보다 큰 값들만 링크드 리스트에 집어넣으면 242 -> 131 ->123 형식이 될 것
    이후 delete from head 사용
    */
    my_list s1;
    node t;
    
    int list[5] = { 32, 123, 27, 131, 242 }, i, x;

    for (i = 0; i < 5; i++) {
        if (list[i] > 100) {
            t.number = list[i];
            s1.add_to_head(t);
        }
    }

    while (1){

        t = s1.delete_from_head();

        cout << t.number << endl;

        if (s1.list_empty() == 1) {
            break;
        }
    }

    return 0;
}
