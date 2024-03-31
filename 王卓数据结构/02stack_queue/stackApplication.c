#include "stack.h"

void decimalToBase(int decimalNumber, int base)
{
    Stack s;
    initStack(&s);
    char baseDigits[] = "0123456789ABCDEF"; // 用于转换的字符集

    // 不断除以基数，余数入栈
    while (decimalNumber > 0)
    {
        int remainder = decimalNumber % base;
        push(&s, remainder);
        decimalNumber /= base;
    }

    // 从栈中取出并打印结果
    while (!isEmpty(&s))
    {
        printf("%c", baseDigits[pop(&s)]); // baseDigits是字符数组
    }
    printf("\n");
}
// 检查括号是否匹配的函数
int checkBrackets(const char *str)
{
    Stack s;
    initStack(&s);

    while (*str)
    {
        if (*str == '(' || *str == '[' || *str == '{')
        {
            // 如果是开括号，压栈
            push(&s, *str);
        }
        else if (*str == ')' || *str == ']' || *str == '}')
        {
            // 如果是闭括号，检查栈顶是否匹配
            if (isEmpty(&s))
            {
                return 0; // 栈已空，无法匹配
            }
            int topChar = pop(&s);
            if ((*str == ')' && topChar != '(') ||
                (*str == ']' && topChar != '[') ||
                (*str == '}' && topChar != '{'))
            {
                return 0; // 括号不匹配
            }
        }
        str++;
    }

    // 如果栈为空，则所有括号匹配
    return isEmpty(&s);
}
int evaluatePostfix(const char *expression)
{
    Stack s;
    initStack(&s);

    while (*expression)
    {
        if (isdigit(*expression))
        {
            push(&s, *expression - '0'); // 转换字符到整数并压栈
        }
        else if (*expression == '+' || *expression == '-' || *expression == '*' || *expression == '/')
        {
            int val2 = pop(&s);
            int val1 = pop(&s);
            switch (*expression)
            {
            case '+':
                push(&s, val1 + val2);
                break;
            case '-':
                push(&s, val1 - val2);
                break;
            case '*':
                push(&s, val1 * val2);
                break;
            case '/':
                if (val2 == 0)
                {
                    printf("Error: Division by zero.\n");
                    return -1;
                }
                push(&s, val1 / val2);
                break;
            }
        }
        expression++;
    }
    return pop(&s);
}
// 返回运算符的优先级，越大表示优先级越高
int precedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0;
    }
}

void infixToPostfix(const char *infix, char *postfix)
{
    Stack s;
    initStack(&s);
    int index = 0;

    while (*infix)
    {
        if (isdigit(*infix))
        {
            postfix[index++] = *infix; // 直接输出数字
        }
        else if (*infix == '(')
        {
            push(&s, *infix); // 左括号压栈
        }
        else if (*infix == ')')
        {
            /*
            当遍历到中缀表达式中的一个闭括号')'时，需要找到与之匹配的开括号'('。
            为了找到这个开括号，代码从栈顶开始向下遍历，弹出并将栈中的运算符添加到后缀表达式中，直到遇到与闭括号匹配的开括号'('为止。
            在这个过程中，所有弹出的运算符都是位于闭括号与匹配的开括号之间的运算符。这些运算符按照它们在栈中的顺序（也就是它们在原中缀表达式中的顺序）被添加到后缀表达式中，保证了运算的正确顺序。
            当遇到开括号'('后，这个开括号也被弹出栈，但不会被添加到后缀表达式中。开括号的弹出表示已经处理完了这对括号内的所有内容。
            */
            while (!isEmpty(&s) && s.data[s.top] != '(')
            {
                postfix[index++] = pop(&s); // 将匹配左括号前的所有运算符输出
            }
            pop(&s); // 弹出左括号
        }
        else //+-*/等操作符
        {
            /*
            假设有一个中缀表达式"3+4*5"，并且我们正在处理+运算符。
            栈是空的，所以+直接被压栈。
            接下来，我们遇到*运算符。由于*的优先级高于栈顶的+运算符，*也被压栈。
            遍历结束后，栈中的运算符按照优先级从高到低的顺序依次弹出并添加到后缀表达式中，保证了运算的正确执行顺序。
            通过这种方式，算法确保了后缀表达式反映了正确的运算顺序和优先级。
            */
            // 栈中最上面的运算符优先级要最高
            while (!isEmpty(&s) && precedence(s.data[s.top]) >= precedence(*infix))
            {
                postfix[index++] = pop(&s); // 弹出所有优先级大于等于当前运算符的运算符
            }
            push(&s, *infix); // 当前运算符压栈
        }
        infix++;
    }

    // 将栈中剩余的运算符输出
    while (!isEmpty(&s))
    {
        postfix[index++] = pop(&s);
    }
    postfix[index] = '\0'; // 字符串结束符
}

int test1()
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
        return -1;
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
    test3();
    return 0;
}