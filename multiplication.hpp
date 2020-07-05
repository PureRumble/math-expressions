#ifndef MULTIPLICATION_HPP
#define MULTIPLICATION_HPP

#include "binary_operator.hpp"
#include "expression.hpp"
#include "constant.hpp"

#include <string>

namespace ImintMath
{

class Multiplication : public BinaryOperator
{
  protected:
    virtual std::string getName() const override;

    virtual Constant* calculate(
      const Constant* first, const Constant* second
    ) const override;

    virtual BinaryOperator* construct(
      const Expression* first, const Expression* second
    ) const override;

  public:
    Multiplication( const Expression* first, const Expression* second );

    Multiplication( const Multiplication& multiplication );

    virtual Expression* copy() const override;
};

}

#endif
