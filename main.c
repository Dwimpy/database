#include "ft_string.h"
#include <stdio.h>

int main(int ac, char **argv, char **envp) {

	string *str;
	string *str2;
	(void)ac;
	(void)argv;
	(void)envp;
//	str = string_new("       to be question         ");
	str = string_new("hello world\n");
//	string_clear(str);
//	string_append(str, "hello world\n");
//	string_append(str, "hello world\n");
//	string_append(str, "hello world\n");
//	string_append(str, "hello world\n");
//	string_append(str, "hello world\n");
//	string_resize(str, 5);
//	string_resize_set(str, 25, '\0');
//	string_append(str, "bro ce faci\n");
//	string_append(str, "hello world\n");
//
//	string_print(str);
//	string_resize_set(str, 100, '\0');
//	string_shrink_fit(str);

//	string_swap(&str, &str2);
//	string_print(str);
//	string_print(str2);

//	string_erase(str, 4, 3);
//	string_print(str2);
//	printf("Len: %zu", string_length(str));
//	string_trim(str);
//	string_print(str);
//	printf("\n");
//	string_reserve(str, 150);
//	printf("Capac: %zu", string_capacity(str));
//	printf("\nLen: %zu", string_length(str));
//	string_insert(str, 6, "the ");
//	string_insert(str, string_length(str), "to be ");
//	string_replace(str, string_length(str), "the ");
//	string_replace_len(str, string_length(str), 2, "the ");
//	string *test = string_substring(str, 4, string_length(str));
//	string_print(test);
//	printf("\nLen: %zu", string_capacity(str));
//	printf("%d\n", string_starts_with(str, "hello"));
//	printf("%d\n", string_ends_with(NULL, NULL));
//	string_to_upper(str);
//	string_to_upper(str);
//	string_reverse(str);
	printf("%zu\n", string_find_first_of(str, "\nedr"));
	string_print(str);
	string_free(str);
//	string_free(str2);
	return (0);
}
