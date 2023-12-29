// Lesson 15 2
#include <iostream>

struct Student
{
    std::string name;
    unsigned age = 0;
    unsigned markForMath = 60;
    unsigned markForProg = 60;
    unsigned markForBio = 60;
    float averageEvaluation = 0.f;
};

float averageEvaluation(Student *st) {
    float mark = 0.f;
    const int amountOfSubject = 3;
    mark = (st->markForMath + st->markForProg + st->markForBio) / amountOfSubject;

    return mark;
}

void sortingStudentsByAverageEvaluation(Student* st, const int size) {
    Student tmpStudent;

    for (int k = 0; k < size - 1; k++) {
        for (int i = 0; i < size - 1 - k; i++) {
            if (st[i].averageEvaluation > st[i + 1].averageEvaluation) {
                tmpStudent = st[i];
                st[i] = st[i + 1];
                st[i + 1] = tmpStudent;
            }
        }
    }
}

Student* findTheBestStudent(Student* st, const int size) {
    Student* bestStudent = nullptr;
    float maxEvaluation = 0.f;

    for (int i = 0; i < size; i++) {
        if (st[i].averageEvaluation > maxEvaluation) {
            maxEvaluation = st[i].averageEvaluation;
            bestStudent = &st[i];
        }
    }
    return bestStudent;
}

int coutSuccessedStudents(Student* st, const int size) {
    const int successCeiling = 75;
    int counter = 0;
    for (int i = 0; i < size; i++) {
        if (st[i].averageEvaluation > successCeiling) {
            counter++;
        }
    }
    return counter;
}

int main()
{
    const int SIZE = 5;
    Student students[SIZE] = {
        {"Piter", 20, 10, 20, 30, 0.f},
        {"Lana", 19, 90, 60, 90, 0.f},
        {"Denis", 22, 20, 30, 40, 0.f},
        {"Marko", 20, 50, 20, 30, 0.f},
        {"John", 21, 80, 80, 70, 0.f} };

    srand(time(nullptr));
    for (int i = 0; i < SIZE; i++) {
        students[i].averageEvaluation = averageEvaluation(&students[i]);

        std::cout << "Evaluation of Mathematic = " << students[i].markForMath << std::endl;
        std::cout << "Evaluation of Programming = " << students[i].markForProg << std::endl;
        std::cout << "Evaluation of Biology = " << students[i].markForBio << std::endl;
        std::cout << "------------------------------" << std::endl;
        std::cout << "Average evaluation for student = " << students[i].averageEvaluation << std::endl;
        std::cout << std::endl << std::endl;
    }


    std::cout << "Sorted students by average evaluation:" << std::endl;
    sortingStudentsByAverageEvaluation(students, SIZE);
    for (int i = 0; i < SIZE; i++) {
        std::cout << "["<< i + 1 << "] " << students[i].name << " average = " << students[i].averageEvaluation  << std::endl;
    }
    std::cout << std::endl << std::endl;

    std::cout << "The Best student is: " << findTheBestStudent(students, SIZE)->name << std::endl;
    std::cout << std::endl << std::endl;

    std::cout << "Amount of Success Students: " << coutSuccessedStudents(students, SIZE) << std::endl;


}