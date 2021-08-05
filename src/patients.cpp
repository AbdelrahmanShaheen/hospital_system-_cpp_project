#include "..\include\patients.h"

void hospital_queue::print() {
    for (int patient = 0; patient < queue.size(); patient++) {
        cout << queue[patient].first << " ";
        if (queue[patient].second == 0) {
            cout << "regular\n";
        } else {
            cout << "urgent\n";
        }
    }
}
