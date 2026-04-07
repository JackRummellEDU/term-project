#include <gtest/gtest.h>
#include "Parser.h"
#include "ExpressionError.h"
#include "ASTNode.h"

class ParserTest : public ::testing::Test {
  protected:
    ASTNode* parseExpr(const std::string& expr){
      Parser parser(expr);
      return parser.parse();
    }
};

/******************************************** Valid Entry Tests Start ********************************************/ 
TEST_F(ParserTest, Simple_Addition_Integers) {
  ASTNode* root = parseExpr("3 + 4");
  EXPECT_DOUBLE_EQ(root->evaluate(), 7.0);
  delete root;
}

TEST_F(ParserTest, Simple_Addition_Decimals) {
  ASTNode* root = parseExpr("3.6 + 4");
  EXPECT_DOUBLE_EQ(root->evaluate(), 7.6);
  delete root;
}

TEST_F(ParserTest, Simple_Subtraction) {
  ASTNode* root = parseExpr("10 - 7");
  EXPECT_DOUBLE_EQ(root->evaluate(), 3);
  delete root;
}

TEST_F(ParserTest, Simple_Multiplication) {
  ASTNode* root = parseExpr("2 * 5");
  EXPECT_DOUBLE_EQ(root->evaluate(), 10);
  delete root;
}

TEST_F(ParserTest, Simple_Division) {
  ASTNode* root = parseExpr("20 / 2");
  EXPECT_DOUBLE_EQ(root->evaluate(), 10);
  delete root;
}

TEST_F(ParserTest, Simple_Multiplication_And_Division) {
  ASTNode* root = parseExpr("10 * 2 / 5");
  EXPECT_DOUBLE_EQ(root->evaluate(), 4);
  delete root;
}

TEST_F(ParserTest, Simple_Modulo) {
  ASTNode* root = parseExpr("20 % 3");
  EXPECT_DOUBLE_EQ(root->evaluate(), 2);
  delete root;
}

TEST_F(ParserTest, Operator_Precedence_Simple) {
  ASTNode* root = parseExpr("5 + 10 * 3");
  EXPECT_DOUBLE_EQ(root->evaluate(), 35);
  delete root;
}

TEST_F(ParserTest, Operator_Precedence_Complex) {
  ASTNode* root = parseExpr("5 + 10 * 3 - 20 / 2");
  EXPECT_DOUBLE_EQ(root->evaluate(), 25);
  delete root;
}

TEST_F(ParserTest, Parentheses_Precedence_Simple) {
  ASTNode* root = parseExpr("6 * (2 + 4)");
  EXPECT_DOUBLE_EQ(root->evaluate(), 36);
  delete root;
}

TEST_F(ParserTest, Parentheses_Precedence_Complex) {
  ASTNode* root = parseExpr("5 * ((3 + 2) * 2) / 2");
  EXPECT_DOUBLE_EQ(root->evaluate(), 25);
  delete root;
}

TEST_F(ParserTest, Exponentiation_Simple) {
  ASTNode* root = parseExpr("2**3");
  EXPECT_DOUBLE_EQ(root->evaluate(), 8);
  delete root;
}

TEST_F(ParserTest, Exponentiation_Complex) {
  ASTNode* root = parseExpr("2**3**2");
  EXPECT_DOUBLE_EQ(root->evaluate(), 512);
  delete root;
}

TEST_F(ParserTest, Unary_Operator_Simple) {
  ASTNode* root = parseExpr("-10 + 6");
  EXPECT_DOUBLE_EQ(root->evaluate(), -4);
  delete root;
}

TEST_F(ParserTest, Unary_Operator_Complex) {
  ASTNode* root = parseExpr("6 + -10 + 8");
  EXPECT_DOUBLE_EQ(root->evaluate(), 4);
  delete root;
}

TEST_F(ParserTest, Unary_Operator_Nested_Simple) {
  ASTNode* root = parseExpr("-(-10)");
  EXPECT_DOUBLE_EQ(root->evaluate(), 10);
  delete root;
}

TEST_F(ParserTest, Unary_Operator_Nested_Complex) {
  ASTNode* root = parseExpr("-(-10) + 6 + -6 * -2");
  EXPECT_DOUBLE_EQ(root->evaluate(), 28);
  delete root;
}

TEST_F(ParserTest, Complex_Addition_With_Extraneous_Parentheses) {
  ASTNode* root = parseExpr("(((2 + 3))) + (((1 + 2)))");
  EXPECT_DOUBLE_EQ(root->evaluate(), 8);
  delete root;
}

TEST_F(ParserTest, Mixed_Operators_With_Extraneous_Parentheses) {
  ASTNode* root = parseExpr("((5 * 2) - ((3 / 1) + ((4 % 3))))");
  EXPECT_DOUBLE_EQ(root->evaluate(), 6);
  delete root;
}

TEST_F(ParserTest, Nested_Parentheses_With_Exponents) {
  ASTNode* root = parseExpr("(((2**(1 + 1)) + ((3 - 1)**2)) / ((4 / 2) % 3))");
  EXPECT_DOUBLE_EQ(root->evaluate(), 4);
  delete root;
}

