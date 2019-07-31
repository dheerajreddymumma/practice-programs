//
//  main.cpp
//  CIELRCPT
//
//  Created by Dheeraj Reddy on 22/01/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int T, num;
    cin >> T;
    while(T--){
        cin >> num;
        int total = 0;
        
        if (num >= 2048) {
            total += num/2048;
            num %= 2048;
        }
        
        while (num > 0) {
            num &= (num-1);
            total += 1;
        }
        
        cout<<total<<endl;
        
    }
    return 0;
}
