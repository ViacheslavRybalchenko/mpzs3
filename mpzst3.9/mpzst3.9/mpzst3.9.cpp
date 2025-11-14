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

ListNode* partition(ListNode* head, int x) {
    ListNode lessDummy(0);
    ListNode greaterDummy(0);

    ListNode* lessTail = &lessDummy;
    ListNode* greaterTail = &greaterDummy;

    ListNode* curr = head;

    while (curr != nullptr) {
        if (curr->val < x) {
            lessTail->next = curr;
            lessTail = lessTail->next;
        }
        else {
            greaterTail->next = curr;
            greaterTail = greaterTail->next;
        }
        curr = curr->next;
    }

    greaterTail->next = nullptr;
    lessTail->next = greaterDummy.next;

    return lessDummy.next;
}

int main() {
    setupConsole();
    std::cout << "--- Завдання 9: Розділити список ---" << std::endl;

    ListNode* head1 = createList({ 1, 4, 3, 2, 5, 2 });
    int x1 = 3;
    std::cout << "Input: ";
    printList(head1);
    head1 = partition(head1, x1);
    std::cout << "Output (x=3): ";
    printList(head1);

    ListNode* head2 = createList({ 2, 1 });
    int x2 = 2;
    std::cout << "Input: ";
    printList(head2);
    head2 = partition(head2, x2);
    std::cout << "Output (x=2): ";
    printList(head2);

    return 0;
}