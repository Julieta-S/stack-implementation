#include "stack.h"
using namespace stack_implementation;

template<class T>
stack<T>::stack(const stack<T>& st)
{
	size_ = st.size_;
	top_ = st.top_;
	pointer_ = new T[size_];
	for (int i = 0; i, size_; ++i)
	{
		pointer_[i] = st.pointer_[i];
	}
}

template<class T>
stack<T>& stack<T>::operator=(const stack<T>& st)
{
	if (&st == this)
		return *this;
	size_ = st.size_;
	top_ = st.top_;
	pointer_ = new T[size_];
	for (int i = 0; i, size_; ++i)
	{
		pointer_[i] = st.pointer_[i];
	}
	return *this;
}

template<class T>
stack<T>::stack(stack<T>&& st)
{
	size_ = st.size_;
	top_ = st.top_;
	pointer_ = st.pointer_;
	st.pointer_ = nullptr;
}

template<class T>
stack<T>& stack<T>::operator=(stack<T>&& st)
{
	if (&st == this)
		return *this;
	delete[] pointer_;
	size_ = st.size_;
	top_ = st.top_;
	pointer_ = st.pointer_;
	st.pointer_ = nullptr;
	return *this;
}

template<class T>
stack<T>::stack(int n) :size_(n), top_(-1)
{
	pointer_ = new T[n];
}

template<class T>
stack<T>::~stack()
{
	delete[] pointer_;
}

template<class T>
bool stack<T>::empty() const
{
	return top_ == -1;
}

template<class T>
bool stack<T>::full() const
{
	return top_ + 1 == size_;
}

template<class T>
void stack<T>::push(const T& var)
{
	if (!full())
	{
		pointer_[++top_] = var;
	}
}

template<class T>
void stack<T>::pop()
{
	if (!empty())
	{
		--top_;
	}
}

template<class T>
T& stack<T>::top()
{
	if (!empty())
		return pointer_[top_];
}
