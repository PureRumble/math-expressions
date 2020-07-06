#include "expression.hpp"

#include "constant.hpp"
#include <cstdint>
#include <cstddef>
#include <string>
#include <stdexcept>

namespace ImintMath
{

std::string Expression::toString() const
{
  return this->getStrRepr( false );
}

Expression::ValueType Expression::evaluate() const
{
  const Expression::VariableMap map;

  return this->evaluate( map );
}

Expression::ValueType Expression::evaluate(
  const Expression::VariableMap& map
)
const
{
  Expression* simplified = this->simplify( map );

  Constant* constant = dynamic_cast<Constant*>( simplified );

  Expression::ValueType value = 0;

  if( constant != nullptr )
  {
    value = constant->getValue();
  }

  delete simplified;

  if( constant == nullptr )
  {
    throw std::runtime_error( "Expression obj did not evaluate to a constant" );
  }

  return value;
}

Expression* Expression::simplify() const
{
  Expression::VariableMap map;
  return this->simplifyRec( map );
}

Expression* Expression::simplify( const Expression::VariableMap& map ) const
{
  return this->simplifyRec( map );
}

}
