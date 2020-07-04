#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

#include <cstdint>
#include <string>

namespace ImintMath
{

class Expression
{
  public:
    virtual ~Expression() = default;

    virtual Expression* copy() const = 0;

    virtual std::string toString() const;

    virtual std::string getStrRepr( bool withParantheses ) const = 0;

    virtual Expression* simplify() const = 0;

    virtual int64_t evaluate() const;
};

}

#endif
