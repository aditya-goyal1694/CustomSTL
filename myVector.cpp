#include "customVector.h"
#include <iostream>
using namespace std;

int main(){
    MyVector<int> vec;
    vec.push_back(7);
    cout<<vec[0];
}