#pragma once
#include "ExpressionManagerInterface.h"
#include <sstream>
#include <stack>
#include <string>
#include <iostream>
#include <cctype>
#include "ctype.h"
#include <stdio.h>
#include <string.h>
#ifndef postfixEvaluate_h
#define postfixEvaluate_h
#ifndef SyntaxError_h
#define SyntaxError_h

using namespace std;

//Data fields
//static const std::string OPERATORS;
std::stack<int> operand_stack;
const std::string OPERATORS = "+-*%/";

int eval_op(char op);

bool is_operator(char ch)
{
    return OPERATORS.find(ch) != std::string::npos;
}




const std::string PARENS = "}])([{";
bool is_paren(char ch)
{
    return PARENS.find(ch) != std::string::npos;
}





class SyntaxError : public std::invalid_argument
{
    friend class ExpressionManager;
    friend class postfixEvaluate;
public:\
    SyntaxError(std::string msg) : std::invalid_argument(msg) {}
};



class postfixEvaluate
{
    friend class ExpressionManager;
    friend class SyntaxError;
    
    //postfixEvaluate(){}
    //virtual ~postfixEvaluate(){}
    //Public Member Functions
public:
    /** Evaluates a postfix expression
     @param expression The expression to be evaluated
     @return The value of the expression
     @throws Syntax_Error if a syntax error is detected
     */
    
    static int eval(const std::string& expression);
    
    
    
    //Private member functions
private:
    /** Evaluates the current operator
     This function pops the two operands off the operand stack and applies the operator.
     @param op A character representing the operator
     @throws Syntax_Error if top is attempted on an empty stack
     */
    
    //int eval_op(char op);
    
    /** Determines whether a character is an operator
     @param ch The character to be tested
     @return true if the character is an operator
     */
    //bool is_operator(char ch) const
    //{
    //    return OPERATORS.find(ch) != std::string::npos;
    //}
    
    //Data fields
    //static const std::string OPERATORS;
    //std::stack<int> operand_stack;
};

class ExpressionManager : public ExpressionManagerInterface
{
    friend class postfixEvaluate;
    friend class SyntaxError;
    
public:
    
    ExpressionManager(){}
    virtual ~ExpressionManager(){}
    
    /////////////////////////////////IS BALANCED?/////////////////////////////////
    /*
     * Checks whether an expression is balanced on its parentheses
     *
     * - The given expression will have a space between every number or operator
     *
     * @return true if expression is balanced
     * @return false otherwise
     */
    
    //The set of opening parentheses
    const string OPEN = "([{";
    //The corresponding set of closing parentheses
    const string CLOSE = ")]}";
    
    /** Function to determine whether a character is one of the opening parentheses (defined in constant OPEN).
     @param ch Character to be tested
     @return true If the character is an opening parenthesis
     */
    
    bool is_open(char ch)
    {
        return OPEN.find(ch) != string::npos;
    }
    
    /** Function to determine whether a character is one of the closing parentheses (Defined in constant CLOSE)
     @param ch Character to be tested
     @return true If the character is a closing parenthesis
     */
    
    bool is_close(char ch)
    {
        return CLOSE.find(ch) != string::npos;
    }
    
    /** Test the input string to see that it contains balanced parentheses. This function tests an input string to see that each type of parenthesis is balanced. '(' is matched with ')', '[' is matched with ']', and '{' is matched with '}'.
     @param postfixExpression A string containing the expression to be examined
     @return true if all parentheses match
     */
    
    bool isBalanced(string postfixExpression)
    {
        //A stack for the open parentheses that haven't been matched
        stack<char> s;
        bool balanced = true;
        string::const_iterator iter = postfixExpression.begin();
        while (balanced && (iter != postfixExpression.end()))
        {
            char next_ch = *iter;
            if (is_open(next_ch))
            {
                s.push(next_ch);
            }
            else if (is_close(next_ch))
            {
                if (s.empty())
                {
                    balanced = false;
                }
                else
                {
                    char top_ch = s.top();
                    s.pop();
                    balanced = OPEN.find(top_ch) == CLOSE.find(next_ch);
                }
            }
            ++iter;
        }
        //if it is not balanced, return "invalid"
           return balanced && s.empty();
        
    }
    
