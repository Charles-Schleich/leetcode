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
    std::unordered_map<int, std::list<std::pair <int, int>>::iterator> hashmap;

    bool initialized{false};
public:
    LRUCache(int capacity) : capacity(capacity){
        initialized = true;
    }

    int get(int key) {
        using namespace std;

        if (hashmap.count(key)==0){
            return -1;
        } else {
            // re-order to get found value to the front.
            // hashmap.count(key);
            list<pair <int, int>>::iterator iter = hashmap[key];
            int v = iter->second;
            pair<int,int> p = make_pair(key,v);
            dll.remove(p);
            dll.push_front(p);
            hashmap[key] = dll.begin();
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
                list<pair <int, int>>::iterator iter = dll.end();
                --iter;
                hashmap.erase(iter->first);
                dll.pop_back();
            };
            // add to front of list
            dll.emplace_front(make_pair(key,value));
            hashmap[key] = dll.begin(); 
        } else {
            dll.begin()->second = value;
        }
    };

    void view_list() {
        using namespace std;

        list<pair <int, int>>::iterator it = dll.begin();
        if (!initialized) return;
        cout<< "    Mem("<< dll.size() <<"): ";
        while(true)
        {
            if (it == dll.end()) break; 
            cout<< " (" <<  it->first << ","<< it->second <<") ";
            it++;
        }
        cout << endl;

        // Print out values in Hash map 
        cout<< "    Hash  :(";
        for( unordered_map<int, list<pair <int, int>>::iterator>::const_iterator it = hashmap.begin(); it != hashmap.end(); ++it){
            std::cout << it->first << ", ";
        }
        cout<< ")" << "\n";

    }

};


