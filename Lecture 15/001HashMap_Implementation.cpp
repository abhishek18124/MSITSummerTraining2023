/*

	Implementation of HashMap/HashTable

*/

#include<iostream>

using namespace std;

class node {

public :

	int K;
	int V;
	node* next;

	node(int K, int V) {
		this->K = K;
		this->V = V;
		this->next = NULL;
	}

};

class HashMap {
	int N; //  to store the hash table capacity
	int M; //  to store the hash table size
	double L; // to store the load factor threshold

	node** T; // to store the pointer to the  dynamic
	// array that represents the hash table

	int hashFn(int K) {
		// transform K into a hash index
		return K % N;
	}

	void transfer(node* head) {
		// 1. rehash (K, V) pairs present in the linkedList represented
		//    by "head" pointer to the updated hashMap
		node* temp = head;
		while (temp != NULL) {
			insert(temp->K, temp->V);
			temp = temp->next;
		}

		// 2. release memory allocated for the linkedList represented
		//    by "head" pointer
		while (head != NULL) {
			temp = head;
			head = head->next;
			delete temp;
		}

	}

	void rehash() {

		// 1. save pointer to the current hashMap and its capacity
		node** oldT = T;
		int oldN = N;

		// 2. create a hashMap with double capacity
		N = 2 * N;
		T = new node*[N];
		for (int i = 0; i < N; i++) {
			T[i] = NULL;
		}
		M = 0;

		// 3. transfer (K, V) pairs from old hashMap to the updated hashMap
		for (int i = 0; i < oldN; i++) {
			// transfer the (K, V) pairs from the LL at the ith index of the old hashTable into the new hashTable
			transfer(oldT[i]);
		}

		// 4. release the memory allocated to the old hashMap
		delete [] oldT;

	}

public :

	HashMap(int N = 5, double L = 0.7) {
		this->N = N;
		this->M = 0;
		this->L = L;

		T = new node*[N];
		for (int i = 0; i < N; i++) {
			T[i] = NULL;
		}
	}

	void insert(int K, int V) {

		// 1. transform the key into hash index using the hash function
		int hashIdx = hashFn(K);

		// 2. create a node with the given (K, V) pair and insert it at
		//    head of the linkedList stored at the hash index
		node* n = new node(K, V);

		// 3. update the pointer to the head of the linkedList stored at
		//    the hash index such that it holds the address of the newly
		//    created node
		n->next = T[hashIdx];
		T[hashIdx] = n;
		M++;

		// 4. rehash, if loadFactor exceeds the loadFactor Threshold
		double loadFactor =  M * 1.0 / N;
		if (loadFactor > L) {
			cout << "rehashing since load factor = " << loadFactor << endl;
			rehash();
		}

	}

	node* find(int K) {

		// 1. transform the key into hash index using the hash function
		int hashIdx = hashFn(K);

		// 2. search for the node with the given key in the  linkedList
		//    stored at the hash index
		node* temp = T[hashIdx];
		while (temp != NULL) {
			if (temp->K == K) {
				break;
			}
			temp = temp->next;
		}
		return temp;

	}

	void erase(int K) {

		// 1. transform the key into hash index using the hash function
		int hashIdx = hashFn(K);

		// 2. delete the node with the given key from the linkedList
		//    stored at the hash index

		node* temp = T[hashIdx];

		if (temp == NULL) {
			return;
		}

		if (temp->K == K) {
			// delete the head node
			T[hashIdx] = temp->next;
			delete temp;
			M--;
		} else {
			node* prev = NULL;

			while (temp != NULL) {
				if (temp->K == K) {
					prev->next = temp->next;
					delete temp;
					M--;
					break;
				}
				prev = temp;
				temp = temp->next;
			}
		}


	}

	void printLinkedList(node* head) {
		while (head != NULL) {
			cout << "(" << head->K << ", " << head->V << ") ";
			head = head->next;
		}
		cout << endl;
	}

	void printHashMap() {
		// iterate over buckets in the hashMap
		for (int i = 0; i < N; i++) {
			// print the linkedList stored ith bucket of the hashMap
			cout << i << " : ";
			printLinkedList(T[i]);
		}
		cout << endl;
	}

	int& operator[](int K) {
		node* temp = find(K);
		if (temp == NULL) {
			// K is not present in the hashMap
			int garbage;
			insert(K, garbage);
			temp = find(K);
		}
		return temp->V;
	}
};

int main() {

	HashMap hashMap;

	hashMap.insert(0, 0);
	hashMap.insert(1, 1);
	hashMap.insert(6, 36);

	hashMap.printHashMap();

	hashMap.insert(7, 49);

	hashMap.printHashMap();

	// int key = 60;
	// node* temp = hashMap.find(key);
	// if (temp != NULL) {
	// 	// you've found the node in the hashTable with the key as key
	// 	cout << temp->V << endl;
	// } else {
	// 	cout << key << " is not present" << endl;
	// }

	// hashMap.insert(11, 121);
	// hashMap.printHashMap();

	// key = 6;

	// hashMap.erase(6);
	// hashMap.printHashMap();

	// hashMap.erase(11);
	// hashMap.printHashMap();

	cout << hashMap[6] << endl; // cout << hashMap.operator[](6) << endl;
	cout << hashMap[7] << endl;

	hashMap[6] = 0;

	cout << hashMap[6] << endl;

	hashMap.printHashMap();

	hashMap[12] = 144;

	cout << hashMap[12] << endl;

	hashMap.printHashMap();

	hashMap[12] = 0;

	cout << hashMap[12] << endl;

	hashMap.printHashMap();


	return 0;
}