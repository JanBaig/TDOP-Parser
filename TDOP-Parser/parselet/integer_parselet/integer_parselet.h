#ifndef INTEGERPARSELET 
#define INTEGERPARSELET 

#include "../interface_prefix_parselet.h"

class IntegerParselet : public InterfacePrefixParselet {

public:

	IntegerParselet() = default;

	InterfaceExpression* parse(Parser* parser, Token token);
};


#endif


