#include "expression.hpp"
#include "constant.hpp"
#include <cassert>
#include <iostream>

using namespace ImintMath;

int main()
{
  Constant* constant = new Constant( 77 );

  assert( constant->getValue() == 77 );

  assert( constant->evaluate() == 77 );

  assert( constant->toString() == "77" );

  Constant* constEval = dynamic_cast<Constant*>( constant->simplify() );

  assert( constEval != nullptr );
  assert( constEval != constant );
  assert( constEval->getValue() == 77 );

  return 0;
}
