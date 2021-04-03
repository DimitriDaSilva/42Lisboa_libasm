/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dds <dda-silv@student.42lisboa.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 22:47:41 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/03 20:53:03 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		ascending(void *d1, void *d2)
{
	return ((int)((long long)d2 - (long long)d1));
}

int		descending(void *d1, void *d2)
{
	return ((int)((long long)d1 - (long long)d2));
}


void	ft_list_sort_test(void)
{
	print_header("ft_list_sort_test");

	t_list	*list = NULL;

	/*
	ft_list_sort(&list, &ascending);
	check(list == NULL);

	ft_list_push_front(&list, (void *)1);
	ft_list_sort(&list, &ascending);
	check(list != NULL
			&& list->next == NULL
			&& list->data == (void *)1);

	ft_list_push_front(&list, (void *)2);
	ft_list_sort(&list, &ascending);
	check(list != NULL
			&& list->next != NULL 				&& list->data == (void *)1
			&& list->next->next == NULL			&& list->next->data == (void *)2);

	ft_list_push_front(&list, (void *)3);
	printf("List:\n");
	printf("Begin_list %p\n", &list);
	printf("1st node: data = %d & next = %p & addr = %p\n", (int)list->data, list->next, list);
	printf("2nd node: data = %d & next = %p & addr = %p\n", (int)list->next->data, list->next->next, list->next);
	printf("3rd node: data = %d & next = %p & addr = %p\n", (int)list->next->next->data, list->next->next->next, list->next->next);
	ft_list_sort(&list, &ascending);
	printf("List:\n");
	printf("Begin_list %p\n", &list);
	printf("1st node: data = %d & next = %p & addr = %p\n", (int)list->data, list->next, list);
	printf("2nd node: data = %d & next = %p & addr = %p\n", (int)list->next->data, list->next->next, list->next);
	printf("3rd node: data = %d & next = %p & addr = %p\n", (int)list->next->next->data, list->next->next->next, list->next->next);
	check(list != NULL
			&& list->next != NULL 				&& list->data == (void *)1
			&& list->next->next != NULL			&& list->next->data == (void *)2
			&& list->next->next->next == NULL 	&& list->next->next->data == (void *)3);

	ft_list_push_front(&list, (void *)3);
	ft_list_sort(&list, &descending);
	check(list != NULL
			&& list->next != NULL 				&& list->data == (void *)3
			&& list->next->next != NULL			&& list->next->data == (void *)2
			&& list->next->next->next == NULL 	&& list->next->next->data == (void *)1);
	*/

		printf("List is empty\n");
		printf("Begin_list: %p\n", &list);
		printf("Running ft_list_sort... \n");
		ft_list_sort(&list, &ascending);
		printf("No crash!\n");
		printf("\n");

		printf("Adding a node with 1 as data... \n");
		ft_list_push_front(&list, (void *)1);
		printf("List:\n");
		printf("Begin_list %p\n", &list);
		printf("1st node: data = %d & next = %p & addr = %p\n", (int)list->data, list->next, list);
		printf("Running ft_list_sort... \n");
		ft_list_sort(&list, &ascending);
		printf("List:\n");
		printf("Begin_list %p\n", &list);
		printf("1st node: data = %d & next = %p & addr = %p\n", (int)list->data, list->next, list);
		printf("\n");

		printf("Adding a node with 2 as data... \n");
		ft_list_push_front(&list, (void *)-1);
		printf("List:\n");
		printf("Begin_list %p\n", &list);
		printf("1st node: data = %d & next = %p & addr = %p\n", (int)list->data, list->next, list);
		printf("2nd node: data = %d & next = %p & addr = %p\n", (int)list->next->data, list->next->next, list->next);
		printf("Running ft_list_sort... \n");
		ft_list_sort(&list, &ascending);
		printf("Begin_list %p\n", &list);
		printf("1st node: data = %d & next = %p & addr = %p\n", (int)list->data, list->next, list);
		printf("2nd node: data = %d & next = %p & addr = %p\n", (int)list->next->data, list->next->next, list->next);
		printf("\n");

		printf("Adding a node with 3 as data... \n");
		ft_list_push_front(&list, (void *)3);
		ft_list_push_front(&list, (void *)-1);
		printf("List:\n");
		printf("Begin_list %p\n", &list);
		printf("1st node: data = %d & next = %p & addr = %p\n", (int)list->data, list->next, list);
		printf("2nd node: data = %d & next = %p & addr = %p\n", (int)list->next->data, list->next->next, list->next);
		printf("3rd node: data = %d & next = %p & addr = %p\n", (int)list->next->next->data, list->next->next->next, list->next->next);
		printf("Running ft_list_sort... \n");
		ft_list_sort(&list, &ascending);
		printf("Begin_list %p\n", &list);
		printf("1st node: data = %d & next = %p & addr = %p\n", (int)list->data, list->next, list);
		printf("2nd node: data = %d & next = %p & addr = %p\n", (int)list->next->data, list->next->next, list->next);
		printf("3rd node: data = %d & next = %p & addr = %p\n", (int)list->next->next->data, list->next->next->next, list->next->next);

	/*
	printf("List:\n");
	printf("Begin_list %p\n", &list);
	printf("1st node: data = %d & next = %p & addr = %p\n", (int)list->data, list->next, list);
	printf("\n");

	printf("Adding a node with 2 as data... \n");
	ft_list_push_front(&list, (void *)2);
	printf("List:\n");
	printf("Begin_list %p\n", &list);
	printf("1st node: data = %d & next = %p & addr = %p\n", (int)list->data, list->next, list);
	printf("2nd node: data = %d & next = %p & addr = %p\n", (int)list->next->data, list->next->next, list->next);
	printf("Running ft_list_sort... \n");
	ft_list_sort(&list, &ascending);
	printf("Begin_list %p\n", &list);
	printf("1st node: data = %d & next = %p & addr = %p\n", (int)list->data, list->next, list);
	printf("2nd node: data = %d & next = %p & addr = %p\n", (int)list->next->data, list->next->next, list->next);
	printf("\n");

	printf("Adding a node with 3 as data... \n");
	ft_list_push_front(&list, (void *)3);
	printf("List:\n");
	printf("Begin_list %p\n", &list);
	printf("1st node: data = %d & next = %p & addr = %p\n", (int)list->data, list->next, list);
	printf("2nd node: data = %d & next = %p & addr = %p\n", (int)list->next->data, list->next->next, list->next);
	printf("3rd node: data = %d & next = %p & addr = %p\n", (int)list->next->next->data, list->next->next->next, list->next->next);
	printf("Running ft_list_sort... \n");
	ft_list_sort(&list, &ascending);
	printf("Begin_list %p\n", &list);
	printf("1st node: data = %d & next = %p & addr = %p\n", (int)list->data, list->next, list);
	printf("2nd node: data = %d & next = %p & addr = %p\n", (int)list->next->data, list->next->next, list->next);
	printf("3rd node: data = %d & next = %p & addr = %p\n", (int)list->next->next->data, list->next->next->next, list->next->next);


	//printf("Begin_list:   %p\n", &list);
	//printf("Ret value:    %p\n", ft_list_sort(&list, ascending));
	//ft_list_push_front(&list, (void *)1);
	//printf("1st node:     %p\n", list);
	//printf("2nd node:     %p\n", list->next);
	//printf("Ret value:    %p\n", ft_list_sort(&list, ascending));
	//printf("Ret value:    %p\n", ft_list_sort(&list, ascending));
	printf("Next address: %p\n", list->next);
	printf("Head address: %p\n", list);

	ft_list_push_front(&list, (void *)2);
	ft_list_sort(&list, ascending);
	check(list->data == (void *)2);
	ft_list_push_front(&list, (void *)1);
	ft_list_sort(&list, ascending);
	check(list->data == (void *)1 && list->data == (void *)2);
	free(list->next);
	*/

	free(list);
}
