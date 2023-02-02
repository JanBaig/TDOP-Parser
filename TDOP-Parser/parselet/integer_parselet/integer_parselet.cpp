#include "integer_parselet.h"
#include "../../expressions/integer_expression/integer_expression.h"

InterfaceExpression* IntegerParselet::parse(Parser* parser, Token token) {
		
	parser->stackTest.push(token.text);
	return new IntegerExpression(token.text);
} 