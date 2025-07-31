#include <stdio.h>
#include <stdlib.h>
#include "record.h"
#include "auth.h"



int main() {
    int choice, num_records;
    Student s;

    if (!authenticate_user()) {
        printf("Exiting the program...\n");
        return 0;
    }

    printf("Enter the number of student records to input: ");
    scanf("%d", &num_records);

    for (int i = 0; i < num_records; i++) {
        printf("\nEnter details for Student %d:\n", i + 1);
        input_student_details(&s);
        calculate_results(&s);
        save_to_file(&s, i == 0);  
        display_student_report(s);
    }

    append_table_footer();  
    while (1) {
        printf("\nMenu:\n");
        printf("1. Display previous records\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n1. Display all records\n");
                printf("2. Display a specific record by Roll No\n");
                printf("Enter your choice: ");
                int sub_choice;
                scanf("%d", &sub_choice);

                switch (sub_choice) {
                    case 1:
                        display_all_records();
                        break;
                    case 2:
                    {
                        int roll_no;
                        printf("Enter Roll No: ");
                        scanf("%d", &roll_no);
                        int found = display_specific_record(roll_no);
                        if (!found) {
                            printf("Record with Roll No %d not found.\n", roll_no);
                        }
                    }
                    break;
                    default:
                        printf("Invalid choice. Try again.\n");
                        break;
                }
                break;
            case 2:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
