class Solution {

    class cmp{
        public :
           bool operator()(ListNode*a, ListNode*b){
             return a->val > b->val;
          }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, cmp> minHeap;

        for(int i=0; i<lists.size();i++){
            if(lists[i]!=NULL){
                minHeap.push(lists[i]);
            }
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(!minHeap.empty()){
            ListNode*top = minHeap.top();
            minHeap.pop();

            if(top->next!=NULL){
                minHeap.push(top->next);
            }

            if(head==NULL){
                head = top;
                tail = top;
            }
            else{
                tail->next = top;
                tail = top;
            }
        }

        return head;
        
    }
};