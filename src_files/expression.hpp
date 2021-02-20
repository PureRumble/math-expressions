#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

#include <cstdint>
#include <string>
#include <unordered_map>

namespace ImintMath
{

/* Abstract super class. Sub class instance represent mathematical
expression. For instance Constant and Addition are sub classes and
new Constant( 5 ) is the mathematical constant 5 and
new Addition( new Constant( 3 ), new Constant( 4 ) ) is 3+4. */
class Expression
{
  public:
/* Type alias to be used to hold constant values in Expressions.
For instance Constant constructor accepts one ValueType and
Expression::evaluate() returns a ValueType. */
    using ValueType = int64_t;

/* Type alias for a data structure used to specify variable names and their
values. Is used to specify what values Variables in an Expression should
have when simplifying or evaluating the Expression's final value. */
    using VariableMap = std::unordered_map< std::string, ValueType >;

/* Declaring destructor virtual so destruction propagates down to sub class
destructors as well. */
    virtual ~Expression() = default;

/* Returns a deep copy of the class instance. For instance
Addition::copy() returns a new Addition instance where both operands
have also been deep copied. */
    virtual Expression* copy() const = 0;

/* Returns a string repr of the Expression instance. For instance it returns
5+varA for new Addition( new Constant( 5 ), new Variable( "varA" ) ).
Nested expressions in a BinaryOperator instance are put in parantheses.
For instance (varA+5)*4. */
    virtual std::string toString() const;

/* Used internally by toString(). Must be public since used on memb vars in
a sub class. */
    virtual std::string getStrRepr( bool withParantheses ) const = 0;

/* Returns a deep copy of the Expression instance where BinaryOperator
instances that resolve to constants are replaced by Constant instances.
This is done recursively.
For instance (5+6)*3 is replaced by new Constant( 33 ) while
(5+6)*varA is replaced by
new Multiplication( new Constant( 11 ), new Variable( "varA" ) ). */
    Expression* simplify() const;

/* Returns a deep copy of the Expression instance where Variable
instances have been replaced by constant values, and the Expression
instance is then simplified as Expression::simplify() does.

The constant value of each Variable is specified by the arg map, which
holds pairs of string and Expression::ValueType.

For instance if map = { { "var1", 4 }, { "var2", 5 } } then for the
Expression (var1+4)*var3 evaluate() returns
new Multiplication( new Constant( 8 ), new Variable( "var3" ). */
    Expression* simplify( const VariableMap& map ) const;

/* Used internally by Expression::simplify(). Must be public since used
on memb vars in a sub class. */
    virtual Expression* simplifyRec( const VariableMap& map ) const = 0;

/* Returns the value that the Expression instance resolves to if it only
contains BinaryOperators and Constants. Throws a runtime_error otherwise.

For instance returns -18 for (5+4)*-2 but throws a runtime_error for
(5+(varA+4))*-2. */
    ValueType evaluate() const;

/* Returns the value that the Expression instance resolves to when all
Variable instances have been replaced by constant values.

The constant value of each Variable is specified by the arg map, which
holds pairs of string and Expression::ValueType. Each string is a
Variable name.

A runtime_error is thrown if the Expression contains atleast one Variable
which's name isn't specified by the arg map.

For instance if map = { { "var1", 4 }, { "var2", 5 } } then for the
Expression var1*var2 evaluate() returns 20. But for the expression
var1+var3 evaluate() throws a runtime_error. */
    ValueType evaluate( const VariableMap& map ) const;
};

}

#endif
