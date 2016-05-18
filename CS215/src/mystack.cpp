//============================================================================
// Name        : mystack.cpp
// Author      : anuj
// Version     :
// Copyright   : Your copyright notice
// Description : Stack implementation concepts involved copy constructor and assignment operator
//============================================================================

#include <iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

typedef int T; // Where "...." is a placeholder for any C++ type.

template <typename T> class scoped_array;

template <typename T> class scoped_array {
public:
	explicit scoped_array (T *p = 0) : ptr_ (p) {}
	~scoped_array () { delete [] ptr_; }
	T &operator[](std::ptrdiff_t i) const { return ptr_[i]; }
	T *get() const { return ptr_; }
	void swap (T *&b) { T *tmp = b; b = ptr_; ptr_ = tmp; }
	void swap (scoped_array<T> &b)
	{ T *tmp = b.ptr_; b.ptr_ = this->ptr_; this->ptr_ = tmp; }
private:
	T *ptr_;
	scoped_array (const scoped_array<T> &);
	scoped_array &operator=(const scoped_array<T> &);
};

class Stack {
public:
	class Underflow { /* ... */ }; // WARNING: be cautious when using
	class Overflow { /* ... */ }; // exception specifiers...
	Stack (size_t size);
	Stack (const Stack &rhs);
	void operator= (const Stack &rhs);
	~Stack (void);
	void push (const T &item) throw (Overflow);
	void pop (T &item) throw (Underflow);
	bool is_empty (void) const { return top_ == 0; }
	bool is_full (void) const { return top_ == size_; }
private:
	size_t top_, size_; T *stack_;
};

Stack::Stack (size_t s): top_ (s), size_ (s), stack_ (new T[s]) {}
Stack::~Stack () { delete [] stack_; }

void Stack::push (const T &item) throw (Stack::Overflow) {
	if (is_full ()) throw Stack::Overflow ();
	stack_[top_++] = item;
}
void Stack::pop (T &item) throw (Stack::Underflow) {
	if (is_empty ()) throw Stack::Underflow ();
	item = stack_[--top_];
}

Stack::Stack (const Stack &s)
				: top_ (s.top_), size_ (s.size_), stack_ (0) {
	scoped_array<T> temp_stack (new T[s.size_]);
	for (size_t i = 0; i < s.size_; ++i) temp_stack[i] = s.stack_[i];
	temp_stack.swap (stack_);
}
void Stack::operator= (const Stack &s) {
	if (this == &s) return; // Check for self-assignment
	scoped_array<T> temp_stack (new T[s.size_]);
	for (size_t i = 0; i < s.size_; ++i) temp_stack[i] = s.stack_[i];
	top_ = s.top_; size_ = s.size_;
	temp_stack.swap (stack_);
}

/*
void Stack::operator= (const Stack &s) {
	if (this == &s) return; // Check for self-assignment
	Stack t (s);
	std::swap (t.top_, top_); std::swap (t.size_, size_);
	std::swap (t.stack_, stack_);
}
*/




/*
class Stack { // ...
private: // ...
	scoped_array<T> stack_;
	void swap (Stack &);
};
// ...
Stack::Stack (const Stack &s)
: top_ (s.top_), size_ (s.size_), stack_ (new T[s.size_]) {
	for (size_t i = 0; i < s.size_; ++i) stack_[i] = s.stack_[i];
}
Stack::~Stack () {  no-op!  }


void Stack::operator= (const Stack &s) {
	if (this == &s) return; // Check for self-assignment
	Stack temp_stack (s);
	swap (temp_stack);
}
void Stack::swap (Stack &t) {
	std::swap (t.top_, top_);
	std::swap (t.size_, size_);
	t.stack_.swap (stack_);
}

void foo (void) {
	Stack s1 (1), s2 (100);
	try {
		T item;
		s1.push (473);
		s1.push (42); // Exception, push’d full stack!
		s2.pop (item); // Exception, pop’d empty stack!
		s2.top_ = 10; // Access violation caught!
	} catch (Stack::Underflow) {  Handle underflow...  }
	catch (Stack::Overflow) {  Handle overflow...  }
	catch (...) {  Catch anything else...  throw; }
} // Termination is handled automatically.
}



*/

/*
template<typename T>
class mystack{

	T* val;
public:
	int top,N;
	mystack(int size) : top(-1) , N(size) , val (new T[size]){}

	mystack(const mystack<T>& that){
		top = that.top;
		val = new T[that.N];
		N = that.N;
		memcpy(val , that.val , N);
	}

	void operator=(const mystack& that){
		top = that.top;
		N = that.N;
		for(int i =0 ; i < N ; i++)
			val[i] = that.val[i];
	}
	~mystack(){
		delete[] val;
		cout<<"Memory deleted";
	}
	class StackFull{};
	class StackEmpty{};
	void push(const T& num) throw (StackFull);
	T pop() throw (StackEmpty);

};

template<typename T>
void mystack<T>::push(const T& num) throw (StackFull){
	try{
		if(top+1 == N)
			throw StackFull();
		else{
			++top;
			val[top] = num;
		}
	}
	catch(StackFull& s){
		cout<<"Stack full exception caught\n";
	}
}

template<typename T>
T mystack<T>::pop() throw (StackEmpty){
	int result = -1;
	try{
		if(top == -1)
			throw StackEmpty();
		else{
			result = val[top];
			top--;
		}
	}
	catch(StackEmpty& e){
		cout<<"Stack empty exception caught\n";
	}
	return result;
}


int main() {

 *If we do not give copy constructor then delete s will also delete array of s2 since shallow copy is done therefore
 *s2 and s both share same array
 *mystack<int>* s = new mystack<int>(5);
	mystack<int> s2(*s);
	delete s;

	mystack<int> s2(5);
	//{
	mystack<int> s(5);

	for(int i=0 ; i<5 ; i++)
		s.push(i);
	for(int i=0 ; i<5 ; i++)
		cout<<s.pop()<<"\t";
	s2 = s;
	//}

	//delete s;
	cout<<"\n tops is "<<s2.top<<"N is "<<s2.N<<endl;
	for(int i=0 ; i<5 ; i++)
			cout<<s2.pop()<<"\t";
	return 0;
}
 */
