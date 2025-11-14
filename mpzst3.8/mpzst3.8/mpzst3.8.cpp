#define NOMINMAX
#ifdef _WIN32
#include <windows.h>
#endif
#include <iostream>
#include <vector>

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

ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == nullptr || k == 1) {
        return head;
    }

    ListNode* groupEnd = head;
    for (int i = 0; i < k; ++i) {
        if (groupEnd == nullptr) {
            return head;
        }
        groupEnd = groupEnd->next;
    }

    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* next = nullptr;

    for (int i = 0; i < k; ++i) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    if (next != nullptr) {
        head->next = reverseKGroup(next, k);
    }

    return prev;
}

int main() {
    setupConsole();
    std::cout << "--- Завдання 8: Розвернути вузли в k-групі ---" << std::endl;

    ListNode* head1 = createList({ 1, 2, 3, 4, 5 });
    std::cout << "Input: ";
    printList(head1);
    head1 = reverseKGroup(head1, 2);
    std::cout << "Output (k=2): ";
    printList(head1);

    ListNode* head2 = createList({ 1, 2, 3, 4, 5 });
    std::cout << "Input: ";
    printList(head2);
    head2 = reverseKGroup(head2, 3);
    std::cout << "Output (k=3): ";
    printList(head2);

    return 0;
}