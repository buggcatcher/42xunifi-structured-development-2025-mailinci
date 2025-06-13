#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    FILE_TYPE,
    DIRECTORY_TYPE
} NodeType;

typedef struct FSNode {
    char *name;
    NodeType type;
    int size;  // File: dimensione effettiva, Directory: 0
    struct FSNode *children;  // Lista dei figli (file e sottodirectory)
    struct FSNode *next;      // Puntatore al fratello successivo
} FSNode;

// base
FSNode *create_file(const char *name, int size);
FSNode *create_directory(const char *name);
void add_child(FSNode *parent, FSNode *child);
FSNode *find_node(FSNode *root, const char *name);

// bonus
int compute_total_size(FSNode *node);
void print_structure(const FSNode *node, int indent);
void free_filesystem(FSNode *node);

#endif
