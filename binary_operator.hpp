#ifndef BINARY_OPERATOR_HPP
#define BINARY_OPERATOR_HPP

#include "expression.hpp"
#include "constant.hpp"

#include <cstdint>
#include <string>

namespace ImintMath
{

/* Abstract super class. Sub class instances represent binary operators
in mathematical expressions. For instance
new Multiplication( new Constant( 5 ), new Constant( 7 ) ) is 5*7.

A BinaryOperator can contain nested BinaryOperators as operands. For instance
new Addition(
    new Multiplication( new Constant( 5 ), new Constant( 7 ) ),
    new Multiplication( new Variable( "varA" ), new Variable( "varB" ) )
)
is (5*7)+(varA*varB).
*/
class BinaryOperator : public Expression
{
  private:
    const Expression* first;
    const Expression* second;

  protected:
/* Returns the operator name. For instance Addition::getName() returns "+" */
    virtual std::string getName() const = 0;

/* Returns a new Constant that is the result of applying the BinaryOperator on
the Constants first and second. */
    virtual Constant* calculate(
      const Constant* first, const Constant* second
    ) const = 0;

/* Returns a new BinaryOperator by giving the args first and second to the sub
class constructor. */
    virtual BinaryOperator* construct(
      const Expression* first, const Expression* second
    ) const = 0;

  public:
/* Constructs a new BinaryOperator. The instances first and second are not
copied and instead the pointer values are saved. The pointers must not be
nullptr. */
    BinaryOperator( const Expression* first, const Expression* second );

/* Constructs a new BinaryOperator. The arg binaryOperator is deeply copied. */
    BinaryOperator( const BinaryOperator& binaryOperator );

    virtual ~BinaryOperator() override;

    virtual Expression* copy() const = 0;

    virtual std::string getStrRepr( bool withParantheses ) const override;

    virtual Expression* simplifyRec( const Expression::VariableMap& map )
    const override;
};

}

#endif

