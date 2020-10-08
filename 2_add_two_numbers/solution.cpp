#include <iostream>
#include <vector> 
#include <unordered_map> 

using namespace std; 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int len1 = getlen(l1);
        int len2 = getlen(l2);
        ListNode* ln1;
        ListNode* ln2;
        ListNode* ln3;

        if (len1 >= len2){} 
        else {
            ListNode* temp = l1;
            l1 = l2;
            l2 = temp;
            len2 = len1;
            cout<< "l2 is longer" << endl; 
        }
        ln1 =  l1;
        ln2 =  l2;
        ln3 =  l2;


        int count = 1;
        int carry = 0;
        while ( ln1 != nullptr){

            int ans; 
            if (count>len2){
                ans = (ln1->val) + carry;
            } 
            else {
                ans = (ln1->val) + (ln2->val) + carry; 
                ln2 = (ln2->next);
            }

            carry = 0;
            if (ans >= 10){
                carry = 1;
                ans = ans-10;
            }
            ln1->val = ans;

            // This is the dodgiest shit ive written in my life
            if (ln1->next == nullptr && carry==1){
                ln3->val = 1;                
                ln3->next = nullptr;
                (ln1->next) = ln3 ;
                break;
            }
            ln1 = (ln1->next);
            ++count;
        }

        return l1;
    }

    int getlen(ListNode* l1){
        ListNode* ln =  l1;
        int len1 = 0;
        while ( ln != nullptr){
            ln = (ln->next);
            ++len1; 
        }
        return len1;
    }
};






