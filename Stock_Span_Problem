#include <iostream>
#include <stack>
using namespace std;


void cal(int price[], int n, int S[])
{

	stack<int> st;
	st.push(0);

	S[0] = 1;
	for (int i = 1; i < n; i++) {
		while (!st.empty() && price[st.top()] <= price[i])
			st.pop();

		S[i] = (st.empty()) ? (i + 1) : (i - st.top());

		st.push(i);
	}
}

void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

int main()
{
	int price[] = {100, 80, 60, 70, 60, 75, 85};
	int n = sizeof(price) / sizeof(price[0]);
	int S[n];

	cal(price, n, S);

	print(S, n);

	return 0;
}
