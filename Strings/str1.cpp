#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main(){
    string str = "chaitanya sharma";
    string str1(5 , 'n');
    
    //string inputstr;
    
    //getline(cin , inputstr);
    
    //str.append(str1);
    
    
    //cout << str << endl;
    //cout << str1 << endl;
    //cout <<  str + str1 << endl;
    
    //cout << str.erase(9 , 7) << endl;
    //cout << str.find("ait") << endl;
    
    // cout << str.size() << endl;
    // cout << str.length() << endl;
    // cout << str.substr(9,16) << endl;

    //cout << str.insert(9, " lol") << endl;
    //cout << inputstr << endl;

    // string s1 = "798";
    // int x = stoi(s1);
    // cout<< x+2 << endl;

    //sorting of string 
    string s1 = "dkfhiwereoasfiehfiefhdfadjfne";
    sort(s1.begin(), s1.end());
    cout << s1<< endl;
    return 0;
}