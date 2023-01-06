#ifndef PREFIXINTERFACE 
#define PREFIXINTERFACE 

#include "../expressions/interface_expression.h"
#include "../parser/parser.h"

class InterfacePrefixParselet {

public:

	virtual InterfaceExpression* parse(Parser parser, Token token) = 0; // might have to change the parser argument to become a pointer
};

#endif

