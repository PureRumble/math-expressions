#ifndef CONSTANT_HPP
#define CONSTANT_HPP

#include "expression.hpp"

#include <cstdint>

namespace ImintMath
{

class Constant : public Expression
{
  private:
    const int64_t value;

  protected:

    virtual std::string getStrRepr( bool withParantheses ) const override;

  public:
    Constant( const int64_t value );

    virtual Expression* simplify() const override;

    int64_t getValue() const;
};

}

#endif
