#include "constant.hpp"

#include "expression.hpp"
#include <cstdint>
#include <string>

namespace ImintMath
{

Constant::Constant( const Constant::ConstType value ) : value( value )
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

Expression* Constant::simplify() const
{
  return new Constant( *this );
}

Constant::ConstType Constant::getValue() const
{
  return this->value;
}

}
