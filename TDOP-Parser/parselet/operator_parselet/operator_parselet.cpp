#include "operator_parselet.h"
#include "../../expressions/operator_expression/operator_expression.h"

InterfaceExpression* OperatorParselet::parse(Parser parser, InterfaceExpression* left, Token token) {
	
	// Need to return the precedence of the previous operator... Right now on non-infix token
	InterfaceExpression* right = parser.testing(parser.prevPrecedence); 
	return new OperatorExpression(left, token.text, right);
}

