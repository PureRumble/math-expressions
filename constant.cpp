#include "constant.hpp"

#include "expression.hpp"
#include <cstdint>
#include <string>

namespace ImintMath
{

Constant::Constant( const Expression::ValueType value ) : value( value )
{

}

Expression* Constant::copy() const
{
  return new Constant( *this );
};

std::string Constant::getStrRepr( const bool withParantheses ) const
{
  return std::to_string( this->value );
}

Expression* Constant::simplifyRec( const Expression::VariableMap& map ) const
{
  return new Constant( *this );
}

Expression::ValueType Constant::getValue() const
{
  return this->value;
}

}
