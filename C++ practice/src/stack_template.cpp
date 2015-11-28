template <typename T> class Stack {
public:
	Stack (size_t size);
	Stack (const Stack<T> &rhs);
	void operator= (const Stack<T> &rhs);
	~Stack (void)
	void push (const T &item);
	void pop (T &item);
	bool is_empty (void) const;
	bool is_full (void) const;
private:
	size_t top_, size_; scoped_array<T> stack_;
	void swap (scoped_array<T> &t);
};

template <typename T> inline
Stack<T>::Stack (size_t size): top_ (0), size_ (size), stack_ (new T[size]) { }

template <typename T> inline 
Stack<T>::~Stack (void) { /* no-op! */ }

template <typename T> inline void
Stack<T>::push (const T &item) { stack_[top_++] = item; }

template <typename T> inline void
Stack<T>::pop (T &item) { item = stack_[--top_]; }

#include "Stack.h"
void foo (void) {
	Stack<int> s1 (1000);
	Stack<float> s2;
	Stack< Stack <Activation_Record> *> s3;
	s1.push (-291);
	s2.top_ = 3.1416; // Access violation caught!
	s3.push (new Stack<Activation_Record>);
	Stack <Activation_Record> *sar;
	s3.pop (sar);
	delete sar; // Termination of s1, s2, & s3 handled automatically
}
