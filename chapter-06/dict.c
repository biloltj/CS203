#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dnode{
    char * key;
    char * value;
    struct dnode * next;
};
struct pydict{
    struct dnode * head;
    struct dnode * tail;
    int count;
};

struct pydict * pydict_new(){
    struct pydict *p = malloc(sizeof(*p));
    p->head = NULL;
    p->tail = NULL;
    p->count = 0;
    return p;
};
struct dnode * pydict_find(struct pydict * self,char * key){
    struct dnode * cur = self->head;
    while(cur){
        if (strcmp(cur->key, key) == 0){
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
};
struct dnode * pydict_put(struct pydict *self, char * key, char * value){
    struct dnode * node = pydict_find(self, key);
    if (node){
        free((void *)node->value);
        node->value = strdup(value);
        return node;
    }
    node = malloc(sizeof(*node));
    node->key = strdup(key);
    node->value = strdup(value);
    node->next = NULL;
    if (self->tail){
        self->tail->next = node;
        self->tail = node;
    } else {
        self->head = node;
        self->tail = node;
    }
    self->count++;
    return node;
};
char * pydict_get(struct pydict * self, char * key){
    struct dnode * node = pydict_find(self, key);
    if (node){
        return node->value;
    }
    return NULL;
};
int pydict_len(struct pydict * self){
    return self->count;
};
void pydict_print(struct pydict * self){
    struct dnode * cur = self->head;
    printf("{");
    while(cur){
        printf("'%s':'%s'", cur->key, cur->value);
        if (cur->next) printf(",");
        cur = cur->next;
    }
    printf("}\n");
};  

int main(void)
{
    struct pydict * dct = pydict_new();
    pydict_put(dct, "z", "Catch phrase");
    pydict_print(dct);
    pydict_put(dct, "z", "W");
    pydict_print(dct);
    pydict_put(dct, "y", "B");
    pydict_put(dct, "c", "C");
    pydict_put(dct, "a", "D");
    pydict_print(dct);
    printf("Length =%d\n",pydict_len(dct));

    printf("z=%s\n", pydict_get(dct, "z"));
    printf("x=%s\n", pydict_get(dct, "x"));

    printf("\nDump\n");
    for(struct dnode * cur = dct->head; cur != NULL ; cur = cur->next ) {
        printf("%s=%s\n", cur->key, cur->value);
    }

    
}
