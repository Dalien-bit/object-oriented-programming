#include <bits/stdc++.h>
using namespace std;

class Student {
public:
  string name;
  int roll;

  // Default constructor
  Student() {
    name = "";
    roll = -1;
  }

  // parameterised constructor
  Student(string n, int r) {
    name = n;
    roll = r;
  }

  // Copy constructor
  Student(Student &st) {
    name = st.name;
    roll = st.roll;
  }

  ~Student() {
    cout << "Student(" << name << ", " << roll << ") is being destroyed\n";
  }

  void print() {
    if (name == "") {
      cout << "Object name not instantiated\n";
    }
    cout << name << " " << roll << "\n";
  }
};

class Teacher {
  int salary;

public:
  string name, subject;

  Teacher(string n, string sub, int sal) {
    name = n;
    subject = sub;
    salary = sal;
  }

  void setSalary(int sal) { salary = sal; }

  int getSalary() { return salary; }
};

class Parent {
private:
  int x;

protected:
  int y;

public:
  int z;
  Parent() : x(1), y(2), z(3) {}
  Parent(int x, int y, int z) : x(x), y(y), z(z) {}
  void print() { cout << x << " " << y << " " << z << "\n"; }

  ~Parent() { cout << "Destroying parent\n"; }
};

class Child1 : public Parent {
  // x  will remain unaccessible
  // y will remain protected
  // z will remain public
public:
  void print() {
    cout << "x is unaccessible, y is protected " << y << " x is public " << z
         << "\n";
  }

  ~Child1() { cout << "Destroying child1\n"; }
};
class Child2 : protected Parent {
  // x  will remain unaccessible
  // y will remain protected
  // z will remain protected
public:
  void print() {
    cout << "x is unaccessible, y is protected " << y << " x is protected " << z
         << "\n";
  }

  ~Child2() { cout << "Destroying child2\n"; }
};
class Child3 : private Parent {
  // x not accessible
  // y not accessible
  // z not accessible
public:
  void print() { cout << "All are unaccessible \n"; }
  ~Child3() { cout << "Destroying child3\n"; }
};

class GrandChild1 : public Child1 {
public:
  GrandChild1() { cout << "GrandChild1 created\n"; }

  ~GrandChild1() { cout << "GrandChild1 destroyed\n"; }
};

class Parent1 {
public:
  Parent1() { cout << "Parent1 class created\n"; }
  ~Parent1() { cout << "Parent1 class destroyed\n"; }
};
class Parent2 {
public:
  Parent2() { cout << "Parent2 class created\n"; }
  ~Parent2() { cout << "Parent2 class destroyed\n"; }
};

class MultiChild : public Parent1, public Parent2 {
public:
  MultiChild() { cout << "MultiChild class created\n"; }
  ~MultiChild() { cout << "MultiChild class destroyed\n"; }
};

class Addition {
public:
  void add(int x, int y) { cout << x + y << "\n"; }
  void add(int x, int y, int z) { cout << x + y + z << "\n"; }

  void add(vector<int> nums) {
    cout << accumulate(nums.begin(), nums.end(), 0) << "\n";
  }
};

class ComplexNumber {
public:
  float x, y;
  ComplexNumber() : x(0), y(0){};
  ComplexNumber(int x, int y) : x(x), y(y){};

  ComplexNumber operator+(ComplexNumber &cn) {
    ComplexNumber ans(x + cn.x, y + cn.y);
    return ans;
  }

  void print() { cout << x << " + i" << y << "\n"; }
};

class Par {
public:
  virtual void print() { cout << "Par class\n"; }
  void show() { cout << "Par class\n"; }
};

class Chil : public Par {
public:
  void print() { cout << "Chil class\n"; }
  void show() { cout << "Chil class\n"; }
};

class Something {
  int x, y;

public:
  Something() : x(0), y(0) {}
  Something(int x, int y) : x(x), y(y) {}

  friend void func(Something &smth);
};

void func(Something &smth) {
  cout << "func can access private data " << smth.x << " " << smth.y << "\n";
}

void fundsConstDest() {
  Student *st = new Student("Suresh", 22);
  Student st1;
  st1.name = "Kamlesh";
  st1.roll = 23;
  Student st2("Ramesh", 21);

  Student st3 = st2;

  st->print();
  st1.print();
  st2.print();
  st3.print();

  delete st;
}

void encaps() {
  Teacher t1("Binod", "English", 50000);
  cout << t1.getSalary() << "\n";
}

void inherit() {
  Parent p1(1, 2, 3);
  p1.print();
  Child1 ch1;
  Child2 ch2;
  Child3 ch3;

  ch1.print();
  ch2.print();
  ch3.print();

  GrandChild1 gc1;

  MultiChild mc;
}

void funcOverloading() {
  Addition ad;
  ad.add(2, 3);
  ad.add(3, 4, 5);
  ad.add({1, 2, 3, 4});
}

void operatorOverloading() {
  ComplexNumber comp1(2, 3), comp2(3, 4);
  ComplexNumber comp3 = comp1 + comp2;

  comp3.print();
}

void functionOverriding() {
  Par *p = new Par();
  Chil c;

  p = &c;
  p->print();
  p->show();
}

void friendFunc() {
  Something smth(1, 2);
  func(smth);
}

int main() {
  // fundsConstDest();
  // encaps();
  // inherit();
  // funcOverloading();
  // operatorOverloading();
  // functionOverriding();
  friendFunc();

  return 0;
}