#include <iostream>
#include <deque>
using namespace std;

const int MAX_SPECIALIZATION = 20;
const int MAX_QUEUE = 5;
struct hospital_queue{
 deque<pair<string ,int>>queue;
 void print();
};

