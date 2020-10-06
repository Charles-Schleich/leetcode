#pragma once
#include <algorithm>
#include <iostream>
#include <map>
#include <list>

#include "mod1/LRUCache.hpp"
#include "mod1/LRU_Tests.hpp"


void run(std::list<std::string> commands, std::list<std::pair<int,int>> input){
    using namespace std;

    list<string>::iterator cmd_iter = commands.begin();
    list<pair<int,int>>::iterator in_iter = input.begin();

    LRUCache* obj; //= new LRUCache(1);
    while (cmd_iter != commands.end()){
        obj -> view_list();
        if (*cmd_iter == "LRUCache") {
            cout << "LRUCache " << in_iter->first << endl;
            obj = new LRUCache(in_iter->first);
        } else if (*cmd_iter == "put") {
            cout << "put(" << in_iter->first << ","<< in_iter->second <<")"<< endl;
            obj->put(in_iter->first,in_iter->second); 
        } else if (*cmd_iter == "get") {
            cout << "get(" << in_iter->first  <<")"<< endl;
            int out = obj->get(in_iter->first);
            cout << out << endl;
        };
        ++cmd_iter;
        ++in_iter;
    }

}

std::pair<int,int> p(int a, int b ){
    return std::make_pair(a,b);
}

void test1(){
    using namespace std;
    cout << "===\nTest 1\n===\n"; 
    list<string> commands      = {"LRUCache", "get"  };
    list<pair<int,int>> input  = { p(0,0)   , p(0,0) };

    run(commands,input);

}

void test2(){
    // ["LRUCache", "put" , "put" , "get", "put" , "get", "put" , "get", "get", "get"]
    // [[2]    ,    [1, 1], [2, 2], [1]  , [3, 3], [2]  , [4, 4], [1]  , [3]  , [4]  ]
    using namespace std;
    cout << "===\nTest 2\n===\n"; 
    list<string> commands      = {"LRUCache", "put" , "put" , "get" , "put" , "get" , "put" , "get" , "get" , "get"  };
    list<pair<int,int>> input  = { p(2,0)   , p(1,1), p(2,2), p(1,0), p(3,3), p(2,0), p(4,4), p(1,0), p(3,0), p(4,0) };

    run(commands,input);
}


void test3(){
    using namespace std;

    cout << "===\nTest 3\n===\n"; 
    list<string> commands      = {"LRUCache",  "put",  "get",  "put",  "get",  "get"};
    list<pair<int,int>> input  = { p(1,0)   , p(2,1), p(2,0), p(3,2), p(2,0), p(3,0)};
    run(commands, input);
}






// Main 
void lru_main(){
    std::cout << "mod1\n================" << std::endl;

    test1();
    test2();
    test3();

    std::cout << "================" << std::endl;
};
