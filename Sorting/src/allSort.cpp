/*
To sort an array read from a file 06/08/09 03:57

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int val;
	struct node *next;
};
typedef struct node* nodeptr;
void insert(nodeptr* head,int n);

void bubble(int x[],int n);
void insertion(int x[],int y);
int partition(int x[],int lb,int ub);
void quick(int x[],int lb,int ub);
void selection(int x[],int y);
void merge(int x[],int n);
void address(int x[],int n);
void radix(int x[],int n);


int main()
{
	FILE *fp;
	int n1,n2,a[1000],p[1000],i=0,c,l,b,j;
	fp=fopen("array.dat","w");
	n1=n2=rand()%100;
	printf("no. of entries %d\n\n",n1);
	for(i=0;i<n1;i++)
	{
		a[i]=rand()%100;
		putw(a[i],fp);
	}
	i=0;
	printf("\n");
	fclose(fp);
	fp=fopen("array.dat","r");
	printf("original array is\n");
	while((c=getw(fp))!=EOF)
	{
		p[i]=c;
		printf("%d\t",p[i]);
		i++;
	}
	fclose(fp);
	printf("\nenter choice:\n1)bubble.\n2)insertion.\n3)quick.\n4)selection.\n5)merge.\n6)address.\n7)radix.\n");
	scanf("%d",&b);
	if(b<=7&&b>=1)
	{
		switch(b)
		{
			case 1:
					bubble(p,n1);
					break;
			case 2:
					insertion(p,n1);
					break;
			case 3:
					quick(p,0,n1-1);
					break;
			case 4:
					selection(p,n1);
					break;
			case 5:
					merge(p,n1);
					break;
			case 6:
					address(p,n1);
					break;
			case 7:
					radix(p,i);
					break;
		}
		printf("\n\n");
		for(i=0;i<n1;i++)
                        printf("%d\t",p[i]);
	}
	else
	{
		printf("enter valid choice\n");
	}
	getch();
}


void bubble(int x[],int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(x[j]<=x[j+1])
				continue;
			elseswap unsorted elements
			{
				temp=x[j];
				x[j]=x[j+1];
				x[j+1]=temp;
			}
		}
	}
}

void insertion(int a[],int n)
{
	int i,j,max,pos,temp;
     for(i=1;i<n;i++){
                        temp=a[i];
                        for(j=i-1;j>=0&&temp<a[j];j--)
                                                      a[j+1]=a[j];
                        a[j+1]=temp;
                        }


    int i,n,temp;
	for(i=0;i<y;i++)
	{
		if(x[i]<x[i+1])
			continue;
		else
		{
			temp=x[i+1];
			for(n=i;n>=0;n--)/*shift previous entries
			{
				x[n+1]=x[n];
				if(n==0||(x[n-1]<temp))
				break;
			}
			x[n]=temp;//unsorted entry placed correctly
//		 }
//	}
}

int partition(int x[],int lb,int ub)
{
	int a,down,temp,up,i;
	a=x[lb];
	up=ub;
	down=lb;
	while(down<up)
	{
		while(x[down]<=a&&down<ub)
			down++;
		while(x[up]>a)
			up--;
		if(down<up)
		{
			temp=x[down];
			x[down]=x[up];
			x[up]=temp;
		}
	}
	x[lb]=x[up];
	x[up]=a;
	return up;
}

void quick(int x[],int lb,int ub)
{
	int p;
	if(lb>=ub)
		return;
	p=partition(x,lb,ub);
	quick(x,lb,p-1);
	quick(x,p+1,ub);
}

void selection(int x[],int y)
{
	int i,j,min,temp;
	for(i=0;i<y;i++)
	{
		min=i;
		for(j=i+1;j<y;j++)
		{
			if(x[j]<x[min])
				min=j;
		}
		if(min!=i)
		{
			temp=x[i];
			x[i]=x[min];
			x[min]=temp;
		}
	}
}

void merge(int x[],int y)
{
	int temp[100],i,j,k,l1,l2,u1,u2,s;
	s=1;
	while(s<y)
	{
		l1=0;
		k=0;
		while(l1+s<y)
		{
			l2=l1+s;
			u1=l2-1;
			u2=(l2+s-1<y)?l2+s-1:y-1;

			for(i=l1,j=l2;i<=u1&&j<=u2;k++)
			{
				if(x[i]<=x[j])
				{
					temp[k]=x[i++];
				}
				else
				{
					temp[k]=x[j++];
				}
			}
			for(;i<=u1;k++)
				temp[k]=x[i++];
			for(;j<=u2;k++)
				temp[k]=x[j++];
			l1=u2+1;
		}
		for(i=l1;k<y;i++)
			temp[k++]=x[i];
		for(i=0;i<y;i++)
			x[i]=temp[i];
		s*=2;
	}
}


void address(int x[],int n){
     int f[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
     int i,index,pos,a,b,pre,k=0;
     struct{
            int info;
            int next;
            }node[100];
     for(i=0;i<n;i++){
                      node[i].info=x[i];
                      node[i].next=-1;
                      }
     for(i=0;i<n;i++){
                      index=(node[i].info)/10;
                      if(f[index]==-1)
                                      f[index]=i;
                      else{
                           pos=f[index];
                           a=node[i].info;
                           b=node[pos].info;
                           pre=-1;
                           while(a>b&&pos!=-1){
                                      pre=pos;
                                      pos=node[pos].next;
                                      b=node[pos].info;
                                     }
                           if(pre==-1){
                                      f[index]=i;
                                      node[i].next=pos;
                                      }
                           else{
                               node[pre].next=i;
                               node[i].next=pos;
                               }
                           }
                    }
     //printf("after \n");
     //for(i=0;i<10;i++)
       //       printf("f %d\t",f[i]);
     //printf("after \n");
     //for(i=0;i<5;i++)
       //       printf("node %d %d\t%d\n",i,node[i].info,node[i].next);
     printf("sorted\n");
     for(i=0;i<10;i++){
                       index=f[i];
                       while(index!=-1){
                                x[k++]=node[index].info;
                                index=node[index].next;
                                }
                       }
}


void radix(int x[],int n){
     struct node* q[10],*p=NULL;
     int i,j,k,pass=1,digit;
     printf("hello");
     for(i=0;i<10;i++)
                      q[i]=NULL;
     for(i=0;i<2;i++){
                      for(j=0;j<n;j++){
                                       digit=(x[j]/pass)%10;
                                       insert(&q[digit],x[j]);
                                       }
                      k=0;
                      for(j=0;j<10;j++){
                                       p=q[j];
                                       while(p!=NULL){
                                                            x[k++]=p->val;
                                                            p=p->next;
                                                            }
                                      }
                     for(j=0;j<10;j++)
                                      q[j]=NULL;
                     for(j=0;j<n;j++)
                                     printf("%d\t",x[j]);
                     pass*=10;
                     }
}

void insert(nodeptr* head,int n)
{
	struct node *temp,*p=*head;
	p=*head;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->val=n;
	temp->next=NULL;
	if(*head==NULL)
		*head=temp;
	else
	{
		while(p->next!=NULL)
			p=p->next;
		p->next=temp;
	}

}



*/
