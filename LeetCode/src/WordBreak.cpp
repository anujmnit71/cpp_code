/*
class Solution {
public:

    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int len = s.size();
        vector<vector<int> > isValid(len , vector<int>(len,0));
        //memset(isValid , 0 , sizeof(int)*len*len);

        for(int i = 0 ; i < len ; i ++){
        	if(wordDict.find(s.substr(i,1)) != wordDict.end())
        		isValid[i][i] = 1;
        }

        for (int L=2; L<= len; L++){
        	for (int i=0 ; i < len-L+1; i++){
        		int j = i+L-1;
        		if(wordDict.find(s.substr(i,L)) != wordDict.end() ){
        			isValid[i][j] = 1;
        			continue;
        		}
        		for (int k=i; k<=j-1; k++){
        			if(isValid[i][k] && isValid[k+1][j]){
        				isValid[i][j] = 1;
        				break;
        			}
        		}
        	}
        }

        return isValid[0][len-1];
    }
};
*/
