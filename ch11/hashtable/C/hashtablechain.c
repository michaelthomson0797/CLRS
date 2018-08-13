#include "linkedlist.c"
#define MODULO 101

struct Node** mkHashTable() {
    struct Node** table = (struct Node**) malloc(MODULO * sizeof(struct Node*));

    for(int i = 0; i < MODULO; i++) {
        table[i] = (struct Node*) malloc(sizeof(struct Node));
        table[i] = NULL;
    }
    
    return table;
}
    

int hash(int key) {
    return (key % MODULO) - 1;
}

int hashInsert(struct Node** table, int key) {
    int index = hash(key);
    insert(&table[index], key);
}

int hashDelete(struct Node** table, int key) {
    int index = hash(key);
    delete(&table[index], key);
}

void printHashTable(struct Node** table) {
    for(int i = 0; i < 101; i++) {
        if(table[i] != NULL) {
            printf("%d: ", i);
            printLinkedList(table[i]);
        }
    }
}

int main() {
    struct Node** table = mkHashTable();

    hashInsert(table, 1);
    hashInsert(table, 2);
    hashInsert(table, 103);
    hashInsert(table, 204);
    hashInsert(table, 3);
    hashInsert(table, 4);
    hashInsert(table, 5);
    hashInsert(table, 6);

    hashDelete(table, 103);
    hashDelete(table, 5);
    printHashTable(table);
}

