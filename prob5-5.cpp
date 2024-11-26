#include <iostream>
#include <sstream>
#include <stack>
#include <cctype>
using namespace std;

const string OPERATORS = "+-*/()";
const int PRECEDENCE[] = { 1, 1, 2, 2, -1, -1 };
stack<char> operator_stack;
stack<double> k;
string::size_type is_n(string ch) {
	return OPERATORS.find('-');
}
string::size_type is_float(string ch) {
	return OPERATORS.find('.');
}
string::size_type is_operator(char ch) {
	return OPERATORS.find(ch);
}
int precedence(char op) {
	return PRECEDENCE[is_operator(op)];
}
void process_op(char op, stringstream& postfix) {
	if (operator_stack.empty() || op == '(') {
		operator_stack.push(op);
	}
	else {
		char top_op = operator_stack.top();
		if (precedence(op) > precedence(top_op)) {
			operator_stack.push(op);
		}
		else {
			while (!operator_stack.empty() && precedence(op) <= precedence(top_op)) {
				operator_stack.pop();
				if (top_op == '(')
					break;
				postfix << top_op << ' ';
				if (!operator_stack.empty())
					top_op = operator_stack.top();
			}
			if (op != ')')
				operator_stack.push(op);
		}
	}
}
string convert(string infix) {
	stringstream postfix, infixstream(infix);
	string token;
	while (infixstream>>token) {
		if (isdigit(token[0]) || (token.size() > 1&&token[0]=='-')) {
			postfix << token << ' ';
		}
		else if (is_operator(token[0]) != string::npos) { 
			process_op(token[0], postfix);
		}
		else {
			throw runtime_error("Syntax Error: invalid character encountered.");
		}
	}
	while (!operator_stack.empty()) {
		char op = operator_stack.top();
		
		if (op == '(')
			throw runtime_error("Unmatched parenthesis.");
		postfix << op << ' ';
		operator_stack.pop();
	}
	string tok;
	
	while (postfix >> tok)
	{
		if (is_operator(tok[0]) != string::npos && tok.size() < 2) {
			double a = k.top();
			k.pop();
			double b = k.top();
			k.pop();
			switch (tok[0]) {
			case '+': k.push(b + a); break;
			case '-': k.push(b - a); break;
			case '*': k.push(b * a); break;
			case '/': k.push(b / a); break;
			}
		}
		else
		{
			k.push(stod(tok));
		}

		
	}
	cout << postfix.str() << "= " << k.top() << endl;
		return postfix.str() + "= ";
	
}


int main() {
	string expr;
	cout << "Enter an infix expression: ";
	getline(cin, expr);
	convert(expr);
	return 0;
}
