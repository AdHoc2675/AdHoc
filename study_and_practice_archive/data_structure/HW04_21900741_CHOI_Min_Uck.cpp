/*
Infix expression을 Postfix expression으로 변환하는 프로그램을 작성하시오.
test case 예)
입력 :  a * (b + c)
출력 :  a b c + *

입력 : a*(b+c)-d/e
출력 : abc+*de/-
*/

#include <iostream>
#include <string>
#define EOS '$'
using namespace std;

class MyStack {
public:
	char stack[100];
	int top;

	MyStack();
	void push(char c);
	char pop();
	bool empty();
	char top_element();
};

MyStack::MyStack() {
	top = 0;
}

void MyStack::push(char c) {
	stack[top] = c;
	top++;
}

char MyStack::pop() {
	top--;
	return(stack[top]);
}

bool MyStack::empty() {
	return (top == 0);
}

char MyStack::top_element() {
	return (stack[top - 1]);
}

int precedence(char c) {
	if (c == '$' || c == '(')
		return 0;
	else if (c == '+' || c == '-')
		return 1;
	else if (c == '*' || c == '/')
		return 2;
}

int main() {
	string input;
	MyStack s1;
	char buff[100];
	int stringLength;

	//cin >> input; 은 한 단어만 가능
	cin.getline(buff, 80); // c++에서 한 개의 line을 읽는 방법

	input = buff; // 입력받은 buff의 내용을 input에 집어넣음

	s1.push(EOS);

	stringLength = input.size();

	for (int i = 0; i < stringLength; i++) {
		if (input[i] >= 48 && input[i] <= 122) {
			cout << input[i];
		}
		else if (input[i] == ')') { //닫는 괄호면 stack에서 pop하여 type 비교
			while (precedence(s1.top_element()) != 0) {
				cout << s1.pop();
			}

			s1.pop();

		}
		else if (input[i] == '(') { //여는 괄호면 stack에 push
			s1.push(input[i]);
		}
		else {
			while (precedence(input[i]) <= precedence(s1.top_element()))
				cout << s1.pop();
			s1.push(input[i]);
		}
	}

	while (s1.stack[s1.top-1] != '$') {
		cout << s1.pop();
	}
}