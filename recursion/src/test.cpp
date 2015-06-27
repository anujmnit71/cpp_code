/*
 partially paranthesized infix to postfix

#include<cstdio>
#include<stack>

using namespace std;

void intopost(char in[],char post[]);
int prec(char op1,char op2);
int isdigit(char ch);
stack<char> s;

int main()
{
    char in[100],post[100],ch;
    int test=0;

    cin>>test;
    while(test--){
    	cin>>in;
    	intopost(in,post);
    	cout<<post<<endl;
    }

    getchar();
}

int isdigit(char ch){
    return (ch>='A'&&ch<='Z');
}

void intopost(char in[],char post[]){
     int pos=0,i=0;
     char symb;
     while(in[pos]){
                    if(isdigit(in[pos]))
                                        post[i++]=in[pos];
                    else{
                         while(!s.empty() && prec(in[pos],s.top())){
                                                                   symb= s.top();
                                                                   s.pop();
                                                                   post[i++]=symb;
                                                                   }
                         if(in[pos]==')'&& s.top()=='('){
                                                         s.pop();
                                                         pos++;
                                                         continue;
                                                         }
                         s.push(in[pos]);
                         }
                    pos++;
                    }
                    while(!s.empty()){
                                     post[i++]=s.top();
                                     s.pop();
                    }
                    post[i]='\0';
}


int prec(char op1,char op2){// if op1 has higher precedence return 0
    int x,y;
    int precd[7][6]={
                   {1,1,1,1,1,0},
                   {1,1,1,1,1,0},
                   {0,0,1,1,1,0},
                   {0,0,1,1,1,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {1,1,1,1,1,0}
                  };
     switch(op1){
                 case '+':
                      {
                          x=0;
                          break;
                          }
                 case '-':
                      {
                          x=1;
                          break;
                          }
                 case '*':
                      {
                          x=2;
                          break;
                          }
                 case '/':
                      {
                          x=3;
                          break;
                          }
                 case '^':
                      {
                          x=4;
                          break;
                          }
                 case '(':
                      {
                          x=5;
                          break;
                          }
                 case ')':
                      {
                          x=6;
                          break;
                          }
                 default:
                         printf("\nerror in op1\n");
                 }
      switch(op2){
                 case '+':
                      {
                          y=0;
                          break;
                          }
                 case '-':
                      {
                          y=1;
                          break;
                          }
                 case '*':
                      {
                          y=2;
                          break;
                          }
                 case '/':
                      {
                          y=3;
                          break;
                          }
                 case '^':
                      {
                          y=4;
                          break;
                          }
                 case '(':
                      {
                          y=5;
                          break;
                          }
                 default:
                         printf("\nerror in op2\n");
                 }
      return precd[x][y];
}

*/
