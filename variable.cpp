#include "variable.hpp"

#include "expression.hpp"
#include <cstdint>
#include <string>
#include <unordered_map>
#include <cstddef>

namespace ImintMath
{

Variable::Variable( const std::string name ) : name( name )
{

}

bool Variable::operator==( const Variable& variable ) const
{
  return this->name == variable.name;
}

Expression* Variable::copy() const
{
  return new Variable( *this );
}

std::string Variable::getStrRepr( const bool withParantheses ) const
{
  return this->name;
}

Expression* Variable::simplifyRec( const Expression::VariableMap& map ) const
{
  return new Variable( *this );
}

std::string Variable::getName() const
{
  return this->name;
}

}
