template <typename T>
class Stack {
public:
	virtual ~Stack (void) = 0; // Need implementation!
	virtual void push (const T &item) = 0;
	virtual void pop (T &item) = 0;
	virtual bool is_empty (void) const = 0;
	virtual bool is_full (void) const = 0;
	void top (T &item) { /* Template Method */ pop (item); push (item); }
};

#include "Stack.h"
#include <vector>
template <typename T> class V_Stack : public Stack<T> {
public:
	enum { DEFAULT_SIZE = 100 };
	V_Stack (size_t size = DEFAULT_SIZE);
	V_Stack (const V_Stack &rhs);
	virtual void push (const T &item);
	virtual void pop (T &item);
	virtual bool is_empty (void) const;
	virtual bool is_full (void) const;
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
template <typename T> int
V_Stack<T>::is_full (void) const { return top_ >= stack_.size (); }

