#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){};
};

/**
 * l1 和 l2 都是从数字的最低位开始，那么只需同步依次遍历两个链表，对每个数进行就加运算，记录下进位，每次计算都要考虑进位
 * 当某一个链表为走到头时，对另一个链表继续遍历，直到全部运算完，最后注意进位是否为零，如果不为零需要加上进位
*/
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    if (l1 == nullptr)
        return l2;
    if (l2 == nullptr)
        return l1;
    // 可以从第二位开始
    ListNode *head = new ListNode(0);
    ListNode *move = head;
    int carry = 0;
    while (l1 != nullptr || l2 != nullptr)
    {
        int a = l1 == nullptr ? 0 : l1->val,
            b = l2 == nullptr ? 0 : l2->val;
        int sum = a + b + carry;
        move->next = new ListNode(sum % 10);
        move = move->next;
        carry = sum / 10;
        l1 = l1 == nullptr ? nullptr : l1->next;
        l2 = l2 == nullptr ? nullptr : l2->next;
    }
    if (carry != 0){
        move->next = new ListNode(carry);
    }
    return head->next;
}

int main()
{
    int size1, size2;
    while (true)
    {
        cin >> size1;
        ListNode *l1 = nullptr, *l2 = nullptr, *move_1, *move_2;
        for (int i = 0; i < size1; ++i)
        {
            int tmp;
            cin >> tmp;
            if (l1 == nullptr)
            {
                l1 = new ListNode(tmp);
                move_1 = l1;
            }
            else
            {
                move_1->next = new ListNode(tmp);
                move_1 = move_1->next;
            }
        }
        cin >> size2;
        for (int i = 0; i < size2; ++i)
        {
            int tmp;
            cin >> tmp;
            if (l2 == nullptr)
            {
                l2 = new ListNode(tmp);
                move_2 = l2;
            }
            else
            {
                move_2->next = new ListNode(tmp);
                move_2 = move_2->next;
            }
        }
        cout << "Point: 1\n";
        ListNode *ans = addTwoNumbers(l1, l2);
        stack<int> result;
        while (ans != nullptr)
        {
            result.push(ans->val);
            ans = ans->next;
        }
        while (!result.empty())
        {
            cout << result.top();
            result.pop();
        }
        cout << endl;
    }
    return 0;
}
