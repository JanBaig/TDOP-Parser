#include "operator_parselet.h"
#include "../../expressions/operator_expression/operator_expression.h"
#include <iostream>
#include <typeinfo>

InterfaceExpression* OperatorParselet::parse(Parser* parser, InterfaceExpression* left, Token token) {
	
	int precedence = parser->precedenceMap[token.type] + 1;
 	InterfaceExpression* right = parser->cTesting(precedence);
	
	std::cout << "OperatorExpression" << " Left: " << left->print() << " Right: " << right->print() << std::endl;

	int testing = stoi(left->print());
	int testing2 = stoi(right->print());
	
	// Error because of the fact that (3 * 4) is being printed and the right arg for the future operation is not being simplified. 
	// Need to simply first before adding the argument into the operatorExpression (can step through code to verify

	// int result = testing + testing2;
	// parser->stackTest.push(std::to_string(result));

	return new OperatorExpression(left, token.text, right);
}

