//
//  main.cpp
//  printAllCombinations
//
//  Created by Dheeraj Reddy on 18/01/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool desc(int first, int second){
    if(first < second)
        return false;
    return true;
}

bool asc(int first, int second){
    if(first < second)
        return false;
    return true;
}

void print_combinations(vector<int> array)
{
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int num;
    cout<<"Enter the number of elements: ";
    cin >> num;
    vector<int> array(num);
    for(int i=0;i<num;i++)
        cin >> array[i];
    sort(array.begin(), array.end(), desc);
    print_combinations(array);
    for(auto x: array)
        cout<<x<<endl;
    
    vector<int>::reverse_iterator rit;
    for(rit = array.rbegin(); rit != array.rend(); rit++)
    {
        cout<<*rit<<endl;
    }
    return 0;
}
