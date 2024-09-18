#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_PERSON 1000
#define MAX_LEN 300
#define MAX_FIELD 20

struct person
{
    char *name, *address;
    char *phone, *email, *web;
};
typedef struct person Person;

Person directory[MAX_PERSON];
int n = 0; // 주소록에 저장된 사람의 수

void load_data(char *file_name);
void print_person(Person p);
void list_directory();
void search_directory(char *prefix);
char *trim(char *str);
void add_person(char *name);
Person get_person_info(char *name);
void clear_person(Person p);
void save_directory();

int main()
{
    load_data("address.tsv");
    char command[MAX_FIELD], arguments[MAX_LEN];
    while (1)
    {
        printf("$ ");
        scanf("%s", command);
        if (strcmp(command, "exit") == 0)
            break;
        if (strcmp(command, "list") == 0)
            list_directory();
        else if (strcmp(command, "find") == 0)
        {
            fgets(arguments, MAX_LEN, stdin);
            char *name = trim(arguments);
            if (strlen(name) <= 0)
                continue;
            search_directory(name);
        }
        else if (strcmp(command, "add") == 0)
        {
            fgets(arguments, MAX_LEN, stdin);
            char *name = trim(arguments);
            if (strlen(name) <= 0)
                continue;
            add_person(name);
        }
        else if (strcmp(command, "delete") == 0)
        {
            fgets(arguments, MAX_LEN, stdin);
            char *name = trim(arguments);
            if (strlen(name) <= 0)
                continue;
            delete_person(name);
        }
        else if (strcmp(command, "save") == 0)
        {
            save_directory();
        }
    }
    return 0;
}

char *trim(char *str)
{
    while (*str != '\0' && isspace(*str)) // isspace(): 공백, newline, tab 검출
        str++;
    char *t = str + strlen(str) - 1;
    while (t != str && isspace(*t))
    {
        *t = '\0';
        t--;
    }
    return str;
}

void load_data(char *file_name)
{
    char line[MAX_LEN];
    FILE *fp = fopen(file_name, "r");
    while (fgets(line, MAX_LEN, fp) != NULL)
    {
        if (line[strlen(line) - 1] == '\n')
            line[strlen(line) - 1] = '\0';

        char *token = strtok(line, "\t");
        directory[n].name = strdup(token);

        token = strtok(NULL, "\t");
        directory[n].address = strdup(token);

        token = strtok(NULL, "\t");
        directory[n].phone = strdup(token);

        token = strtok(NULL, "\t");
        directory[n].email = strdup(token);

        token = strtok(NULL, "\t");
        directory[n++].web = strdup(token);
    }
    fclose(fp);
}

void print_person(Person p)
{
    printf("%s:\n", p.name);
    printf(" Address: %s\n", p.address);
    printf(" Phone: %s\n", p.phone);
    printf(" Email: %s\n", p.email);
    printf(" Web: %s\n", p.web);
}

void list_directory()
{
    for (int i = 0; i < n; i++)
    {
        print_person(directory[i]);
    }
}

void search_directory(char *prefix) // 접두어 비교
{
    for (int i = 0; i < n; i++)
    {
        if (strncmp(directory[i].name, prefix, strlen(prefix)) == 0) // strncmp(): 문자열에서 n개의 글자를 떼어서 비교하는 함수
            print_person(directory[i]);
        else if (strncmp(directory[i].name, prefix, strlen(prefix)) > 0)
            break;
    }
}

void add_person(char *name)
{
    Person p = get_person_info(name);
    int i = n - 1;
    while (i >= 0 && strcmp(name, directory[i].name) < 0)
    {
        directory[i + 1] = directory[i];
        i--;
    }
    directory[i + 1] = p;
    n++;
}

Person get_person_info(char *name)
{
    Person p;
    char buf[MAX_LEN];
    p.name = strdup(name);

    printf(" Address: ");
    fgets(buf, MAX_LEN, stdin);
    p.address = strdup(trim(buf));

    printf(" Phone: ");
    fgets(buf, MAX_LEN, stdin);
    p.phone = strdup(trim(buf));

    printf(" Email: ");
    fgets(buf, MAX_LEN, stdin);
    p.email = strdup(trim(buf));

    printf(" Web: ");
    fgets(buf, MAX_LEN, stdin);
    p.web = strdup(trim(buf));

    return p;
}

void delete_person(char *name)
{
    char answer[10];
    for (int i = 0; i < n; i++)
    {
        if (strncmp(directory[i].name, name, strlen(name)) == 0)
        {
            printf("Want to delete '%s'? ", directory[i].name);
            scanf("%s", answer);
            if (strcmp(answer, "yes") == 0 || strcmp(answer, "y") == 0)
            {
                clear_person(directory[i]);
                for (int j = i + 1; j < n; j++)
                {
                    directory[j - 1] = directory[j];
                }
                n--, i--;
            }
        }
        else if (strncmp(directory[i].name, name, strlen(name)) > 0)
            break;
    }
}

void clear_person(Person p) // strdup garbage 삭제
{
    free(p.name);
    free(p.address);
    free(p.phone);
    free(p.email);
    free(p.web);
}

void save_directory()
{
    FILE *fp = fopen("address.tsv", "w");       // 기존에 있던 파일은 삭제 후 다시 생성됨
    for (int i = 0; i < n; i++)
        fprintf(fp, "%s\t%s\t%s\t%s\t%s\n", directory[i].name, directory[i].address,
                directory[i].phone, directory[i].email, directory[i].web);
    fclose(fp);
}