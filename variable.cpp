#include "variable.hpp"

#include "expression.hpp"
#include <cstdint>
#include <string>

namespace ImintMath
{

Variable::Variable( const std::string name ) : name( name )
{

}

Expression* Variable::copy() const
{
  return new Variable( *this );
}

std::string Variable::getStrRepr( const bool withParantheses ) const
{
  return this->name;
}

Expression* Variable::simplify() const
{
  return new Variable( *this );
}

std::string Variable::getName() const
{
  return this->name;
}

}
