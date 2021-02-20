#ifndef CONSTANT_HPP
#define CONSTANT_HPP

#include "expression.hpp"

#include <cstdint>

namespace ImintMath
{

/* Class instance represents a constant in a mathematical expression.
For instance new Addition( new Constant( 5 ), new Constant( 7 ) ) is 5+7.
*/
class Constant : public Expression
{
  private:
    const Expression::ValueType value;

  public:
    Constant( const Expression::ValueType value );

    virtual Expression* copy() const override;

    virtual std::string getStrRepr( bool withParantheses ) const override;

/* Returns a copy of this Constant, irrespective of the arg map's content. */
    virtual Expression* simplifyRec( const Expression::VariableMap& map )
    const override;

/* Returns the value of this constant. */
    Expression::ValueType getValue() const;
};

}

#endif

