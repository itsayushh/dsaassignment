#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

// Structure for a symbol table entry
typedef struct Symbol {
    char name[50];        // Identifier name
    char type[20];        // Data type
    int scope;            // Scope level (e.g., global = 0)
    struct Symbol* next;  // For chaining in case of hash collisions
} Symbol;

Symbol* hashTable[SIZE];

// Hash function to compute index
int hash(char* name) {
    int hashVal = 0;
    for (int i = 0; name[i] != '\0'; i++)
        hashVal = (hashVal * 31 + name[i]) % SIZE;
    return hashVal;
}

// Insert into symbol table
void insert(char* name, char* type, int scope) {
    int index = hash(name);
    Symbol* current = hashTable[index];

    // Check if symbol already exists
    while (current != NULL) {
        if (strcmp(current->name, name) == 0 && current->scope == scope) {
            printf("Error: Symbol '%s' already exists in current scope.\n", name);
            return;
        }
        current = current->next;
    }

    // Create new symbol
    Symbol* newSymbol = (Symbol*)malloc(sizeof(Symbol));
    strcpy(newSymbol->name, name);
    strcpy(newSymbol->type, type);
    newSymbol->scope = scope;
    newSymbol->next = hashTable[index];
    hashTable[index] = newSymbol;

    printf("Inserted: %s (%s) in scope %d\n", name, type, scope);
}

// Search for a symbol
Symbol* search(char* name, int scope) {
    int index = hash(name);
    Symbol* current = hashTable[index];

    while (current != NULL) {
        if (strcmp(current->name, name) == 0 && current->scope == scope)
            return current;
        current = current->next;
    }

    return NULL;
}

// Display the symbol table
void display() {
    printf("\n--- Symbol Table ---\n");
    printf("Index\tName\tType\tScope\n");

    for (int i = 0; i < SIZE; i++) {
        Symbol* current = hashTable[i];
        while (current != NULL) {
            printf("%d\t%s\t%s\t%d\n", i, current->name, current->type, current->scope);
            current = current->next;
        }
    }
}

int main() {
    insert("x", "int", 0);
    insert("y", "float", 0);
    insert("x", "char", 1); // Allowed in different scope

    Symbol* sym = search("x", 0);
    if (sym)
        printf("Found symbol: %s (%s) in scope %d\n", sym->name, sym->type, sym->scope);
    else
        printf("Symbol not found.\n");

    display();
    return 0;
}
