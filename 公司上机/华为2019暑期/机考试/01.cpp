#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include "sstream"

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

vector<int> ip_to_arr(const string ip_add) {
    vector<string> ip_str = split(ip_add, ".");
    vector<int> res;
    stringstream ss;
    for(int i = 0; i < ip_str.size(); i++) {
        int temp = std::atoi(ip_str[i].c_str());
        res.push_back(temp);
    }
    return res;
}

int main() {
    string ip1, ip2, mask;
    cin >> ip1 >> ip2 >> mask;
    vector<int> ip1_int = ip_to_arr(ip1);
    vector<int> ip2_int = ip_to_arr(ip2);
    vector<int> mask_int = ip_to_arr(mask);
    vector<int> ip1_sub_net;
    vector<int> ip2_sub_net;

    for(int i = 0; i < ip1_int.size(); i++) {
        ip1_sub_net.push_back(ip1_int[i] & mask_int[i]);
        ip2_sub_net.push_back(ip2_int[i] & mask_int[i]);
    }
    if(ip1_sub_net == ip2_sub_net) {
        cout << "1 ";
    } else {
        cout << "0 ";
    }
    for(int i = 0; i < ip1_sub_net.size(); i++) {
        if(i == 0) {
            cout << ip1_sub_net[i];
        } else {
            cout << "." << ip1_sub_net[i];
        }
    }
    cout << endl;
    return 0;
}

// 192.168.1.1 192.168.1.12 255.255.255.0