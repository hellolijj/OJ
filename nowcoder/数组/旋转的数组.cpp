// 本质还是二分法的题目，一开始理解不了题目意思
// 还是理解不了这个题目的意思, 万般无奈下可考虑使用传统求最小值方法做

#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int length = rotateArray.size();
        if(length == 0) {
            return -1;
        }

        int low = 0, hign = length-1;
        while(low < hign) {
            int min = low + (hign - low) / 2;
            if(rotateArray[min] < rotateArray[low]) {
                low = min;
            }
            if(rotateArray[min] < rotateArray[hign]) {
                hign = min+1;
            }
        }
        return rotateArray[low];
    }
};

int main() {
    int a[5] = {4,5,6,1,2};
    vector<int> v(5);
    for(int i = 0; i < v.size(); i++) {
        v.push_back(a[i]);
    } 
    class Solution solu;
    printf("%d\n", solu.minNumberInRotateArray(v));
    return 0;
}