// 本质还是二分法的题目，一开始理解不了题目意思
// 还是理解不了这个题目的意思, 万般无奈下可考虑使用传统求最小值方法做

#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
    int minNumberInRotateArray1(vector<int> rotateArray) {
        
        if(rotateArray.size() == 0) {
            return 0;
        }
        
        for(int i = 0; i < rotateArray.size()-1; i++) {
            if(rotateArray[i] > rotateArray[i+1]) {
                return rotateArray[i+1];
            }
        }
        
        return rotateArray[0];
    }
    int minNumberInRotateArray(vector<int> rotateArray) {
        int length = rotateArray.size();
        if(length == 0) {
            return 0;
        }

        int low = 0, hign = length-1;
        int min = 0;

        while(rotateArray[low] > rotateArray[hign]) {
            if(hign - low == 1) {
                min = hign;
                break;
            }
            min = low + (hign - low) / 2;
            if (rotateArray[min] >= rotateArray[low]) {
                low = min;
            }
            if (rotateArray[min] <= rotateArray[hign]) {
                hign = min;
            }
        }

        return rotateArray[min];
    }

};

int main() {
    int a[5] = {4,5,6,1,2};
    vector<int> v;
    for(int i = 0; i < 5; i++) {
        v.push_back(a[i]);
    } 
    class Solution solu;
    printf("%d\n", solu.minNumberInRotateArray(v));
    printf("%d\n", solu.minNumberInRotateArray1(v));
    return 0;
}

// 使用二分法不确定 a[min] 与 谁比较然后作出怎么样的操作