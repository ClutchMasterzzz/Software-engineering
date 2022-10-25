#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <regex>
#include <stack>
#include <vector>
#include <map>
using namespace std;
string readFileIntoString(string filename) {
    ifstream ifile(filename);
    ostringstream buf;
    char ch;
    while (buf && ifile.get(ch))
        buf.put(ch);
//返回与流对象buf关联的字符串
    ifile.close();
    return buf.str();
}

int main() {
    string str = readFileIntoString("C:\\Users\\Mr.SupX\\Desktop\\Software Engineering\\test.cpp");

    return 0;
}
