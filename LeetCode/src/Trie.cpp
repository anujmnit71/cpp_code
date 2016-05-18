/*
#include <iostream>
#include<cstdlib>
#include<fstream>
#include<vector>
#include <sstream>
#include<cstring>

using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
	TrieNode* childNodes[26];
	bool isLeafNode;
    TrieNode() {
    	for(int i = 0 ; i < 26 ; i++){
    		childNodes[i] = NULL;
    	}
    	isLeafNode = false;
    }
};

class Trie {

	private:
		TrieNode* root;

	public:
		Trie() {
			root = new TrieNode();
		}

    // Inserts a word into the trie.
    void insert(string s) {
    	TrieNode* walk = root;
    	for(int i = 0 ; i < s.size() ; i++){
    		if(walk->childNodes[s[i] - 'a'] != NULL){
    			walk = walk->childNodes[s[i] - 'a'];
    		}
    		else{
    			walk->childNodes[s[i] - 'a'] = new TrieNode();
    			cout<<"inserting"<<s[i]<<"\n";
    			walk = walk->childNodes[s[i] - 'a'];
    		}
    	}
    	walk->isLeafNode = true;
    }

    // Returns if the word is in the trie.
    bool search(string s) {
    	TrieNode* walk = root;
    	if(walk == NULL)
    		return false;
    	int i = 0;
		while(i < s.size()){
			walk = walk->childNodes[s[i] - 'a'];
			if(walk)
				cout<<"found "<<s[i]<<" "<<i<<"\n";
			else
				return false;
			i++;
		}
		if(walk->isLeafNode)
			return true;
		else
			return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
    	TrieNode* walk = root;
		if(walk == NULL)
			return false;
		int i = 0;
		while(i < prefix.size()){
			walk = walk->childNodes[prefix[i] - 'a'];
			if(walk)
				cout<<"found "<<prefix[i]<<" "<<i<<"\n";
			else
				return false;
			i++;
		}
		return true;
    }

};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main(){
	int test,element;
	ifstream infile("ipLeetCode");
	if(infile)
		cout<<"success";
	infile>>test;
	Trie parent;
	parent.insert("cat");
	parent.insert("car");
	parent.insert("bat");
	cout<<parent.search("catv")<<endl;
	cout<<parent.search("bar")<<endl<<endl;
	cout<<parent.startsWith("ca")<<endl;
	cout<<parent.startsWith("za")<<endl;
	cout<<parent.startsWith("catvr")<<endl;
	return 0;
}
*/
