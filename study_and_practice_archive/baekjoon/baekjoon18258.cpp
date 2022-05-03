/*


입력
첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 2,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 문제에 나와있지 않은 명령이 주어지는 경우는 없다.

출력
출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.
*/

#include <iostream>
#include <string>
using namespace std;
#define arraySize 1000

class my_queue {

	int array[arraySize];
	int front, rear;

public:
	my_queue();
	void push(int n); //push X: 정수 X를 큐에 넣는 연산이다.
	int pop(); //pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
	int size(); //size: 큐에 들어있는 정수의 개수를 출력한다.
	int empty(); //empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
	int frontOut(); //front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
	int backOut(); //back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
};

my_queue::my_queue() {
	front = 0;
	rear = 0;
}

int my_queue::empty() {	//empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
	if (rear == front) {
		return 1;
	}
	else {
		return 0;
	}
}

void my_queue::push(int n) {	//push X: 정수 X를 큐에 넣는 연산이다.
	array[rear] = n;
	rear = (rear + 1) % arraySize;
}

int my_queue::pop() {	//pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
	int for_return;

	for_return = front;

	if (empty() == 1) {
		return -1;
	}
	else {
		front = (front + 1) % arraySize;
		return array[for_return];
	}
}

int my_queue::size() {	//size: 큐에 들어있는 정수의 개수를 출력한다.
	return rear - front;
}

int my_queue::frontOut() {	//front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
	if (empty() == 1) {
		return -1;
	}
	else {
		return array[front];
	}
}

int my_queue::backOut() {	//back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
	if (empty() == 1) {
		return -1;
	}
	else {
		return array[rear-1];
	}
}

int main() {
	int times;
	string order;
	int input;
	my_queue q1;

	cin >> times;

	for (int i = 0; i < times; i++) {
		cin >> order;
		
		if (order == "push") {
			cin >> input;
			q1.push(input);
		}
		else if (order == "pop") {
			cout << q1.pop();
		}
		else if (order == "size") {
			cout << q1.size();
		}
		else if (order == "empty") {
			cout << q1.empty();
		}
		else if (order == "front") {
			cout << q1.frontOut();
		}
		else if (order == "back") {
			cout << q1.backOut();
		}
	}

	return 0;
}