#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool mypredicate(int i, int j) {
	return (i == j);
}
void test() {
	vector<int> myvector = { 10,20,30,30,20,10,10,20 };
	//auto it = search_n(myvector, 20);
	//cout << "该下标为:"<<it << endl;
	// using default comparison:
	
	auto it = std::search_n(myvector.begin(), myvector.end(), 1, 20);

	cout << "该下标为:" << int(it - myvector.begin()) << endl;
	if (it != myvector.end())
		std::cout << "two 30s found at position " << (it - myvector.begin()) << '\n';
	else
		std::cout << "match not found\n";

	//// using predicate comparison:
	//it = std::search_n(myvector.begin(), myvector.end(), 2, 10, mypredicate);

	//if (it != myvector.end())
	//	std::cout << "two 10s found at position " << int(it - myvector.begin()) << '\n';
	//else
	//	std::cout << "match not found\n";
}

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
	vector<int> Res(nums1.size(), 0);//先定义用来输出结果的数组
	// auto nums1First = nums1.begin(),
	//     nums1Last = nums1.end();
	for (int i = 0; i < nums1.size(); i++) {

		auto nums2Index = search_n(nums2.begin(), nums2.end(), 1, nums1[i]);
		int nums2Index1 = nums2Index - nums2.begin();//求出当前nums[i]在nums2的下标
		if (nums2Index1 + 1 > nums2.size()) {
			Res[i] = -1;
			continue;
		}

		if (nums2[nums2Index1 + 1] > nums1[i])
			Res[i] = nums2[nums2Index1];
		else
			Res[i] = -1;
	}
	return Res;
}

void test01() {
	vector<int>nums1 = { 4, 1, 2 }, nums2 = { 1, 3, 4, 2 };
	nextGreaterElement(nums1, nums2);
}
int main() {
	test01();
	return 0;
}