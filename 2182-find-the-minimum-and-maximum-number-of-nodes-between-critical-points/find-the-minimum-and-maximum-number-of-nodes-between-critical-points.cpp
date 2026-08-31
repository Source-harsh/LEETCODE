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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode * temp = head->next;
        ListNode* back = head;
        ListNode* front = temp->next;
        if(front == NULL) return {-1,-1};
        int i = 1;
        vector<int> dist;
        while(front != NULL){
            if((temp->val > back->val && temp->val > front->val)||(temp->val < back->val && temp->val < front->val)) dist.push_back(i);
            temp = temp->next;
            back = back->next;
            front = front->next;
            i++;
        }
        if(dist.size() <= 1) return {-1,-1};
        sort(dist.begin(),dist.end());
        int mindist = INT_MAX;
        for(int j=1;j<dist.size();j++){
            mindist = min(mindist,abs(dist[j]-dist[j-1]));
        }
        return {mindist,abs(dist[0] - dist[dist.size() - 1])};
    }
};