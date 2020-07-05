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

    bool operator==( const Variable& variable ) const;

    virtual Expression* copy() const override;

    virtual std::string getStrRepr( bool withParantheses ) const override;

    virtual Expression* simplify( const Expression::VariableMap& map )
    const override;

    std::string getName() const;
};

}

template<>
struct std::hash< ImintMath::Variable >
{
  std::size_t operator()( const ImintMath::Variable& variable ) const
  {
    return std::hash<std::string>()( variable.getName() );
  }
};

#endif
