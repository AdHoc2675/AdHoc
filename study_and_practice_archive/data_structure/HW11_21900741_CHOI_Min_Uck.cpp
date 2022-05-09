/*
Heap 구현 예제: {성명, 점수}의 원소를 저장하는 heap 구현, 점수를 Key 값으로 고려
다음 main 함수의 의도에 따라 동작하는 프로그램을 완성하시오. (강의 내용 참조)
*/

#include <iostream>
#define HSIZE 100
using namespace std;



class element {
public:
    string name;
    double score; //Key 값
    void set_data(string n, double s);
};

void element::set_data(string n, double s) {
    name = n;
    score = s;
}

class my_heap {
    element h[HSIZE];
    int csize; // elements의 개수
public:
    my_heap();
    int h_size();
    void insert_heap(element t);
    element delete_heap();
    bool heap_full();
    bool heap_empty();
};

my_heap::my_heap() {
    csize = 0;
}

bool my_heap::heap_empty() {
    if (csize == 0) {
        return true;
    }
    else {
        return false;
    }
}

bool my_heap::heap_full() {
    if (csize >= HSIZE - 1) {
        return true;
    }
    else {
        return false;
    }
}

int my_heap::h_size() {
    return csize;
}

void my_heap::insert_heap(element t) {
    csize++;

    int k;
    k = csize;

    while ((k != 1) && (t.score > h[k / 2].score)) {
        h[k] = h[k / 2];
        k = k / 2;
    }

    h[k] = t;
}

element my_heap::delete_heap() {
    element t;
    element tmp;
    int parent, child;

    t = h[1]; //root를 return하기 위해 저장
    tmp = h[csize]; //끝원소
    csize--;
    parent = 1; //root
    child = 2; //root의 left child

    while (child <= csize) {
        if ((child < csize) && (h[child].score < h[child + 1].score)) { //child가 tree의 범위 내에 있으면서, right child가 존재하고 더 크면
            child++; // right child를 선택
        }
        if (tmp.score >= h[child].score) { //끝원소 값이 child의 값보다 크면
            break; //루프를 끝냄
        }
        h[parent] = h[child];
        parent = child; //한 단계 아래로
        child = child * 2; //child는 한 단계 아래의 left child가 됨
    }

    h[parent] = tmp;

    return t;
}

int main()

{
    my_heap   h1;
    element   temp;

    temp.set_data("Kim", 88);
    h1.insert_heap(temp);
    temp.set_data("Lee", 77);
    h1.insert_heap(temp);
    temp.set_data("Park", 98);
    h1.insert_heap(temp);
    temp.set_data("Choi", 74);
    h1.insert_heap(temp);
    temp.set_data("Ryu", 94);
    h1.insert_heap(temp);
    temp.set_data("Cho", 85);
    h1.insert_heap(temp);
    while (h1.h_size() > 0) {
        temp = h1.delete_heap();
        cout << temp.name << " : " << temp.score << "\n";
    }

    return 0;
}

/*
<예상 출력 >

Park : 98
Ryu : 94
Kim : 88
Cho : 85
Lee : 77/
Choi : 74
*/