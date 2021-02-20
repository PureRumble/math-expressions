#include "addition.hpp"

#include "binary_operator.hpp"
#include "expression.hpp"
#include "constant.hpp"
#include <string>

namespace ImintMath
{

Addition::Addition( const Expression* first, const Expression* second ) :
  BinaryOperator::BinaryOperator( first, second )
{

}

Addition::Addition( const Addition& addition ) :
  BinaryOperator::BinaryOperator( addition )
{

}

std::string Addition::getName() const
{
  return "+";
}

Constant* Addition::calculate( const Constant* first, const Constant* second )
const
{
  Expression::ValueType firstVal = first->getValue();
  Expression::ValueType secondVal = second->getValue();

  return new Constant( firstVal + secondVal );
}

BinaryOperator* Addition::construct(
  const Expression* first, const Expression* second
)
const
{
  return new Addition( first, second );
}

Expression* Addition::copy() const
{
  return new Addition( *this );
}

}
