#ifndef VARIABLE_HPP
#define VARIABLE_HPP

#include "expression.hpp"

#include <cstdint>
#include <string>

namespace ImintMath
{

/* Class instance represents a variable in a mathematical expression.
For instance new Addition( new Variable( "varA" ), new Constant( 7 ) )
is varA+7.

Variable instances in an Expression instance can then
be replaced by constant values by using Expression::simplify() or
Expression::evaluate() together with an Expression::VariableMap. */
class Variable : public Expression
{
  private:
    const std::string name;

  public:
    Variable( const std::string name );

    virtual Expression* copy() const override;

    virtual std::string getStrRepr( bool withParantheses ) const override;

/* Returns a new Expression instance. If the current Variable's name exists
in the arg map then the corresponding variable value is used to create a
new Constant and it is returned. Otherwise a copy of this Variable is
returned. */
    virtual Expression* simplifyRec( const Expression::VariableMap& map )
    const override;

    std::string getName() const;
};

}

#endif

