#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lnode{
  char * text;
  struct lnode * next;
};

struct pylist{
  struct lnode * head;
  struct lnode * tail;
  int count;

};

struct pylist * pylist_new(){
  struct pylist *p = malloc(sizeof(*p));
  p->head = NULL;
  p->tail = NULL;
  p->count = 0;
  return p;
};

void pylist_del(struct pylist* self){
  struct lnode * cur, *next;
  cur = self->head;
  while(cur){
    next = cur->next;
    free((void *)cur->text);
    free((void *)cur);
    cur = next;
  }
  free((void *)self);   
};

void pylist_print(struct pylist * self){
  struct lnode * cur = self->head;
  printf("[");
  while(cur){
    printf("'%s'", cur->text);
    if (cur->next) printf(",");
    cur = cur->next;
  }
  printf("]\n");
};


void pylist_index(struct pylist * self,char * str){
  struct lnode * cur = self->head;
  int index = 0;
  while(cur){
    if (strcmp(cur->text, str) == 0){
      printf("Index of '%s' is %d\n", str, index);
      return;
    }
    cur = cur->next;
    index++;
  }
  return -1;
}

void pylist_append(struct pylist * self, char * str){
  struct lnode *node = malloc(sizeof(*node));
  if(!node) return;
  node->text = strdup(str);
  node->next = NULL;
  if(self->tail == NULL){
    self->tail = node;
    self->head = node;
  } else {
    self->tail->next = node;
    self->tail = node;
  }
  printf("Head: %s\n",self->head->text);
  printf("Tail: %s\n",self->tail->text);
  
  self->count++;
  printf("Count: %d\n", self->count);
}
int main(void) {
  struct pylist * lst = pylist_new();
  pylist_append(lst, "Hello World");
  pylist_print(lst);
  pylist_append(lst,"Bilol");
  pylist_print(lst);
  pylist_append(lst,"Python");
  pylist_print(lst);  
  pylist_append(lst,"C Programming");
  pylist_print(lst);
  pylist_index(lst,"Python");
  pylist_del(lst);
  return 0;

}

