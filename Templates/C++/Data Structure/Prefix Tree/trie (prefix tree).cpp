#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

struct node {
    char* value;
    bool endmark;
    node* next[52 + 1];
    node()
    {
        endmark = false;
        for (int i = 0; i < 53; i++)
            next[i] = NULL;
    }
} * root;

void insert(char *str, int len)
{
    //int len = strlen(str);
    node* curr = root;
    for(int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        if(curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
    }
    curr->value = str;
    curr->endmark = true;
}

void search(char *str, int len)
{
    //int len = strlen(str);
    node* curr = root;
    for(int i = 0; i < len; i++) {
        int id = (int)str[i] - 'a';
        if(curr->next[id] == NULL){
            printf("%s is Not Found\n",str);
            return;
        }

        curr = curr->next[id];
    }
    if(curr->endmark)
        printf("%s is Found\n",curr->value);

}
void del(node* cur)
{
    for (int i = 0; i < 53; i++)
        if (cur->next[i])
            del(cur->next[i]);

    delete (cur);
}
int main()
{

    puts("ENTER NUMBER OF WORDS");
    root = new node();
    int num_word;
    cin >> num_word;
    for (int i = 1; i <= num_word; i++) {
        char str[50];
        scanf("%s", str);
        //gets(str);
        insert(str, strlen(str));
    }
    puts("ENTER NUMBER OF QUERY");
    int query;
    cin >> query;
    for(int i = 1; i <= query; i++) {
        char str[50];
        scanf("%s", str);
        search(str, strlen(str));
    }
    del(root);
    return 0;
}
