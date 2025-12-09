#include "ScalarConverter.hpp"
#include <cstring>

int main()
{
	std::string idk="65.545";

	ScalarConverter::convert(idk);
}

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // for isdigit

// Function to apply the operator to two operands
int apply_operator(int left, int right, char op)
{
    switch (op)
    {
        case '+': return left + right;
        case '*': return left * right;
        default: return 0;
    }
}

// Function to get the precedence of an operator
int get_precedence(char op)
{
    if (op == '*') return 2;
    if (op == '+') return 1;
    return 0;
}

int evaluate_expression(char *expr)
{
    int stack[100]; // Operand stack
    int top = -1; // Operand stack pointer
    char op_stack[100]; // Operator stack
    int top_op = -1; // Operator stack pointer
    
    for (int i = 0; expr[i] != '\0'; i++)
    {
        char current = expr[i];
        
        // If the current character is a digit, push it to the operand stack
        if (isdigit(current))
        {
            int num = current - '0'; // Convert character to integer
            stack[++top] = num;
        }
        
        // If the current character is an opening parenthesis, push it to the operator stack
        else if (current == '(')
        {
            op_stack[++top_op] = current;
        }
        
        // If the current character is a closing parenthesis, apply operators until '(' is encountered
        else if (current == ')')
        {
            while (top_op >= 0 && op_stack[top_op] != '(')
            {
                char prev_op = op_stack[top_op--]; // Pop the operator
                int right = stack[top--]; // Pop the right operand
                int left = stack[top--]; // Pop the left operand
                stack[++top] = apply_operator(left, right, prev_op); // Apply the operator and push the result
            }
            top_op--; // Pop the '(' from the operator stack
        }
        
        // If the current character is an operator (+ or *), process it
        else if (current == '+' || current == '*')
        {
            // While there's an operator on the stack with higher or equal precedence, apply it
            while (top_op >= 0 && get_precedence(op_stack[top_op]) >= get_precedence(current))
            {
                char prev_op = op_stack[top_op--]; // Pop the operator
                int right = stack[top--]; // Pop the right operand
                int left = stack[top--]; // Pop the left operand
                stack[++top] = apply_operator(left, right, prev_op); // Apply the operator and push the result
            }
            op_stack[++top_op] = current; // Push the current operator to the operator stack
        }
    }

    // Now apply any remaining operators in the operator stack
    while (top_op >= 0)
    {
        char op = op_stack[top_op--]; // Pop the operator
        int right = stack[top--]; // Pop the right operand
        int left = stack[top--]; // Pop the left operand
        stack[++top] = apply_operator(left, right, op); // Apply the operator and push the result
    }

    return stack[top]; // The final result will be the only value left on the operand stack
}

int main()
{
    char expr[] = "1+2("; // Example expression with parentheses
    int result = evaluate_expression(expr);
    printf("Result: %d\n", result); // Expected output: 1 + 2 * (4 + 5) = 1 + 2 * 9 = 1 + 18 = 19
    return 0;
}
