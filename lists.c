#include "shell.h"

/**
 * add_node - adds a node to the start of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
list_t *add_node(list_t **head, const char *str, int num)
{
    list_t *new_head;

    if (!head)
        return NULL;

    new_head = malloc(sizeof(list_t));
    if (!new_head)
        return NULL;

    memset(new_head, 0, sizeof(list_t));
    new_head->num = num;

    if (str)
    {
        new_head->str = _strdup(str);
        if (!new_head->str)
        {
            free(new_head);
            return NULL;
        }
    }

    new_head->next = *head;
    *head = new_head;
    return new_head;
}

/**
 * add_node_end - adds a node to the end of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
    list_t *new_node;

    if (!head)
        return NULL;

    new_node = malloc(sizeof(list_t));
    if (!new_node)
        return NULL;

    memset(new_node, 0, sizeof(list_t));
    new_node->num = num;

    if (str)
    {
        new_node->str = _strdup(str);
        if (!new_node->str)
        {
            free(new_node);
            return NULL;
        }
    }

    if (*head)
    {
        list_t *node = *head;
        while (node->next)
            node = node->next;
        node->next = new_node;
    }
    else
    {
        *head = new_node;
    }

    return new_node;
}

/**
 * print_list_str - prints only the str element of a list_t linked list
 * @h: pointer to the first node
 *
 * Return: size of list
 */
size_t print_list_str(const list_t *h)
{
    size_t i = 0;

    while (h)
    {
        _puts(h->str ? h->str : "(nil)");
        _puts("\n");
        h = h->next;
        i++;
    }

    return i;
}

/**
 * delete_node_at_index - deletes a node at the given index
 * @head: address of pointer to the first node
 * @index: index of the node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
    if (!head || !*head)
        return 0;

    list_t *node = *head;
    list_t *prev_node = NULL;
    unsigned int i = 0;

    list_t *temp_node;  // Move the declaration here

    while (node)
    {
        if (i == index)
        {
            if (prev_node)
                prev_node->next = node->next;

            free(node->str);
            free(node);
            return 1;
        }

        i++;
        prev_node = node;
        node = node->next;
    }

    return 0;
}

/**
 * free_list - frees all nodes of a list
 * @head_ptr: address of pointer to the head node
 *
 * Return: void
 */
void free_list(list_t **head_ptr)
{
    if (!head_ptr || !*head_ptr)
        return;

    list_t *node = *head_ptr;
    list_t *next_node;  // Move the declaration here

    while (node)
    {
        next_node = node->next;
        free(node->str);
        free(node);
        node = next_node;
    }

    *head_ptr = NULL;
}

