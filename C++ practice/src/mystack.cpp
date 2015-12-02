/*
#include<iostream>
#include<cstdio>
using namespace std;


class UnderFlow : public exception{
				
};
class OverFlow : public exception{
	
};

template<class T> class MyStack{
	private:
			int n;
			T* arr;
			int top = -1;
	public:
			MyStack(int size){
				top = 0;
				n = size;
				arr = new T[n]; 
			}
			MyStack(){
				top = 0;
				n = 10;
				arr = new T[n]; 
			}
			~MyStack(){
				cout<<"Destructor call"<<endl;
				delete arr;
			}
			void push(T element);
			T pop();
			bool isEmpty();
			bool isFull();
};

template<class T> 
bool MyStack<T>::isEmpty(){
	return this->top == 0;
}

template<class T> 
bool MyStack<T>::isFull(){
	return top == n;
}

template<class T> 
T MyStack<T>::pop(){
	if(this->isEmpty())
		throw new UnderFlow();
	return arr[--top];
}

template<class T> 
void MyStack<T>::push(T elem){
	if(this->isFull())
		throw new OverFlow();
	arr[top] = elem;
	top++;
}


int main(){
	MyStack<int> st(5);
	try{
		for(int i = 10 ; i < 15 ; i++)
			st.push(i);
		
		for(int i = 10 ; i < 16 ; i++)
			cout<<st.pop()<<"\n";
	}
	catch(UnderFlow* u){
		cout<<"UnderFlow called \n";
	}
	catch(OverFlow* o){
		cout<<"OverFlow called \n";
	}
		
}
*/
