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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		vector<int> str1;
		vector<int> str2;

		for (; l1 != nullptr; l1 = l1->next)
		{
			str1.push_back(l1->val);
		}

		for (; l2 != nullptr; l2 = l2->next)
		{
			str2.push_back(l2->val);
		}

		if (str1.size() < str2.size())
		{
			vector<int> tmp = str1;
			str1 = str2;
			str2 = tmp;

		}

		for (size_t i = 0; i < str1.size(); i++)
		{
			if (i >= str2.size())
				break;
			str1[i] += str2[i];
		}
		ListNode* res = new ListNode(0);
		ListNode* result = res;

		for (size_t i = 0; i < str1.size(); i++)
		{
			if (str1[i] >= 10)
			{
				ListNode* tmp = new ListNode();
				res->next = tmp;
				res->next->val = str1[i] / 10;
				res->val += str1[i] % 10;
				res = res->next;
			}
			else
			{
				ListNode* tmp = new ListNode(0);
				res->next = tmp;
				res->val += str1[i];
				if (res->val >= 10)
				{
					res->next->val = res->val / 10;
					res->val = res->val % 10;
				}

                if (i == str1.size() - 1 && res->next->val == 0)
				{
					res->next = nullptr;
					break;
				}
				res = res->next;
			}
		}
		return result;
    }
};
