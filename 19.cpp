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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<int> list;
        while(head != nullptr) {
            list.emplace_back(head -> val);
            head = head -> next;
        }

        int len = list.size();
        list.erase(list.end() - n);

        len --;
        if (len == 0)
            return nullptr;

        ListNode* res = new ListNode(list[0]);
        ListNode* res_tail = res;
        for (int i = 1; i < len; i ++) {
            res_tail -> next = new ListNode(list[i]);
            res_tail = res_tail -> next;
        }

        return res;
    }
};

int main() {
    Solution s;

    vector<int> arr = {1, 2, 3, 4, 5};
    print(s.removeNthFromEnd(build(arr), 2));

    arr = {1};
    print(s.removeNthFromEnd(build(arr), 1));

    arr = {1, 2};
    print(s.removeNthFromEnd(build(arr), 1));
}