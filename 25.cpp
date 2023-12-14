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
    void reverseKNode(ListNode* prev, int times) {
        ListNode *head, *tail;
        head = prev -> next;
        tail = head -> next;

        for (int i = 0; i < times; i ++) {
            head -> next = tail -> next;
            tail -> next = prev -> next;
            prev -> next = tail;
            tail = head -> next;
        }
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1)
            return head;

        ListNode* dummy = new ListNode(0, head);
        ListNode *pioneer = dummy, *tem_prev = dummy;
        while(dummy != nullptr) {
            for (int i = 0; i < k; i ++) {
                pioneer = pioneer -> next;
                if (pioneer == nullptr)
                    return dummy -> next;
            }
            pioneer = tem_prev -> next;
            reverseKNode(tem_prev, k - 1);
            tem_prev = pioneer;
        }
        return dummy -> next;
    }
};

int main() {
    Solution s;
    vector<int> arr;

    arr = {1, 2, 3, 4, 5};
    print(s.reverseKGroup(build(arr), 2));
    print(s.reverseKGroup(build(arr), 3));
    print(s.reverseKGroup(build(arr), 4));
}