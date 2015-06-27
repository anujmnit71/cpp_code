/*

#include<cstdio>
#include<stack>
#include<vector>
#include<iostream>
#include<cctype>

using namespace std;

int has_initialized = 0;
void* managed_memory_start;
void* last_valid_address;

struct mem_init_block{
	int is_available;
	int size;
};

void malloc_init(void* ptr , int length){
	has_initialized = 1;
	managed_memory_start = ptr;
	last_valid_address = ptr + length;

}

void myfree(void * firstbyte){
	struct mem_init_block* mcb;
	mcb = firstbyte - sizeof(mem_init_block);
	mcb->is_available = 1;

}

int main()
{
	void* ptr_memory = (void*)malloc(sizeof(char)*1000);

	return 0;
}


*/
