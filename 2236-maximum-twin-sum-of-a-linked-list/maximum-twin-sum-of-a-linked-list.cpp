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
    int pairSum(ListNode* head) {
        vector<int> store;
        ListNode* temp = head;
        while(temp != nullptr){
            store.push_back(temp->val);
            temp = temp->next;
        }
        int l = 0, r = store.size()-1;
        int maxi = 0;
        while(l<r){
            maxi = max(maxi,store[l]+store[r]);
            l++;
            r--;
        }

        return maxi;
    }
};