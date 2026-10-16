#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

void getRoute(unordered_map<string, string> tickets) {
    unordered_set<string> to;

    for (pair<string, string> ticket : tickets) {
        to.insert(ticket.second);
    }

    string start = "";
    for (pair<string, string> ticket : tickets) {
        if (to.find(ticket.first) == to.end()) {
            start = ticket.first;
        }
    }

    cout << start << " -> ";
    while (tickets.count(start)) {
        cout << tickets[start] << " -> ";
        start = tickets[start];
    }
    cout << "destination.\n";
}

int main() {
    unordered_map<string, string> tickets;
    tickets["chennai"] = "banglore";
    tickets["mumbai"] = "delhi";
    tickets["goa"] = "chennai";
    tickets["delhi"] = "goa";

    getRoute(tickets);

    return 0;
}