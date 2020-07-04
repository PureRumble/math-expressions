#ifndef BINARY_OPERATOR_HPP
#define BINARY_OPERATOR_HPP

#include "expression.hpp"
#include "constant.hpp"

#include <cstdint>
#include <string>

namespace ImintMath
{

class BinaryOperator : public Expression
{
  private:
    const Expression* first;
    const Expression* second;

  public:
    BinaryOperator( const Expression* first, const Expression* second );

    virtual ~BinaryOperator() override;
};

}

#endif
