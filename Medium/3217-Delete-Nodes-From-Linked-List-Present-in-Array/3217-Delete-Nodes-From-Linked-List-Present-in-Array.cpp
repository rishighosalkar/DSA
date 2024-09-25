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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s;
        for(int i=0; i<nums.size(); i++)
            s.insert(nums[i]);

        while(head != nullptr && s.count(head->val) > 0){
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
        
        if(head == nullptr)
            return nullptr;

        ListNode* curr = head;

        while(curr->next){
            if(s.find(curr->next->val) != s.end()){
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            }
            else
                curr = curr->next;
        }

        return head;

    }
};