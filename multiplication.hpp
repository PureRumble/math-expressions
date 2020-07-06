#ifndef MULTIPLICATION_HPP
#define MULTIPLICATION_HPP

#include "binary_operator.hpp"
#include "expression.hpp"
#include "constant.hpp"

#include <string>

namespace ImintMath
{

/* Class instance represents a multiplication. For instance
new Multiplication( new Constant( 5 ), new Constant( 7 ) ) is 5*7.
*/
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
