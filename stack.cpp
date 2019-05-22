#include <iostream>
#include <string>

using std::string;

class Stack {
public:
	Stack(int n) {
		buffer = new char[n];
		size = n;
		top = 0;
	}
	
	~Stack() {
		delete[] buffer;
	}
	
	bool isFull() {
		if(top == size) {
			return true;
		}
		return false;
	}
	
	bool isEmpty() {
		if(top == 0) {
			return true;
		}
		return false;
	}
	
	bool pop(char &elem) {
		if(isEmpty()) {
			//printf("empty\n");
			return false;
		}
		top--;
		elem = buffer[top];
		return true;
	}
	
	bool push(char elem) {
		if(isFull()) {
			//printf("full\n");
			return false;
		}
		buffer[top] = elem;
		top++;
		return true;
	}
	
	char s_top() {
		return buffer[top-1];
	}
	
	void clear() {
		top = 0;
	}
	
	bool isMatched(string &match, Stack *stack) {
		char temp;
		for(int i=0;i<match.length();i++) {
			if(match[i] == '[') {
				stack->push(match[i]);
			}
			if(match[i] == '{') {
				stack->push(match[i]);
			}
			if(match[i] == '(') {
				stack->push(match[i]);
			}
			if(match[i] == ']') {
				if(stack->isEmpty()) {
					printf("not valid!!!\n");
					return false;
				}
				if(stack->s_top() == '[') {
					stack->pop(temp);
				}
			}
			if(match[i] == '}') {
				if(stack->isEmpty()) {
					printf("not valid!!!\n");
					return false;
				}
				if(stack->s_top() == '{') {
					stack->pop(temp);
				}
			}
			if(match[i] == ')') {
				if(stack->isEmpty()) {
					printf("not valid!!!\n");
					return false;
				}
				if(stack->s_top() == '(') {
					stack->pop(temp);
				}
			}
		}
		
		if(stack->isEmpty()) {
			printf("valid!!!\n");
			return true;
		} else {
			printf("not valid!!!\n");
			stack->dump();
			return false;
		}
	}
	
	dump() {
		for(int i=0;i<top;i++) {
			printf("%c ",buffer[i]);
		}
		printf("\n");
	}

private:
	char *buffer;
	int size;
	int top;
};

int main() {
	Stack *stack = new Stack(20);
	stack->push('1');
	stack->push('2');
	stack->push('3');
	stack->push('4');
	stack->push('5');
	stack->push('6');
	stack->push('7');
	stack->push('8');
	
	for(int i=0 ;i<8;i++) {
		char temp;
		stack->pop(temp);
		//printf("%c  ",temp);
	}

	string match="[(){}]";
	stack->isMatched(match,stack);
	
	stack->clear();
	
	string match2="{{{[()]}}}";
	stack->isMatched(match2,stack);
	
	string match3="[(])";
	stack->isMatched(match3,stack);
}
