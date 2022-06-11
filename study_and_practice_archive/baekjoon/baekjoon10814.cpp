#include <iostream>
using namespace std;

//이 문제는 여러 정렬 알고리즘을 연습하기 위해 정답이 아닌 여러 알고리즘도 포함되어있음
//따라서 문제를 제출할 때는 stable sort 알고리즘을 선택하고 제출할것

#define person_size 100000

class person {
public:
    int age;
    string name;

    void set_data(int n, string str);
};

void person::set_data(int n, string str) {
    age = n;
    name = str;
}

void print_data(person a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i].age << " " << a[i].name << "\n";
    }
}

void insertion_sort(person a[], int n) {
    int i, j;

    for (i = 1; i < n; i++) {
        person temp = a[i];
        
        for (j = i - 1; j >= 0; j--) {
            if (a[j].age >= temp.age) {
                a[j + 1] = a[j];
            }
        }
        a[j + 1] = temp;
    }
}

void selection_sort(person a[], int n) {
    person temp;

    for (int i = 0; i < n; i++) {
        int min = i;

        for (int j = i + 1; j < n; j++) {
            if (a[min].age >= a[j].age) {
                min = j;
            }
            temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }
    }
}

void bubble_sort(person a[], int n) {
    person temp;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (a[j].age > a[j + 1].age) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void quick_sort(person a[], int left, int right) {
    person pivot, temp;
    int i, j;

    if (left >= right) {
        return;
    }

    i = left;
    j = right + 1;
    pivot = a[left];
    
    do {
        do {
            i++;
        } while ((i <= right) && (a[i].age < pivot.age));
        do {
            j--;
        } while (a[j].age > pivot.age);
        if (i < j) {
            swap(a[i], a[j]);
        }
    } while (i < j);

    swap(a[left], a[j]);
    quick_sort(a, left, j - 1);
    quick_sort(a, j + 1, right);
}

void merge(person a[], person b[], int n1, int n2, int n3, int n4) {
    int i, j, k, t;
    i = n1;
    j = n3;
    k = n1;

    while ((i <= n2) && (j <= n4)) {
        if (a[i].age <= a[j].age) {
            b[k++] = a[i++];
        }
        else {
            b[k++] = a[j++];
        }
    }
    if (i > n2) {
        for (t = j; t <= n4; t++) {
            b[t] = a[t];
        }
    }
    else {
        for (t = i; t <= n2; t++) {
            b[k + t - i] = a[t];
        }
    }
}

void merge_pass(person a[], person b[], int n, int s) {
    int i, j;
    for (i = 0; i < (n - (2 * s) + 1); i = i + 2 * s) {
        merge(a, b, i, i + s - 1, i + s, i + 2 * s - 1);
    }
    if (i + s <= n) {
        merge(a, b, i, i + s - 1, i + s, n);
    }
    else {
        for (j = i; j <= n; j++) {
            b[j] = a[j];
        }
    }
}

void merge_sort(person a[], int n) {
    int s = 1;
    person b[person_size + 1];

    while (s < n) {
        merge_pass(a, b, n - 1, s);
        s = s * 2;
        merge_pass(b, a, n - 1, s);
        s = s * 2;
    }
}

void adjust(person a[], int troot, int size) {
    int age;
    int child;
    person temp;

    temp = a[troot];
    age = a[troot].age;
    child = 2 * troot;

    while (child <= size) {
        if ((child < size) && (a[child].age < a[child + 1].age)) {
            child++;
        }
        if (age > a[child].age) {
            break;
        }
        else {
            a[child / 2] = a[child];
            child = child * 2;
        }
    }
    a[child / 2] = temp;
}

void heap_sort(person a[], int n) {
    int i;
    person b[person_size + 1];
    person temp;

    for (int i = 0; i < n; i++) {
        b[i + 1] = a[i];
    }

    for (i = n / 2; i > 0; i--) {
        adjust(b, i, n);
    }

    for (i = n - 1; i > 0; i--) {
        temp = b[1];
        b[1] = b[i + 1];
        b[i + 1] = temp;
        adjust(b, 1, i);
    }

    for (int i = 0; i < person_size; i++) {
        a[i] = b[i + 1];
    }
}

int main()
{
    int n;
    int age;
    string name;
    person p[person_size];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> age;
        cin >> name;
        p[i].set_data(age, name);
    }

    //insertion_sort(p, n);
    //selection_sort(p, n);
    //bubble_sort(p, n);

    //quick_sort(p, 0, n - 1);
    merge_sort(p, n);
    //heap_sort(p, n);

    print_data(p, n);

    return 0;
}

