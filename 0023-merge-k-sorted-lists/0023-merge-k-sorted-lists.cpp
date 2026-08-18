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
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a -> val > b -> val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        for(ListNode* head : lists) {
            if(head != nullptr) {
                pq.push(head);
            }
        }

        ListNode dummy(0);
        ListNode* temp = &dummy;

        while(!pq.empty()) {
            ListNode* head = pq.top();
            pq.pop();

            temp -> next = head;
            temp = temp -> next;

            if(head -> next){
                pq.push(head -> next);
            }
        }

        return dummy.next;
    }
};