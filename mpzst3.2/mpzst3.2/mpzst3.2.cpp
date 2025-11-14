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

ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr) {
        return head;
    }

    ListNode* current = head;
    while (current != nullptr && current->next != nullptr) {
        if (current->val == current->next->val) {
            ListNode* toDelete = current->next;
            current->next = current->next->next;
            delete toDelete;
        }
        else {
            current = current->next;
        }
    }
    return head;
}

int main() {
    setupConsole();
    std::cout << "--- Завдання 2: Видалити дублікати ---" << std::endl;

    ListNode* head1 = createList({ 1, 1, 2 });
    std::cout << "Input: ";
    printList(head1);
    head1 = deleteDuplicates(head1);
    std::cout << "Output: ";
    printList(head1);

    ListNode* head2 = createList({ 1, 1, 2, 3, 3 });
    std::cout << "Input: ";
    printList(head2);
    head2 = deleteDuplicates(head2);
    std::cout << "Output: ";
    printList(head2);

    return 0;
}