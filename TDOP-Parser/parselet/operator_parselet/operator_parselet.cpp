#include "operator_parselet.h"
#include "../../expressions/operator_expression/operator_expression.h"
#include <iostream>

InterfaceExpression* OperatorParselet::parse(Parser* parser, InterfaceExpression* left, Token token) {
	
	int precedence = parser->precedenceMap[token.type] + 1;
 	InterfaceExpression* right = parser->cTesting(precedence);
	
	// Some sort of ds here, implement a stack here

	std::cout << "OperatorExpression" << " Left: " << left->print() << " Right: " << right->print() << std::endl;
	
	return new OperatorExpression(left, token.text, right);
}

