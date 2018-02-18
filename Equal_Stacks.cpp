#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
vector <int> A;
vector <int> B;
vector <int> C;
vector <int> comparision_function(int sumA,int sumB,int sumC,int min){
    vector<int> loc;
    if(sumA > min){
        //cout << sumA-min << endl;
        loc.push_back(sumA-min);
    }
    else{
        loc.push_back(0);
    }
    if(sumB > min){
        loc.push_back(sumB-min);
    }
    else{
        loc.push_back(0);
    }
    if(sumC > min){
        loc.push_back(sumC-min);
    }
    else{
        loc.push_back(0);
    }
    return loc;
}
int compare(int sumA, int sumB,int sumC){
    int count =0;
    if(((sumA==sumB) && (sumB == sumC) && (sumC==sumA)) || ((A.size() ==0) && (B.size() ==0) && (C.size()==0))){
        return sumA;
    }
    int min_value = min(min(sumA,sumB),sumC);
    vector <int> val = comparision_function(sumA,sumB,sumC,min_value);
    for(int i=0;i<3;i++){
        if(val[i] > 0 && i==0 && A.size() !=0){
            sumA = sumA - A.back();
            A.pop_back();
        }
        if(val[i] >0 && i==1 && B.size()!=0){
            sumB=sumB - B.back();
            B.pop_back();
        }
        if(val[i] >0 && i==2 && C.size()!=0){
            sumC = sumC - C.back();
            C.pop_back();
        }
    }
    return compare(sumA,sumB,sumC);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int a, b,c;
    cin >> a >> b >> c;
    int input;
    int sumA =0;
    int sumB=0;
    int sumC=0;
    for(int i=0;i<a;i++){
        cin >> input;
        sumA+=input;
        A.push_back(input);
    }
    for(int i=0;i<b;i++){
        cin >> input;
        sumB+=input;
        B.push_back(input);
    }
    for(int i=0;i<c;i++){
        cin >> input;
        sumC+=input;
        C.push_back(input);
    }
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    reverse(C.begin(),C.end());
    int value = compare(sumA,sumB,sumC);
    cout << value <<endl;
    return 0;
}
