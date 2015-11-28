#include<iostream>
using namespace std;

class Base{
	private:
			~Base();
		
	public:
			Base(){
				puts("Base called \n");
			}
			Base(const Base& b){
				puts("Copy ctor called \n");
			}
			
			Base& operator=(const Base& b){
				puts("Assign called \n");
			}
			
		Base func(Base b){
			puts("In func \n");
			return b;
		}
				
};

class Derived:public Base{
	private:
		Derived& operator=(const Derived& b){ // this won't be called for assignment operator unless definitation is 
											//	 Derived& operator=(const Derived& b)
											//	Base class assignment operator is called 
			puts("Derived assign operator called \n");
		}
		//~Derived();
	public:
		Derived(){
			puts("Derived ctor called \n");
		}
		Base func(Derived b){
			puts("In func2 \n");
			return b;
		}
		Derived(Derived& d){
			puts("Derived copy ctor called \n");
		}
		
};

int main(){
	//Base b1;
	//Base b2 = b1;;
	//b1.func(b1);
	//b2 = b1;
	//Base b1;
	Derived d1;
	//d1 = d2;
	//b1.func(d1);
	//d1.func(d1);
	//d1 = (Derived)b1;
}
