#include <ioatream>
using namespace std;

//方法一:动态规划
class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int* dp = new int[array.size()];
		dp[0] = array[0];
		int max_val = dp[0];
		for (int i = 1; i < array.size(); i++) {
			dp[i] = max(dp[i - 1] + array[i], array[i]);
			if (dp[i] > max_val)
				max_val = dp[i];
		}
		return max_val;
	}
};
//方法二:贪心算法
class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int max_val = array[0];
		int total = array[0];
		for (int i = 1; i < array.size(); i++) {
			if (total > 0) {
				total += array[i];
			}
			else {
				total = array[i];
			}
			if (total > max_val)
				max_val = total;
		}
		return max_val;
	}
};

#include <iostream>
#include <string>
using namespace std;
//判断是否为回文串
bool IsPalindrome(string& str, int* start, int* end) {
	int i = 0;
	int j = str.size() - 1;
	bool result = true;
	while (i < j) {
		if (str[i] != str[j]) {
			result = false;
			break;
		}
		i++;
		j--;
	}
	if (start != nullptr)
		*start = i;
	if (end != nullptr)
		*end = j;
	return result;
}

int main() {
	int num;
	cin >> num;
	while (num) {
		string str;
		cin >> str;
		int start = 0;
		int end = str.size() - 1;
		if (IsPalindrome(str, &start, &end)) {
			cout << -1 << endl;
		}
		else {
			str.erase(start, 1);
			if (IsPalindrome(str, nullptr, nullptr))
				cout << start << endl;
			else
				cout << end << endl;
		}
		num--;
	}
	return 0;
}

class Solution {
public:
	ListNode* GetLength(ListNode* pHead, int& len) {
		if (pHead == nullptr)
			return nullptr;
		ListNode* end = nullptr;
		while (pHead) {
			end = pHead;
			pHead = pHead->next;
			len++;
		}
		return end;
	}
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		if (pHead1 == nullptr || pHead2 == nullptr) {
			return nullptr;
		}
		int len1 = 0;
		int len2 = 0;
		ListNode* end1 = GetLength(pHead1, len1);
		ListNode* end2 = GetLength(pHead1, len2);
		if (end1 != end2)
			return nullptr;
		int step = abs(len1 - len2);
		if (len1 > len2) {
			while (step) {
				pHead1 = pHead1->next;
				step--;
			}
		}
		else {
			while (step) {
				pHead2 = pHead2->next;
				step--;
			}
		}
		while (pHead1 && pHead2) {
			if (pHead1 == pHead2)
				return pHead1;
			pHead1 = pHead1->next;
			pHead2 = pHead2->next;
		}
		return nullptr;
	}
};

class Solution {
public:
	int TreeDepth(TreeNode* pRoot) {
		if (pRoot == nullptr)
			return 0;
		return 1 + max(TreeDepth(pRoot->left), TreeDepth(pRoot->right));
	}
};

class Solution {
public:
	struct compare {
		bool operator()(int a, int b) {
			string xs = to_string(a);
			string ys = to_string(b);
			string A = xs;
			A += ys;
			string B = ys;
			B += xs;
			return A < B;
		}
	};
	string PrintMinNumber(vector<int> numbers) {
		string result = "";
		if (numbers.size() != 0) {
			compare com;
			sort(numbers.begin(), numbers.end(), com);
			for (int i = 0; i < numbers.size(); i++) {
				result += to_string(numbers[i]);
			}
		}
		return result;
	}
};