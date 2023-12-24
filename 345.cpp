#include <iostream>
#include <string>

using namespace std;

class dequeElement {
public:
    string s;
    int idx;
    dequeElement* next;
    dequeElement* prev;

    dequeElement(char c, int idx): s(string(1, c)), idx(idx), next(nullptr), prev(nullptr) {};
};

class deque {
public:
    int len;
    dequeElement* head;
    dequeElement* tail;

    deque(): head(nullptr), tail(nullptr), len(0) {};
    void push_back(char c, int idx) {
        dequeElement* newElement = new dequeElement(c, idx);
        if (head != nullptr) {
            tail -> next = newElement;
            newElement -> prev = tail;
            tail = newElement;
        }
        else {
            head = newElement;
            tail = newElement;
        }

        len ++;
    }

    dequeElement* pop_back() {
        dequeElement* tmp = tail;
        tail = tail -> prev;
        len --;

        return tmp;
    }

    dequeElement* pop_front() {
        dequeElement* tmp = head;
        head = head -> next;
        len --;

        return tmp;
    }
};

class Solution {
public:
    bool isVowel[256] = {false};
    Solution() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        isVowel['a'] = isVowel['A'] = true;
        isVowel['e'] = isVowel['E'] = true;
        isVowel['i'] = isVowel['I'] = true;
        isVowel['o'] = isVowel['O'] = true;
        isVowel['u'] = isVowel['U'] = true;
    }
    
    string reverseVowels(string s) {
        int len = s.length();
        
        int left = 0, right = len - 1;
        while (left < right) {
            while (!isVowel[s[left]]) {
                left ++;
            }
            while (!isVowel[s[right]]){
                right --;
            }
            
            if (left >= right)
                return s;
                
            swap(s[left], s[right]);
            left ++;
            right --;
        }
        
        return nullptr;
    }
};

int main() {
    string s;   cin >> s;
    Solution sol;
    cout << sol.reverseVowels(s) << endl;
}