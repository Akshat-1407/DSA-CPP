object is a instace of a class

By default inside a class access modifier is private

## Access Modifiers

#### There are three access modifiers:

* **Public -**
    * Members decleard as public are accessible from any part of the program.
    * They can be accessed by the objects of the class and external code.

* **Private -** 
    * Members declared as private are accessible only within the same class.
    * They are not accessible form outside the class, including derived classes.

* **Protected -**
    * Members decleared as protected are accessible within the same class and by derived classes
    * They are not directly accessible from external code.
    * They are not accessible in the main function.

## Getters and Setters are used to access private data elements outside the class. They are functions.

* Getters are used to get the **PRIVATE** properties.
* Setters are used to modify the **PRIVATE** properties. Also used to add conditions while setting the value.


## Inheretence

| Base Class | Derived Class (Private Mode) | Derived Class (Protected Mode)   | Derived Class (Public Mode) |
|------------|------------------------------|----------------------------------|-----------------------------|
| Private    | Not Inherited                | Not Inherited                    | Not Inherited               |
| Protected  | Private                      | Protected                        | Protected                   |
| Public     | Private                      | Protected                        | Public                      |


### Syntax of Inheritance

```cpp
class Base {
    // Base class members
};

class Derived : accessSpecifier Base {
    // Derived class members
};
```

### Types of Inheritance -

C++ supports several types of inheritance:

* Single Inheritance: A derived class inherits from one base class.
* Multiple Inheritance: A derived class inherits from more than one base class.
* Multilevel Inheritance: A derived class is also a base class for another derived class.
* Hierarchical Inheritance: Multiple derived classes inherit from a single base class.









# HW - Padding and Greedy Alignment, Initialization List




