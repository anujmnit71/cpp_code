#include<cstdio>
#include<iostream>

using namespace std;

class sample{
public:
	virtual void f(int x){
		cout<<"Calling f with "<<x<<" \n";
	}
	
	virtual void h(int x){
		cout<<"Calling h with "<<x<<" \n";
	}
	
	void g(){
		cout<<"Calling g \n";

		int* ptrobj = (int* ) this;
		int* ptr_vtable = (int* ) (*ptrobj);
		int* ptrfunc = (int*) (*ptr_vtable);

		void (*ptrfunccall)( sample*const, int);
		ptrfunccall = (void (*)( sample*const, int ))ptrfunc;
		(*ptrfunccall)(this,25);
		ptrfunc = (int*)(pt
		rfunc +1);// not calling second virtual function
		ptrfunccall = (void (*)( sample*const, int ))ptrfunc;
		(*ptrfunccall)(this,5);
		
	}

};

int main(){
	sample s;
	s.g();
}
