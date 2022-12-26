#include "operator_parselet.h"
#include "../../expressions/operator_expression/operator_expression.h"

InterfaceExpression* OperatorParselet::parse(Parser parser, InterfaceExpression* left, Token token) {
	
	parser.consume();
	InterfaceExpression* right = parser.parseExpression();
	return new OperatorExpression(left, token.text, right);

}
