#include <string>
#include "operator_expression.h"

std::string OperatorExpression::print() {
	
	std::string binaryExpr = "( " + OperatorExpression::left->print() + " " + OperatorExpression::operType + " " + OperatorExpression::right->print() + " )";
	return binaryExpr;
}