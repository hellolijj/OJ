#include <cstdio>
#include <cstring>
#include <vector> 
#include <iostream>

using namespace std;

vector<string> split(const string &str, const string &dlim) {
    vector<string> res;
    string::size_type pos1 = 0, pos2 = str.find(dlim);
    while(pos2 != string::npos) {
        res.push_back(str.substr(pos1, pos2-pos1));
        pos1 = pos2 + dlim.size();
        pos2 = str.find(dlim, pos1);
    }
    if(pos1 != str.length()) {
        res.push_back(str.substr(pos1));
    }
    return res;
}

int main() {
    vector<string> res = split("my name is lijj", "sd");
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    return 0;
}

// string::npos 相当于 -1
// string::size_type 相当于 unsign int