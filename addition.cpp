#include "binaryoperator.hpp"
#include "expression.hpp"
#include "constant.hpp"

#include <cstdint>
#include <string>

namespace ImintMath
{

Addition::Addition( const Expression* first, const Expression* second ) :
  BinaryOperator::BinaryOperator( first, second )
{

}

Addition::Addition( const Addition& Addition )
{

}

std::string Addition::getName() const
{

}

Constant* Addition::calculate( const Constant* first, const Constant* second )
const
{

}

BinaryOperator* Addition::construct(
  const Expression* first, const Expression* second
)
const
{

}

Expression* Addition::copy() const
{

}

}
