#include <stdio.h>
#include <stdlib.h>

struct Node
{
	struct Node *prev;
	int data;
	struct Node *next;
};

struct Node *head;

void display()
{
	struct Node *ptr = head;

	printf("\n\n");

	while (ptr != NULL)
	{
		if (ptr->prev != NULL)
		{
			printf(" < ");
		}

		printf("%d", ptr->data);

		if (ptr->next != NULL)
		{
			printf(" > ");
		}

		ptr = ptr->next;
	}

	printf("\n\n");
}

struct Node *createNode(int data)
{
	struct Node *node = (struct Node *)malloc(sizeof(int));
	node->prev = NULL;
	node->data = data;
	node->next = NULL;
	return node;
}

int delete()
{
	if (head == NULL)
	{
		printf("\nempty list\n");
		return 1;
	}

	int idx;
	printf("Enter index to delete: ");
	scanf("%d", &idx);

	if (idx < 1)
	{
		printf("\ninvalid index\n");
		return 1;
	}

	struct Node *ptr = head;

	while (ptr != NULL && idx > 1)
	{
		ptr = ptr->next;
		idx--;

		if (ptr == NULL && idx > 0)
		{
			printf("\ninvalid index\n");
			return 1;
		}
	}

	struct Node *prev = ptr->prev;
	struct Node *next = ptr->next;

	if (prev == NULL)
	{
		head = next;
	}
	else
	{
		prev->next = next;
	}

	if (next != NULL)
	{
		next->prev = prev;
	}

	free(ptr);
	display();
	return 0;
}

void insert()
{
	int idx, data;
	printf("Enter index and element to add: ");
	scanf("%d %d", &idx, &data);
	struct Node *node = createNode(data);
	struct Node *ptr = head;

	while (ptr != NULL && idx > 1)
	{
		if (ptr->next != NULL && idx > 1)
		{
			ptr = ptr->next;
		}

		idx--;
	}

	if (ptr != NULL && ptr->next == NULL)
	{
		ptr->next = node;
		node->prev = ptr;
	}
	else
	{
		if (ptr->prev != NULL)
		{
			struct Node *prev = ptr->prev;
			node->prev = prev;
			prev->next = node;
		}
		else
		{
			head = node;
		}

		node->next = ptr;
		ptr->prev = node;
	}

	display();
}

void create()
{
	int n;
	head = NULL;

	printf("\nNumber of elements to be added: ");
	scanf("%d", &n);
	printf("\n");

	for (int i = 0; i < n; i++)
	{
		printf("Enter %d element: ", i + 1);
		int data;
		scanf("%d", &data);
		struct Node *node = createNode(data);

		if (head == NULL)
		{
			head = node;
		}
		else
		{
			struct Node *ptr = head;

			while (ptr != NULL)
			{
				if (ptr->next == NULL)
				{
					break;
				}

				ptr = ptr->next;
			}

			node->prev = ptr;
			ptr->next = node;
		}
	}

	display();
}

int main()
{
	int op;
	head = NULL;

	printf("\n1. %-10s\t2. %-10s\n3. %-10s\t4. %-10s\n5. %-10s\t\n", "create", "insert", "delete", "search", "reverse");

	do
	{
		printf("\noperation: ");
		scanf("%d", &op);

		switch (op)
		{
		// create
		case 1:
			create();
			break;

		// insert
		case 2:
			insert();
			break;

		// delete
		case 3:
			delete ();
			break;
-
			// // search
			// case 4:
			//   search();
			// break;

			// // reverse
			// case 5:
			//   reverse();
			// break;

		default:
			printf("\ninvalid operation\n");
			break;
		}

	} while (op);

	return 0;
}