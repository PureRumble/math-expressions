#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

#include <cstdint>
#include <string>

namespace ImintMath
{

class Expression
{
  protected:
      virtual std::string getStrRepr( bool withParantheses ) const = 0;

  public:
    virtual ~Expression() = default;

    std::string toString() const;

    virtual Expression* simplify() const = 0;

    int64_t evaluate() const;
};

}

#endif
