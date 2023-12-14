#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print(ListNode* head) {
    cout << "===== Answer =====" << endl;
    while (head != nullptr) {
        cout << head -> val << " -> ";
        head = head -> next;

        if (head == nullptr)
            cout << "nullptr" << endl;
    }
    cout << "==================" << endl << endl;
}

ListNode* build(vector<int> arr) {
    ListNode* head = new ListNode(arr[0]);
    ListNode* tail = head;
    
    int len = arr.size();
    for (int i = 1; i < len; i ++) {
        tail -> next = new ListNode(arr[i]);
        tail = tail -> next;
    }

    return head;
}

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ios::sync_with_stdio(0);
        
        if (head == nullptr || head -> next == nullptr)
            return head;

        ListNode *ans = head -> next;
        ListNode *tem_head = head, *tail = head -> next, *pre_head;

        tem_head -> next = tail -> next;
        tail -> next = tem_head;

        pre_head = tem_head;
        tem_head = tem_head -> next;
        if (tem_head == nullptr)
            return ans;

        tail = tem_head -> next;
        while (tail != nullptr) {
            pre_head -> next = tail;
            tem_head -> next = tail -> next;
            tail -> next = tem_head;

            pre_head = tem_head;
            tem_head = tem_head -> next;
            if (tem_head == nullptr)
                break;
            tail = tem_head -> next;
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> arr;

    arr = {1, 2, 3, 4};
    print(s.swapPairs(build(arr)));

    arr = {1, 2, 3, 4, 5};
    print(s.swapPairs(build(arr)));

    arr = {1};
    print(s.swapPairs(build(arr)));
}