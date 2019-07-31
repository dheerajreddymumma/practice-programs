//
//  main.cpp
//  MANYCHEF
//
//  Created by Dheeraj Reddy on 27/01/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

/*void process_string_backwards(string &s) {
    int status = 0;
    for(long i = s.length()-1; i>= 0; i--) {
        if(status == 0) {
            if (s[i] == 'F')
                status = 1;
            else if (s[i] == '?') {
                if(i-3 >= 0 && (s[i-1] == 'E' || s[i-1] == '?') && (s[i-2] == 'H' || s[i-2] == '?') && (s[i-3] == 'C' || s[i-3] == '?')) {
                    s[i] = 'F';
                    status = 1;
                }
                else
                    s[i] = 'A';
            }
        }
        else if (status == 1) {
            if (s[i] == 'E')
                status = 2;
            else if (s[i] == '?') {
                if(i-2 >= 0 && (s[i-1] == 'H' || s[i-1] == '?') && (s[i-2] == 'C' || s[i-2] == '?')) {
                    s[i] = 'E';
                    status = 2;
                }
                else if(i-3 >= 0 && (s[i-1] == 'E' || s[i-1] == '?') && (s[i-2] == 'H' || s[i-2] == '?') && (s[i-3] == 'C' || s[i-3] == '?'))
                    s[i] = 'F';
                else
                {
                    s[i] = 'A';
                    status = 0;
                }
            }
            else if (s[i] == 'F')
                status = 1;
            else
                status = 0;
        }
        else if (status == 2) {
            if (s[i] == 'H')
                status = 3;
            else if (s[i] == '?') {
                if(i-1 >= 0 && (s[i-1] == 'C' || s[i-1] == '?')) {
                    s[i] = 'H';
                    status = 3;
                }
                else if(i-3 >= 0 && (s[i-1] == 'E' || s[i-1] == '?') && (s[i-2] == 'H' || s[i-2] == '?') && (s[i-3] == 'C' || s[i-3] == '?')) {
                    s[i] = 'F';
                    status = 1;
                }
                else {
                    s[i] = 'A';
                    status = 0;
                }
            }
            else if (s[i] == 'F')
                status = 1;
            else
                status = 0;
        }
        else {
            if (s[i] == '?' || s[i] == 'C') {
                status = 0;
                s[i] = 'C';
            }
            else if(i-3 >= 0 && (s[i-1] == 'E' || s[i-1] == '?') && (s[i-2] == 'H' || s[i-2] == '?') && (s[i-3] == 'C' || s[i-3] == '?')) {
                s[i] = 'F';
                status = 1;
            }
            else
                status = 0;
        }
    }
}*/

void process_string(string &s) {
    int length = s.length();
    
    for(int i=length-4; i>=0; i--) {
        if((s[i] == 'C' || s[i] == '?') && (s[i+1] == 'H' || s[i+1] == '?') && (s[i+2] == 'E' || s[i+2] == '?') && (s[i+3] == 'F' || s[i+3] == '?')) {
            s[i] = 'C'; s[i+1] = 'H'; s[i+2] = 'E'; s[i+3] = 'F';
        }
    }
    
    for (int i=0; i<length; i++) {
        if (s[i] == '?')
            s[i] = 'A';
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        process_string(s);
        cout<<s<<endl;
    }
    return 0;
}
