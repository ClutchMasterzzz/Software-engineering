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
vector<int> findSwitch(vector<string> v1){
    vector<int> answer;
    stack<char> myStack;
    bool judge = false;
    int count = 0;
    for(int i=0;i<v1.size();i++){
        string strS = v1[i];
        if(strS.find("switch") != strS.npos){
            judge = true;
        }
        if(judge){
            if(strS.find('{') != strS.npos){
                myStack.push('{');
            }else if(strS.find('}') != strS.npos){
                myStack.pop();
            }
        }
        if(myStack.empty() != true){
            if(strS.find("case") != strS.npos){
                count ++;
            }
        }else{
            judge = false;
            if(count != 0){
                answer.push_back(count);
                count = 0;
            }
        }
    }
    return answer;
}
vector<string> dealWithString(string str){
    vector<string> v;
    string sub = "";
    for(int i=0;i<str.length();i++){
        if(str[i] == '\n'){
            sub += str[i];
            v.push_back(sub);
            sub = "";
        }else{
            sub += str[i];
        }
    }
    return v;
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
    string address = "C:\\Users\\Mr.SupX\\Desktop\\Software Engineering\\test.cpp";
    string str = readFileIntoString(address);
    vector<string> ans = dealWithString(str);
    // if - else & if -elseif -else
    vector<int> answer = find_if_else(ans);
    // switch-case
    vector<int> answer_switch = findSwitch(ans);
    //
    smatch result;
    regex pattern("void|signed|unsigned|short|long|int|float|double|char|enum|struct|union|typedef|Bool|Imaginary|Complex|const|volatile|restrict|inline|auto|static|extern|register|sizeof|goto|return|break|continue|if|else|switch|case|default|do\\s|while|for");
    string::const_iterator iterStart = str.begin();
    string::const_iterator iterEnd = str.end();
    string temp;
    int count = 0;
    while (regex_search(iterStart, iterEnd, result, pattern))
    {
        count ++;
        iterStart = result[0].second;
    }
    cout << "total num: " << count << endl;
    cout << "switch num: " << answer_switch.size() << endl;
    cout << "case num: ";
    for(int i=0;i<answer_switch.size();i++){
        cout << answer_switch[i] << " ";
    }cout << endl;
    cout << "if-else num: " << answer[0] << endl;
    cout << "if-elseif-else num:" << answer[1] << endl;
    return 0;
}
