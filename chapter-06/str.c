#include <stdio.h>

int main(void){
    printf("Testing pystr class\n");
    struct pystr * x = pystr_new();
    pystr_dump(x);
    
    pystr_append(x, "H");
    pystr_dump(x);

    pystr_append(x, "ello world");
    pystr_dump(x);

    pystr_assign(x, "A completely new string");
    printf("String =%s\n", pystr_cstr(x));
    printf("Length =%zu\n", pystr_length(x));

    pystr_del(x);
    

}

struct  pystr
{
    int length;
    char * data;
    int alloc;

};
struct pystr *pystr_new(){
    
    struct pystr *p = malloc(sizeof(*p));
    p->length = 0;
    p->alloc = 10;
    p->data = malloc(10);
    p->data[0] = '\0';
    return p;
    
}

void pystr_del(const struct pystr* self){
    free((void *)self->data);
    free((void *)self);
}

void pystr_dump(const struct pystr* self){
    printf("Pystr length=%d alloc=%d data=%s\n", self->length, self->alloc, self->data);

}


void pystr_append(struct pystr* self, const char* s){
    int slen = strlen(s);
    if (self->length + slen + 1 > self->alloc){
        int new_alloc = self->alloc * 2;
        while (new_alloc < self->length + slen + 1){
            new_alloc *= 2;
        }
        char * new_data = malloc(new_alloc);
        strcpy(new_data, self->data);
        free(self->data);
        self->data = new_data;
        self->alloc = new_alloc;
    }
    strcat(self->data, s);
    self->length += slen;
}

void pystr_assign(struct pystr* self, const char* s){
    int slen = strlen(s);
    if (slen + 1 > self->alloc){
        int new_alloc = self->alloc * 2;
        while (new_alloc < slen + 1){
            new_alloc *= 2;
        }
        char * new_data = malloc(new_alloc);
        free(self->data);
        self->data = new_data;
        self->alloc = new_alloc;
    }
    strcpy(self->data, s);
    self->length = slen;
}

void pystr_appends(struct pystr* self, const char* s){
    int slen = strlen(s);
    if (self->length + slen + 1 > self->alloc){
        int new_alloc = self->alloc * 2;
        while (new_alloc < self->length + slen + 1){
            new_alloc *= 2;
        }
        char * new_data = malloc(new_alloc);
        strcpy(new_data, self->data);
        free(self->data);
        self->data = new_data;
        self->alloc = new_alloc;
    }
    strcat(self->data, s);
    self->length += slen;
}