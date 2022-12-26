#ifndef OPERPARSELET
#define OPERPARSELET

#include "../interface_infix_parselet.h"

class OperatorParselet : public InterfaceInfixParselet {

public:

	InterfaceExpression* parse(Parser parser, InterfaceExpression* left, Token token);

}; 

#endif