#include <iostream>
#include <string.h>

using namespace std;

class Student {
	string name;
public:
	Student() {
		name = "Lolik";
	}
	Student(string x) {
		this->name = x;
	}
	void AssingValues(string x) {
		this->name = x;
	}
	void Printer() {
		cout << "Name: " << name << endl;
	}
	string getName() {
		return this->name;
	}
	void setMark(string x) {
		this->name = x;
	}
};

class Group {
	Student* slaves;
public:
	static int amountOfSlaves;
	Group() {
		slaves = new Student[amountOfSlaves];
	}
	void Adder(Student slave) {
		IncrementIncrease(1);
		Student* temporaryArr = new Student[amountOfSlaves];
		for (int i = 0; i < amountOfSlaves - 1; i++)
		{
			temporaryArr[i].AssingValues(slaves[i].getName());
		}
		temporaryArr[amountOfSlaves - 1].AssingValues(slave.getName());
		delete[]slaves;
		slaves = nullptr;
		slaves = new Student[amountOfSlaves];
		slaves = temporaryArr;
	}
	void Deleter(int index) {
		IncrementDecrease(1);
		Student* temporaryArr = new Student[amountOfSlaves];
		int tempIndex = 0;
		for (int i = 0; i < amountOfSlaves + 1; i++)
		{
			if (i + 1 == index) {
				continue;
			}
			else {
				temporaryArr[tempIndex].AssingValues(slaves[i].getName());
				tempIndex++;
			}
		}
		delete[] slaves;
		slaves = temporaryArr;
		slaves = new Student[amountOfSlaves];
		slaves = temporaryArr;
		delete[]temporaryArr;
		temporaryArr = nullptr;
	}

	void Renamer(int index, string name) {
		slaves[index - 1].AssingValues(name);
	}
	void Writer() {
		for (int i = 0; i < amountOfSlaves; i++)
		{
			cout << "Name of student " << i + 1 << " is: " << slaves[i].getName() << endl;
		}
	}
	static void IncrementIncrease(int x) {
		amountOfSlaves += x;
	}
	static void IncrementDecrease(int x) {
		amountOfSlaves -= x;
	}
};
int Group::amountOfSlaves = 0;
int main()
{
	cout << Group::amountOfSlaves << endl;
	Group obj;
	Student obj2;
	obj.Adder(obj2);
	obj.Writer();
	obj.Renamer(1, "likilio");
	obj.Writer();
	obj.Deleter(1);
}