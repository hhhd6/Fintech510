#include <string>
#include <sstream>
#include <cstdlib>

class Expression {
public:
    virtual std::string toString() const = 0;
    virtual long evaluate() const = 0;
    virtual ~Expression() {}
};

class NumericExpression : public Expression {
private:
    long value;
public:
    explicit NumericExpression(long val) : value(val) {}
    std::string toString() const override {
        std::ostringstream out;
        out << value;
        return out.str();
    }
    long evaluate() const override {
        return value;
    }
};

class BinaryExpression : public Expression {
protected:
    Expression *leftOperand, *rightOperand;
public:
    BinaryExpression(Expression *left, Expression *right) : leftOperand(left), rightOperand(right) {}
    ~BinaryExpression() override {
        delete leftOperand;
        delete rightOperand;
    }
};

class AddExpression : public BinaryExpression {
public:
    AddExpression(Expression *left, Expression *right) : BinaryExpression(left, right) {}
    std::string toString() const override {
        return "(" + leftOperand->toString() + " + " + rightOperand->toString() + ")";
    }
    long evaluate() const override {
        return leftOperand->evaluate() + rightOperand->evaluate();
    }
};

class SubtractExpression : public BinaryExpression {
public:
    SubtractExpression(Expression *left, Expression *right) : BinaryExpression(left, right) {}
    std::string toString() const override {
        return "(" + leftOperand->toString() + " - " + rightOperand->toString() + ")";
    }
    long evaluate() const override {
        return leftOperand->evaluate() - rightOperand->evaluate();
    }
};

class MultiplyExpression : public BinaryExpression {
public:
    MultiplyExpression(Expression *left, Expression *right) : BinaryExpression(left, right) {}
    std::string toString() const override {
        return "(" + leftOperand->toString() + " * " + rightOperand->toString() + ")";
    }
    long evaluate() const override {
        return leftOperand->evaluate() * rightOperand->evaluate();
    }
};

class DivideExpression : public BinaryExpression {
public:
    DivideExpression(Expression *left, Expression *right) : BinaryExpression(left, right) {}
    std::string toString() const override {
        return "(" + leftOperand->toString() + " / " + rightOperand->toString() + ")";
    }
    long evaluate() const override {
        return leftOperand->evaluate() / rightOperand->evaluate();
    }
};

