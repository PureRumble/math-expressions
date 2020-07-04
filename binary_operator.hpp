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
    virtual BinaryOperator* copy() const = 0;

    virtual std::string getStrRepr( bool withParantheses ) const override;

    virtual std::string getName() const = 0;

    virtual Expression* simplify() const override;

    virtual Constant* calculate( Constant* first, Constant* second ) const = 0;

  public:
    BinaryOperator( const Expression* first, const Expression* second );

    BinaryOperator( const BinaryOperator& binaryOperator );

    virtual ~BinaryOperator() override;
};

}

#endif
