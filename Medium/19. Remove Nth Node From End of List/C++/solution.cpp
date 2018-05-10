#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * 用两个指针，一个指针先走n步，另一个指针从头开始，之后一起走
 * 如果n为1，直接找到最后一个删去，这里注意如果只有一个节点时删除头指针
 * 如果n大于1，首先判断是否有n个节点，如果没有返回头指针，如果有则使用上述方法
 * 如果删去头指针，返回头指针后一个
*/
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    if (n == 0)
        return head;
    if (n == 1)
    {
        if (head->next == nullptr)
            return nullptr;
        ListNode *cur = head;
        while (cur->next->next != nullptr)
            cur = cur->next;
        cur->next = nullptr;
        return head;
    }
    else
    {
        ListNode *cur = head, *ahead = head;
        for (int i = 0; i < n - 1; ++i)
        {
            ahead = ahead->next;
            if (ahead == nullptr)
                return head;
        }
        if (ahead->next == nullptr)
            return head->next;
        while (ahead->next != nullptr)
        {
            cur = cur->next;
            ahead = ahead->next;
        }
        cur->val = cur->next->val;
        cur->next = cur->next->next;
        return head;
    }
}

int main()
{
    while (true)
    {
        int size;
        cin >> size;
        int value;
        cin >> value;
        ListNode *head = new ListNode(value), *cur = head;
        for (int i = 1; i < size; ++i)
        {
            cin >> value;
            cur->next = new ListNode(value);
            cur = cur->next;
        }
        int n;
        cin >> n;
        head = removeNthFromEnd(head, n);
        while (head != nullptr)
        {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl << "Finish!" << endl;
    }
    return 0;
}
