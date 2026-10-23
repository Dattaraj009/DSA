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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int cnt = 0;
        while(temp != nullptr){
            cnt++;
            temp = temp->next;
        }
        temp = head;
        ListNode* prev = nullptr;
        cnt = cnt - n;
        while(cnt > 0 && temp != nullptr){
           prev = temp;
           temp = temp->next;
           cnt--;
        }
        if(prev && temp){
            prev->next = temp->next;
            temp->next = nullptr;
            delete temp;
        }
        else if(cnt==0){
            if(temp->next){
                head = head->next;
                delete temp;
            }
            else{
                return nullptr;
            }
        }

        return head;
    }
};