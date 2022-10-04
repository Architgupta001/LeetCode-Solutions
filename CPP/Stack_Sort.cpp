#include <bits/stdc++.h>

using namespace std;

void sort(stack<int> &st, int num)
{
    if (st.empty() ||(st.top() < num))
    {
        st.push(num);
        return;
    }
    int x = st.top();
    st.pop();
    sort(st, num);
    st.push(x);
}

void get(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int num = st.top();
    st.pop();
    // recursive call
    get(st);
    sort(st, num);
}
int main()
{
    // reverse using recursion
    stack<int> st;
    st.push(23);
    st.push(2);
    st.push(21);
    st.push(28);
    st.push(11);

    get(st);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}
