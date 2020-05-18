#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string s;
    int num;
    cin>>s;
    cin>>num;
    int i,j;
        sort(s.begin(),s.end());
        for(i=0;i<s.size();i++)
        {
            for(j=i+1;j<s.size();j++)
            {
                string temp=s;
                swap(temp[j],temp[i]);
                sort(temp.begin()+i+1,temp.end());
                if(stoll(temp)>stoll(s) && stoll(temp)<=num)
                    swap(s[i],s[j]);
            }
        }
    cout<<s;
    return 0;
}
