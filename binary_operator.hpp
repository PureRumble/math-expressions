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

  protected:
    virtual std::string getName() const = 0;

    virtual Constant* calculate(
      const Constant* first, const Constant* second
    ) const = 0;

    virtual BinaryOperator* construct(
      const Expression* first, const Expression* second
    ) const = 0;

  public:
    BinaryOperator( const Expression* first, const Expression* second );

    BinaryOperator( const BinaryOperator& binaryOperator );

    virtual ~BinaryOperator() override;

    virtual Expression* copy() const = 0;

    virtual std::string getStrRepr( bool withParantheses ) const override;

    virtual Expression* simplifyRec( const Expression::VariableMap& map )
    const override;
};

}

#endif
