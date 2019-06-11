#include "debug.h"
#include <iostream>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define HASH_SHIFT  4
#define HASH_SIZE  (1<<HASH_SHIFT)
#define HASH_MASK   HASH_SIZE-1
using namespace std;
struct hash_table {
	unsigned int used;
	unsigned long entry[HASH_SIZE];
};

unsigned int hash_function(unsigned long value) {
	return value & HASH_MASK;  //取最后四位 
}

void hash_table_reset(struct hash_table *table) {
	table->used = 0;
	for(int i=0;i<HASH_SIZE;i++) {
		table->entry[i] = ~0;  //11111..
	}
}

unsigned int next_probe(unsigned int prev_key) {
	return (prev_key + 1) & HASH_MASK;
}

void hash_table_add(struct hash_table *table, unsigned long value) {
	unsigned int key = hash_function(value);
	if(table->used >= HASH_SIZE) {
		return;
	}
	
	while(table->entry[key] != ~0) {
		key = next_probe(key); //找到第一个空位 
	}
	
	table->entry[key] = value;
	table->used++;
}

unsigned int hash_table_slot(struct hash_table *table, unsigned long value) {
	unsigned int key = hash_function(value);
	for(int i=0;i<HASH_SIZE;i++) {
		if(table->entry[key] == value || table->entry[key] == ~0) //找到或者没找到都停止 
			break;
		key = next_probe(key);
	}
	return key;
}

bool hash_table_find(struct hash_table *table, unsigned long value) {
	return table->entry[hash_table_slot(table,value)] == value;
}

void hash_table_del(struct hash_table *table,unsigned long value) {
	unsigned int i,j,k;
	if(!hash_table_find(table,value)) //如果找不到返回 
		return;
	table->used--;
	i = j = hash_table_slot(table,value);
	while(true) { //删掉该元素，移动最后一个元素到此位置。 
		table->entry[i] = ~0;
		do {
			j = next_probe(j);
			if(table->entry[j] == ~0) {
				return;
			}
			k = hash_function(table->entry[j]);
			printf("i = %d, j= %d, k=%d\n",i,j,k);
		} while ((i<=j)?(i<k && k<=j) : (i<k||k<=j));
		
		table->entry[i] = table->entry[j];
		i = j;
	}
} 

void hash_funtion_test() {
	int i;
	srand(time(NULL));
	for(i=0;i<10;i++) {
		unsigned long val = rand();
		printf("%u -> %u\n",val,hash_function(val));
	}
}

void dump_hash_table(struct hash_table *table) {
	for(int i=0;i<HASH_SIZE;i++) {
		if(table->entry[i] == ~0)
			printf("%2u:   nil\n",i);
		else
			printf("%2u:%10u-> %2u\n",i,table->entry[i],hash_function(table->entry[i]));
	}
}

void hash_table_del_test2()
{
	struct hash_table table;

	hash_table_reset(&table);
	hash_table_add(&table, 0x1ff0);
	hash_table_add(&table, 0x1ff1);
	hash_table_add(&table, 0x1ff2);
	hash_table_add(&table, 0x1ff3);
	hash_table_add(&table, 0x1ff4);
	hash_table_add(&table, 0x1ff5);
	hash_table_add(&table, 0x1ff6);
	hash_table_add(&table, 0x2ff0);
	hash_table_add(&table, 0x3ff0);
	printf("hashtable->used:%d\n",table.used);
	dump_hash_table(&table);

	printf("=== Remove %u\n",0x1ff0);
	hash_table_del(&table, 0x1ff2);
	printf("hashtable->used:%d\n",table.used);
	dump_hash_table(&table);
}

#if HASH_TABLE
int main() {
	printf("hash table:\n");
	//hash_funtion_test();
	hash_table_del_test2();
	return 0;
}
#endif
