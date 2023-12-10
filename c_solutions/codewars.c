#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

////////////// Match the end of a string //////////////////////

// bool solution(const char *string, const char *ending) {
//     int match_count = 0;

//     int ei = strlen(ending) - 1;

//     for (int i = strlen(string) - 1; i >= 0; i--) {
//         if (ei < 0) break; // if ei is less than 0, we've reached the end of
//         the ending string

//         char string_char = string[i];
//         char ending_char = ending[ei];

//         if (string_char == ending_char) {
//             match_count++;
//         }

//         ei--;
//     }
//     return match_count == strlen(ending);
// }

// void test_solution() {
//     bool sol_1 = solution("abc", "bc");
//     bool sol_2 = solution("abc", "d");
//     if (sol_1) printf("\nsol_1 passed\n");
//     if (!sol_2) printf("\nsol_2 passed\n");
// }

////////////// Deadfish //////////////////////

// int count_char(const char *str, char target) {
//     int count = 0;
//     while (*str) { // Loop until the end of the string (null character)
//         if (*str == target) {
//             count++;
//         }
//         str++; // Move to the next character
//     }
//     return count;
// }

// int *parse(const char *program) {
//     int o_count = count_char(program, 'o'), value = 0, vi = 0;
//     int *values = malloc(sizeof(int) * o_count);
//     int *v = values;

//     for (char *p = program; *p; p++) {
//         switch (*p) {
//             case 'i': value++; break;
//             case 'd': value--; break;
//             case 's': value *= value; break;
//             case 'o': *v++ = value; vi++; break;
//         }
//     }

//     return values;
// }

// void test_solution() {
//     int answer_1[2] = {8, 64};
//     int *sol_1 = parse("iiisdoso");

//     if (sol_1[0] == answer_1[0] && sol_1[1] == answer_1[1]) printf("\nsol_1
//     passed\n");

//     free(sol_1);
// }

////////////// Highest and Lowest //////////////////////

// void solution(const char *strnum, char *result) {
//     int high = INT_MIN, low = INT_MAX;

//     char *copy = malloc(strlen(strnum) + 1);
//     strcpy(copy, strnum);

//     char *token = strtok(copy, " ");
//     while (token != NULL) {
//         int num = atoi(token);
//         if (num > high) high = num;
//         if (num < low) low = num;
//         token = strtok(NULL, " ");
//     }

//     sprintf(result, "%d %d", high, low);
// }

// void test_solution() {
//     char result[100];
//     solution("10 2 -1 -20", result);
//     printf("\n%s\n", result);
// }

typedef struct {
    int *data;
    int length, capacity;
} ArrayList;

ArrayList newList(int start_cap) {
    ArrayList list;
    list.data = (int *)malloc(sizeof(int) * start_cap);
    list.length = 0;
    list.capacity = start_cap;
    return list;
}

void push(ArrayList *list, int value) {
    if (list->length == list->capacity) {
        int *temp = (int *)malloc(sizeof(int) * list->capacity * 2);
        memcpy(temp, list->data, sizeof(int) * list->capacity);
        free(list->data);
        list->data = temp;
        list->capacity *= 2;
    }
    list->data[list->length++] = value;
}

int solution(const int values[], size_t count) {
    ArrayList evens = newList(1), odds = newList(1);

    for (int i = 0; i < (int)count; i++) {
        if (values[i] % 2 == 0) {
            push(&evens, values[i]);
        } else {
            push(&odds, values[i]);
        }
    }

    if (evens.length == 1)
        return evens.data[0];
    else if (odds.length == 1)
        return odds.data[0];
    return 0;
}

void test_solution() {
    int values[] = {2, 4, 3, 6, 8};
    int sol = solution(values, 5);
    printf("\n%d\n", sol);
}

int main() {
    test_solution();
    return 0;
}
