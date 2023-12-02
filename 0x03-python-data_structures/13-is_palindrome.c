#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * is_palindrome - Checks if a linked list is a palindrome
 * @head: Pointer to the head of the list
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
	if (*head == NULL || (*head)->next == NULL)
		return (1);

	listint_t *slow = *head;
	listint_t *fast = *head;
	listint_t *prev_slow = *head;
	listint_t *second_half = NULL;
	listint_t *mid_node = NULL;
	int is_palindrome = 1;

	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		prev_slow = slow;
		slow = slow->next;
	}

	if (fast != NULL) // Odd number of elements, move to the next node
	{
		mid_node = slow;
		slow = slow->next;
	}

	second_half = slow;
	prev_slow->next = NULL;
	reverse_list(&second_half); // Implement reverse_list() to reverse the second half of the list

	is_palindrome = compare_lists(*head, second_half);

	if (mid_node != NULL) // Reconstructing the original list
	{
		prev_slow->next = mid_node;
		mid_node->next = second_half;
	}
	else
		prev_slow->next = second_half;

	return is_palindrome;
}
