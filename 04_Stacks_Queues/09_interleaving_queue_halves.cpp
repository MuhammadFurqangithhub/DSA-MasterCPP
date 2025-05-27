#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int>& q) {
    if (q.size() % 2 != 0) {
        cout << "Queue size must be even for interleaving." << endl;
        return;
    }

    int halfSize = q.size() / 2;
    queue<int> firstHalf;

    // Step 1: Push first half into auxiliary queue
    for (int i = 0; i < halfSize; ++i) {
        firstHalf.push(q.front());
        q.pop();
    }

    // Step 2: Interleave elements from firstHalf and remaining elements in q
    while (!firstHalf.empty()) {
        q.push(firstHalf.front());
        firstHalf.pop();

        q.push(q.front());
        q.pop();
    }
}

void printQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;
    for (int i = 1; i <= 6; ++i) {
        q.push(i);
    }

    cout << "Original Queue: ";
    printQueue(q);

    interleaveQueue(q);

    cout << "Interleaved Queue: ";
    printQueue(q);

    return 0;
}
