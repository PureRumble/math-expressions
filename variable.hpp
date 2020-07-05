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
    using VariableMap =
      std::unordered_map< Variable, int64_t >;

    Variable( const std::string name );

    bool operator==( const Variable& variable ) const;

    virtual Expression* copy() const override;

    virtual std::string getStrRepr( bool withParantheses ) const override;

    virtual Expression* simplifyRec( const Expression::VariableMap& map )
    const override;

    std::string getName() const;
};

}

#endif
