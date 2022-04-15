#include "student.h"
#include <stdbool.h>

/**
 * This structure contains the name of a course, its code, the students taking the course as well as the total number of students registered in the course.
 *
 */
typedef struct _course 
{
  char name[100]; /**< The name of the corresponding course*/
  char code[10]; /**< The code for this course*/
  Student *students; /**< Array containing all students who are taking this course*/
  int total_students; /**< Total number of students taking the corresponding course*/
} Course;

void enroll_student(Course *course, Student *student);
void print_course(Course *course);
Student *top_student(Course* course);
Student *passing(Course* course, int *total_passing);


