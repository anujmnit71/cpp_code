    #include <cstdio>
    #include<iostream>
    #include <algorithm>
    #include<string>

    typedef long long int in;
    using namespace std;

    struct sol
    {
		in one;
		in two,three,four;
    }s;
     
    struct SegmentTreeNode {
			//in prefixMaxSum, suffixMaxSum, maxSum, sum;
			in prefixSumsCount[3];
			in totalSum;
		 
		void assignLeaf(in value) {
			totalSum=value%3;
			prefixSumsCount[0]=0;
			prefixSumsCount[1]=0;
			prefixSumsCount[2]=0;
			prefixSumsCount[totalSum]++;
		}
		 
		void merge(SegmentTreeNode& left, SegmentTreeNode& right) {
			totalSum=(left.totalSum + right.totalSum)%3;
			//copy left
			for (in mod = 0; mod < 3; mod++)
			prefixSumsCount[mod] = left.prefixSumsCount[mod];
			// merge with right
			for (in mod = 0; mod < 3; mod++)
				prefixSumsCount[(mod + left.totalSum) % 3] += right.prefixSumsCount[mod];
		 
		}
		 
		struct sol getValue() {
			struct sol val ;//= (struct sol*)malloc(sizeof(struct sol));
		 
			val.one=prefixSumsCount[0];
			val.two=prefixSumsCount[1];
			val.three=prefixSumsCount[2];
			val.four=totalSum;
			return val;
		}
    };
     
    //template<class T, class V>
    class SegmentTree {
		SegmentTreeNode* nodes;
		in N;
		 
		public:
		SegmentTree(char arr[], in N) {
		this->N = N;
		nodes = new SegmentTreeNode[getSegmentTreeSize(N)];
		buildTree(arr, 1, 0, N-1);
		}
		 
		~SegmentTree() {
		delete[] nodes;
		}
		 
		struct sol getValue(in lo, in hi) {
		SegmentTreeNode result = getValue(1, 0, N-1, lo, hi);
		return result.getValue();
		}
		 
		void update(in index, in value) {
		update(1, 0, N-1, index, value);
		}
		 
		private:
		void buildTree(char arr[], in stIndex, in lo, in hi) {
		if (lo == hi) {
		nodes[stIndex].assignLeaf(arr[lo]);
		return;
		}
     
		in left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
		buildTree(arr, left, lo, mid);
		buildTree(arr, right, mid + 1, hi);
		nodes[stIndex].merge(nodes[left], nodes[right]);
		}
     
    SegmentTreeNode getValue(in stIndex, in left, in right, in lo, in hi) {
    if (left == lo && right == hi)
    return nodes[stIndex];
     
    in mid = (left + right) / 2;
    if (lo > mid)
    return getValue(2*stIndex+1, mid+1, right, lo, hi);
    if (hi <= mid)
    return getValue(2*stIndex, left, mid, lo, hi);
     
    SegmentTreeNode leftResult = getValue(2*stIndex, left, mid, lo, mid);
    SegmentTreeNode rightResult = getValue(2*stIndex+1, mid+1, right, mid+1, hi);
    SegmentTreeNode result;
    result.merge(leftResult, rightResult);
    return result;
    }
     
    in getSegmentTreeSize(in N) {
    in size = 1;
    for (; size < N; size <<= 1);
    return size << 1;
    }
     
    void update(in stIndex, in lo, in hi, in index, in value) {
    if (lo == hi) {
    nodes[stIndex].assignLeaf(value);
    return;
    }
     
    in left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
    if (index <= mid)
    update(left, lo, mid, index, value);
    else
    update(right, mid+1, hi, index, value);
     
    nodes[stIndex].merge(nodes[left], nodes[right]);
    }
    };
     
    int main() {
     
     
    in n,m;
     
    scanf("%lld",&n);
    scanf("%lld",&m);
     
    char arr[100010];
     
    in i;
    scanf("%s",arr); // Build segment tree from given array
     
    SegmentTree st(arr, n);
     
    while(m--)
    {
    in a,b,c;
    scanf("%lld%lld%lld",&c,&a,&b);
     
    if (c==2)
    {
    s=st.getValue(a-1, b-1);
    //s=getSum(st, n, a-1, b-1);
    in res = 0;
    in solut[3];
    solut[0]=s.one;
    solut[1]=s.two;
    solut[2]=s.three;
     
    for (in mod = 0; mod < 3; mod++)
    {
    in count = solut[mod];
    if (mod == 0)
    count++; // do not forget about an empty prefix
    res += count * (count - 1) / 2;
    }
    // writein(res);
    printf("%lld\n",res);
    }
    if(c==1)
    {
    st.update(a-1,b);
    }
    }
     
     
    return 0;
     
    }
