/*import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
import java.lang.Object;

class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        Integer total = new Integer(0);
        int[] minSum = new int[1];
        minSum[0] = Integer.MAX_VALUE;
        if(triangle.size() == 0)
            return 0;
        minimumTotalUtil(triangle , 0 , 0 , 0 , minSum );
        return minSum[0];
    }
    
    void minimumTotalUtil(List<List<Integer>> triangle , int row , int col , int sum , int[] minSum){
        if(row == triangle.size() - 1){
            if(minSum[0] > sum + (triangle.get(row)).get(col))
                minSum[0] = sum + (triangle.get(row)).get(col);
            return;
        }
        //if( sum + (triangle.get(row)).get(col) <= minSum)
            minimumTotalUtil(triangle , row + 1 , col , sum + (triangle.get(row)).get(col) , minSum);
        //if( sum + (triangle.get(row)).get(col) <= minSum)
            minimumTotalUtil(triangle , row + 1 , col + 1, sum + (triangle.get(row)).get(col) , minSum);
        
    }
}


public class Triangle {

    public static void main(String[] args) throws FileNotFoundException{
         //Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. 
        Scanner s = new Scanner(new File("src/ip_Practice.txt"));
		
        int test = s.nextInt();
        while( test-- > 0){
	        int sizearr = s.nextInt();
	        List<List<Integer> > allList = new ArrayList<List<Integer> >();
	        for(int i = 0 ; i < sizearr ; i++){
	        	List<Integer> currList = new ArrayList<Integer>();
	        	for(int j = 0 ; j <= i ; j++){
	        		currList.add(s.nextInt());
	        	}
	        	allList.add(currList);
	        }
	        Solution s1 = new Solution();
	        System.out.println(s1.minimumTotal(allList));
        }
    }
}*/