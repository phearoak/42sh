/*
** EPITECH PROJECT, 2020
** minishell.h
** File description:
** include
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>
#include <ncurses.h>
#include <gobblings.h>
#include <backticks.h>
#include <history.h>
#include <time.h>
#include <variables.h>
#include <line_edit.h>
#include <alias.h>
#include <builtins.h>
#include <line_termios.h>
#include <foreach.h>

#ifndef __MINISHELL_H__
#define __MINISHELL_H__

typedef struct argv_s argv_t;
typedef struct list_sh_s list_sh_t;
typedef struct shell_s shell_t;
typedef struct var_s var_t;
typedef struct alias_s alias_t;
typedef struct job_control_s job_control_t;

struct var_s
{
    char *name;
    char *value;
    var_t *next;
};

struct alias_s
{
    char *name;
    char *value;
    alias_t *next;
};

struct argv_s {
    char *word;
    argv_t *next;
};

struct list_sh_s {
    char *command;
    int separator;
    char *file;
    int *pipes;
    int *save_pipes;
    list_sh_t *next;
};

struct job_control {
    int pid;
    int background;
    job_control_t *next;
};

struct shell_s {
    int check;
    int check_error;
    char *to_swap_cmd;
    char *unavailable;
    int exclamation_use;
    list_history_t *history;
    list_history_t *reverse;
    job_control_t *job;
    var_t *vars;
    alias_t *alias;
    WINDOW *window;
    char *save;
    char **env;
    int tab;
    int ncurse;
    int ignoreeof;
    char *init_path;
};

void get_line_before(shell_t *shell);
void get_line_after(shell_t *shell, int ncurses);
int execute_line_after(list_sh_t **cmd, shell_t *shell);
int execute_line_parent(list_sh_t **cmd, shell_t *shell);
int execute_line_before(list_sh_t **cmd, shell_t *shell);
char *get_command_line(char *str);
void do_line_before(list_sh_t **list, shell_t *shell, char *line);
int is_separator(char c);
int strlen_command(char *str, int i);
char **get_argv_line(char *str);
int execute_command_path_a(char *path, char **argv, shell_t *shell, \
list_sh_t **cmd);
int execute_command_path_b(char *path, char **argv, shell_t *shell, \
list_sh_t **cmd);
int execute_command_path_p(char *path, char **argv, shell_t *shell, \
list_sh_t **cmd);
char *find_path(char **path, char *command);
char **get_inhibitors(char **argv);
char **get_path(char **env);
void do_command_exit(int option);
int check_execute_command(char *command, char **argv, shell_t *shell);
int do_command_env(char **env);
int do_command_unsetenv(char **argv, char ***env);
int do_command_setenv(char **argv, char ***env);
int do_command_binary(shell_t *shell, char *path, char **argv);
int command_not_exist(char *command);
int count_str(char **array);
int do_command_cd(char **argv, char ***env);
int command_handling(char *command);
int env_exist(char *var, char **env);
char *get_value_env(char *var, char **env);
char *get_home(int i, char *error, char **env);
int is_dir(char *path);
int do_cd_indirect(char *path, char ***env);
void cd_to_setenv(char *var, char *value, char ***env);
int get_list_sh_command(char *line, list_sh_t **list);
void check_parent_redirection(list_sh_t *cmd, int *pipes);
void check_child_redirection(list_sh_t *cmd, int *pipes);
int *check_create_pipes(list_sh_t *cmd);
char *dup_min_max(char *str, int start, int end);
void list_sh_push_back(list_sh_t **list, char *cmd, int op, char *file);
void sort_sh_command(char **array);
int check_if_command(char c);
char **split_sh_command(char *str);
int do_command_echo(char **argv);
int check_flag(char **argv, char flag);
int get_line_parent(char *line, shell_t *shell);
void check_command_exit(int check, int *exit, int separator, int type);
void jump_command_until_semicolon(list_sh_t **list);
int check_exit_and_or(int *check, int *check_exit, list_sh_t **list);
void jump_parent_with_index(char *str, int *index);
void jump_separator_in_str(char **str);
void jump_command_in_str(char **str);
void jump_parent_in_str(char **str);
void jump_space_in_str(char **str);
int handle_segfault_binary(int status, int waiting);
void exec_failed(char *path);
void check_child_redirection_next(list_sh_t *cmd);
int do_command_parent(char **argv , shell_t *shell);
char **get_argv(char **argv, char **all_path, shell_t *shell);
int exec_builtin_command(char *command, char **argv, shell_t *shell, \
list_sh_t **cmd);
int do_cd_direct(char *path, char ***env);
void reset_pipes(list_sh_t *cmd);
int run_scripting(shell_t *shell, char *path, char **argv, int is_exec);
void parse_script(shell_t *shell, char **script, char *filepath, int is_exec);
int parse_if(shell_t *shell, char **script, int *y);
int do_if(shell_t *shell, char *line);
int parse_conditions(shell_t *shell, char *line);
int check_incompatible_binary(char *path, int status);
int check_segfault(int status, int waiting);
int check_wrong_pipes(char **array);
void do_redirection_double_left(list_sh_t *cmd, int *pipes);
void jump_quote_with_index(char *str, int *index);
void jump_quote_in_str(char **str);
void jump_special_char_in_command(char *str, int *index, int command);
void change_str_command_redirect(char **command, char *file);
char **add_str_at_index(char **array, char *str, int index);
char **check_add_str_for_redirection(char **array);
int check_space_before_redirect(char **array, int i);

/* history */
char *check_command_exclamation(char *line, shell_t *shell);
int check_execute_exclamations(char *line, shell_t *shell);
int do_command_history(shell_t *shell, char *command, char **argv);
int check_exclamation_exist(shell_t *shell, char *line, int index);
void event_not_found(shell_t *shell);
int check_exclamation_double(list_history_t *rev, shell_t *shell, char *cmd);
int check_exclamation_global(list_history_t *rev, shell_t *shell, char *cmd);
int check_exclamation_str(list_history_t *rev, shell_t *shell, char *cmd);
int check_exclamation_number(list_history_t *hist, list_history_t *rev,
shell_t *shell, int index);
int get_command_negatif(list_history_t *reverse, shell_t *shell, int index);
int get_command_positif(list_history_t *history, shell_t *shell, int index);
int get_command_str(list_history_t *reverse, shell_t *shell, char *cmd);
int get_command_global(list_history_t *reverse, shell_t *shell, char *cmd);
void add_command_in_history(shell_t *shell, char *command, int *index);

#endif