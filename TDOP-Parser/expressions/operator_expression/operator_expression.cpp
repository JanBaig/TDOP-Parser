#include <string>
#include "operator_expression.h"

std::string OperatorExpression::print() {
	
	std::string binaryExpr = "( " + left->print() + " " + operType + " " + right->print() + " )";
	return binaryExpr;
} 

