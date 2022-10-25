#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <regex>
#include <stack>
#include <vector>
#include <map>
using namespace std;
int find_SubString(string s,string sub){
    int idx = 0;
    int cnt = 0;
    while((idx = s.find(sub,idx)) != s.npos){
        idx++;
        cnt++;
    }
    return cnt;
}
vector<int> find_if_else(vector<string> v){
    stack<bool> mystack;
    vector<int> answer;
    int v1 = 0,v2 = 0;
    int size = 0;
    for(int i=0;i<v.size();i++){
        string strS = v[i];
        if(strS.find("else if") == strS.npos && strS.find("if") != strS.npos){
            mystack.push(false);
            size ++;
            continue;
        }else if(strS.find("else if") != strS.npos && mystack.empty() != true){
            mystack.top() = true;
            continue;
        }else if(strS.find("else if") == strS.npos && strS.find("else") != strS.npos){
            if(mystack.top() == true){
                v2 ++;
            }else{
                v1 ++;
            }
            mystack.pop();
            continue;
        }
    }
    answer.push_back(v1);
    answer.push_back(v2);
    return answer;
}
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
