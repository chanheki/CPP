#include <iostream>
#include <ctime>
#include <cstring>

class Base
{
private:
public:
	std::string * name;
	int age;

	virtual ~Base() {
		std::cout << "Base" << std::endl;
	}
	Base(void) {
		std::cout << "Base on" << std::endl;
	}
	Base(const Base& src) : name(src.name), age(src.age) {
		std::cout << "Base copy" << std::endl;
	}
	Base(std::string name, int age) {
		std::cout << "Base name, age" << std::endl;
		this->name = new std::string(name);
		this->age = age;
	}
	// Base& operator=(Base const& rhs) {
	// 	std::cout << "Base operator=" << std::endl;
	// 	return *this;
	// }
	void showInfo() const {
		std::cout << "name: " << name << std::endl;
		std::cout << "age: " << age << std::endl;
	}
};

class A : public Base
{
public:
	~A() {
		std::cout << "A" << std::endl;
	}
	int a = 1;
};

#ifdef LEAKS
 void leaks() {
	system("leaks exercise");
 }
#endif
int main() { 
#ifdef LEAKS
	atexit(leaks);
#endif
	// A *a = new A();
	// Base *base = a;

	// delete base;

	Base a("chanheki", 20);
	Base b("jang", 25);

	a.showInfo();
	b.showInfo();

	b = a;

	std::cout << &a.name << std::endl;
	std::cout << &b.name << std::endl;

	a.showInfo();
	b.showInfo();

}