TEST_F(ParserTest, Combination_Extraneous_AND_Necessary_Parenthes_Test) {
  ASTNode* root = parseExpr("(((((5 - 3))) * (((2 + 1))) + ((2 * 3))))");
  EXPECT_DOUBLE_EQ(root->evaluate(), 12);
  delete root;
}

TEST_F(ParserTest, Extraneous_Parentheses_With_Division) {
  ASTNode* root = parseExpr("((9 + 6)) / ((3 * 1) / (((2 + 2))) - 1)");
  EXPECT_DOUBLE_EQ(root->evaluate(), -60);
  delete root;
}

TEST_F(ParserTest, Combining_Unary_Operators_With_Arithmetic_Operations) {
  ASTNode* root = parseExpr("+(-2) * (-3) - ((-4) / (+5))");
  EXPECT_DOUBLE_EQ(root->evaluate(), 6.8);
  delete root;
}

TEST_F(ParserTest, Unary_Negation_And_Addition_In_Parentheses) {
  ASTNode* root = parseExpr("-(+1) + (+2)");
  EXPECT_DOUBLE_EQ(root->evaluate(), 1);
  delete root;
}

TEST_F(ParserTest, Negation_And_Addition_With_Negated_Parentheses) {
  ASTNode* root = parseExpr("-(-(-3)) + (-4) + (+5)");
  EXPECT_DOUBLE_EQ(root->evaluate(), -2);
  delete root;
}

TEST_F(ParserTest, Unary_Negation_And_Parentheses) {
  ASTNode* root = parseExpr("+2**(-3)");
  EXPECT_DOUBLE_EQ(root->evaluate(), 0.125);
  delete root;
}

TEST_F(ParserTest, Combining_Unary_Operators_With_Parentheses) {
  ASTNode* root = parseExpr("-(+2) * (+3) - (-4) / (-5)");
  EXPECT_DOUBLE_EQ(root->evaluate(), -6.8);
  delete root;
}
/******************************************** Valid Entry Tests End ********************************************/



/******************************************** Invalid Entry Tests Start ********************************************/
TEST_F(ParserTest, Division_By_Zero) {
  ASTNode* root = parseExpr("10 / 0");
  EXPECT_THROW(root->evaluate(), ExpressionError);
  delete root;
}

TEST_F(ParserTest, Modulo_By_Zero) {
  ASTNode* root = parseExpr("10 % 0");
  EXPECT_THROW(root->evaluate(), ExpressionError);
  delete root;
}

TEST_F(ParserTest, Unmatched_Parentheses) {
  EXPECT_THROW(parseExpr("(3 + 4"), ExpressionError);
}

TEST_F(ParserTest, Empty_Parentheses) {
  EXPECT_THROW(parseExpr("1 + ()"), ExpressionError);
}

TEST_F(ParserTest, Extra_Parentheses) {
  EXPECT_THROW(parseExpr("1 + 2)"), ExpressionError);
}

TEST_F(ParserTest, Invalid_Character) {
  EXPECT_THROW(parseExpr("14 $ 6"), ExpressionError);
}

TEST_F(ParserTest, Missing_Right_Operand) {
  EXPECT_THROW(parseExpr("6 - "), ExpressionError);
}

TEST_F(ParserTest, Missing_Left_Operand) {
  EXPECT_THROW(parseExpr("* 2"), ExpressionError);
}

TEST_F(ParserTest, Invalid_Operator_Sequence) {
  EXPECT_THROW(parseExpr("1 + * 4"), ExpressionError);
}

TEST_F(ParserTest, Invalid_Operator_Usage_Message) {
  ASTNode* root = parseExpr("((5 + 2) / (3 * 0))");
  try {
    root->evaluate();
    FAIL();
  } catch (const ExpressionError& e) {
    EXPECT_STREQ(e.what(), "Division by zero");
  } catch (...) {
    FAIL() << "Expected ExpressionError";
  }
  delete root;
}

TEST_F(ParserTest, Invalid_Operator_Sequence_Message) {
  try {
    parseExpr("((2 -) 1 + 3)");
    FAIL();
  } catch (const ExpressionError& e) {
    EXPECT_STREQ(e.what(), "Expected number or '('");
  } catch (...) {
    FAIL() << "Expected ExpressionError";
  }
}

TEST_F(ParserTest, Modulo_By_Zero_Message) {
  ASTNode* root = parseExpr("10 % 0");
  try {
    root->evaluate();
    FAIL();
  } catch (const ExpressionError& e) {
    EXPECT_STREQ(e.what(), "Modulo by zero");
  } catch (...) {
    FAIL() << "Expected ExpressionError";
  }
  delete root;
}

TEST_F(ParserTest, Division_By_Zero_Message) {
  ASTNode* root = parseExpr("10 / 0");
  try {
    root->evaluate();
    FAIL();
  } catch (const ExpressionError& e) {
    EXPECT_STREQ(e.what(), "Division by zero");
  } catch (...) {
    FAIL() << "Expected ExpressionError";
  }
  delete root;
}
/******************************************** Invalid Entry Tests End ********************************************/