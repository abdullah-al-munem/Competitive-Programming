

// Complete the insertNodeAtPosition function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {

    struct SinglyLinkedListNode* fnNode = (struct SinglyLinkedListNode*)malloc(sizeof(struct SinglyLinkedListNode));

    fnNode->data = data;
    fnNode->next = NULL;
    struct SinglyLinkedListNode* tmp = head;
    int i;
    for(i = 0; i<position-1; i++){
        tmp = tmp->next;

        if(tmp == NULL)
            break;
    }
    if(tmp != NULL){
        fnNode->next = tmp->next;
        tmp->next = fnNode;
    }


    return head;

}


