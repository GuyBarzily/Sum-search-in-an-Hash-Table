#pragma once
/*Dast 2 - second assignment*/
/*Guy Barzily - 318207594*/
/*Shahar Kozenyuk -318253713*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <typeinfo>
#include <fstream>
#include <time.h>


#define TABLE_SIZE 10000
#define SIZE1 15

using namespace std;
//A new class to help us build a sum array that stors the index of the first integer array
class List
{
	int index_one;
	int index_two;
	int index_three;
	int sum;

public:
	List();
	List(int in1, int in2, int in3, int sum);
	int getIn1();
	int getIn2();
	int getIn3();
	int getSum();
	void setIn1(int num);
	void setIn2(int num);
	void setIn3(int num);
	void setSum(int num);
	bool operator ==(List l);
};

//we use the Duoble hash technic to put the sum array in a hash table
class DoubleHash {
	List* hashTable;
	int curr_size;
	
public:
	DoubleHash();
	bool isFull();
	int hash1(int key);
	int hash2(int key);
	void insertHash(List* L);
	void print();
	int search(int key);
	List* getHash();

};
void sum6(int arr[], int s);


