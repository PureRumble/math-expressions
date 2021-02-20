# Description

A library of classes for representing and evaluating mathematical expressions
recursively.

This prints `5+(7*8)`:

```
Expresion* expr =
new Addition(
	new Constant(5),
	new Multiplication(new Constant(7), new Constant(8))
);
std::cout << expr->toString() << std::endl;
```

Variables can also be represented. This prints `5+(7*varA)`

```
Expresion* expr =
new Addition(
	new Constant(5),
	new Multiplication(new Constant(7), new Variable("varA"))
);
std::cout << expr->toString() << std::endl;
```

An expression can be simplified. Here the expression `(5*varA+7)+(2*3*varB)` is
simplified after substituting `1` for `varA` and the result `12+(6*varB)` is
printed

```
Expresion* expr =
new Addition(
	new Addition(
		new Multiplication(new Constant(5), new Variable("varA")),
		new Constant(7)
	),
	new Multiplication(
		new Multiplication(new Constant(2), new Constant(3)),
		new Variable("varB")
	)
);

Expression::VariableMap varMap( { { "varA", 1 } } );

Expression* simpl = expr->simplify(varMap);
std::cout << simpl->toString() << std::endl;
```

# Build and tests

Run the following from the repo root to build and run tests

```
make
./bin/test_expressions
make clean
```
