//
// Created by David Lazo on 25/09/2019.
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<pair<string,int>> amountMoney;

void vectorPrint(){
    for(auto it=amountMoney.begin();it != amountMoney.end();++it)
        cout<<it-> first <<" " <<it-> second << endl;
}
void modify(string id, int am, bool masmas){
    for(auto it=amountMoney.begin(); it!= amountMoney.end();++it){
        if(it->first == id){
            if(masmas) it->second+=am;
            else it->second-=am;
        }
    }
}

int main() {
    int numPerson;

    string Id;
    string persona;

    int costGift;
    int Totality;
    int costo;

    bool firstGroup=true;

    while (cin >> numPerson) {

        for (int i = 0; i < numPerson; ++i) {
            cin >> Id;
            amountMoney.emplace_back(Id,0);
        }

        for (int i = 0; i < numPerson; ++i) {
            cin >> Id >> costGift >> Totality;

            if(Totality!=0){
                costo = costGift / Totality;

                modify(Id,costo*Totality,false);

                for (int j = 0; j < Totality; ++j) {
                    cin >> persona;
                    modify(persona,costo,true);
                }

            }

        }

        if(!firstGroup) cout<<endl;
        vectorPrint();
        firstGroup = false;
        amountMoney.clear();
    }
    return 0;
}
