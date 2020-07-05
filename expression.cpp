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

int64_t Expression::evaluate() const
{
  Expression* simplified = this->simplify();

  Constant* constant = dynamic_cast<Constant*>( simplified );

  int64_t value = 0;

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
  return this->simplify( map );
}

}
