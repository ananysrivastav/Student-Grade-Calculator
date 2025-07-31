#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "record.h"

void input_student_details(Student* s) {
    printf("Enter Roll No: ");
    scanf("%d", &s->roll_no);
    printf("Enter Name: ");
    scanf(" %[^\n]", s->name);
    printf("Enter marks for 5 subjects: ");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &s->marks[i]);
    }
}

void calculate_results(Student* s) {
    s->total = 0;
    for (int i = 0; i < 5; i++) {
        s->total += s->marks[i];
    }
    s->percentage = s->total / 5.0;
    if (s->percentage >= 90)
        s->grade = 'A';
    else if (s->percentage >= 80)
        s->grade = 'B';
    else if (s->percentage >= 70)
        s->grade = 'C';
    else if (s->percentage >= 60)
        s->grade = 'D';
    else
        s->grade = 'F';
}

void save_to_file(Student* s, int write_header) {
    FILE* file = fopen("student_data.txt", "a");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }
    if (write_header) {
        fprintf(file, "---------------------------------------------------------------\n");
        fprintf(file, "| Roll No | Name             | Marks               | Total | %%age  | Grade |\n");
        fprintf(file, "---------------------------------------------------------------\n");
    }

    fprintf(file, "| %-7d | %-16s |", s->roll_no, s->name);
    for (int i = 0; i < 5; i++) {
        fprintf(file, " %3d", s->marks[i]);
    }
    fprintf(file, " | %5d | %5.2f |   %c   |\n", s->total, s->percentage, s->grade);
    fclose(file);
}

void display_student_report(Student s) {
    printf("\nStudent Report:\n");
    printf("Roll No: %d\n", s.roll_no);
    printf("Name: %s\n", s.name);
    printf("Marks: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", s.marks[i]);
    }
    printf("\nTotal: %d\n", s.total);
    printf("Percentage: %.2f\n", s.percentage);
    printf("Grade: %c\n", s.grade);
}

void display_all_records() {
    FILE* file = fopen("student_data.txt", "r");
    if (!file) {
        printf("No records found.\n");
        return;
    }
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);
}

int display_specific_record(int roll) {
    FILE* file = fopen("student_data.txt", "r");
    if (!file) return 0;

    char line[200];
    int found = 0;
    int print_next = 0;

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "Roll No")) 
        print_next = 1;
        if (print_next && strstr(line, "---")) 
        { printf("%s", line); 
        print_next = 2; 
        continue; }

        int r;
        if (line[0] == '|') {
            char roll_str[10];
            strncpy(roll_str, line + 2, 7);
            roll_str[7] = '\0';
            r = atoi(roll_str);
            if (r == roll) {
                if (print_next == 2) 
                printf("%s", line);
                found = 1;
                break;
            }
        }
    }
    fclose(file);
    return found;
}

void append_table_footer() {
    FILE* file = fopen("student_data.txt", "a");
    if (!file) 
    return;
    fprintf(file, "---------------------------------------------------------------\n");
    fclose(file);
}
