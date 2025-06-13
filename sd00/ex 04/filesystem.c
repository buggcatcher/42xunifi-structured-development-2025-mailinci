#include "filesystem.h"
#include <stdio.h>

FSNode *create_file(const char *name, int size)
{
    FSNode *file;

    file = malloc(sizeof(FSNode));
    if (!file)
        return NULL;

    file->name = strdup(name);
    if (!file->name)
    {
        free(file);
        return NULL;
    }

    file->type = FILE_TYPE;
    file->size = size;
    file->children = NULL;
    file->next = NULL;

    return file;
}

FSNode *create_directory(const char *name)
{
    FSNode *dir;

    dir = malloc(sizeof(FSNode));
    if (!dir)
        return NULL;

    dir->name = strdup(name);
    if (!dir->name)
    {
        free(dir);
        return NULL;
    }

    dir->type = DIRECTORY_TYPE;
    dir->size = 0;
    dir->children = NULL;
    dir->next = NULL;

    return dir;
}

void add_child(FSNode *parent, FSNode *child)
{
    FSNode *current;

    if (!parent || !child || parent->type != DIRECTORY_TYPE)
        return;

    if (!parent->children)
    {
        parent->children = child;
        return;
    }

    current = parent->children;
    while (current->next)
        current = current->next;

    current->next = child;
}

FSNode *find_node(FSNode *root, const char *name)
{
    FSNode *current;
    FSNode *found;

    if (!root || !name)
        return NULL;

    if (strcmp(root->name, name) == 0)
        return root;

    if (root->type == DIRECTORY_TYPE)
    {
        current = root->children;
        while (current)
        {
            found = find_node(current, name);
            if (found)
                return found;
            current = current->next;
        }
    }

    return NULL;
}



// int main(void)
// {
//     FSNode *root;
//     FSNode *file1;
//     FSNode *dir1;
//     FSNode *found;

//     root = create_directory("root");
//     if (!root)
//     {
//         printf("Errore creazione root\n");
//         return 1;
//     }

//     file1 = create_file("file.txt", 1234);
//     dir1 = create_directory("dir1");

//     add_child(root, file1);
//     add_child(root, dir1);

//     found = find_node(root, "file.txt");
//     if (found)
//         printf("Trovato nodo: %s (type %d)\n", found->name, found->type);
//     else
//         printf("Nodo 'file.txt' non trovato\n");

//     found = find_node(root, "dir1");
//     if (found)
//         printf("Trovato nodo: %s (type %d)\n", found->name, found->type);
//     else
//         printf("Nodo 'dir1' non trovato\n");

//     found = find_node(root, "nonexistent");
//     if (!found)
//         printf("Nodo 'nonexistent' non trovato (corretto)\n");

//     // libero manualmente i nodi perchè free_filesystem è nel bonus
//     free(file1->name);
//     free(file1);
//     free(dir1->name);
//     free(dir1);
//     free(root->name);
//     free(root);

//     return 0;
// }
