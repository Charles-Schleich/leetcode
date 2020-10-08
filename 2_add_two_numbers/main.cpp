#include <iostream>
#include <cmath>
#include <vector> 
#include "solution.cpp"
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

}



// ListNode * makelinkedlist(ListNode * ogNode, vector<int> v){
// 	if (v.size()==0){ return nullptr; };
// 	int x = v.back();
// 	cout<< "NODE "<< x << endl;
// 	v.pop_back();
// 	ListNode node = ListNode(3, makelinkedlist(v));
// 	return &node;
// }


void test1(){
	cout<< "test1" << endl;
	vector<int> ln1{2,4,3};
	vector<int> ln2{5,6,4};

	ListNode l13 = ListNode(3, nullptr);
	ListNode l12 = ListNode(4, &l13);
	ListNode l11 = ListNode(2, &l12);

	ListNode l23 = ListNode(4, nullptr);
	ListNode l22 = ListNode(6, &l23);
	ListNode l21 = ListNode(5, &l22);

	cout<< "here" << endl;
	Solution *s1 = new Solution{};
	s1->addTwoNumbers(&l11,&l21);
}

void test2(){
	cout<< "test1" << endl;
	vector<int> ln1{2,4,3};
	vector<int> ln2{5,6,4};

	ListNode l17 = ListNode(9, nullptr);
	ListNode l16 = ListNode(9, &l17);
	ListNode l15 = ListNode(9, &l16);
	ListNode l14 = ListNode(9, &l15);
	ListNode l13 = ListNode(9, &l14);
	ListNode l12 = ListNode(9, &l13);
	ListNode l11 = ListNode(9, &l12);

	ListNode l24 = ListNode(9, nullptr);
	ListNode l23 = ListNode(9, &l24);
	ListNode l22 = ListNode(9, &l23);
	ListNode l21 = ListNode(9, &l22);

	cout<< "here" << endl;
	Solution *s1 = new Solution{};
	// ListNode* lprint = s1->addTwoNumbers(&l11,&l21);
	ListNode* lprint = s1->addTwoNumbers(&l21,&l11);

	cout << "print" << endl;
	cout << "(" ;
	while ( lprint != nullptr){
		cout << lprint->val << "," << endl;
		lprint = (lprint->next);
	}
	cout << ")" << endl;

}


// [9,9,9,9,9,9,9], l2 = [9,9,9,9]

void dev(){
	
}

int main(int argc, char const *argv[])
{
	cout << "start" << endl;
	test1();
	test2();
	// dev();
	return 0;
} 
