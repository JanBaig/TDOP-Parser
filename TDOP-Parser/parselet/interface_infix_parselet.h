#ifndef INFIXINTERFACE
#define INFIXINTERFACE 

#include "../expressions/interface_expression.h"
#include "../parser/parser.h"

class InterfaceInfixParselet {

public:

	virtual InterfaceExpression* parse(Parser parser, InterfaceExpression* left, Token token) = 0;
};


#endif
