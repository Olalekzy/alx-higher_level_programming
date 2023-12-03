#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint - adds a new node at the beginning of a listint_t list
 * @head: pointer to a pointer to the head of listint_t
 * @n: int to add in listint_t list
 * Return: address of the new element, or NULL if it failed
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
    listint_t *new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = n;
    new_node->next = *head;
    *head = new_node;
    return (new_node);
}

/**
 * is_palindrome - identifies if a singly linked list is palindrome
 * @head: pointer to a pointer to the head of listint_t
 * Return: 1 if it is a palindrome else 0
 */
int is_palindrome(listint_t **head)
{
    listint_t *current = *head;
    listint_t *reversed = NULL;
    listint_t *temp;

    if (*head == NULL || (*head)->next == NULL)
        return (1);

    while (current != NULL)
    {
        add_nodeint(&reversed, current->n);
        current = current->next;
    }

    temp = reversed;

    while (*head != NULL)
    {
        if ((*head)->n != temp->n)
        {
            free_listint(reversed);
            return (0);
        }
        *head = (*head)->next;
        temp = temp->next;
    }

    free_listint(reversed);
    return (1);
}

