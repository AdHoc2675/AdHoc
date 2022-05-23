// baekjoon2751.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int num, tmp;
    vector<int> arr;

    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < num; i++) {
        cout << arr[i] << '\n';
    }
}