//
//  main.cpp
//  chair
//
//  Created by Dheeraj Reddy on 25/04/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(int argc, const char * argv[]) {
    string s;
    cin >> s;
    int numChances;
    cin >> numChances;
    map<char,int> obj;
    map<char,int>::iterator it1;
    for(auto x: s) {
        it1 = obj.find(x);
        if(it1 != obj.end())
            it1->second += 1;
        else
            obj.insert(make_pair(x, 1));
    }

    char guess;
    int count =0, totalCorrect = 0;
    cout << "Game Rules: You have " << numChances << " chances to guess all the characters of the string. If you want to quit the game in between press 0.\n";
    while(true) {
        cout << "Input your character: ";
        cin >> guess;
        if(guess == '0') {
            cout << "Game Over. You Lost" << endl;
            break;
        }
        else {
            it1 = obj.find(guess);
            if(it1 == obj.end()) {
                count++;
                cout << "Wrong character. Error number " << count <<". You have "<< numChances - count <<" chances left."<<endl;
                if(count == numChances) {
                    cout << "Game Over. You Lost" << endl;
                    break;
                }
            }
            else {
                totalCorrect++;
                cout << "Correct Guess. You have " << s.size() - totalCorrect << " more to go." << endl;
                if(totalCorrect == s.size()) {
                    cout << "Congratulations you won" <<endl;
                    break;
                }
                if(it1->second == 1)
                    obj.erase(it1);
                else
                    it1->second -= 1;
            }
        }
    }
    return 0;
}
