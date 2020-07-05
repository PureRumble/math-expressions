#include "expression.hpp"
#include "constant.hpp"
#include "variable.hpp"
#include "binary_operator.hpp"
#include "addition.hpp"
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
  delete constant;
  delete constEval;


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

  delete varEval;
  delete variable;


  BinaryOperator* binOp = new Addition( new Constant( 11 ), new Constant( 5 ) );

  assert( binOp->toString() == "11+5" );

  Constant* addConst = dynamic_cast<Constant*>( binOp->simplify() );

  assert( addConst != nullptr );
  assert( addConst->getValue() == 16 );

  Constant::ConstType constValue = binOp->evaluate();
  assert( constValue == 16 );

  delete binOp;
  delete addConst;


  Addition* addOp =
    new Addition(
      new Addition( new Constant( 5 ), new Constant( 1 ) ),
      new Constant( -1 )
    );

  assert( addOp->toString() == "(5+1)+-1" );

  assert( addOp->evaluate() == 5 );

  addConst = dynamic_cast<Constant*>( addOp->simplify() );

  assert( addConst != nullptr );
  assert( addConst->getValue() == 5 );

  delete addOp;
  delete addConst;



  addOp =
    new Addition(
      new Addition( new Constant( 5 ), new Variable( "var" ) ),
      new Constant( -1 )
    );

  assert( addOp->toString() == "(5+var)+-1" );

  excThrown = false;

  try
  {
    addOp->evaluate();
  }
  catch( std::runtime_error e )
  {
    excThrown = true;
  }

  assert( excThrown == true );

  Addition* addSimpl = dynamic_cast<Addition*>( addOp->simplify() );

  assert( addSimpl != nullptr );
  assert( addSimpl->toString() == "(5+var)+-1" );

  delete addOp;
  delete addSimpl;



  addOp =
    new Addition(
      new Addition(
        new Addition( new Constant( 5 ), new Variable( "varA" ) ),
        new Addition( new Constant( 7 ), new Variable( "varB" ) )
      ),
      new Constant( -1 )
    );

  assert( addOp->toString() == "((5+varA)+(7+varB))+-1" );

  addSimpl = dynamic_cast<Addition*>( addOp->simplify() );
  assert( addSimpl != nullptr );
  assert( addSimpl->toString() == "((5+varA)+(7+varB))+-1" );

  excThrown = false;

  try
  {
    addOp->evaluate();
  }
  catch( std::runtime_error e )
  {
    excThrown = true;
  }

  assert( excThrown == true );

  delete addOp;
  delete addSimpl;



  addOp =
    new Addition(
      new Addition(
        new Addition(
          new Addition( new Constant( 7 ), new Constant( 3 ) ),
          new Variable( "varA" )
        ),
        new Addition( new Constant( 7 ), new Variable( "varB" ) )
      ),
      new Constant( -1 )
    );

  addSimpl = dynamic_cast<Addition*>( addOp->simplify() );
  assert( addSimpl != nullptr );
  assert( addSimpl->toString() == "((10+varA)+(7+varB))+-1" );

  delete addOp;
  delete addSimpl;

  return 0;
}
