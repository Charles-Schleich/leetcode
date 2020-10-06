#pragma once
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map> 
#include <list>
#include <utility> 


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

class LRUCache {
private:
    int capacity{0};
    std::list<std::pair <int, int>> dll;
    // std::unordered_map<int, std::list<std::pair <int, int>>::iterator> hashmap;

    bool initialized{false};
public:
    LRUCache(int capacity) : capacity(capacity){
        initialized = true;
    }

    int get(int key) {
        using namespace std;

        list<pair <int, int>>::iterator it = dll.begin();
        bool found = false;
        int v;

        while(it != dll.end() ){
            if(it->first == key){
                found = true;
                v = it->second;
                break;
            }
            it++;
        }

        if (found == false){
            return -1;
        } else {
            // re-order to get found value to the front.
            dll.remove(make_pair(key,v));
            dll.push_front(make_pair(key,v));
            return v;
        }
    }
    
    void put(int key, int value) {
        using namespace std;
        // 1. search through list for item
        if (get(key)==-1){
            // doesnt exist 
            if (dll.size() == capacity){
                // Check size and pop if full
                dll.pop_back();
            };
            // add to front of list
            dll.emplace_front(make_pair(key,value));
        } else {
            dll.pop_front();
            dll.emplace_front(make_pair(key,value));
        }
    };

    void view_list() {
        using namespace std;

        list<pair <int, int>>::iterator it = dll.begin();

        if (!initialized)
            return;
        int k=0,v=0;
        // cout<< dll.end();
        cout<< "    Mem("<< dll.size() <<"): ";

        while(true)
        {
            if (it == dll.end()){
                break;
            } 
            cout<< " (" <<  it->first << ","<< it->second <<") ";
            it++;
        }
        cout << endl;
    }
};


