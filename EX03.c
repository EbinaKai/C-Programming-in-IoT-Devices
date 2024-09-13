/*
Ex 3.

That asks number of students and creates an array of that many integers.

Program then initializes the array elements to -1.

Then the program asks user to enter student number in range 1 – nr of students or zero to stop. If valid non zero number is given the program asks user to enter grade in the range 0-5 or -1 to not enter a grade for the student.

When user stops by entering 0 then program prints student numbers followed by grade or N/A if grade is -1.
*/

#include <stdio.h>

int input();

int main(void) {
    int num_students, num_student, grade;

    printf("How many students: ");
    num_students = input();

    int students[num_students];

    for (int i = 0; i < num_students; i++) {
        students[i] = -1;
    }

    while (1) {
        printf("Enter student number (1 – %d) or 0 to stop: ", num_students);
        num_student = input();

        if (num_student == 0) {
            break;
        }

        num_student--;
        printf("Enter grade (0 – 5) for student %d or -1 to cancel: ", num_student);
        grade = input();

        if (grade < -1 || grade > 5) {
            printf("Invalid grade\n");
        } else {
            students[num_student] = grade;
        }
    }

    printf("Student Grade\n");
    for (int i = 0; i < num_students; i++) {
        if (students[i] == -1) {
            printf("%-7d N/A\n", i+1);
        } else {
            printf("%-7d %-5d\n", i+1, students[i]);
        }
    }
    return 0;
}

int input() {
    int selection = -0x80000000;
    do {
        if (scanf("%d", &selection) != 1) {
            while(getchar() != '\n') {}
            printf("invalid input\n");
            printf("Please try again: ");
        }
    } while(selection == -0x80000000);
    return selection;
}