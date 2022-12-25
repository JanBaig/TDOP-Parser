#ifndef INTEGEREXPR
#define INTEGEREXPR 

#include "../interface_expression.h"

class IntegerExpression : public InterfaceExpression {

public:

	std::string tokenText;

	IntegerExpression(std::string tokenText) : tokenText(tokenText) {};

	std::string print();

};

#endif
