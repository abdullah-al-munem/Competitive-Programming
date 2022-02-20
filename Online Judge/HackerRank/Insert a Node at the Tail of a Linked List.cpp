

// Complete the insertNodeAtTail function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {

    if(head == NULL){
        head = (struct SinglyLinkedListNode*)malloc(sizeof(struct SinglyLinkedListNode));
        head->data = data;
        head->next = NULL;
    }
    else{
        struct SinglyLinkedListNode* last = NULL;
        last = (struct SinglyLinkedListNode*)malloc(sizeof(struct SinglyLinkedListNode));
        last->data = data;
        last->next = NULL;
        struct SinglyLinkedListNode* m = head;
        while(m->next != NULL){
            m = m->next;
        }
        m->next = last;
    }
    return head;

}


