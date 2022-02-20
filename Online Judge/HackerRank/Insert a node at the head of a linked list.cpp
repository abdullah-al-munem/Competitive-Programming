

// Complete the insertNodeAtHead function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {
    struct SinglyLinkedListNode* fnNode = (struct SinglyLinkedListNode*)malloc(sizeof(struct SinglyLinkedListNode));
    fnNode->data = data;
    fnNode->next = llist;
    llist = fnNode;
    return llist;

}


