#include "binary_operator.hpp"

#include "expression.hpp"
#include "constant.hpp"
#include <cstdint>
#include <string>
#include <stdexcept>

namespace ImintMath
{

BinaryOperator::BinaryOperator(
  const Expression* first, const Expression* second
)
{
  if( first == nullptr || second == nullptr )
  {
    throw std::invalid_argument( "Args first and second must not be null." );
  }

  this->first = first;
  this->second = second;
}

BinaryOperator::BinaryOperator( const BinaryOperator& binaryOperator )
{
  this->first = binaryOperator.first->copy();
  this->second = binaryOperator.second->copy();
}

BinaryOperator::~BinaryOperator()
{
  delete first;
  delete second;
}

std::string BinaryOperator::getStrRepr( bool withParantheses ) const
{
  std::string strRepr = this->getName();

  strRepr = this->first->getStrRepr( true ) + strRepr;

  strRepr += this->second->getStrRepr( true );

  if( withParantheses == true )
  {
    strRepr = "(" + strRepr + ")";
  }

  return strRepr;
}

Expression* BinaryOperator::simplifyRec( const Expression::VariableMap& map )
const
{
  const Expression* firstSimpl = this->first->simplifyRec( map );

  const Expression* secondSimpl = this->second->simplifyRec( map );

// If both operands have been simplified down to Constants then this
// BinaryOperator can be simplified down to a constant too (by simply
// calculating it for the two new Constants).
  const Constant* firstConst = dynamic_cast<const Constant*>( firstSimpl );

  const Constant* secondConst = dynamic_cast<const Constant*>( secondSimpl );

  if( firstConst != nullptr && secondConst != nullptr )
  {
    return this->calculate( firstConst, secondConst );
  }
  else
  {
// Otherwise atleast one of the operands weren't simplified down to a
// Constant and then this BinaryOperator can't become a Constant either.
// So construct and return a new simplified BinaryOperator.
    return this->construct( firstSimpl, secondSimpl );
  }
}

}

