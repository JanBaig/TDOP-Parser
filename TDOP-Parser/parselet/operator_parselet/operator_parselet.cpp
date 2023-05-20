#include "operator_parselet.h"
#include "../../expressions/operator_expression/operator_expression.h"
#include <iostream>
#include <typeinfo>

InterfaceExpression* OperatorParselet::parse(Parser* parser, InterfaceExpression* left, Token token) {
	
	int precedence = parser->precedenceMap[token.type] + 1;

 	InterfaceExpression* right = parser->parseExpression(precedence);
	
	std::cout << "Left: " << left->print() << ", Right: " << right->print() << ", Operator: " << token.text << std::endl;

	return new OperatorExpression(left, token.text, right);
}

