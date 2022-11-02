#include <iostream>

class Employee {
  private:
    std::string Name;
    std::string Company;
    int Age;
    
  public:
    Employee(std::string name, std::string company, int age) {
      Name = name;
      Age = age;
      Company = company;
    }

    void greet() {
      std::cout << "My name is " << Name << "." << std::endl;
      std::cout << "I am " << Age << " years old." << std::endl;
      std::cout << "I work at " << Company << " company." << std::endl;
    }
};

int main() {
  Employee emp_1 = Employee("sam", "Google", 28);
  emp_1.greet();
}