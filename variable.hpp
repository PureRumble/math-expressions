#ifndef VARIABLE_HPP
#define VARIABLE_HPP

#include "expression.hpp"

#include <cstdint>
#include <string>

namespace ImintMath
{

class Variable : public Expression
{
  private:
    const std::string name;

  public:
    Variable( const std::string name );

    virtual Expression* copy() const override;

    virtual std::string getStrRepr( bool withParantheses ) const override;

    virtual Expression* simplify() const override;

    std::string getName() const;
};

}

#endif
