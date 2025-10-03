#include <iostream>
#include <unordered_map>
#include <map>
#include <unordered_set>

using namespace std;

int main() {
    // unordered_map<string, int> m;
    // map<string, int> m;
    // m["India"] = 150;
    // m["China"] = 150;
    // m["US"] = 120;
    // m["UK"] = 50;
    // m["Bhutan"] = 2;
    // m["Pakistan"] = 30;
    // m["Bangladesh"] = 20;
    // m["Canada"] = 30;

    // for (pair<string, int> cntry : m) {
    //     cout << "("<< cntry.first << ", " << cntry.second << ")" << endl;
    // }

    // cout << endl;

    // // for deleting something from hashtable we use `erase(key)`
    // m.erase("China");
    // // count(key) -> if it is exist or not, check
    // if (m.count("Mal Mandro")) {
    //     cout << "China Exist\n";
    // } else {
    //     cout << "Not Exist\n";
    // }
    
    unordered_set<string> set;

    set.insert("India");
    set.insert("Pakistani");
    set.insert("China");
    set.insert("UK");
    set.insert("US");
    set.insert("Afganishtan");

    cout << "Size of the set is : " << set.size() << endl;

    // if you try to insert duplicate it, just simply ignore 

    // for finding any key use find(key)

    if (set.find("India") != set.end()) {
        cout << "Yes, Exist\n";
    } else {
        cout << "Not Exists\n";
    }

    for (auto el : set) {
        cout << el << ",";
    }
    
    cout << endl;
    return 0;
}