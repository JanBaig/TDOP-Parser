#include "integer_parselet.h"
#include "../../expressions/integer_expression/integer_expression.h"

InterfaceExpression* IntegerParselet::parse(Parser parse, Token token) {

	return new IntegerExpression(token.text);
} 