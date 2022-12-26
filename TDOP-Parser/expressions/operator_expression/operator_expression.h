#ifndef OPEREXPR
#define OPEREXPR 

#include "../interface_expression.h"

class OperatorExpression : public InterfaceExpression { 

public:
	InterfaceExpression* left;
	std::string operType;
	InterfaceExpression* right;

	OperatorExpression(InterfaceExpression* left, std::string operType, InterfaceExpression* right) : 
		left(left), operType(operType), right(right) {}; 

	std::string print();
};

#endif

