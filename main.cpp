#include "expression.hpp"
#include "constant.hpp"
#include "variable.hpp"
#include <cassert>
#include <iostream>
#include <stdexcept>

using namespace ImintMath;

int main()
{
  Constant* constant = new Constant( 77 );

  assert( constant->getValue() == 77 );

  assert( constant->toString() == "77" );

  Constant* constEval = dynamic_cast<Constant*>( constant->simplify() );

  assert( constEval != nullptr );
  assert( constEval != constant );
  assert( constEval->getValue() == 77 );

  assert( constant->evaluate() == 77 );



  Variable* variable = new Variable( "TestVarName" );

  assert( variable->getName() == "TestVarName" );

  assert( variable->toString() == "TestVarName" );

  Variable* varEval = dynamic_cast<Variable*>( variable->simplify() );

  assert( varEval != nullptr );
  assert( varEval != variable );
  assert( variable->getName() == "TestVarName" );

  bool excThrown = false;

  try
  {
    variable->evaluate();
  }
  catch( std::runtime_error re )
  {
    excThrown = true;
  }

  assert( excThrown == true );

  return 0;
}
