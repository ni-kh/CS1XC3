#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

/**
 * @brief Adds the given grade to the given student's marks list.
 *
 * @param student The given student.
 * @param grade The given grade.
 */
void add_grade(Student* student, double grade)
{
  student->num_grades++;
  if (student->num_grades == 1) student->grades = calloc(1, sizeof(double)); 
  /*^^Calloc is used here because memory space only needs to be allocated to 1 item. 
  Past 1 item, realloc should be used to expand on the previously allocated memory, which it is below.*/
  else 
  {
    student->grades = 
      realloc(student->grades, sizeof(double) * student->num_grades);
  }
  student->grades[student->num_grades - 1] = grade;
}

/**
 * @brief Calculates the average mark of the given student.
 *
 * @param student The given student.
 *
 * @return The real value of the calculated average.
 */
double average(Student* student)
{
  if (student->num_grades == 0) return 0;

  double total = 0;
  for (int i = 0; i < student->num_grades; i++) total += student->grades[i];
  return total / ((double) student->num_grades);
}

/**
 * @brief Prints the details of the given student.
 *
 * @param student The given student.
 */
void print_student(Student* student)
{
  printf("Name: %s %s\n", student->first_name, student->last_name);
  printf("ID: %s\n", student->id);
  printf("Grades: ");
  for (int i = 0; i < student->num_grades; i++) 
    printf("%.2f ", student->grades[i]);
  printf("\n");
  printf("Average: %.2f\n\n", average(student));
}

/**
 * @brief Generates random students based on the provided information (i.e. provided first names,
 * last names and etc.).
 *
 * @param grades Determines how many grades a randomly generated student should have.
 *
 * @return List of generated students.
 */
Student* generate_random_student(int grades)
{
  char first_names[][24] = 
    {"Shahrzad", "Leonti", "Alexa", "Ricardo", "Clara", "Berinhard", "Denzel",
     "Ali", "Nora", "Malcolm", "Muhammad", "Madhu", "Jaiden", "Helena", "Diana",
     "Julie", "Omar", "Yousef",  "Amir", "Wang", "Li", "Zhang", "Fen", "Lin"};

  char last_names[][24] = 
   {"Chen", "Yang", "Zhao", "Huang", "Brown", "Black", "Smith", "Williams", 
    "Jones", "Miller", "Johnson", "Davis", "Abbas", "Ali", "Bakir", "Ismat", 
    "Khalid", "Wahed", "Taleb", "Hafeez", "Hadid", "Lopez", "Gonzalez", "Moore"};
 
  Student *new_student = calloc(1, sizeof(Student));

  strcpy(new_student->first_name, first_names[rand() % 24]);
  strcpy(new_student->last_name, last_names[rand() % 24]);

  for (int i = 0; i < 10; i++) new_student->id[i] = (char) ((rand() % 10) + 48);
  new_student->id[10] = '\0';
  //^^This for-loop is adding a NULL character to the end of all of the assigned strings to determine when each word ends.

  for (int i = 0; i < grades; i++) 
  {
    add_grade(new_student, (double) (25 + (rand() % 75)));
  }
  //^^Here, this for-loop is randomly adding some marks onto students' marks.
  return new_student;
}
