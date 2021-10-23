#include "bits/stdc++.h"
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	void deleteNode(ListNode* node) {
		ListNode *t = node->next;
		*node = *t;
	}
};
int main() {

	return 0 ;
}
