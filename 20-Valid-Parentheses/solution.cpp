class Solution {
public:
    bool isValid(string s) {
        stack<char> test_stack;
        int n = s.size();
        for(int i=0; i<n; i++)
        {
            switch(s[i])
            {
                case '(':
                case '[':
                case '{':
                    test_stack.push(s[i]); break;
                case ')':
                    if(test_stack.empty() || test_stack.top() != '(')
                        return false;
                    else
                        test_stack.pop();
                    break;
                case ']':
                    if(test_stack.empty() || test_stack.top() != '[')
                        return false;
                    else
                        test_stack.pop();
                    break;
                case '}':
                    if(test_stack.empty() || test_stack.top() != '{')
                        return false;
                    else
                        test_stack.pop();
                    break;
                default:
                    return false;
            }
        }
        return test_stack.empty();
    }
};