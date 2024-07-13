#include "ft_string.h"
#include "not_implemented.h"

#define NOT_FOUND ((ssize_t)-1)

typedef struct string {
	char	*data;
	size_t	len;
	size_t	capacity;
} string;

string *string_new(const char *str) {

	if (!str)
		return NULL;

	string *p_string = (string *)malloc(sizeof(string));
	if (!p_string)
		return NULL;
	size_t len = strlen(str);
	size_t new_capacity = len + 1;
	p_string->data = (char *)malloc(new_capacity);
	memcpy(p_string->data, str, len);
	p_string->len = len;
	p_string->data[p_string->len] = '\0';
	p_string->capacity = new_capacity;
	return p_string;
}

string	*string_copy(const string *str) {
	string	*copy;

	copy = string_new(str->data);
	return copy;
}

string	*string_new_empty(size_t capacity) {
	string *str = string_new("");
	string_reserve(str, capacity);
	memset(str->data, '\0', str->capacity);
	return str;
}

string	*string_substring(const string *str, size_t pos, size_t len) {

	if (pos >= str->len) {
		fprintf(stderr, "Index out of bounds\n");
		return NULL;
	}

	if (len >= str->len - pos) {
		len = str->len - pos;
	}

	string	*new_str = string_new_empty(len + 1);
	memcpy(new_str->data, &str->data[pos], len);
	new_str->len = len;
	return new_str;
}


void	string_print(const string *str) {
	printf("%s", str->data);
}

void	string_free(string *str) {
	if (str) {
		free(str->data);
		str->data = NULL;
		free(str);
	}
}

size_t	string_length(const string *str) {
	return str->len;
}

size_t	string_capacity(const string *str) {
	return str->capacity;
}

bool	string_empty(const string *str) {
	return (str->len == 0);
}

void	string_clear(string *str) {
	memset(str->data, 0, str->len);
	str->len = 0;
}

char	string_at(const string *str, size_t index) {
	if (index >= str->len) {
		fprintf(stderr, "Index out of bounds\n");
		return (str->data[str->len]);
	}
	return str->data[index];
}

char	string_back(const string *str) {
	return string_at(str, str->len - 1);
}

char	string_front(const string *str) {
	return string_at(str, 0);
}

string	*string_append(string *str, const char *value) {
	size_t value_len = strlen(value);
	size_t new_len = str->len + value_len;
	if (new_len >= str->capacity)
		string_resize(str, new_len);

	memcpy(&str->data[str->len], value, value_len);
	str->len = new_len;
	str->data[str->len] = '\0';
	return str;
}

string *string_push_back(string *str, char c) {

	size_t new_len = str->len + 1;

	if (new_len >= str->capacity) {
		string_resize(str, new_len);
	}
	str->data[str->len] = c;
	str->len = new_len;
	str->data[str->len] = '\0';
	return (str);
}

void	string_resize(string *str, size_t new_len) {

	if (str->len == new_len && str->capacity == str->len + 1) {
		fprintf(stderr, "String length is already %zu", str->len);
		return ;
	}
	size_t	new_capacity = new_len + 1;
	char	*new_str = (char *)realloc(str->data, new_capacity);
	if (!new_str) {
		fprintf(stderr, "Failed to allocate memory");
		return ;
	}

	str->data = new_str;
	if (new_len > str->len) {
		memset(&str->data[str->len], '\0', new_len - str->len);
	}
	str->capacity = new_capacity;
}

void	string_resize_set(string *str, size_t new_len, char c) {

	if (str->len == new_len && str->capacity == str->len + 1) {
		fprintf(stderr, "String length is already %zu", str->len);
		return ;
	}
	size_t	new_capacity = new_len + 1;
	char	*new_str = (char *)realloc(str->data, new_capacity);
	if (!new_str) {
		fprintf(stderr, "Failed to allocate memory");
		return ;
	}

	str->data = new_str;
	if (new_len > str->len) {
		memset(&str->data[str->len], c, new_len - str->len);
	}
	if (c != '\0')
		str->len = new_len;
	str->data[str->len] = '\0';
	str->capacity = new_capacity;
}

string	*string_shrink_fit(string *str) {
	string_resize(str, str->len);
	str->len = strlen(str->data);
	str->data[str->len] = '\0';
	return (str);
}

void	string_swap(string **str1, string **str2) {
	string *tmpstr;

	tmpstr = *str1;
	*str1 = *str2;
	*str2 = tmpstr;
}

void	string_erase(string *str, size_t pos, size_t len) {

	if (pos >= str->len) {
		fprintf(stderr, "Index out of bounds\n");
		return ;
	}

	if (len > str->len - pos)
		len = str->len - pos;
	size_t bytes_left = str->len - (len + pos);
	memmove(&str->data[pos], &str->data[pos + len], bytes_left);
	memset(&str->data[pos + bytes_left], '\0', len);
	str->len -= len;
}

string	*string_insert(string *str, size_t pos, const char *value) {
	if (value == NULL)
		return str;

	if (pos > str->len) {
		fprintf(stderr, "Index out of bounds\n");
		return str;
	}

	size_t value_len = strlen(value);
	size_t new_len = str->len + value_len;
	if (new_len >= str->capacity) {
		string_resize(str, new_len);
	}
	memmove(&str->data[pos + value_len], &str->data[pos], str->len - pos);
	memcpy(&str->data[pos], value, value_len);
	str->len = new_len;
	str->data[new_len] = '\0';
	return str;
}

