#include <iostream>
#include <vector>
#include <algorithm>
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

    tail -> next = nullptr;
    return head;
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        int val1 = 0, val2 = 0;

        ListNode* res = new ListNode();

        ListNode* res_tail = res;
        while(list1 != nullptr || list2 != nullptr) {
            res_tail -> next = new ListNode();
            res_tail = res_tail -> next;

            if (list1 && list2) {
                val1 = list1 -> val, val2 = list2 -> val;

                if (val1 > val2) {
                    res_tail -> val = val2;
                    list2 = list2 -> next;
                }
                else {
                    res_tail -> val = val1;
                    list1 = list1 -> next;
                }
            }
            else if (list1) {
                res_tail -> val = list1 -> val;
                list1 = list1 -> next;
            }
            else {
                res_tail -> val = list2 -> val;
                list2 = list2 -> next;
            }

        }

        return res -> next;
    }
};

int main() {
    Solution s;

    ListNode* list1;
    ListNode* list2;

    list1 = build({1, 2, 4}), list2 = build({1, 3, 4});
    print(s.mergeTwoLists(list1, list2));

    // list1 = build({}), list2 = build({});
    // print(s.mergeTwoLists(list1, list2));

    // list1 = build({}), list2 = build({0});
    // print(s.mergeTwoLists(list1, list2));
}