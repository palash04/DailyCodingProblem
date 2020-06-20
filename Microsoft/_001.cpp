/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Microsoft.

Compute the running median of a sequence of numbers. That is, given a stream of numbers, print out the median of the list so far on each new element.

Recall that the median of an even-numbered list is the average of the two middle numbers.

For example, given the sequence [2, 1, 5, 7, 2, 0, 5], your algorithm should print out:

2
1.5
2
3.5
2
2
2
*/

#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
    priority_queue<int> lower;
    priority_queue<int,vector<int>,greater<>> higher;
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        if (lower.size() == 0 && higher.size() == 0){
            lower.push(num);
            return;
        }
        if (lower.size()){
            if (num <= lower.top()){
                lower.push(num);
            }else{
                higher.push(num);
            }
        }
        int diff = abs((int)lower.size() - (int)higher.size());
        if (diff <= 1) return;
        if (lower.size() > higher.size()){
            int top = lower.top();lower.pop();
            higher.push(top);
        }else{
            int top = higher.top();higher.pop();
            lower.push(top);
        }
    }
    
    double findMedian() {
        double res;
        if (lower.size() == higher.size()){
            res = (double(lower.top()) + (double)(higher.top()))/2.0;
        }else{
            if (lower.size() > higher.size()){
                res = lower.top();
            }else{
                res = higher.top();
            }
        }
        return res;
    }
};


int main(){
    MedianFinder m;
    m.addNum(2);
    cout << m.findMedian() << "\n";
    m.addNum(1);
    cout << m.findMedian() << "\n";
    m.addNum(5);
    cout << m.findMedian() << "\n";
    m.addNum(7);
    cout << m.findMedian() << "\n";
    m.addNum(2);
    cout << m.findMedian() << "\n";
    m.addNum(0);
    cout << m.findMedian() << "\n";
    m.addNum(5);
    cout << m.findMedian() << "\n";
}

