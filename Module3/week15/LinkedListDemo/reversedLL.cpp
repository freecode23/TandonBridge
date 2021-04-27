LinkedListNode *reverse(LinkedListNode *head)
{
    // no need to reverse if head is nullptr
    // or there is only 1 node.
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    LinkedListNode *node_to_do = head->next;

    LinkedListNode *reversed_node = head;
    reversed_node->next = nullptr;

    while (node_to_do != nullptr)
    {
        LinkedListNode *temp = node_to_do;
        node_to_do = node_to_do->next;

        temp->next = reversed_node;
        reversed_node = temp;
    }

    return reversed_node;
}

int main()
{
    vector<int> v1 = {7, 14, 21, 28};
    LinkedListNode *list_head = LinkedList::create_linked_list(v1);

    cout << "Original: ";
    LinkedList::display(list_head);
    list_head = reverse(list_head);
    cout << "After Reverse: ";
    LinkedList::display(list_head);

    vector<int> v2 = {28, 21, 14, 7};
    LinkedListNode *expected_list_head = LinkedList::create_linked_list(v2);
}