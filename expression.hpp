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
    using ValueType = int64_t;

    using VariableMap = std::unordered_map< std::string, ValueType >;

    virtual ~Expression() = default;

    virtual Expression* copy() const = 0;

    virtual std::string toString() const;

    virtual std::string getStrRepr( bool withParantheses ) const = 0;

    Expression* simplify() const;

    Expression* simplify( const VariableMap& map ) const;

    virtual Expression* simplifyRec( const VariableMap& map ) const = 0;

    ValueType evaluate() const;

    ValueType evaluate( const VariableMap& map ) const;
};

}

#endif
