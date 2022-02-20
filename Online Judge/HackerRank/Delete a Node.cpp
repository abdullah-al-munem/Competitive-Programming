

// Complete the deleteNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {

    struct SinglyLinkedListNode *tmp = head;
    struct SinglyLinkedListNode *tmp2 = NULL;
    struct SinglyLinkedListNode *tmp3 = NULL;
    int i = 0;
    while(tmp != NULL)
    {
        if( i == position)
            break;
        tmp2=tmp;
        tmp=tmp->next;

        i++;
    }
    if(tmp == head)
    {
        tmp3 = head;
        head = head->next;
        free(tmp3);
        return head;
    }
    else
    {
        tmp2->next = tmp->next;
        free(tmp);
        return head;
    }



}


