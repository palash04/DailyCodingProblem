/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Twitter.

You run an e-commerce website and want to record the last N order ids in a log. Implement a data structure to accomplish this, with the following API:

record(order_id): adds the order_id to the log
get_last(i): gets the ith last element from the log. i is guaranteed to be smaller than or equal to N.
You should be as efficient with time and space as possible.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    list<int> records;
    int N;
public:
    Solution(int N){
        this->N = N;
    }
    
    void record(int order_id){
        records.push_back(order_id);
        if (records.size() > N){
            list<int>::iterator it = records.begin();
            records.erase(it);
        }
    }
    
    int get_last(int i){
        if (i > records.size()) return -1;
        i--;    // ith last element
        list<int>::reverse_iterator it = records.rbegin();
        advance(it,i);
        return *it;
    }
};

int main(){
    int N = 4;
    Solution s(N);
    s.record(1);
    s.record(2);
    s.record(3);
    s.record(4);
    s.record(5);
    s.record(6);
    s.record(7);

    cout << s.get_last(2) << "\n";  // get 2nd last element
    cout << s.get_last(4) << "\n";  // get 4th last element
    cout << s.get_last(5) << "\n";  // get 5th last element, returns -1 as i is not less than equal to N
    
}
