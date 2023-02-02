#ifndef NAMEPARSELET 
#define NAMEPARSELET 

#include "../interface_prefix_parselet.h"

class NameParselet : public  InterfacePrefixParselet {

public:

	NameParselet() = default;

	InterfaceExpression* parse(Parser* parser, Token token);
};

#endif