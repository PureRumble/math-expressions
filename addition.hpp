#ifndef ADDITION_HPP
#define ADDITION_HPP

#include "binaryoperator.hpp"
#include "expression.hpp"
#include "constant.hpp"

#include <cstdint>
#include <string>

namespace ImintMath
{

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

    Addition( const Addition& Addition );

    virtual BinaryOperator* copy() const override;
};

}

#endif