    /////////////////////////////////POSTFIX-TO-INFIX/////////////////////////////////
    /**
     * Converts a postfix expression into an infix expression
     * and returns the infix expression.
     *
     * - The given postfix expression will have a space between every number or operator.
     * - The returned infix expression must have a space between every number or operator.
     * - Redundant parentheses are acceptable i.e. ( ( 3 * 4 ) + 5 ).
     * - Check lab requirements for what will be considered invalid.
     *
     * return the string "invalid" if postfixExpression is not a valid postfix expression.
     * otherwise, return the correct infix expression as a string.
     */
    virtual string postfixToInfix(string postfixExpression)
    {
        stack<string> theStack;
        
        //somehow make the string stream = to the expression
        istringstream input(postfixExpression);
        
        
        //we need to turn the string that they gave us into an int to pass it into isdigit
        
        char theInput;
        
        if(isBalanced(postfixExpression) == true)
        {
            while (input >> theInput)
            {
                //if the expression's character is a number, push onto the stack
                if (isdigit(theInput))
                {
                    input.putback(theInput);
                    string value;
                    input >> value;
                    
                    for(unsigned int i = 0; i<value.length(); i++)
                    {
                        char character = value[i];
                        if (!isdigit(character))
                        {
                            return "invalid";
                        }
                    }
                    
                    theStack.push(value);
                }
                
                else if (is_operator(theInput))
                {
                    if(theStack.size() >= 2)
                    {
                        ostringstream output;
                        
                        string right = theStack.top();
                        theStack.pop();
                        //cout << "right: " << right << "/n";
                        
                        string left = theStack.top();
                        theStack.pop();
                        //cout << "left: " << left << "/n";
                        
                        output << "( " << left << " " << theInput << " " << right << " )";
                        //cout << output.str();
                        theStack.push(output.str());
                    }
                    else if (theStack.size() < 2)
                    {
                        return "invalid";
                    }
                }
                else
                {
                    return "invalid";
                }
            }
            //if we reach here, it means we have reached the end of the expression
            
            //The expression that's left on the stack when you reach the end of the string, is the result
            if(theStack.size() > 1)
            {
                return "invalid";
            }
            
            string result = theStack.top();
            return result;
            
        }
        else
            return "invalid";
    };
    
    
    
    int precedence(char theOperator)
    {
        switch (theOperator)
        {
            case '(':
            case '[':
            case '{':
                return 0;
            case '+':
            case '-':
                return 1;
            case '*':
            case '/':
            case '%':
                return 2;
            case ')':
            case ']':
            case '}':
                return 3;
            default:
                return 0;
        }
        
    }
    /////////////////////////////////INFIX-TO-POSTFIX/////////////////////////////////
    /*
     * Converts an infix expression into a postfix expression
     * and returns the postfix expression
     *
     * - The given infix expression will have a space between every number or operator.
     * - The returned postfix expression must have a space between every number or operator.
     * - Check lab requirements for what will be considered invalid.
     *
     * return the string "invalid" if infixExpression is not a valid infix expression.
     * otherwise, return the correct postfix expression as a string.
     */
    virtual string infixToPostfix(string infixExpression)
    {
        stack<char> theStack;
        istringstream input(infixExpression);
        
        char theInput;
        ostringstream output;
        
        if(isBalanced(infixExpression) == true)
        {
            while (input >> theInput)
            {
                //cout << "input::: " << theInput << "\n\n\n";
                //if the expression's character is a number, push onto the stack
                if (isdigit(theInput))
                {
                    input.putback(theInput);
                    string value;
                    input >> value;
                    
                    output << value << " ";
                    
                    
                    int stack_weight;
                    if (theStack.size() == 0)
                    {
                        stack_weight = -1;
                    }
                    else
                    {
                        stack_weight = precedence(theStack.top());
                    }
                    //cout << "theInput: " << value << "\n";
                    //cout << "stack size: " <<theStack.size() << "\n";
                    //cout << "stack weight is: " << stack_weight << "\n\n";
                    
                    int input_weight = precedence(theInput);
                    //cout << "Input Weight: " << input_weight << "\n\n";
                }
                
                else if (is_operator(theInput) || is_paren(theInput))
                {
                    //cout << "theInput" << theInput;
                    int stack_weight;
                    if (theStack.size() == 0)
                    {
                        stack_weight = -1;
                    }
                    else
                    {
                        stack_weight = precedence(theStack.top());
                    }
                    //cout << "theInput: " << theInput << "\n";
                    //cout << "stack size: " <<theStack.size() << "\n";
                    //cout << "stack weight is: " << stack_weight << "\n\n";
                    
                    
                    int input_weight = precedence(theInput);
                    //cout << "Input Weight: " << input_weight << "\n\n";
                    
                    if (input_weight == 3)
                    {
                        switch (theInput)
                        {
                            case ')':
                                while (theStack.top() != '(')
                                {
                                    output << theStack.top() << " ";
                                    theStack.pop();
                                }
                                break;
                            case ']':
                                while (theStack.top() != '[')
                                {
                                    output << theStack.top() << " ";
                                    theStack.pop();
                                }
                                break;
                            case '}':
                                while (theStack.top() != '{')
                                {
                                    output << theStack.top() << " ";
                                    theStack.pop();
                                }
                                break;
                        }
                        theStack.pop();
                    }
                    else if (input_weight == 0)
                    {
                        theStack.push(theInput);
                    }
                    else if (input_weight > stack_weight)
                    {
                        theStack.push(theInput);
                        //cout << theInput << "the segmentation fault happens here \n";
                        //cout << "stack weight is: " << stack_weight << "\n";
                        //infixToPostfix 40 * ( 2 + 4 - ( 2 + 2 ) ) - 4 / 5 / 6
                        //It's getting stuck on the second +
                    }
                    else if (input_weight <= stack_weight)
                    {
                        while (input_weight <= stack_weight)
                        {
                            //cout << "HALEY WAS HERE" << theInput <<"\n";
                            output << theStack.top() << " ";
                            theStack.pop();
                            if (theStack.size() == 0)
                            {
                                stack_weight = -1;
                            }
                            else
                            {
                                stack_weight = precedence(theStack.top());
                            }
                        }
                        theStack.push(theInput);
                    }
                }
                else
                {
                    //cout << "the input:" << theInput << "haley";
                    return "invalid";
                }
            }
            //if we reach here, it means we have reached the end of the expression
            if (theStack.empty())
            {
                string output_minus_last = output.str().substr(0, output.str().size()-1);
                
                return output_minus_last;
            }
            else
            {
                while (!theStack.empty())
                {
                    if (theStack.size() == 1)
                    {
                        //cout << "theStack.top is: " << theStack.top()<< "OKAY\n";
                        //cout << "output is: " << output.str() << "\n";
                        output << theStack.top();
                        theStack.pop();
                    }
                    else
                    {
                        output << theStack.top() << " ";
                        theStack.pop();
                    }
                }
            }
            //The expression that's left on the stack when you reach the end of the string, is the result
            string trueOutput = postfixEvaluate(output.str());
            if(trueOutput == "invalid")
            {
                return trueOutput;
            }
            else
            {
                return output.str();
            }
        }
        else
        {
            cout << "NOT BALANCED. Expression is: " << infixExpression << "\n";
            return "invalid";
        }
        
        
    };
    
    
    
    
    /////////////////////////////////POSTFIX EVALUATE/////////////////////////////////
    /*
     * Evaluates a postfix expression returns the result as a string
     *
     * - The given postfix expression will have a space between every number or operator.
     * - Check lab requirements for what will be considered invalid.
     *
     * return the string "invalid" if postfixExpression is not a valid postfix Expression
     * otherwise, return the correct evaluation as a string
     */
    
    
    
