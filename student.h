/**
 * This structure contains information representing a student such as their first and last names, their student ID, grades and total number of grades.
 *
 */
typedef struct _student 
{ 
  char first_name[50]; /**< Student's first name*/
  char last_name[50]; /**< Student's last name*/
  char id[11]; /**< The student ID of corresponding student*/
  double *grades; /**< The student's grades*/
  int num_grades; /**< The total number of the student's grades*/
} Student;

void add_grade(Student *student, double grade);
double average(Student *student);
void print_student(Student *student);
Student* generate_random_student(int grades); 
