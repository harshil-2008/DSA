#include<iostream>
#include<stack>
using namespace std;

int priority(char ch)
{
    if(ch == '^')
        return 3;
    if(ch == '*' || ch == '/')
        return 2;
    if(ch == '+' || ch == '-')
        return 1;

    return 0;
}

void infixToPostfix(string exp)
{
    stack<char> s;
    string result = "";

    for(int i = 0; i < exp.length(); i++)
    {
        char ch = exp[i];

        if((ch >= 'a' && ch <= 'z') ||
           (ch >= 'A' && ch <= 'Z') ||
           (ch >= '0' && ch <= '9'))
        {
            result = result + ch;
        }

        else if(ch == '(')
        {
            s.push(ch);
        }

        else if(ch == ')')
        {
            while(!s.empty() && s.top() != '(')
            {
                result = result + s.top();
                s.pop();
            }

            if(!s.empty())
                s.pop();
        }

        else
        {
            while(!s.empty() && priority(s.top()) >= priority(ch))
            {
                result = result + s.top();
                s.pop();
            }

            s.push(ch);
        }
    }

    while(!s.empty())
    {
        result = result + s.top();
        s.pop();
    }

    cout << "Postfix: " << result << endl;
}

int main()
{
    string exp;

    cout << "Enter infix expression: ";
    cin >> exp;

    infixToPostfix(exp);

    return 0;
}
