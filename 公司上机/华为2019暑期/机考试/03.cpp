#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include<sstream>

using namespace std;
const int N = 55;
struct Node
{
	int x, y;
	int step; // step 为从起点s到达该位置最短需要多少步

}S, T, Temp;



int main() {
    string line;
	getline(cin, line);
	stringstream ss(line);
	vector<int> nums;
    vector<vector<int> > metux;
    int x;
	while (ss >> x) {
        nums.push_back(x);
    }
	int v_size = nums.size();
    metux.push_back(nums);
    for (int i = 0; i < v_size-1; i++) {
        string line_next;
        getline(cin, line_next);
        stringstream ss_next(line_next);
        vector<int> nums;
        int x;
        while (ss_next >> x) {
            nums.push_back(x);
        }
        metux.push_back(nums);
	}

    cout << -1 << endl;
    return 0;
}

