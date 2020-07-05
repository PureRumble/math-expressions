#ifndef CONSTANT_HPP
#define CONSTANT_HPP

#include "expression.hpp"

#include <cstdint>

namespace ImintMath
{

class Constant : public Expression
{
  public:
    using ConstType = int64_t;

  private:
    const ConstType value;

  public:
    Constant( const ConstType value );

    virtual Expression* copy() const override;

    virtual std::string getStrRepr( bool withParantheses ) const override;

    virtual Expression* simplify( const Expression::VariableMap& map )
    const override;

    ConstType getValue() const;
};

}

#endif
