// HW12_21900741_CHOI_Min_Uck.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

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
    my_heap(element a[], int n);
    int h_size();
    void insert_heap(element t);
    element delete_heap();
    bool heap_full();
    bool heap_empty();
    double score_sum();
    double score_average();
    int node_delete_by_name(string tname);
};

my_heap::my_heap() {
    csize = 0;
}

my_heap::my_heap(element a[], int n) {
    csize = 0;
    for (int i = 0; i < n; i++) {
        insert_heap(a[i]);
    }
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

double summation(element a[], int troot, int n) {
    if (troot > n) {
        return 0;
    }
    return (a[troot].score + summation(a, 2 * troot, n) + summation(a, 2 * troot + 1, n));
}

double my_heap::score_sum() {
    return summation(h, 1, csize);
}

double my_heap::score_average() {
    if (csize == 0) {
        return 0;
    }
    return score_sum() / csize;
}

void heap_adjust(element a[], int troot, int size) {
    double tmpkey;
    int child;
    element tmp;

    tmp = a[troot];
    tmpkey = a[troot].score;
    child = 2 * troot;

    while (child <= size) {
        if ((child < size) && (a[child].score < a[child + 1].score)) {
            child++;
        }
        if (tmpkey > a[child].score) {
            break;
        }
        else {
            a[child / 2] = a[child];
                child = child * 2;
        }
    }
}

int delete_node(element a[], int troot, string tname, int n) {
    element temp;

    if (troot >= n) {
        return 0;
    }
    if (a[troot].name == tname) {
        temp = a[troot];
        a[troot] = a[n];
        a[n] = temp;
        heap_adjust(a, troot + 1, n);
        return 1;
    }
    else {
        if (delete_node(a, 2 * troot, tname, n) == 1) {
            return 1;
        }
        else {
            return delete_node(a, 2 * troot + 1, tname, n);
        }

    }
}

int my_heap::node_delete_by_name(string tname) {
    if (csize == 0) {
        return 0;
    }
    if (delete_node(h, 1, tname, csize) == 1) {
        csize--;
        return 1;
    }
    else {
        return 0;
    }
}


int main()

{
    element   a[10] = { {"Kim",88}, {"Lee", 77}, {"Park", 98}, {"Choi", 74}, {"Ryu",94}, {"Cho", 85} };
    my_heap   h1(a, 6);
    element temp;

    cout << "Number of nodes : " << h1.h_size() << endl;
    cout << "Score Sum = " << h1.score_sum() << endl;
    cout << "Score average = " << h1.score_average() << endl;

    h1.node_delete_by_name("Kim");

    cout << "\n-- After the deletion operation. --\n\n";
    cout << "Number of nodes : " << h1.h_size() << endl;
    cout << "Score Sum = " << h1.score_sum() << endl;
    cout << "Score average = " << h1.score_average() << endl;

    while (h1.h_size() > 0) {
        temp = h1.delete_heap();
        cout << temp.name << " : " << temp.score << "\n";
    }

    return 0;
}

/*
<예상 출력>

Number of nodes : 6

Score Sum = 516

Score average = 86

-- After the deletion operation. --

Number of nodes : 5

Score Sum = 428

Score average = 85.6

Park : 98

Ryu : 94

Cho : 85

Lee : 77

Choi : 74
*/