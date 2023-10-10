
//WAP to calculate your CGPA of first two semesters by passing structure to a function.
#include <stdio.h>


struct Semester {
    int numCourses;
    int grades[10];
};


float calculateCGPA(struct Semester semesters[], int numSemesters) {
    float totalCredits = 0;
    float totalGradePoints = 0;

    for (int i = 0; i < numSemesters; i++) {
        for (int j = 0; j < semesters[i].numCourses; j++) {
            totalGradePoints += semesters[i].grades[j];
            totalCredits++;
        }
    }

    return totalGradePoints / totalCredits;
}

int main() {
    int numSemesters = 2; 
    struct Semester semesters[numSemesters];

   
    for (int i = 0; i < numSemesters; i++) {
        printf("Enter the number of courses in semester %d: ", i + 1);
        scanf("%d", &semesters[i].numCourses);

        printf("Enter the grades (as numerical values) for semester %d:\n", i + 1);
        for (int j = 0; j < semesters[i].numCourses; j++) {
            scanf("%d", &semesters[i].grades[j]);
        }
    }

    
    float cgpa = calculateCGPA(semesters, numSemesters);

    
    float finalCGPA = cgpa/9.5;
    printf("Your CGPA for the first two semesters is: %.2f\n", finalCGPA);

    return 0;
}
