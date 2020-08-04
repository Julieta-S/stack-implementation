#include "stack.h"
#include "stack.cpp"

int main()
{
	stack<int> st(5);
	for (int i = 10; i < 15; ++i)
	{
		st.push(i);
	}

	cout << st.top() << endl;
	st.top() = 1;
	cout << st.top() << endl;

	stack<int> st1(move(st));
	for (int i = 0; i < 5; ++i)
	{
		cout << st1.top() << " ";
		st1.pop();
	}
}