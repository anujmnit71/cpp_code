/*
//============================================================================
// Name        : mystack.cpp
// Author      : anuj
// Version     :
// Copyright   : Your copyright notice
// Description : stack class using abstract class ,  polymorphism
//============================================================================

#include <stddef.h>
#include <iostream>
#include<vector>

using namespace std;

template <typename T>
class Stack {
public:
	virtual ~Stack (void) = 0; // Need implementation!
	virtual void push (const T &item) = 0;
	virtual void pop (T &item) = 0;
	virtual bool is_empty (void) const = 0;
	virtual bool is_full (void) const = 0;
	void top (T &item) {  Template Method  pop (item); push (item); }
};

template <typename T> class V_Stack : public Stack<T> {
public:
	enum { DEFAULT_SIZE = 100 };
	V_Stack (size_t size = DEFAULT_SIZE);
	V_Stack (const V_Stack &rhs);
	virtual void push (const T &item);
	virtual void pop (T &item);
	bool is_full (void) const;
	virtual bool is_empty (void) const;

private:
	size_t top_; std::vector<T> stack_;
};

template <typename T>
V_Stack<T>::V_Stack (size_t size): top_ (0), stack_ (size) {}

template <typename T>
V_Stack<T>::V_Stack (const V_Stack &rhs): top_ (rhs.top_), stack_ (rhs.stack_) {}

template <typename T> void
V_Stack<T>::push (const T &item) { stack_[top_++] = item; }

template <typename T> void
V_Stack<T>::pop (T &item) { item = stack_[--top_]; }

template <typename T> bool
V_Stack<T>::is_full (void) const { return top_ >= stack_.size (); }


template <typename T> class Node; // forward declaration.
template <typename T> class L_Stack : public Stack<T> {
public:
	enum { DEFAULT_SIZE = 100 };
	L_Stack (size_t hint = DEFAULT_SIZE);
	~L_Stack (void);
	virtual void push (const T &new_item);
	virtual void pop (T &top_item);
	virtual bool is_empty (void) const { return head_ == 0; }
	virtual bool is_full (void) const { return 0; }
private:
	// Head of linked list of Node<T>’s.
	Node<T> *head_;
};

template <typename T> class Node {
	friend class L_Stack<T>;
public:
	Node (T i, Node<T> *n = 0): item_ (i), next_ (n) {}
private:
	T item_;
	Node<T> *next_;
};

//class L_Stack implementation:
template <typename T> L_Stack<T>::L_Stack (size_t): head_ (0) {}
template <typename T> void L_Stack<T>::push (const T &item) {
	Node<T> *t = new Node<T> (item, head_); head_ = t;
}
template <typename T> void L_Stack<T>::pop (T &top_item) {
	top_item = head_->item_;
	Node<T> *t = head_; head_ = head_->next_;
	delete t;
}
template <typename T> L_Stack<T>::~L_Stack (void)
{ for (T t; head_ != 0; pop (t)) continue; }

Stack<int> *make_stack (bool use_V_Stack){
	Stack<int>* ptr_s =  use_V_Stack ? (Stack<int>*)new V_Stack<int> : (Stack<int>*)new L_Stack<int>;
	return ptr_s;
}

void print_top (Stack<int> *stack) {
	std::cout << "top = " << stack->top() << endl;
}
int main (int argc, char **) {
	Stack<int>* sp =  make_stack(argc > 1);
	sp->push (10);
	print_top (sp.get ());
}
*/
