#include<cstdio>
using namespace std;

class Button{
public:
	virtual void paint() = 0;
};

class ScrollBar{
public:
	virtual void paint() = 0;
};

class WinButton : public Button{
public:
	void paint(){
		cout<<"Creating Win Button";
	}
};

class MacButton : public Button{
public:
	void paint(){
		cout<<"Creating Mac Button";
	}
};


class ScrollBar 
{
public:
	virtual void paint() = 0;
};
 
class WinScrollBar : public ScrollBar 
{
public:
	void paint (){
		std::cout << " Window ScrollBar \n";
       }
};
 
class MacScrollBar : public ScrollBar {
public:

	void paint (){
		std::cout << " Mac ScrollBar \n";
       }
};


class Guifactory
{
public:
	virtual Button* createButton() = 0;
	virtual ScrollBar* createScrollBar() = 0;
	Guifactory();
	~Guifactory();
	
};

class WinFactory : public Guifactory{
	virtual Button* createButton(){

	} ;
	virtual ScrollBar* createScrollBar() = 0;
};

class MacFactory : public Guifactory{
	void createButton(){
		cout<<"Creating Mac button \n";
	}
	void createScrollBar(){
		cout<<"Creating Mac Scroll Bar \n";
	}
};

class WinGui{
	Guifactory factory;
	public:
		WinGui(Guifactory f) : factory(f){}
	void addButton(){
		cout<<"Creating Win button \n";
	}
};

class MacGui{
	void createButton(){
		cout<<"Creating Win button \n";
	}
};