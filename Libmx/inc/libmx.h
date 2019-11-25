#ifndef LIBMX_HEADER
#define LIBMX_HEADER

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>
#include <stdio.h> // for test
#include <string.h>
#include <malloc/malloc.h>

// My functions
bool mx_isspace(char c);
bool mx_isdigit(int c);
bool mx_isalpha(int c);
bool mx_islower(int c);
bool mx_isupper(int c);
int mx_tolower(int c);
int mx_toupper(int c);
int mx_strncmp(const char *s1, const char *s2, size_t n);
void mx_printerr(const char *s);
void mx_terminate(char *error_message);
void *mx_memalloc(size_t size);

// Utils pack
void mx_printchar(char c);                                             // ok
void mx_print_unicode(wchar_t c);                                      // ok
void mx_printstr(const char *s);                                       // ok
void mx_print_strarr(char **arr, const char *delim);                   // ok
void mx_printint(int n);                                               // ok
double mx_pow(double n, unsigned int pow);                             // ok
int mx_sqrt(int x);                                                    // ok
char *mx_nbr_to_hex(unsigned long nbr);                                // ok
unsigned long mx_hex_to_nbr(const char *hex);                          // ok
char *mx_itoa(int number);                                             // ok
void mx_foreach(int *arr, int size, void (*f)(int));                   // ok
int mx_binary_search(char **arr, int size, const char *s, int *count); // ok
int mx_bubble_sort(char **arr, int size);                              // ok
int mx_quicksort(char **arr, int left, int right);                     // 20 points !!!

// String pack
int mx_strlen(const char *s);                                                   // ok
void mx_swap_char(char *s1, char *s2);                                          // ok
void mx_str_reverse(char *s);                                                   // ok
void mx_strdel(char **str);                                                     // ok
void mx_del_strarr(char ***arr);                                                // ok
int mx_get_char_index(const char *str, char c);                                 // ok
char *mx_strdup(const char *s1);                                                // ok
char *mx_strndup(const char *s1, size_t n);                                     // ok
char *mx_strcpy(char *dst, const char *src);                                    // ok
char *mx_strncpy(char *dst, const char *src, int len);                          // ok
int mx_strcmp(const char *s1, const char *s2);                                  // ok
char *mx_strcat(char *restrict s1, const char *restrict s2);                    // ok
char *mx_strstr(const char *haystack, const char *needle);                      // ok
int mx_get_substr_index(const char *str, const char *sub);                      // ok
int mx_count_substr(const char *str, const char *sub);                          // 80 points fixed
int mx_count_words(const char *str, char c);                                    // ok
char *mx_strnew(const int size);                                                // ok
char *mx_strtrim(const char *str);                                              // 90 points fixed
char *mx_del_extra_spaces(const char *str);                                     // ok
char **mx_strsplit(const char *s, char c);                                      // 75 points fixed
char *mx_strjoin(const char *s1, const char *s2);                               // ok
char *mx_file_to_str(const char *file);                                         // ok
int mx_read_line(char **lineptr, int buf_size, char delim, const int fd);       // 30 points fixed
char *mx_replace_substr(const char *str, const char *sub, const char *replace); // ok

// Memory pack
void *mx_memset(void *b, int c, size_t len);                                             // ok
void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n);                 // ok
void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n);         // 70 points fixed
int mx_memcmp(const void *s1, const void *s2, size_t n);                                 // 54 points fixed
void *mx_memchr(const void *s, int c, size_t n);                                         // ok
void *mx_memrchr(const void *s, int c, size_t n);                                        // ok
void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len); // 75 points fixed
void *mx_memmove(void *dst, const void *src, size_t len);                                // ok
void *mx_realloc(void *ptr, size_t size);                                                // 70 points fixed

//List pack
typedef struct s_list
{
    void *data;
    struct s_list *next;
} t_list;

t_list *mx_create_node(void *data);                             // ok
void mx_push_front(t_list **list, void *data);                  // ok
void mx_push_back(t_list **list, void *data);                   // ok
void mx_pop_front(t_list **head);                               // 60 points fixed
void mx_pop_back(t_list **head);                                // 0 points fixed
int mx_list_size(t_list *list);                                 // ok
t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)); // 0 points fixed

#endif
