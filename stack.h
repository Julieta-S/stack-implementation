#include <iostream>
using namespace std;
namespace stack_implementation
{
	template<class T>
	class stack
	{
	public:
		stack(int n = 50);
		stack(const stack<T>& st);
		stack<T>& operator=(const stack<T>& st);
		stack(stack<T>&& st);
		stack<T>& operator=(stack<T>&& st);
		~stack();
		bool empty() const;
		bool full() const;
		void push(const T& var);
		void pop();
		T& top();
	private:
		T* pointer_;
		int size_;
		int top_;
	};
}
#pragma once
