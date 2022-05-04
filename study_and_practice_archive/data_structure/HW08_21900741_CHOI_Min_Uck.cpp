/*
'주어진 array의 n개 정수 원소 중 가장 큰 값을 찾는 프로그램'을 작성하고자 한다.
아래의 main() 함수에서 find_max() 를 recursive function으로 구현하여 프로그램을 완성하시오.

<예상 출력 >

84

*/
#include <iostream>
using namespace std;

int find_max(int n1[], int n2) {
    int max;

    if (n2 == 1) {
        return n1[0];
    }

    max = find_max(n1, n2 - 1);

    if (max > n1[n2 - 1]) {
        return max;
    }
    else {
        return n1[n2 - 1];
    }
}

int main()

{

    int a[10] = { 24, 12, 33, 27, 41, 15, 84, 52, 16, 72 };

    int m;

    m = find_max(a, 10);

    cout << m;

    return 0;

}