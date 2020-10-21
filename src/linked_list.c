#include "linked_list.h"

// Create and return a new list
list_t *list_create()
{
	/* IMPLEMENT THIS IF YOU WANT TO USE LINKED LISTS */
	list_t *list = (list_t *)malloc(sizeof(list_t));
	if (list == NULL)
	{
		free(list);
		return NULL;
	}
	list->head = NULL;
	list->tail = NULL;
	list->count = 0;
	return list;
}

// Destroy a list
void list_destroy(list_t *list)
{
	/* IMPLEMENT THIS IF YOU WANT TO USE LINKED LISTS */
	if (list == NULL)
	{
		return;
	}
	if (list->head == NULL)
	{
		free(list);
		return;
	}

	list_node_t *node = list->head;
	list_node_t *next = node->next;
	for (size_t i = 0; i < list->count; i++)
	{
		free(node);
		node = next;
		next = node->next;
	}
	free(list);
}

// Return the number of elements in the list
size_t list_count(list_t *list)
{
	/* IMPLEMENT THIS IF YOU WANT TO USE LINKED LISTS */
	return list->count;
}

// Find the first node in the list with the given data
// Returns NULL if data could not be found
list_node_t *list_find(list_t *list, void *data)
{
	/* IMPLEMENT THIS IF YOU WANT TO USE LINKED LISTS */
	if (list == NULL || list->head == NULL)
	{
		return NULL;
	}
	list_node_t *node = list->head;
	do
	{
		if (node->data == data)
		{
			return node;
		}
		node = node->next;
	} while (node != list->head);
	return NULL;
}

// Insert a new node in the list with the given data
void list_insert(list_t *list, void *data)
{
	/* IMPLEMENT THIS IF YOU WANT TO USE LINKED LISTS */
	if (list == NULL)
	{
		return;
	}
	list_node_t *node = (list_node_t *)malloc(sizeof(list_node_t));
	if (node == NULL)
	{
		free(node);
		return;
	}
	if (list->head == NULL)
	{
		list->head = node;
		list->tail = node;
		node->prev = NULL;
		node->next = NULL;
	}
	else
	{
		node->prev = list->tail;
		node->next = NULL;
		node->prev->next = node;
		list->tail = node;
	}
	node->data = data;
	list->count++;
	return;
}

// Remove a node from the list and free the node resources
void list_remove(list_t *list, list_node_t *node)
{
	/* IMPLEMENT THIS IF YOU WANT TO USE LINKED LISTS */
	if (list == NULL || list->head == NULL || node == NULL || list->tail == NULL)
	{
		return;
	}

	if (list->count == 1)
	{
		free(node);
		list->head = NULL;
		list->tail = NULL;
		list->count = 0;
		return;
	}
	if (list->head == node)
	{
		node->next->prev = NULL;
		list->head = node->next;
	}
	else if (list->tail == node)
	{
		node->prev->next = NULL;
		list->tail = node->prev;
	}
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}

	list->count--;
	free(node);
	return;
}

// Execute a function for each element in the list
void list_foreach(list_t *list, void (*func)(void *data))
{
	/* IMPLEMENT THIS IF YOU WANT TO USE LINKED LISTS */
	if (list == NULL || list->head == NULL)
	{
		return;
	}
	list_node_t *node = list->head;
	for (int i = 0; i < list->count; i++)
	{
		(*func)(node->data);
		node = node->next;
	}
	return;
}

// pop list head
void* list_pop(list_t* list) {
	void* data = list->head->data;
	list_remove(list, list->head);
	return data;
}