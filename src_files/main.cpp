#include "expression.hpp"
#include "constant.hpp"
#include "variable.hpp"
#include "binary_operator.hpp"
#include "addition.hpp"
#include "multiplication.hpp"
#include <cassert>
#include <iostream>
#include <stdexcept>
#include <unordered_map>

#include <string>

using namespace ImintMath;

int main()
{
	std::cout << "Running tests" << std::endl;

	Constant* constant = new Constant( 77 );

  assert( constant->getValue() == 77 );

  assert( constant->toString() == "77" );

// Simplifying a Constant returns a new Constant with same value.
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

// Simplifying a Variable returns a new Variable with same name.
// A Constant is not returned since no value was specified for
// variable when calling simplify().
  Variable* varEval = dynamic_cast<Variable*>( variable->simplify() );

  assert( varEval != nullptr );
  assert( varEval != variable );
  assert( varEval->getName() == "TestVarName" );

  delete varEval;

// Evaluating a Variable without specifying a value for it throws
// a runtime_error.
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

// Simplifying a Variable when a new value for it has been specified
// gives a new Constant with that value.
  Expression::VariableMap varMap( { { "TestVarName", 55 } } );

  constEval = dynamic_cast<Constant*>( variable->simplify( varMap ) );

  assert( constEval != nullptr );
  assert( constEval->getValue() == 55 );

  delete constEval;
  delete variable;



// A simple Addition with two constants works correctly.
  BinaryOperator* binOp = new Addition( new Constant( 11 ), new Constant( 5 ) );

  assert( binOp->toString() == "11+5" );

  Constant* addConst = dynamic_cast<Constant*>( binOp->simplify() );

  assert( addConst != nullptr );
  assert( addConst->getValue() == 16 );

  Expression::ValueType constValue = binOp->evaluate();
  assert( constValue == 16 );

  delete binOp;
  delete addConst;



// A simple Multiplication with two constants works correctly.
  binOp = new Multiplication( new Constant( 11 ), new Constant( 5 ) );

  assert( binOp->toString() == "11*5" );

  addConst = dynamic_cast<Constant*>( binOp->simplify() );

  assert( addConst != nullptr );
  assert( addConst->getValue() == 55 );

  constValue = binOp->evaluate();
  assert( constValue == 55 );

  delete binOp;
  delete addConst;



// A BinaryOperator (for instance an Addition) containing other
// BinaryOperators works correctly.
  Addition* addOp =
    new Addition(
      new Multiplication( new Constant( 5 ), new Constant( 1 ) ),
      new Constant( -1 )
    );

  assert( addOp->toString() == "(5*1)+-1" );

  assert( addOp->evaluate() == 4 );

  addConst = dynamic_cast<Constant*>( addOp->simplify() );

  assert( addConst != nullptr );
  assert( addConst->getValue() == 4 );

  delete addOp;
  delete addConst;



  addOp =
    new Addition(
      new Addition( new Constant( 5 ), new Variable( "var" ) ),
      new Constant( -1 )
    );

  assert( addOp->toString() == "(5+var)+-1" );

// Evaluating a BinaryOperator that contains a Variable without
// specifying a value for the Variable throws a runtime_error.
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

// Simplifying a BinaryOperator that contains a Variable without
// specifying a value for the Variable returns a copy of the BinaryOperator.
  Addition* addSimpl = dynamic_cast<Addition*>( addOp->simplify() );

  assert( addSimpl != nullptr );
  assert( addSimpl != addOp );
  assert( addSimpl->toString() == "(5+var)+-1" );

  varMap = Expression::VariableMap( { { "var", 50 } } );

  assert( addOp->evaluate( varMap ) == 54 );

  delete addOp;
  delete addSimpl;



// A deep BinaryOperator with Variables works correctly.
  addOp =
    new Addition(
      new Addition(
        new Multiplication( new Constant( 5 ), new Variable( "varA" ) ),
        new Addition( new Constant( 7 ), new Variable( "varB" ) )
      ),
      new Constant( -1 )
    );

  assert( addOp->toString() == "((5*varA)+(7+varB))+-1" );

  addSimpl = dynamic_cast<Addition*>( addOp->simplify() );
  assert( addSimpl != nullptr );
  assert( addSimpl->toString() == "((5*varA)+(7+varB))+-1" );

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

// Simplifying a deep BinaryOperator with two Variables while specifying
// a value for only one Variable works correctly.
  varMap = Expression::VariableMap( { { "varA", 50 } } );

  Expression* exprSimpl = addOp->simplify( varMap );

  assert( exprSimpl->toString() == "(250+(7+varB))+-1" );

// Evaluating while specifying values for both variables also works correctly.
  varMap = Expression::VariableMap( { { "varA", 50 }, { "varB", -6 } } );

  assert( addOp->evaluate( varMap ) == 250 );

  delete addOp;
  delete addSimpl;
  delete exprSimpl;

	std::cout << "Tests completed successfully" << std::endl;

  return 0;
}
