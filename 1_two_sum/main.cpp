#include <iostream>
#include <cmath>
#include <vector> 
#include "two_sum.cpp"
/**
 * Very basic implementation of main math operations
 * @param  argc Number of command line arguments
 * @param  argv User command line values,
 * @return      Return of x "op" y, where "op" is last
 * command line argument provided by the user: "+","-","/","*"
 * USAGE: ./math 10 5.0 "*"
 */
using namespace std;

void run_test(vector<int>& v, int target){
	Solution *s1 = new Solution{};
	vector<int> ans = s1->twoSum(v, target);
	cout<< "(";
	for (int n : ans){
		cout<< n << ",";
	}
	cout << ")" << endl;
}

void test1(){
	vector<int> v{3,2,4}; 
	int target = 6;
	run_test(v,target);
}

void test2(){
	vector<int> v{ 2,7,11,15}; 
	int target = 9;
	run_test(v,target);
}

void dev(){
	vector<int> v{ 2,7,11,15}; 
	unordered_map<int, int> hmap;

	hmap[v[0]] = 0; 
	hmap[v[1]] = 1; 
	hmap[v[2]] = 2; 
	hmap[v[3]] = 3;

	cout << hmap[v[3]] << endl;
	cout << "-" << (hmap.find(14) == hmap.end()) << "-" << endl;
	cout << "-" << (hmap.find(11) == hmap.end()) << "-" << endl;
	cout << "-" << hmap[1254] << "-" << endl;

}

int main(int argc, char const *argv[])
{
	test1();
	test2();
	// dev();
	return 0;
} 
