#include <iostream>
#include "../inc/Student.h"

int main() {


    while(true)
    {
        std::string studentName; // creating variable to hold studentName
        std::string courseName;
        bool keepAskingForCourses = true;
        Student student1 = Student(); // creating Student obj on heap


        // Prompting For Student Name
        std::cout<<"Please Enter Students Name: (if want to quit enter 'done':"<<endl;
        std::getline(cin >> std::ws, studentName);
        if(studentName == "done") // quitting if done entered
        {
            break;
        }
        student1.setName(studentName);

        // Loop for Course Names
        while(keepAskingForCourses)
        {
            std::cout<<"Enter Course Name: "<<endl;
            std::getline(cin >> std:: ws, courseName);
            if (courseName == "done")
            {
                keepAskingForCourses = false;
                continue;
            }
            student1.addCourse(courseName);
        }

        // Printing Student1
        std::cout<<student1<<endl;

        // loop for second student
        std::cout<<"Please Enter Second Students Name (if want to quit enter 'done'): "<<endl;
        std::getline(cin >> std::ws, studentName);
        if(studentName == "done") // quitting if done entered
        {
            break;
        }

        // copying studen1 to student2
        Student student2 = student1;
        student2.setName(studentName);

        // printing student2 after Copy
        std::cout<<"\nPrinting Student2 After Copying"<<endl;
        std::cout<<student2<<endl;

        // printing student1 after purge
        std::cout<<"\nPrinting Student1 after Purging Courses!"<<endl;
        student1.resetCourses();
        std::cout<<student1<<endl;

        // printing student2 after student1 purge
        std::cout<<"\nPrinting Student2 After Purge of Student1!"<<endl;
        std::cout<<student2<<endl;

        // Deep Copy using assignment operator and Printing Student3
        std::cout<<"\nPerforming Assignment Operator on Student3"<<endl;
        Student student3 = Student();
        student3 = student2;
        std::cout<<student3<<endl;






    }


    return 0;
}
