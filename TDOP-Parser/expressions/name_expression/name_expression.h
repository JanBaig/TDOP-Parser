#ifndef NAMEEXPR  
#define NAMEEXPR 

#include <string>
#include "../interface_expression.h"

class NameExpression : public InterfaceExpression {

public:

	std::string tokenText;

	NameExpression(std::string tokenText) : tokenText(tokenText) {};

	std::string print();

};

#endif 
