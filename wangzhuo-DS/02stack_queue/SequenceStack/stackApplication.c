#include "stack.h"

void decimalToBase(int decimalNumber, int base)
{
}
// 检查括号是否匹配的函数
int checkBrackets(const char *str)
{
    return 0;
}
int evaluatePostfix(const char *expression)
{
    return 0;
}
// 返回运算符的优先级，越大表示优先级越高
int precedence(char op)
{
    return 0;
}

void infixToPostfix(const char *infix, char *postfix)
{
}

void test1()
{
    int decimalNumber;
    int base;

    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);
    printf("Enter the base (2-16): ");
    scanf("%d", &base);

    if (base < 2 || base > 16)
    {
        printf("Base must be between 2 and 16.\n");
    }

    printf("Decimal %d in base %d is: ", decimalNumber, base);
    decimalToBase(decimalNumber, base);
}

// Test function
int test2()
{
    char *testStr1 = "{[()]}";
    char *testStr2 = "{[(])}";
    char *testStr3 = "{[}";

    if (checkBrackets(testStr1))
    {
        printf("%s: Brackets match\n", testStr1);
    }
    else
    {
        printf("%s: Brackets do not match\n", testStr1);
    }

    if (checkBrackets(testStr2))
    {
        printf("%s: Brackets match\n", testStr2);
    }
    else
    {
        printf("%s: Brackets do not match\n", testStr2);
    }

    if (checkBrackets(testStr3))
    {
        printf("%s: Brackets match\n", testStr3);
    }
    else
    {
        printf("%s: Brackets do not match\n", testStr3);
    }

    return 0;
}

int test3()
{
    char postfixExpression[100];
    char *infixExpression = "3*(7-2)+5*3+(6-2)*4";
    // 将输入的中缀表达式转换为后缀表达式，并存储在一个字符数组中
    infixToPostfix(infixExpression, postfixExpression);
    printf("Infix: %s\n", infixExpression);
    printf("Postfix: %s\n", postfixExpression);

    int result = evaluatePostfix(postfixExpression);
    printf("Result: %d\n", result);

    return 0;
}

int main()
{
    testStackFunction();
    return 0;
}