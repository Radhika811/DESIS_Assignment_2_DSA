#include <bits/stdc++.h>
using namespace std;

class LRUCache {
    unordered_map <int,int> mp;
    int CAPACITY=0;
    vector <int> KEYS=vector<int> (10001,-1);
    vector <int> TIME=vector<int> (10001,-1);
    queue <pair<int,int>> timequ;
    int curtime=0;
    int curcap=0;
public:
    LRUCache(int capacity) {
        CAPACITY=capacity;
    }
    
    int get(int key) {
        if (KEYS[key]==-1) return -1;
        timequ.push({key,curtime});
        TIME[key]=curtime;
        curtime++;
        return KEYS[key];

    }
    
    void put(int key, int value) {
        if (curcap<CAPACITY || KEYS[key]!=-1) {
            timequ.push({key,curtime});
            if (KEYS[key]==-1) curcap++;
            KEYS[key]=value;
            TIME[key]=curtime;
            curtime++;
        }
        else {
            while (TIME[timequ.front().first]!=timequ.front().second) {
               // cout<<"rem"<<key<<" "<<value<<timequ.front().first<<endl;
                timequ.pop();

            }
            KEYS[timequ.front().first]=-1;
            TIME[timequ.front().first]=-1;
            timequ.pop();
            timequ.push({key,curtime});
            KEYS[key]=value;
            TIME[key]=curtime;
            curtime++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */