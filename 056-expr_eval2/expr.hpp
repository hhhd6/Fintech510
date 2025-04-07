#ifndef EXPR_HPP
#define EXPR_HPP

#include <string>

// Abstract base class for all expressions
class Expression {
public:
    virtual ~Expression() {}
    virtual std::string toString() const = 0;
};

// Represents a numerical expression
class NumExpression : public Expression {
private:
    long value;
public:
    explicit NumExpression(long v) : value(v) {}
    std::string toString() const override;
};

// Abstract base class for binary operations (optional, for reducing redundancy)
class BinaryExpression : public Expression {
protected:
    Expression *lhs;
    Expression *rhs;
    std::string op;
public:
    BinaryExpression(Expression *l, Expression *r, const std::string &o) : lhs(l), rhs(r), op(o) {}
    ~BinaryExpression() {
        delete lhs;
        delete rhs;
    }
    std::string toString() const override;
};

// Represents a plus expression
class PlusExpression : public BinaryExpression {
public:
    PlusExpression(Expression *l, Expression *r) : BinaryExpression(l, r, "+") {}
};

// Represents a minus expression
class MinusExpression : public BinaryExpression {
public:
    MinusExpression(Expression *l, Expression *r) : BinaryExpression(l, r, "-") {}
};

// Represents a multiplication expression
class TimesExpression : public BinaryExpression {
public:
    TimesExpression(Expression *l, Expression *r) : BinaryExpression(l, r, "*") {}
};

// Represents a division expression
class DivExpression : public BinaryExpression {
public:
    DivExpression(Expression *l, Expression *r) : BinaryExpression(l, r, "/") {}
};

#endif