#include "filesystem.h"

int compute_total_size(FSNode *node)
{
    FSNode *current;
    int total_size;

    if (!node)
        return 0;

    if (node->type == FILE_TYPE)
        return node->size;

    total_size = 0;
    current = node->children;
    while (current)
    {
        total_size += compute_total_size(current);
        current = current->next;
    }
    return total_size;
}

static void print_tree_indent(int indent, int is_last, int *parent_last)
{
    int i;

    i = 0;
    while (i < indent)
    {
        if (i == indent - 1)
        {
            if (is_last)
                printf("└── ");
            else
                printf("├── ");
        }
        else
        {
            if (parent_last && parent_last[i])
                printf("    ");
            else
                printf("│   ");
        }
        i++;
    }
}

static void print_node_info(const FSNode *node)
{
    if (node->type == FILE_TYPE)
        printf("%s (%d bytes)\n", node->name, node->size);
    else
        printf("%s/\n", node->name);
}

static int count_siblings(const FSNode *node)
{
    int count;

    count = 0;
    while (node)
    {
        count++;
        node = node->next;
    }
    return count;
}

static void print_structure_recursive(const FSNode *node, int indent, int is_last, int *parent_last)
{
    const FSNode *current;
    int sibling_count;
    int current_index;
    int *new_parent_last;
    int i;

    if (!node)
        return;

    if (indent > 0)
        print_tree_indent(indent, is_last, parent_last);

    print_node_info(node);

    if (node->type == DIRECTORY_TYPE && node->children)
    {
        sibling_count = count_siblings(node->children);
        current = node->children;
        current_index = 0;

        new_parent_last = malloc((indent + 1) * sizeof(int));
        if (!new_parent_last)
            return;

        i = 0;
        while (i < indent)
        {
            if (parent_last)
                new_parent_last[i] = parent_last[i];
            else
                new_parent_last[i] = 0;
            i++;
        }
        new_parent_last[indent] = is_last;

        while (current)
        {
            current_index++;
            print_structure_recursive(current, indent + 1, (current_index == sibling_count), new_parent_last);
            current = current->next;
        }
        free(new_parent_last);
    }
}

void print_structure(const FSNode *node, int indent)
{
    (void)indent; // parametro non usato, mantenuto per firma

    if (!node)
        return;

    print_structure_recursive(node, 0, 1, NULL);
}

static void free_single_node(FSNode *node)
{
    if (!node)
        return;

    if (node->name)
        free(node->name);

    free(node);
}

void free_filesystem(FSNode *node)
{
    FSNode *current;
    FSNode *next;

    if (!node)
        return;

    if (node->type == DIRECTORY_TYPE && node->children)
    {
        current = node->children;
        while (current)
        {
            next = current->next;
            free_filesystem(current);
            current = next;
        }
    }

    free_single_node(node);
}


int main(void)
{
    FSNode *root;
    FSNode *documents;
    FSNode *pictures;
    FSNode *file1;
    FSNode *file2;
    FSNode *file3;
    int total_size;

    root = create_directory("home");
    documents = create_directory("documents");
    pictures = create_directory("pictures");

    file1 = create_file("readme.txt", 1024);
    file2 = create_file("photo1.jpg", 2048000);
    file3 = create_file("report.pdf", 512000);

    add_child(root, documents);
    add_child(root, pictures);
    add_child(documents, file1);
    add_child(documents, file3);
    add_child(pictures, file2);

    print_structure(root, 0);

    total_size = compute_total_size(root);
    printf("\nTotal: %d bytes\n", total_size);

    free_filesystem(root);

    return 0;
}
