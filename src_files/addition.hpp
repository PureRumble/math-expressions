#ifndef ADDITION_HPP
#define ADDITION_HPP

#include "binary_operator.hpp"
#include "expression.hpp"
#include "constant.hpp"

#include <string>

namespace ImintMath
{

/* Class instance represents an addition. For instance
new Addition( new Constant( 5 ), new Constant( 7 ) ) is 5+7.
*/
class Addition : public BinaryOperator
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
    Addition( const Expression* first, const Expression* second );

    Addition( const Addition& addition );

    virtual Expression* copy() const override;
};

}

#endif

