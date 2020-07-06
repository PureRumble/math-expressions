#include "multiplication.hpp"

#include "binary_operator.hpp"
#include "expression.hpp"
#include "constant.hpp"
#include <string>

namespace ImintMath
{

Multiplication::Multiplication(
  const Expression* first, const Expression* second
) :
  BinaryOperator::BinaryOperator( first, second )
{

}

Multiplication::Multiplication( const Multiplication& multiplication ) :
  BinaryOperator::BinaryOperator( multiplication )
{

}

std::string Multiplication::getName() const
{
  return "*";
}

Constant* Multiplication::calculate(
  const Constant* first, const Constant* second
)
const
{
  Expression::ValueType firstVal = first->getValue();
  Expression::ValueType secondVal = second->getValue();

  return new Constant( firstVal * secondVal );
}

BinaryOperator* Multiplication::construct(
  const Expression* first, const Expression* second
)
const
{
  return new Multiplication( first, second );
}

Expression* Multiplication::copy() const
{
  return new Multiplication( *this );
}

}
