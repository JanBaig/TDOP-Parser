#include "operator_parselet.h"
#include "../../expressions/operator_expression/operator_expression.h"

InterfaceExpression* OperatorParselet::parse(Parser parser, InterfaceExpression* left, Token token) {
	
	int testing = parser.getPrecedence();
	parser.consume();
	InterfaceExpression* right = parser.parseExpression(testing); // this gets
	return new OperatorExpression(left, token.text, right);

}

