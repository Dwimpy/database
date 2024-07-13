#ifndef STRING_H
# define STRING_H

# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <stdio.h>
# include <ctype.h>
// Function definition that triggers a runtime error


typedef struct string string;

// Capacity Methods

size_t	string_length(const string *str);
size_t	string_capacity(const string *str);
bool	string_empty(const string *str);
void	string_clear(string *str);
void	string_resize(string *str, size_t new_len);
void	string_resize_set(string *str, size_t new_len, char c);
string	*string_shrink_fit(string *str);
void	string_reserve(string *str, size_t bytes);

// Element Access

char	string_at(const string *str, size_t index);
char	*string_c_string(const string *str);
char	string_back(const string *str);
char	string_front(const string *str);

// Modifiers

string	*string_append(string *str, const char *value);
string	*string_push_back(string *str, char c);
string	*string_insert(string *str, size_t pos, const char *value);
string	*string_replace(string *str, size_t pos, const char *value);
string	*string_replace_len(string *str, size_t pos, size_t len, const char *value);
string	*string_trim(string *str);
void	string_swap(string **st1, string **str2);
void	string_erase(string *str, size_t pos, size_t len);


// Constructors & Destructors

string	*string_new(const char *str);
string	*string_new_empty(size_t capacity);
string	*string_copy(const string *str);
string	*string_substring(const string *str, size_t pos, size_t len);
void	string_free(string *str);

// Comparison

bool	string_compare(const string *string_1, const string *string_2);
bool	string_compare_n(const string *string_1, const string *string_2, size_t n);
bool	string_starts_with(const string *str, const char *prefix);
bool	string_ends_with(const string *str, const char *suffix);

// Search

ssize_t	string_find(const string *str, const char *substr);
ssize_t	string_rfind(const string *str, const char *substr);
ssize_t string_find_first_of(const string *str, const char *char_set);
ssize_t string_find_last_of(const string *str, const char *char_set);


// Utility

string	*string_to_upper(string *str);
string	*string_to_lower(string *str);
string	*string_title(string *str);
string	*string_reverse(string *str);

// Printing

void	string_print(const string *str);

#endif

