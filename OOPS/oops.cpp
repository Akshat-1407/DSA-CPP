#include <iostream>

using namespace std;

class Person {
    public:
        string name;
        int age;
        double height;
        double weight;

    private:
        int salary;


    public:

    // Default Constructor
    Person() {
        cout << "Default Constructor Called" << endl;
    }

    // Parameterized Construcctor
    Person(string name, int age, int height, int weight, int salary) {
        this->name = name;
        this->age = age;
        this->height = height;
        this->weight = weight;
        this->salary = salary;
    }

    // Copy constructor
    Person(Person& P) {
        this->name = P.name;
        this->age = P.age;
        this->height = P.height;
        this->weight = P.weight;
        this->salary = P.salary;
    } 

    // Method
    void printPerson() {
        cout << "Name: " << this->name << ", Age: " << this->age << ", Height: " << this->height << ", Weight: " << this->weight << ", Salary: " << this->salary << endl;
    }

    // Getter
    int getSalary() {
        return this->salary;
    }

    // Setter
    void setSalary(int salary) {
        this->salary = salary;
    }

    // Destructor
    ~Person() {
        cout << "Destructor Called" << endl;
    }

};


int main() {
    
    // Static Memory Allocation -> Stack
    Person p1("John", 25, 5.6, 55.0, 25000);
    p1.printPerson();

    cout << "Salary before calling setter" << p1.getSalary() << endl; // Getter
    p1.setSalary(15000); // Setter
    cout << "Salary after calling setter" << p1.getSalary() << endl;

    
    // Dynamic Memory Allocation -> Heap
    Person* p2 = new Person("Simon", 31, 5.11, 63, 50000);
    p2->printPerson();

    delete p2; // We have to manually free the dymanically allocated memory. Destructor is called manually using delete keyword..
}
