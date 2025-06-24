#include <iostream>
using namespace std;

int FriendPairingProblem(int friends) {
    if (friends == 1 || friends == 2) {
        return friends;
    }

    return FriendPairingProblem(friends-1) +  FriendPairingProblem(friends - 2) * (friends - 1);

}

int main() {
    cout << FriendPairingProblem(4) << endl;
    return 0;
}