//
// Created by admin on 2023-03-06.
//

#ifndef ASSIGN02_STUDENT_H
#define ASSIGN02_STUDENT_H
#include <string>
#include <iostream>

using namespace std;

class Student{
private:
    std::string name;
    int numOfCourses = 1;
    std::string *courseList = new std::string [numOfCourses]; // will get allocated as soon as instanciate student obj

public:
    Student() = default; // default

    Student(std::string name); // constructor with args


    // copy constructor
    Student(Student& stud); // taking a student obj reference

    // Move Constructor
    Student(Student&& stud) = default; // moving obj to new memory location

    // destructor
    ~Student();


    // Getter and Setter for students Name

    void setName(std::string name);

    std::string getName() const;

    // Getter and Setter for NumOfCourses
    void setNumOfCourses(int numOfCourses);
    int getNumOfCourses() const;


    // Setter for adding a course
    std::string* getCourseList() const {return this->courseList;};

    void addCourse(std::string course);

    void increaseCourseCount();


    // Method to reset Course count
    void resetCourses();


    // Friend Functions have access to its private members and print them out
    friend std::ostream& operator << (std::ostream& osStream, const Student stud)
    {
        osStream<<"Student Name: " + stud.getName() + "\nNumber of Courses: " + std::to_string(stud.getNumOfCourses() -1) + "\nCourse List: ";
        for(int i = 0; i < stud.numOfCourses - 1; i++)
        {
            osStream<<"\nCourse #" << (i+1) << ": " << stud.getCourseList()[i];
        }

        return osStream;
    };

    // Assignment operator overload. Deep Copy
    Student& operator = (const Student& stud2) // taking in a student obj
    {
        std::string *tempArray = new std::string[stud2.numOfCourses];

        name = stud2.name;
        numOfCourses = stud2.numOfCourses;

        // copying over stud2 course list to tempArray
        std::copy(stud2.courseList, stud2.courseList + stud2.numOfCourses, tempArray);

        // deleting courseList contents encase its populated
        delete[] courseList;
        courseList = tempArray;
    }

};

#endif //ASSIGN02_STUDENT_H
