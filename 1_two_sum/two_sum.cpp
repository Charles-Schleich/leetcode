#include <iostream>
#include <vector> 

using namespace std; 

class Solution {
public:
 	vector<int> twoSum(vector<int>& nums, int target) {
	   	int size = nums.size();
       	for (int i = 0; i<size;i++){
			for (int j = i+1; j<size;j++){
				if (nums[i] +nums[j] == target){
                    vector<int> ans{i,j};
					return ans;
				}
			}
		}
       vector<int> ans{};
       return ans;
    }
};


// Sad that Iterators are too slow 

// vector<int> twoSum(vector<int>& nums, int target) {
// 	cout<<"twoSum"<< endl;

// 	vector<int> ans{};		
// 	vector<int>::iterator it = nums.begin();

// 	while (it != nums.end()){
// 		if (*it>=target){
// 			++it;
// 			continue;
// 		}
// 		vector<int>::iterator it2 = it;
// 		while (it2 != nums.end()){
// 			if (*it2>=target) continue;
// 			if (*it2+*it == target){
// 				ans.push_back(*it);
// 				ans.push_back(*it2);
// 				return ans;
// 			}
// 			++it2;
// 		}		
// 		++it;
// 	}

// 	return ans;
// }