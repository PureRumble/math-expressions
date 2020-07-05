#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

#include <cstdint>
#include <string>
#include <unordered_map>

namespace ImintMath
{

class Expression
{
  public:
    using VariableMap = std::unordered_map< std::string, int64_t >;

    virtual ~Expression() = default;

    virtual Expression* copy() const = 0;

    virtual std::string toString() const;

    virtual std::string getStrRepr( bool withParantheses ) const = 0;

    Expression* simplify() const;

    Expression* simplify( const VariableMap& map ) const;

    virtual Expression* simplifyRec( const VariableMap& map ) const = 0;

    virtual int64_t evaluate() const;
};

}

#endif
