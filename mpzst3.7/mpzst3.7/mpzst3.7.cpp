#define NOMINMAX
#ifdef _WIN32
#include <windows.h>
#endif
#include <iostream>
#include <vector>
#include <queue>
#include <functional>

void setupConsole() {
#ifdef _WIN32
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif
}

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void printList(ListNode* head) {
    std::cout << "[ ";
    ListNode* curr = head;
    while (curr != nullptr) {
        std::cout << curr->val << " -> ";
        curr = curr->next;
    }
    std::cout << "nullptr ]" << std::endl;
}

ListNode* createList(const std::vector<int>& vals) {
    if (vals.empty()) {
        return nullptr;
    }
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

struct CompareNode {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    std::priority_queue<ListNode*, std::vector<ListNode*>, CompareNode> pq;

    for (ListNode* list : lists) {
        if (list != nullptr) {
            pq.push(list);
        }
    }

    ListNode dummyHead(0);
    ListNode* tail = &dummyHead;

    while (!pq.empty()) {
        ListNode* minNode = pq.top();
        pq.pop();

        tail->next = minNode;
        tail = tail->next;

        if (minNode->next != nullptr) {
            pq.push(minNode->next);
        }
    }

    return dummyHead.next;
}

int main() {
    setupConsole();
    std::cout << "--- Завдання 7: Об’єднати k списків ---" << std::endl;

    std::vector<ListNode*> lists;
    lists.push_back(createList({ 1, 4, 5 }));
    lists.push_back(createList({ 1, 3, 4 }));
    lists.push_back(createList({ 2, 6 }));

    std::cout << "Input lists: " << std::endl;
    printList(lists[0]);
    printList(lists[1]);
    printList(lists[2]);

    ListNode* merged = mergeKLists(lists);
    std::cout << "Merged: ";
    printList(merged);

    return 0;
}