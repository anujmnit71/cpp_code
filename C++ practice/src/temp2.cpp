/*
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
	friend template <typename T> class L_Stack;
public:
	Node (T i, Node<T> *n = 0): item_ (i), next_ (n) {}
private:
	T item_;
	Node<T> *next_;
};

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

Stack<int> *make_stack (bool use_V_Stack)
{ return use_V_Stack ? new V_Stack<int> : new L_Stack<int>; }
void print_top (Stack<int> *stack) {
	std::cout << "top = " << stack->top () << std::endl;
}
int main (int argc, char **) {
	std::auto_ptr <Stack<int>> sp (make_stack (argc > 1));
	sp->push (10);
	print_top (sp.get ());
}
*/
