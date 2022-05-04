/*
어떤 주어진 string이 Palindrome(좌우 대칭인 string)인지 여부를 판단하는 프로그램을,  stack를 사용하여 구현하시오.

* 영문자만 고려하며, 두 단어 이상의 string에서도 가능하도록 함,  띄어쓰기(space)는 무시할 것,

예를 들어 'race car' 도 palindrome으로 판단
*/

#include <iostream>
#include <string>
#define Palindrome 1
#define NotPalindrome 2
using namespace std;

class ForPalindrome {
public:
	char stack[100];
	int top;

	ForPalindrome();
	void push(char c);
	char pop();
	int palindromeCheck(char c1, char c2);
};

ForPalindrome::ForPalindrome() {
	top = 0;
}

void ForPalindrome::push(char c) {
	stack[top] = c;
	top++;
}

char ForPalindrome::pop() {
	top--;
	return stack[top];
}

int ForPalindrome::palindromeCheck(char c1, char c2) {
	if (c1 == c2) {
		return Palindrome;
	}
	else {
		return NotPalindrome;
	}
}

int main() {
	string input;
	char NoSpace[100];
	ForPalindrome s1;
	char buff[100];
	int stringLength;
	int NoSpacei = 0;

	cin.getline(buff, 80);
	input = buff;
	stringLength = input.size();

	for (int i = 0; i < stringLength ; i++) { //input에서 공백을 지운다
		if (input[i] != ' ') {
			NoSpace[NoSpacei] = input[i];
			NoSpacei++;
		}
	}
	
	stringLength = NoSpacei; //NoSpace의 크기

	for (int i = 0; i < (stringLength / 2); i++) { //string의 절반만 스택에 넣는다.
		s1.push(NoSpace[i]);
	}

	if (stringLength % 2 == 1) { //string의 크기가 홀수면
		for (int i = (stringLength / 2) + 1 ; i < stringLength; i++) { // stringLength / 2 + 1로 시작하는 이유는 문자열 중앙에 있는 char을 피하기 위함
			if (s1.palindromeCheck(s1.pop(), NoSpace[i]) == NotPalindrome) {
				cout << input << " is not Palindrome";

				return 0;
			}
		}
	}
	else { //짝수면
		for (int i = stringLength / 2; i < stringLength; i++) {
			if (s1.palindromeCheck(s1.pop(), NoSpace[i]) == NotPalindrome) {
				cout << input << " is not Palindrome";

				return 0;
			}
		}
	}
	
	cout << input << " is Palindrome";

	return 0;
}