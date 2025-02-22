// find unique triplet such that the sum is 0

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
	int target = 0;
	sort(nums.begin(), nums.end());
	set<vector<int>> s;
	vector<vector<int>> output;
	for (int i = 0; i < nums.size(); i++)
	{
		int j = i + 1;
		int k = nums.size() - 1;
		while (j < k)
		{
			int sum = nums[i] + nums[j] + nums[k];
			if (sum == target)
			{
				s.insert({nums[i], nums[j], nums[k]});
				j++;
			}
			else if (sum < target)
			{
				j++;
			}
			else
			{
				k--;
			}
		}
	}
	for (auto triplets : s)
		output.push_back(triplets);
	return output;
}

int main()
{
	vector<int> nums = {-1, 0, 1, 2, -1, -4};
	vector<vector<int>> output = threeSum(nums);
	for (auto triplets : output)
	{
		for (auto num : triplets)
			cout << num << " ";
		cout << endl;
	}
	return 0;
}