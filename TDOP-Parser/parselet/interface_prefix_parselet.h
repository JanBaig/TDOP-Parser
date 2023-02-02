#ifndef PREFIXINTERFACE 
#define PREFIXINTERFACE 

#include "../expressions/interface_expression.h"
#include "../parser/parser.h"

class InterfacePrefixParselet {

public:

	virtual InterfaceExpression* parse(Parser* parser, Token token) = 0;
};

#endif

