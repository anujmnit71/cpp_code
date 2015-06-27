/*
class Solution {
public:
    void numDistinctUtil(string s, string t , int& count) {
        if(  ((s.size() == 0) && (t.size() != 0) ) || (s.size() !=0 ) && (t.size() == 0) )
            return ;
        if( s.size() == 0 && t.size() == 0 ){
            count++;
            return ;
        }

        if(s[0] == t[0]){
            numDistinctUtil(s.substr(1) , t.substr(1) , count);
        }
        numDistinctUtil(s.substr(1) , t , count);
        return;
    }

    int numDistinct(string s, string t) {
        int count = 0;
        numDistinctUtil(s , t , count);
        return count;
    }
};
*/
