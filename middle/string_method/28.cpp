#include <iostream>
#include <string>
using namespace std;

void getNext(const string s, int* next){
    int j = -1;
    next[0] = j;
    for (int i = 1; i < s.size(); i++){
        while (j >= 0 && s[i] != s[j + 1]){
            j = next[j];
        }
        if (s[i] == s[j + 1]){
            j++;
        }
        next[i] = j;
    }
}
int findSubstr(const string src, const string sub){
    int next[sub.size()];
    getNext(sub, next);
    if (sub.size() == 0) {
        return 0;
    }
    int i = -1;
    for (int j = 0; j < src.size(); j++){
        while (i >= 0 && src[j] != sub[i+1]){
            i = next[i];
        }
        if (src[j] == sub[i+1]){
            i++;
        }
        if (i == (sub.size() - 1)){
            return (j - sub.size() + 1);
        }
    }
    return -1;
}

int main(){
    string a("acbacbabf");
    string b("babf");
    int v = 1;
    v = findSubstr(a,b);
    cout << v << endl;
    return 0;
}
