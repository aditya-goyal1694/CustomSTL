#include "customVector.h"
#include <iostream>
using namespace std;

bool reverse(char str[], int size){
    if(size==1) return true;

    if(str[0]!=str[size-1]) return false;
    bool ans = reverse(str+1, size-2);
    return ans;
}

int main(){
    // MyVector<int> vec;
    // vec.push_back(7);
    // cout<<vec[0];

    char str[]= {'a','b', 'c', 'b', 'a'};
    cout<<reverse(str, 5);
    // for(auto i:str) cout<<i<<" ";
}