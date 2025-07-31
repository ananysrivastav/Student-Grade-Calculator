#ifndef RECORD_H
#define RECORD_H

typedef struct {
    int roll_no;
    char name[50];
    int marks[5];
    int total;
    float percentage;
    char grade;
} Student;

void input_student_details(Student* s);
void calculate_results(Student* s);
void save_to_file(Student* s, int write_header);
void display_student_report(Student s);
void display_all_records();
int display_specific_record(int roll);
void append_table_footer();

#endif