    /** Evaluates a postfix Expression
     @param postfixExpression The expression to be evaluated
     @return The value of the expression
     @throws SyntaxError if a syntax error is detected
     */
    
    virtual string postfixEvaluate(string postfixExpression)
    {
        if(isBalanced(postfixExpression) == true)
        {
            //Be sure the stack is empty
            while (!operand_stack.empty())
                operand_stack.pop();
            
            //Process each token
            istringstream tokens(postfixExpression);
            char next_char;
            while (tokens >> next_char)
            {
                if (isdigit(next_char))
                {
                    tokens.putback(next_char);
                    int value;
                    tokens >> value;
                    operand_stack.push(value);
                }
                else if (is_operator(next_char))
                {
                    if (operand_stack.size() >= 2)
                    {
                        if ((next_char == '/' || next_char == '%') && operand_stack.top() == 0)
                        {
                            return "invalid";
                        }
                        int result = eval_op(next_char);
                        operand_stack.push(result);
                    }
                    else if (operand_stack.size() < 2)
                    {
                        return "invalid";
                    }
                }
                else
                {
                    //cout << "Next char is:" << next_char << "haley";
                    return "invalid";
                }
            }
            
            
            if (!operand_stack.empty())
            {
                int answer = operand_stack.top();
                operand_stack.pop();
                
                if (operand_stack.empty())
                {
                    string returnAnswer = to_string(answer);
                    return returnAnswer;
                }
                else
                {
                    throw SyntaxError("Stack should be empty");
                }
            }
            else
            {
                return "invalid";
            }
        }
        else
        {
            return "invalid";
        }
    }
    
    /** Evaluates the current operator
     This function pops the two operands off the operand stack and applies the operator
     @param op A character representing the operator
     @throws SyntaxError if top is attempted on an empty stack
     */
    
    int eval_op(char op)
    {
        //it's here
        if (operand_stack.empty())
            throw SyntaxError("invalid");
        
        int rhs = operand_stack.top();
        operand_stack.pop();
        if (operand_stack.empty())
            throw SyntaxError("invalid");
        
        int lhs = operand_stack.top();
        operand_stack.pop();
        int result = 0;
        switch(op)
        {
            case '+' : result = lhs + rhs;
                break;
            case '-' : result = lhs - rhs;
                break;
            case '*' : result = lhs * rhs;
                break;
            case '/' : result = lhs / rhs;
                break;
            case '%' : result = lhs % rhs;
                break;
        }
        return result;
    }
    
};

#endif /* postfixEvaluate_h */
#endif /* SyntaxError_h */
