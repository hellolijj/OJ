#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	string str;
	cin >> str;

    // string => %s
    printf("%s", str.c_str());

    // str.length()
	for (int i = 0; i < str.length(); ++i)
	{
		printf("%c", str[i]);
	}

    // 通过迭代器访问
    for(string::iterator it = str.begin(); it != str.end(); it++) {
        printf("%c", *it);
    }

    // string 支持字符串拼接
    str += " world";

    cout << endl << str.substr(3, 3) << endl;

    // string::npos 是string 类查找的返回值
    if (str.find("world") != string::npos) {
        cout << str.find("world") << endl;
    }

    // replace 把 0~2位置的子字符串换为目标字符串
    str.replace(0, 2, "this is lijj");
    cout << str;
	return 0;
}



// 要记住的几个单词

// iostream iterator