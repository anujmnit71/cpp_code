/*
#include <iostream>
#include<cstdlib>
#include<fstream>
#include<vector>
#include <sstream>
#include<cstring>

using namespace std;

int profit[10010][10000] = {-1};

class Solution {
public:
	int table[][]
    int minDistance(string word1, string word2) {
        if(word1.length() == 0)
            return word2.length();

        if(word2.length() == 0)
            return word1.length();

        if(word1[word1.length() - 1] == word2[word2.length() - 1])
            return minDistance(word1.substr(0 , word1.length() - 1) , word2.substr(0 , word2.length() - 1));

        string newword1 = word1.substr(0 , word1.length() - 1);
        string newword2 = word2.substr(0 , word2.length() - 1);

        return min( min(
                            minDistance(newword1 , newword2) + 1, // Replace
                            minDistance(word1 , newword2) + 1    // Insert
                        ),  minDistance(newword1 , word2) + 1    // Delete
                    );
    }
};

int main(){
	int test,element;
	ifstream infile("ipLeetCode");
	if(infile)
//		cout<<"success";
	infile>>test;
	while(test--){
		string word1 , word2 ;
		infile>>word1;
		infile>>word2;
		Solution s;
		cout<<s.minDistance(word1 , word2)<<endl;
	}
	return 0;
}
*/
