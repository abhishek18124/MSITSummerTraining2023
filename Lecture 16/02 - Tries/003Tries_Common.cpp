#include<iostream>
#include<unordered_map>

using namespace std;

class node {

public :

	char ch;
	bool terminal;
	unordered_map<char, node*> childMap;
	int freq;

	node(char ch) {
		this->ch = ch;
		this->terminal = false;
		this->freq = 0;
	}

};

class trie {
	node* root;
	int n;

public :

	trie() {
		root = new node('#');
		n = 0;
	}

	void insert(string str) {
		node* cur = root;
		for (char ch : str) {
			if (cur->childMap.find(ch) == cur->childMap.end()) {
				node* n = new node(ch);
				cur->childMap[ch] = n;
			}
			cur = cur->childMap[ch];
			cur->freq++;
		}
		cur->terminal = true;
		n++;
	}

	bool search(string str) {
		node* cur = root;
		for (char ch : str) {
			if (cur->childMap.find(ch) == cur->childMap.end()) {
				return false;
			}
			cur = cur->childMap[ch];
		}
		return cur->terminal;
	}

	string longestCommonPrefix(string str) {

		node* cur = root;
		string prefix = "";

		for (char ch : str) {
			cur = cur->childMap[ch];
			if (cur->freq != n) {
				break;
			}
			prefix += ch;
		}

		return prefix;

	}
};


int main() {

	string words[] = {"abc", "abcd", "abcdce"};

	trie t;
	for (string word : words) {
		t.insert(word);
	}

	cout << t.longestCommonPrefix(words[0]) << endl;

	return 0;
}