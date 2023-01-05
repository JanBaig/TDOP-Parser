#include "operator_parselet.h"
#include "../../expressions/operator_expression/operator_expression.h"

InterfaceExpression* OperatorParselet::parse(Parser parser, InterfaceExpression* left, Token token) {
	
	int precedence = parser.precedenceMap[token.type] + 1;
	InterfaceExpression* right = parser.cTesting(precedence);
	return new OperatorExpression(left, token.text, right);
}

