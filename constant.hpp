#ifndef CONSTANT_HPP
#define CONSTANT_HPP

#include "expression.hpp"

#include <cstdint>

namespace ImintMath
{

class Constant : public Expression
{
  private:
    const Expression::ValueType value;

  public:
    Constant( const Expression::ValueType value );

    virtual Expression* copy() const override;

    virtual std::string getStrRepr( bool withParantheses ) const override;

    virtual Expression* simplifyRec( const Expression::VariableMap& map )
    const override;

    Expression::ValueType getValue() const;
};

}

#endif