string	*string_trim(string *str) {

	size_t	from_end = str->len - 1;
	size_t	from_front = 0;
	size_t	new_len;

	while (from_front < str->len && isspace((unsigned char)str->data[from_front]))
		from_front++;

	while (from_end > from_front && isspace((unsigned char)str->data[from_end]))
		from_end--;
	new_len = (from_end + 1) - from_front;
	memmove(&str->data[0], &str->data[from_front], new_len);
	str->len = new_len;
	str->data[str->len] = '\0';
	return str;
}

string	*string_replace(string *str, size_t pos, const char *value) {

	if (!str)
		return NULL;

	if (!value)
		return str;

	size_t value_len = strlen(value);
	size_t new_len = str->len + value_len;
	if (new_len >= str->capacity)
		string_resize(str, str->len + value_len);

	memcpy(&str->data[pos], value, value_len);
	str->len = new_len;
	str->data[new_len] = '\0';
	return str;
}

string	*string_replace_len(string *str, size_t pos, size_t len, const char *value) {

	if (!str)
		return NULL;

	if (!value)
		return str;

	size_t value_len = strlen(value);
	if (len > value_len)
		len =value_len;
	size_t new_len = str->len + len;
	if (new_len >= str->capacity)
		string_resize(str, new_len);

	memcpy(&str->data[pos], value, len);
	str->len = new_len;
	str->data[new_len] = '\0';
	return str;
}

char	*string_c_string(const string *str) {
	return str->data;
}

void	string_reserve(string *str, size_t bytes) {
	string_resize(str, bytes - 1);
}

bool	string_compare(const string *string_1, const string *string_2) {
	if (!strcmp(string_1->data, string_2->data))
		return true;
	return false;
}

bool	string_compare_n(const string *string_1, const string *string_2, size_t n) {
	if (!strncmp(string_1->data, string_2->data, n))
		return true;
	return false;
}

bool	string_starts_with(const string *str, const char *prefix) {
	if (!prefix)
		return false;
	if (!strncmp(str->data, prefix, strlen(prefix)))
		return true;
	return false;
}

bool	string_ends_with(const string *str, const char *suffix) {
	if (!suffix)
		return false;

	size_t	suffix_len = strlen(suffix);
	char	*str_end_ptr = &str->data[str->len - suffix_len];
	if (!strcmp(str_end_ptr, suffix))
		return true;
	return false;
}

string	*string_to_upper(string *str) {
	for (int i = 0; i < str->len; ++i) {
		if (isalpha(str->data[i]) && islower(str->data[i])) {
			str->data[i] -= 32;
		}
	}
	return str;
}


string	*string_to_lower(string *str) {
	for (int i = 0; i < str->len; ++i)
		if (isalpha(str->data[i]) && isupper(str->data[i]))
			str->data[i] += 32;
	return str;
}

string	*string_title(string *str) {
	bool	capitalize = true;

	for (int i = 0; i < str->len; ++i) {
		if (capitalize && isalpha(str->data[i]) && islower(str->data[i])) {
			capitalize = false;
			str->data[i] -= 32;
		}
		else if (!capitalize && isspace(str->data[i]))
			capitalize = true;
	}
	return str;
}

ssize_t	string_find(const string *str, const char *substring) {
	if (!substring)
		return NOT_FOUND;

	char	*find_ptr = strstr(str->data, substring);
	if (find_ptr)
		return (find_ptr - str->data);
	return (NOT_FOUND);
}

ssize_t	string_rfind(const string *str, const char *substring) {
	if (!substring)
		return NOT_FOUND;

	char	*p_str_end = &str->data[str->len];
	char	*p_find;
	while (p_str_end != str->data) {
		p_find = strstr(p_str_end, substring);
		if (p_find)
			return (p_find - str->data);
		p_str_end--;
	}
	return (NOT_FOUND);
}

string	*string_reverse(string *str) {
	size_t	j = 0;
	char	buffer[str->len];
	for (size_t i = str->len; i > 0; i--) {
		buffer[j++] = str->data[i - 1];
	}
	buffer[j] = '\0';
	memcpy(str->data, buffer, str->len);
	return str;
}

ssize_t string_find_first_of(const string *str, const char *char_set) {

	if (!char_set)
		return NOT_FOUND;

	size_t	chars_len = strlen(char_set);

	for (size_t i = 0; i < chars_len; i++) {
		char *found = strchr(str->data, (unsigned char)char_set[i]);
		if (found)
			return (found - str->data);
	}
	return NOT_FOUND;
}

ssize_t string_find_last_of(const string *str, const char *char_set) {

	if (!char_set)
		return NOT_FOUND;

	size_t	chars_len = strlen(char_set);

	for (size_t i = 0; i < chars_len; i++) {
		char *found = strrchr(str->data, (unsigned char)char_set[i]);
		if (found)
			return (found - str->data);
	}

	return NOT_FOUND;
}
