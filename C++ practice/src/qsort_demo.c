#include<stdio.h>
#include<string.h>

int fn_cmp(const void * first , const void * second){
	char **n1 , **n2;
	n1 = (char**)first;
	n2 = (char**)second;
	return strcmp(*n1 , *n2);
}

int main(){
	char* names[] = {	
						"anuj",
						"amit",
						"chetan",
						"bhaskar"
					};
	int i = 0;
	for(i= 0 ; i < 4 ; i++)
		puts(names[i]);
		
	qsort(names , sizeof(names)/sizeof(names[0]) , sizeof(names[0]) , fn_cmp);
	
	for(i= 0 ; i < 4 ; i++)
		puts(names[i]);
		
	char *str = "chetan";
	
	char **find = (char**)bsearch(&str , names , sizeof(names)/sizeof(names[0]) , sizeof(names[0]) , fn_cmp);
	puts("============");
	puts(*find);
	
	
}
