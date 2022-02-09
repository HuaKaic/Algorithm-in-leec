#include <iostream>
#include <string>

using namespace std;

int main( int argc, char** argv)
{   int a = 3.25;
    int b = 2.78;
    cout << b << endl;
    string st = "18293845qwert";
    string numeric("8945");
    string::size_type pos = 0;
    cout << st.find(numeric) << endl;
    while((pos = st.find_last_of(numeric,pos)) != string::npos){
        cout << st[pos] << endl;
        ++pos;
    }
}