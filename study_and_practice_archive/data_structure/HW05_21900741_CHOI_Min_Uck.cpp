/*
세가지 유형의 괄호,  ( ),  { }, [ ] 를 사용하는 수식 표현에서,
괄호 사용의 오류를 점검하는 프로그램을 작성하시오.
예)
(a + b) - [ c * {x - (a / b) } ]   ==> 정상
(a + b) - [ c * {x - (a / b} } ] ==> 괄호 불일치 ( }
(a + b) - [ c * {x - (a / b) }  ==> 닫는 괄호 누락
*/

#include <iostream>
#include <string>
#define NORMAL 1	//결과 1. 정상적 수식: 끝까지 불일치가 발생하지 않고, 최종 stack의 상태가 empty인 경우
#define NoMATCH 2	//결과 2. 괄호 typo이 맞지 않는 경우 - match 시도에서 불일치 발생
#define NoOpenBracket 3	//결과 3. 여는 괄호 부족: match 시도중 stack empty 상황 바랭
#define NoCloseBracket 4	//결과 4. 닫는 괄호 부족: 입력 처리가 종료된 후에 stack에 내용이 남아있음
using namespace std;

class ForBracketCheck {
public:
	char stack[100];
	int top;
	ForBracketCheck();
	void push(char c);
	char pop();
	int check(char c1, char c2);
};

ForBracketCheck::ForBracketCheck() {
	top = 0;
}


void ForBracketCheck::push(char c) {
	stack[top] = c;
	top++;
}

char ForBracketCheck::pop() {
	top--;
	return stack[top];
}

int ForBracketCheck::check(char c1, char c2) {
	if (c2 == ')') {
		if (c1 == '(') {
			return NORMAL; //정상인 경우
		}
		else {
			return NoMATCH; //괄호 불일치인 경우
		}
	}
	else if (c2 == '}') {
		if (c1 == '{') {
			return NORMAL;
		}
		else {
			return NoMATCH;
		}
	}
	else if (c2 == ']') {
		if (c1 == '[') {
			return NORMAL;
		}
		else {
			return NoMATCH;
		}
	}
}

int main() {
	string input;
	ForBracketCheck s1;
	char buff[100];
	int stringLength;
	char ForCheck;
	int result;
	bool check = false;

	result = NORMAL;

	cin.getline(buff, 80); // c++에서 한 개의 line을 읽는 방법

	input = buff; // 입력받은 buff의 내용을 input에 집어넣음

	stringLength = input.size();

	for (int i = 0; i < stringLength; i++) {
		if (input[i] == '(' || input[i] == '{' || input[i] == '[') { //여는 괄호: stack에 push
			s1.push(input[i]);
		}
		else if (input[i] == ')' || input[i] == '}' || input[i] == ']') { //닫는 괄호: stack에서 pop하여 type 비교
			if (s1.top == 0) {
				result = NoOpenBracket;
				cout << "여는 괄호 누락";
				return 0;
			}
			ForCheck = s1.pop();
			if (s1.check(ForCheck, input[i]) != NORMAL) {
				result == NoMATCH;
				cout << "괄호 불일치 " << ForCheck << " " << input[i];
				return 0;
			}
		}
	}
	
	if (s1.top > 0) {
		result = NoCloseBracket;
	}

	if (result == NORMAL) {
		cout << "정상";
	}
	else if (result == NoCloseBracket) {
		cout << "닫는 괄호 누락";
	}

	return 0;
}



