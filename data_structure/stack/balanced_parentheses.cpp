#include <iostream>
#include <stack>

using namespace std;

bool ValidParentheses(char* str)
{
    stack<char> s;
    for (int i = 0; i < strlen(str); i++)
    {
        if ((str[i] == '(') || (str[i] == '{') || (str[i] == '['))
        {
            s.push(str[i]);
        }
        else if ((str[i] == ')') || (str[i] == '}') || (str[i] == ']'))
        {
            if (!s.empty() && ((str[i] == ')' && s.top() == '(') ||
                   (str[i] == '}' && s.top() == '{') ||
                   (str[i] == ']' && s.top() == '[')))
            {
                s.pop();
            }   
            else 
            {
                return false;
            }
        }
    }
    if (s.empty()) return true;
    return false;
}
int main()
{
    char a[] = "{}()";
    bool x = ValidParentheses(a);
    cout << x << endl;
}