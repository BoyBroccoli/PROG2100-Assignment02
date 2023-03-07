//
// Created by admin on 2023-03-06.
//
#include "../inc/Student.h"



// Constructor
Student::Student(string name) {
    std::cout<<"CONSTRUCTOR CALLED"<<endl;
    this->name = name;
}


// Copy Constructor
Student::Student(Student &stud)
{
    operator=(stud);
    std::cout<< "COPY CONSTRUCTOR CALLED"<<endl;
}


// Destructor
Student::~Student()
{
    if(this->courseList == nullptr)
    {
        delete[] this->courseList;
    }

    std::cout<<"DESTRUCTOR CALLED!"<<endl;
}


// Getter and Setter for name
std::string Student::getName() const
{
    return name;
}

void Student::setName(std::string name)
{
    this->name = name;
}

// Getter and Setter for numOfCourses
int Student::getNumOfCourses() const
{
    return numOfCourses;
}

void Student::setNumOfCourses(int numOfCourses)
{
    this->numOfCourses = numOfCourses;
}

void Student::increaseCourseCount()
{
    this->numOfCourses++;
}

// method to resetCourses and delete elements
void Student::resetCourses()
{
    this->numOfCourses=1;
    delete[] courseList;
}

// For dynamic array
void Student::addCourse(std::string course)
{
    // dynamically resize the array
    std::string *tempArray = new std::string [numOfCourses +1]; // temp array to hold our course list

    // adding course to courseList first
    this->courseList[numOfCourses - 1] = course; // adding course to first index

    // loop to copy over to tempArray
    for(int i= 0; i< numOfCourses; i++)
    {
        tempArray[i] = this->courseList[i];
    }

    // deleting courseList elements
    delete[] this->courseList;

    // pointing courseList to new tempArray elements
    this->courseList = tempArray;

    // increasing numOfCourseCount
    this->increaseCourseCount();
}

