#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int cnt,b,p,f,hb,cb;
    int price=0;
    cin>>cnt;
    for(int i=0;i<cnt;i++)
    {
        cin>>b>>p>>f>>hb>>cb;
        if(hb>cb) 
        {
            if((b/2)>=p) 
            {
                price=p*hb;
                b=(b/2)-p;
                if(b>=f)
                {
                    price=price+f*cb;
                }
                else
                {
                    price =price+b*cb;
                }
            }
            else 
            {
                price=(b/2)*hb;
            }
        }
        else 
        {
            if((b/2)>=f) 
            {
                price=f*cb;
                b=(b/2)-f;
                if(b>=p)
                {
                    price=price+p*hb;
                }
                else
                {
                    price =price+b*hb;
                }
            }
            else 
            {
                price=(b/2)*cb;
            }
        }
        cout<<price<<"\n";
    }
    return 0;
}
