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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int nums = lists.size();
        if (nums <= 1)
            return nums == 0 ? nullptr : lists[0];

        ListNode *ans, *tail;
        tail = ans = new ListNode(0);
        
        bool complete = false;
        while (!complete) {
            for (int i = 0; i < nums; i ++) {
                if (lists[i] != nullptr) {
                    complete = false;
                    break;
                }
                complete = true;
            }
            if (complete)
                break;

            int tem_min = INT_MAX, tem_min_index = -1;
            for (int i = 0; i < nums; i ++) {
                if (lists[i] == nullptr)
                    continue;

                if (lists[i] -> val < tem_min) {
                    tem_min = lists[i] -> val;
                    tem_min_index = i;
                }
            }
            lists[tem_min_index] = lists[tem_min_index] -> next;

            tail -> next = new ListNode(tem_min);
            tail = tail -> next;
        }

        return ans -> next;
    }
};

int main() {
    Solution s;
    vector<ListNode*> lists;

    // lists.emplace_back(build({1, 4, 5}));
    // lists.emplace_back(build({1, 3, 4}));
    // lists.emplace_back(build({2, 6}));
    // print(s.mergeKLists(lists));

    // lists.clear();
    // print(s.mergeKLists(lists));

    lists.emplace_back(nullptr);
    lists.emplace_back(nullptr);
    print(s.mergeKLists(lists));
}