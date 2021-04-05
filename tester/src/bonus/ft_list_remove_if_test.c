/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if_test.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 10:20:28 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/05 13:37:19 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* CMP functions */

static int	is_equal(void *data1, void *data2)
{
	return (*(long long *)data1 == *(long long *)data2);
}

/*
static int	is_divisible(void *data1, void *data2)
{
	return ((long long)data1 % (long long)data2 == 0);
}
*/


/* FREE functions */

static void	free_int(void *data)
{
	*(long long *)data = 0;
}

/*
static void	free_str(void *data)
{
	free(data);
}
*/

void	ft_list_remove_if_test(void)
{
	print_header("ft_remove_if");

	t_list	*list = NULL;
	void		*ret;
	long long	data_ref;

	ft_list_remove_if(0, (void *)1, &is_equal, &free_int);
	check(1);

	ft_list_remove_if(&list, (void *)1, &is_equal, &free_int);
	check(list == NULL);

	data_ref = 2;
	ft_list_push_front(&list, (void *)1);
	ret = ft_list_remove_if(&list, &data_ref, &is_equal, &free_int);
	check(list == NULL);

	data_ref = 1;
	ft_list_push_front(&list, (void *)1);
	ret = ft_list_remove_if(&list, &data_ref, &is_equal, &free_int);
	check(list != NULL
		&& list->next == NULL 				&& list->data == (void *)1);

	data_ref = 1;
	ft_list_push_front(&list, (void *)10);
	ret = ft_list_remove_if(&list, &data_ref, &is_equal, &free_int);
	check(list != NULL
		&& list->next == NULL 				&& list->data == (void *)1);

	ft_list_push_front(&list, (void *)1);
	ft_list_push_front(&list, (void *)10);
	ft_list_push_front(&list, (void *)50);
	data_ref = 1;
	ret = ft_list_remove_if(&list, &data_ref, &is_equal, &free_int);
	check(list != NULL
		&& list->next != NULL 				&& list->data == (void *)1
		&& list->next->next == NULL			&& list->next->data == (void *)1);

	ft_list_push_front(&list, (void *)50);
	ft_list_push_front(&list, (void *)10);
	ft_list_push_front(&list, (void *)50);
	ft_list_push_front(&list, (void *)1);
	data_ref = 50;
	print_list(list);
	ret = ft_list_remove_if(&list, &data_ref, &is_equal, &free_int);
	check(list != NULL
		&& list->next != NULL 				&& list->data == (void *)1
		&& list->next->next != NULL			&& list->next->data == (void *)1
		&& list->next->next->next == NULL	&& list->next->next->data == (void *)1);
	print_list(list);



	/*
	ft_list_push_front(&list, (void *)10);
	ft_list_push_front(&list, (void *)5);
	ft_list_push_front(&list, (void *)3);
	ft_list_push_front(&list, (void *)36);
	print_list(list);
	ret = ft_list_remove_if(&list, (void *)3, &is_equal, &free_int);
	print_list(list);
	ret = ft_list_remove_if(&list, (void *)2, &is_divisible, &free_int);


	printf("Data's addr: %llx\n", (unsigned long long)list->data);
	printf("Free's addr: %#llx\n", (unsigned long long)&free_int);
	printf("Cmp's addr: %#llx\n", (unsigned long long)&is_equal);
	printf("Ret value: %llx\n", (unsigned long long)ret);

	check(list != NULL
		&& list->next != NULL 				&& list->data == (void *)10
		&& list->next->next != NULL			&& list->next->data == (void *)1
		&& list->next->next->next == NULL 	&& list->next->next->data == (void *)-10);
	*/

	delete_list(&list);

}