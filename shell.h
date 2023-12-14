#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;




/* path.c */
int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);

/* loophsh.c */
int loophsh(char **);

/* err_string_functions.c */
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/* string_functions.c */
int _strleng(char *);
int _strc(char *, char *);
char *starts_w(const char *, const char *);
char *_strccat(char *, char *);

/* string_functions2.c */
char *_strcopy(char *, char *);
char *_strdpl(const char *);
void _puts(char *);
int _putchar(char);

/* string_functions3.c */
char *_strncopy(char *, char *, int);
char *_strnccat(char *, char *, int);
char *_strch(char *, char);

/* string_functions4.c */
char **strw(char *, char *);
char **strw2(char *, char);

/* memory_functions */
char *_memoset(char *, char, unsigned int);
void ssfree(char **);
void *_rlloc(void *, unsigned int, unsigned int);

/* memory_functions2.c */
int pofree(void **);

/* more_functions.c */
int interact(info_t *);
int if_delim(char, char *);
int _ifalpha(int);
int _atoi(char *);

/* more_functions2.c */
int _eratoi(char *);
void error_print(info_t *, char *);
int print_dec(int, int);
char *nconv(long int, int, int);
void rm_comment(char *);


/* hsh.c */
int hsh(info_t *, char **);
int fbuiltin(info_t *);
void fcmd(info_t *);
void fork_com(info_t *);





/* builtin_emulators.c */
int _mexit(info_t *);
int _mcd(info_t *);
int _mhelp(info_t *);

/* builtin_emulators2.c */
int _myhistory(info_t *);
int _myalias(info_t *);

/* getline.c module */
ssize_t get_inp(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHand(int);

/* info.c module */
void c_info(info_t *);
void st_info(info_t *, char **);
void fr_info(info_t *, int);

/* env.c module */
char *_getenv(info_t *, const char *);
int _menv(info_t *);
int _msetenv(info_t *);
int _munsetenv(info_t *);
int pop_env_list(info_t *);

/* env2.c module */
char **get_envi(info_t *);
int _unsetenvi(info_t *, char *);
int _setenvi(info_t *, char *, char *);

/* file_io_functions.c */
char *get_history(info_t *info);
int w_history(info_t *info);
int r_history(info_t *info);
int history_list(info_t *info, char *buf, int linecount);
int renum_history(info_t *info);

/* liststr.c module */
list_t *add_nd(list_t **, const char *, int);
list_t *add_nd_end(list_t **, const char *, int);
size_t print_liststr(const list_t *);
int del_nd_index(list_t **, unsigned int);
void f_list(list_t **);

/* liststr2.c module */
size_t list_leng(const list_t *);
char **list_to_str(list_t *);
size_t p_list(const list_t *);
list_t *node_starts_w(list_t *, char *, char);
ssize_t get_nd_index(list_t *, list_t *);

/* chain.c */
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);






/**
 *struct passinfo - contains pseudo-arguements to pass into a function,
 *					allowing uniform prototype for function pointer struct
 *@arg: a string generated from getline containing arguements
 *@argv: an array of strings generated from arg
 *@path: a string path for the current command
 *@argc: the argument count
 *@line_count: the error count
 *@err_num: the error code for exit()s
 *@linecount_flag: if on count this line of input
 *@fname: the program filename
 *@env: linked list local copy of environ
 *@environ: custom modified copy of environ from LL env
 *@history: the history node
 *@alias: the alias node
 *@env_changed: on if environ was changed
 *@status: the return status of the last exec'd command
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: the fd from which to read line input
 *@histcount: the history line number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;






/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* for convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


#endif
