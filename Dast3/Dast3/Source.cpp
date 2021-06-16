#include "Class.h"
/*Dast 2 - second assignment*/
/*Guy Barzily - 318207594*/
/*Shahar Kozenyuk -318253713*/

/*This function recive an integer array and an interger, it needs to see if there is a sum of 
6 numbers from the array that sums up to the recived s integer */
void sum6(int arr[], int s) {
	DoubleHash h;
	/*we build a new array from the List class, max size of the array is the size of the recived array times 3*/
	List* sum_arr = new List[SIZE1 * SIZE1 * SIZE1];
	int index = 0;
	int sum3 =0;
	/*this loops will sum up every three integers from the array an will put the sums in the List array*/
	for (int i = 0; i < SIZE1-2; i++) {
		for (int j = i + 1; j < SIZE1-1; j++) {
			for (int k = j + 1; k < SIZE1; k++) {
				sum3 = arr[i] + arr[j] + arr[k];
				List* tmp = new List(i, j, k, sum3);
				sum_arr[index++] = *tmp;
			}
		}
	}
	List** sum = new List*[index];
	/*build a new List array with index size, we move the sums from the old array to the new one */
	for (int i = 0; i < index; i++) {
		sum[i] = new List(sum_arr[i].getIn1(), sum_arr[i].getIn2(), sum_arr[i].getIn3(), sum_arr[i].getSum());
	}

	/*uses DoubleHash to insert the sum array to an hash table*/
	for (int i = 0; i < index; i++) {
		h.insertHash(sum[i]);
	}
	cout << "full hash table: " << endl;
	/*the method being used now will search the number that completing the recived sum minus sum[i]*/
	for (int i = 0; i < index; i++) {
		int sum4 = sum[i]->getSum();
		/*if s - sum4 is smaller than 0, there is no way to find a number that will complet the wanted sum*/
		if((s - sum4) >0){
				int in = h.search(s - sum4);
				/*if in equles -1, we did not find s minus sum4 in the hash table*/
			if (in != -1) {
				if ((*sum[i] == h.getHash()[in])) {
					cout << "The sum of " << s << " is from these indexs: " << endl;
					cout << "index 1: " << sum[i]->getIn1() << endl;
					cout << "index 2: " << sum[i]->getIn2() << endl;
					cout << "index 3: " << sum[i]->getIn3() << endl;
					cout << "index 4: " << h.getHash()[in].getIn1() << endl;
					cout << "index 5: " << h.getHash()[in].getIn2() << endl;
					cout << "index 6: " << h.getHash()[in].getIn3() << endl;
					return;
					
				}
			}
		}
	}
	cout << "The sum: " << s << " was not found" << endl;
	
}

int main() {

	int arr[SIZE1];
	for (int i = 0; i < SIZE1; i++) {
		arr[i] = rand() % 70000 + 10000;
	}
	int s = 168383;
	sum6(arr, s);
	return 0;
}