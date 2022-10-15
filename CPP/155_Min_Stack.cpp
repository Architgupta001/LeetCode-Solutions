class MinStack
{
public:
    stack<int> s;
    stack<int> ss;
    MinStack()
    {
    }

    void push(int val)
    {
        if (ss.size() == 0 || ss.top() >= val)
            ss.push(val);
        s.push(val);
    }

    void pop()
    {
        if (s.top() == ss.top())
            ss.pop();
        s.pop();
    }

    int top()
    {
        return s.top();
    }

    int getMin()
    {
        return ss.top();
    }
};