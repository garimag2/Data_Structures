#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int> array;
    vector <int> max;
    max.push_back(0);
    for(int i=0;i<n;i++) {
        int a;
        int b;
        cin >> a;
        if(a==1){
            cin>>b;
            array.push_back(b);
            if(b >= max.back()){
                max.push_back(b);
            }
        }
        if(a==2){
            if(array.back() == max.back()) max.pop_back();
            array.pop_back();
        }
        if(a==3){
            cout << max.back() << endl;
        }
    }
    return 0;
}
