/*题目描述
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。
不能使用除法。
*/

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        if(A.size() < 2) {
            // return ;
        }
        vector<int> res(A.size());
        vector<int> B(A.size());
        vector<int> C(A.size());
        B[0] = 1;
        for(int i = 1; i < A.size(); i++) {
            B[i] = B[i-1] * A[i-1];
        }
        C[A.size()-1] = 1;
        for(int i = A.size()-2; i >= 0; i--) {
            C[i] = C[i+1] * A[i+1]; 
        }
        for(int i = 0; i < res.size(); i++) {
            res[i] = B[i] * C[i];
        }
        return res;
    }
};