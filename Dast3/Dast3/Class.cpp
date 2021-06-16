#include "Class.h"
/*Dast 2 - second assignment*/
/*Guy Barzily - 318207594*/
/*Shahar Kozenyuk -318253713*/

DoubleHash::DoubleHash()
{
	hashTable = new List[TABLE_SIZE];
	curr_size = 0;
	for (int i = 0; i < TABLE_SIZE; i++) {
		List* tmp = new List();
		hashTable[i] = *tmp;
	}
}

bool DoubleHash::isFull()
{
	return (curr_size == TABLE_SIZE);
}

int DoubleHash::hash1(int key)
{

	while (key > 9999)
		key /= 10;
	return key;
}

int DoubleHash::hash2(int key)
{
	return ((key % 10000) +1);
}

void DoubleHash::insertHash(List* L)
{
	if (isFull())
		return;
	int key = L->getSum();
	int index = hash1(key);

	if (hashTable[index].getSum() != -1) {
		int index2 = hash2(key);
		int i = 1;
		while (1) {
			int newIndex = (index + i * index2) % TABLE_SIZE;

			if (hashTable[newIndex].getSum() != -1) {
				hashTable[newIndex].setSum(key);
				hashTable[newIndex].setIn1(L->getIn1());
				hashTable[newIndex].setIn2(L->getIn2());
				hashTable[newIndex].setIn3(L->getIn3());

				break;
			}
			i++;
		}
	}
	else {
		hashTable[index].setSum(key);
		hashTable[index].setIn1(L->getIn1());
		hashTable[index].setIn2(L->getIn2());
		hashTable[index].setIn3(L->getIn3());
	}
	curr_size++;
}

void DoubleHash::print()
{
	for (int i = 0; i < TABLE_SIZE; i++) {
		if (hashTable[i].getSum() != -1)
			cout << i << " --> " << hashTable[i].getSum() << endl;
	}
}

int DoubleHash::search(int key)
{
		int index1 = hash1(key);
		int index2 = hash2(key);
		int i = 0;
		while (hashTable[(index1 + i * index2) % TABLE_SIZE].getSum() != key) {
			if (hashTable[(index1 + i * index2) % TABLE_SIZE].getSum() == -1) {
				/*cout << key << " does not exist" << endl;*/
				return -1;
			}
			i++;
		}
		//cout << key << " found" << endl;
		return ((index1 + i * index2) % TABLE_SIZE);
	
}

List* DoubleHash::getHash()
{
	return this->hashTable;
}

List::List()
{
	this->index_one = -1;
	this->index_two = -1;
	this->index_three = -1;
	this->sum = -1;
}

List::List(int in1, int in2, int in3, int sum)
{
	this->index_one = in1;
	this->index_two = in2;
	this->index_three = in3;
	this->sum = sum;
}

int List::getIn1()
{
	return this->index_one;
}

int List::getIn2()
{
	return this->index_two;
}

int List::getIn3()
{
	return this->index_three;
}

int List::getSum()
{
	if (this == NULL)
		return -1;
	return this->sum;
}

void List::setIn1(int num)
{
	this->index_one = num;
}

void List::setIn2(int num)
{
	this->index_two = num;
}

void List::setIn3(int num)
{
	this->index_three = num;
}

void List::setSum(int num)
{
	this->sum = num;
}

/*this function will be activated only if the sum paremter of each list is equle
and two lists will be equle only if every index from the two lists is different*/
bool List::operator==(List l)
{
	if (this->getIn1() == l.getIn1() || this->getIn1() == l.getIn2() || this->getIn1() == l.getIn3()) {
		return false;
	}
	else if (this->getIn2() == l.getIn1() || this->getIn2() == l.getIn2() || this->getIn2() == l.getIn3()) {
		return false;
	}
	else if (this->getIn3() == l.getIn1() || this->getIn3() == l.getIn2() || this->getIn3() == l.getIn3()) {
		return false;
	}
	return true;

}
