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

// Represents a binary expression with an operator
class PlusExpression : public Expression {
private:
    Expression *lhs;
    Expression *rhs;
public:
    PlusExpression(Expression *l, Expression *r) : lhs(l), rhs(r) {}
    ~PlusExpression() {
        delete lhs;
        delete rhs;
    }
    std::string toString() const override;
};


#endif
