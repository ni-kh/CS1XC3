#include "course.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief This function enrolls a student in a course.
 *
 * @param course The course that the given 'student' wants to enroll in.
 * @param student The student who wants to enroll.
 */
void enroll_student(Course *course, Student *student)
{
  course->total_students++;
  if (course->total_students == 1) 
  {
    course->students = calloc(1, sizeof(Student)); //Calloc is used here because there is only 1 student to locate in memory.
  }
  else 
  {
    course->students = 
      realloc(course->students, course->total_students * sizeof(Student)); 
      /*Here, instead of calloc, realloc must be used because there has already been memory space filled up 
      by 1 student before. This is just going to add more students on top of that in the same memory location.*/
  }
  course->students[course->total_students - 1] = *student;
}

/**
 * @brief Prints the details of any given course.
 *
 * @param course The given course.
 */
void print_course(Course* course)
{
  printf("Name: %s\n", course->name);
  printf("Code: %s\n", course->code);
  printf("Total students: %d\n\n", course->total_students);
  printf("****************************************\n\n");
  for (int i = 0; i < course->total_students; i++) 
    print_student(&course->students[i]);
}

/**
 * @brief Finds the most talented student based on his/her mark in the given course.
 *
 * @param course The given course.
 *
 * @return Pointer to the student found.
 */
Student* top_student(Course* course)
{
  if (course->total_students == 0) return NULL; 
 
  double student_average = 0;
  double max_average = average(&course->students[0]);
  Student *student = &course->students[0];
 
  for (int i = 1; i < course->total_students; i++)
  {
    student_average = average(&course->students[i]);
    if (student_average > max_average) 
    {
      max_average = student_average;
      student = &course->students[i];
    }   
  } 
  //^^To find the top student, this for-loop is used to iterate through all items.
  return student;
}

/**
 * @brief Finds the students who pass the given course.
 *
 * @param course The given course.
 * @param total_passing Size of students found. Will be set inside this function.
 *
 * @return A list of students found.
 */

Student *passing(Course* course, int *total_passing)
{
  int count = 0;
  Student *passing = NULL;
  
  for (int i = 0; i < course->total_students; i++) 
    if (average(&course->students[i]) >= 50) count++;
  
  passing = calloc(count, sizeof(Student)); //Allocates memory to the number of 'count'.

  int j = 0;
  for (int i = 0; i < course->total_students; i++)
  {
    if (average(&course->students[i]) >= 50)
    {
      passing[j] = course->students[i];
      j++; 
    }
  }

  *total_passing = count;

  return passing;
}
