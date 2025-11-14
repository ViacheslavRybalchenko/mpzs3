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
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }
    return false;
}

int main() {
    setupConsole();
    std::cout << "--- Завдання 3: Цикл пов’язаного списку ---" << std::endl;
    std::cout << std::boolalpha;

    ListNode* head1 = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node0 = new ListNode(0);
    ListNode* node4 = new ListNode(-4);

    head1->next = node2;
    node2->next = node0;
    node0->next = node4;
    node4->next = node2;

    std::cout << "Input: [3, 2, 0, -4], pos = 1" << std::endl;
    std::cout << "Output: " << hasCycle(head1) << std::endl;

    ListNode* head2 = new ListNode(1);
    std::cout << "Input: [1], pos = -1" << std::endl;
    std::cout << "Output: " << hasCycle(head2) << std::endl;

    return 0;
}