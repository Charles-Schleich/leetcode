#include <vector> 
#include <unordered_map> 

using namespace std; 

class Solution {
public:
	// // HASH MAP SOLUTION
 	vector<int> twoSum(vector<int>& nums, int target) {
	   	unordered_map<int, int> hmap;
		int size = nums.size();

       	for (int i = 0; i<size;i++){
			hmap[nums[i]] = i;
		}

       	for (int i = 0; i<size;i++){
			if (hmap.find(target-nums[i]) != hmap.end()) {
				if(hmap[target-nums[i]]==i){continue;};
				vector<int> ans{i, hmap[target-nums[i]]};
       			return ans;
			}
		}
       vector<int> ans{};
       return ans;
    }

	// // BRUTE FORCE SOLUTION
 	// vector<int> twoSum(vector<int>& nums, int target) {
	//    	int size = nums.size();
    //    	for (int i = 0; i<size;i++){
	// 		for (int j = i+1; j<size;j++){
	// 			if (nums[i] +nums[j] == target){
    //                 vector<int> ans{i,j};
	// 				return ans;
	// 			}
	// 		}
	// 	}
    //    vector<int> ans{};
    //    return ans;
    // }

};

