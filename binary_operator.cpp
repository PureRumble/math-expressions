#include "binary_operator.hpp"

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

std::string getStrRepr( bool withParantheses ) const
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

}
