#include <stdio.h>
#include <stdlib.h>

typedef enum {
  NAME_ONLY = 0,
  MAJOR_AND_NAME = 1, 
  YEAR_AND_NAME = 2
} Mode;

typedef struct {
  char *first_name;
  char *last_name;
  char *major;
  char *year;
  // TODO: add fields here for major and year
} Student;

void print_student(Mode m, Student s) {
  switch (m) {
    case NAME_ONLY:
      printf("%s %s\n", s.first_name, s.last_name);
      break;
    case MAJOR_AND_NAME:
          printf("%s %s %s\n",s.major, s.first_name, s.last_name);
          break;
    case YEAR_AND_NAME:
          printf("%s %s %s\n", s.year, s.first_name, s.last_name);
          break;
	// TODO: handle other cases
  }
}

/*
	argv[1] will be the Mode integer
	argv[2...] will be student info in the form [first_name, last_name, major, year]
	the fields are all strings (char[])
	except year is a number (int)
*/
int main(int argc, char *argv[]) {
    Student s [argc/4];
    Mode m = (Mode)atof(argv [1]);
    for (int i=0; i<(argc/4); i++)
    {s[i].first_name = argv [i*4+2];
     s[i].last_name = argv [i*4+3];
     s[i].major = argv [i*4+4];
     s[i].year = argv [i*4+5];
     print_student(m, s[i]);
    }
  // TODO: parse argv to populate student structs
  // for now, here's two hardcoded students:
  Student s1, s2;
  s1.first_name = "Julia";
  s1.last_name = "A";
  s2.first_name = "Peter";
  s2.last_name = "Cooper";
  
  print_student(NAME_ONLY, s1);
  print_student(NAME_ONLY, s2);
  return 0;
}
