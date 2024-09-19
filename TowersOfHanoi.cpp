#include "TowersOfHanoi.h"
#include <iostream>

using namespace std;

TowersOfHanoi::TowersOfHanoi(int N) : pegA(N), pegB(N), pegC(N), numDisks(N), moveCount(0) {
    for (int i = N; i >= 1; --i) {
        pegA.push(i);
    }
}

void TowersOfHanoi::solve() {
    moveDisks(numDisks, pegA, pegC, pegB);
}

void TowersOfHanoi::moveDisks(int N, Stackt<int>& source, Stackt<int>& target, Stackt<int>& auxiliary) {
    if (N == 1) {
        target.push(source.pop());
        moveCount++;
        displayPegs();
        return;
    }

    moveDisks(N - 1, source, auxiliary, target);

    target.push(source.pop());
    moveCount++;
    displayPegs();

    moveDisks(N - 1, auxiliary, target, source);
}

void TowersOfHanoi::displayPegs() {
    cout << "Peg A: ";
    pegA.display();
    cout << "Peg B: ";
    pegB.display();
    cout << "Peg C: ";
    pegC.display();
    cout << "-------------------------" << endl;
}
