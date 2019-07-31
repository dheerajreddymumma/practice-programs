//
//  main.cpp
//  codejam_2008_1A_prb2
//
//  Created by Dheeraj Reddy on 15/04/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;



int main(int argc, const char * argv[]) {
    int C;
    cin >> C;
    for(int c = 1; c <= C; c++) {
        int numFlavour = 0, numCustomers = 0;
        cin >> numFlavour;
        vector<int> flavours(numFlavour + 1,0);
        cin >> numCustomers;
        vector<vector<pair<int,int> > > customers;
        for(int i=0;i<numCustomers;i++) {
            int numLikes;
            cin >> numLikes;
            vector<pair<int,int> > customer;
            for(int j=0;j<numLikes;j++) {
                int flavour, isMalted;
                cin >> flavour >> isMalted;
                customer.push_back(make_pair(flavour, isMalted));
            }
            customers.push_back(customer);
        }
        bool solved = false, impossible = false;
        while(!solved && !impossible) {
            for(int i=0;i<numCustomers;i++) {
                bool isSatisfied = false;
                int flavourToMalt = -1;
                for(int j=0;j<customers[i].size();j++) {
                    if(flavours[customers[i][j].first] == customers[i][j].second) {
                        isSatisfied = true;
                        flavourToMalt = -1;
                        break;
                    }
                    else {
                        isSatisfied = false;
                        if(flavours[customers[i][j].first] == 0 && customers[i][j].second == 1)
                            flavourToMalt = customers[i][j].first;
                    }
                }
                if(isSatisfied == false) {
                    if(flavourToMalt == -1)
                        impossible = true;
                    else
                        flavours[flavourToMalt] = 1;
                    break;
                }
                else if(i == numCustomers -1)
                    solved = true;
            }
        }
        cout << "Case #" << c;
        if(impossible == true) {
            cout << ": IMPOSSIBLE" <<endl;
        }
        else {
            cout << ":";
            for(int i=1;i<=numFlavour;i++)
                cout << " " << flavours[i];
            cout << endl;
        }
    }
    return 0;
}
