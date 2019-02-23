#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;
 
bool cmp(pair<string, int> p1, pair<string, int> p2) {
    return p1.second < p2.second;
}
int main() {  
  map<string,int> nmap; 
 
  nmap["LiMin"] = 90;  
  nmap["ZiLinMi"] = 79;  
  nmap["BoB"] = 92;  
  nmap.insert(make_pair("Bing",99));  
  nmap.insert(make_pair("Albert",86));  
  
  // 排序
  vector<pair<string, int> > vi(nmap.begin(), nmap.end());
  sort(vi.begin(), vi.end(), cmp);
  
  // 输出map
  for(map<string, int>::iterator it = nmap.begin(); it != nmap.end(); it++) {
      printf("%s: %d\n", it->first.c_str(), it->second);
  }

    // 输出 vector<pair>
  for(vector<pair<string, int> >::iterator it = vi.begin(); it != vi.end(); it++) {
      printf("%s: %d\n", it->first.c_str(), it->second);
  }
  
  
 
  return 0;  
}

> 在面向对象的类中，使用sort排序方法 sort(vi.begin(), bi.end(), cpm) 这个cmp 需要是一个static方法