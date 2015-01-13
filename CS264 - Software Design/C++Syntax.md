# C++ Syntax

#### [Learn X in Y minutes where X = c++](http://learnxinyminutes.com/docs/c++/)

## Pointers
A pointer is a variable declared to store a memory address. Its declaration will
also tell you the type of data it points to. You can retrieve the memory address
of your variables, then mess with them.

```c++
int x = 0;
int *px = &x;
```
`px` is a pointer to `x`.

### Pointer Operator `*`
- `int * x;` - Creates a ponter `x`
- `cout << *x;` - dereferencing `x` then prints.
- dereference == Get the value of the variable that a pointer points to

### Address of Operator `&`
```c++
  int  a = 10;
  int *b = &a;        // b is a pointer to the address of a
                      // At this point *b and a are synonymous
  cout << b  << endl; // Prints address of a
  cout << *b << endl; // Prints value of a
```

### Calling methods on Object pointers
There are two ways of doing this:
- Using the `->` operator
- Dereferencing the pointer

```c++
int main() {
  vector<int> * v = new vector<int>();

  v -> push_back(10);
  // or
  (* v).push_back(10);

}
```

## [Const](http://duramecho.com/ComputerInformation/WhyHowCppConst.html)
`const` variables can not be changed once initialised

### Simple Use
Creates an `int x` that can not be modified
```c++
const int x = 10;
```

### const pointer.  
Can not change the address but can change the thing it points at.
```c++
int const * x
```

### Pointer to a const variable
```c++
int * const x
```

### const pointer to const variable
ridiculous
```c++
int const * const x
```

## Const in functions
### Function returns a const
```c++
const int foo() {
  const int x = 10;
  return x;
}
```

### The function is not allowed to edit the member variables
The code below can not modify x in any way.
```c++
int foo() const {
  return x;
}
```

### Passing by reference without modifying the variable outside the scope of the function
```c++
int foo(const int &x) {
  return x;
}
```

### January 2011 Examp Paper
Review the code shown in the Listing below. Assuming that the code has completed
execution and that the address of `a` is `0x01A0` answer each of the following:
1. what is the value of `*c`?
2. what is the value of `b`?
3. what is the value of `a`?
4. what is the value of `&a`?
5. what is the value of `*b`?

```c++
  int  a = 10;
  int *b = &a;
  *b = *b + 1;

  int *c = new int();
  *c = *b;

  *b = *b + 1;

  int d = 5
  a = d;
```

| Variable | Value    |
| :------- | :------- |
| `*c`     | `11`     |
| `b`      | `0x01A0` |
| `a`      | `5`      |
| `&a`     | `0x01A0` |
| `*b`     | `5`      |

## Methods
### Basic Syntax
`Return Type` `name` (`arguments`) {  
  `Statements`;  
}  
```c++
void foo(int x) {

}
```

### Default arguments
In this example, x will be equal to 5 and y == 7 if no arguments are given.
- **Note:** Default arguments must be at the end of the arguments list.

```c++
int foo(int x = 5, int y = 7) {
  return x + y;
}

using namespace std;

int main() {
  cout << foo()    << endl; // 5 + 7 == 12
  cout << foo(1)   << endl; // 1 + 7 == 8
  cout << foo(1,2) << endl; // 1 + 2 == 3
}

void invalidDeclaration(int a = 1, int b) {
  // Error!
}
```

### Passing by reference
Passing variables by reference rather than value means that the variable is not
copied to the function scope.  Instead it passes a pointer to the function.  

There are two different methods of passing by reference:

#### Pass and modify the variable outside the scope of the function
```c++
int foo(int &x) {

}
```

#### Pass but dont modify the variable outside the scope of the function
```c++
int foo(const int &x) {

}
```


## Namespaces
- Namespaces provide separate scopes for variable, function, and other
  declarations.
- Namespaces can be nested.

```c++
namespace First {
  namespace Nested {
    void foo() {
      printf("This is First::Nested::foo\n");
    }
  } // end namespace Nested
} // end namespace First

namespace Second {
  void foo() {
    printf("This is Second::foo\n")
  }
}


int main() {
  First::Nested::foo();
  Second::foo();
}
```

### Setting a default namespace
```c++
using namespace std;
```

The code above will set the default namespace to `std`
This allows us to remove `std::` from our code.

This code:
```c++
int main() {
  std::cout << "Hello, World!" << std::endl;
  std::string s = "Hello";
  std::cout << s << std::endl;
}
```
to this:
```c++
using namespace std;

int main() {
  cout << "Hello, World!" << endl;
  string s = "Hello";
  cout << s << endl;
}
```

# Object Oriented C++
## Classes

```c++
class A {
    int x = 0;

  public:
    int y = 1;
    string name;
    string foo(int x);

  protected:
    string whatever;
};
```
## Constructors and Destructors
```c++
class Point {
  public:
    // Default Constructor
    Point();

    Point(int x, int y);

    //Destructor
    ~Point();
};
```

## Object Inheritance
```c++
class Shape {
    int width;
    int height;
  public:
    // Constructors can not be virtual
    // Destructors must be virtual
    Shape();
    virtual ~Shape();

    virtual void getWidth()  const = 0;
    virtual void getHeight() const = 0;

    virtual void setWidth(int width)   = 0;
    virtual void setHeight(int height) = 0;
};

class Square : public Shape {
  public:
    Square();
    ~Square();

    void getWidth() const;
    void getHeight() const;

    void setWidth(int width);
    void setHeight(int height);
};
```

### Virtual
- If any method is Virtual, it must be overriden in the subclass
- a destructor must be virtual if there is a subclass

### Pure Virtual
- If any methods are pure virtual, the object becomes pure virtual
- Pure virtual objects can not be initiated

## Operator Overloading
C++ allows us to overload many of the built in operators like `+`, `-`, `*`,
`<<` ect.  These infix operators are treated like methods that can be overriden.
```c++
class Point {
    int x;
    int y;
  public:
    Point(int x = 0, int y = 0);
    int getX() const;
    int getY() const;
    Point operator + (const Point &);
    Point operator - (const Point &);
    Point operator * (const Point &);

    friend ostream & operator << (ostream &, const Point &);
};

Point::Point(int x, int y) {
  this -> x = x;
  this -> y = y;
}

int Point::getX() const {
  return x;
}

int Point::getY() const {
  return y;
}

Point Point::operator+(const Point &p) {
  Point result(getX() + p.getX(), 1);
  cout << getX() << endl;
  return result;
}
```

### Overriding the Stream operator `<<`
Overloading the `<<` operator allows us to use our object with output Streams.
To override the stream operator for an object, we need to make the ostream a
`friend` class of ours. See the class definition above.

```c++
ostream& operator<<(ostream& os, const Point &p) {
  return os << "Point: " << getx() << ", " << getY();
}
```

## Using Objects
### Creating object on the stack
If an object is created on the Stack,  once it goes out of scope, it will be
deconstructed.  This is calles *automatic storage duration*.
```c++
int main() {
  Square square;
  square.setHeight(10);
}
```

### Creating objects on the Heap
If an object is created on the heap, it will remain in memory even when it goes
out of scope.  Objects created on the heap:
- Must be `delete`d manually.
- Must be declared as a pointer
- We use the `->` operator to call a function on an object, or we could
  dereference the object, like so:
  - `*(square).setHeight(10);`

```c++
int main() {
  Square * square = new Square();
  square -> setHeight(10);
}
```

## Templates
### Function Templates
```c++
template <typename T>
T Max(T const a, T const b) {
  return a >= b ? a : b;
}

int main() {
  cout << Max(1, 2) << endl;                // 2
  cout << Max('z', 'b') << endl;            // z
  cout << Max("hello", "world") << endl;    // world
}
```

### Class Templates
```c++
template <class T>
class Stack {
private:
  vector<T> stack;
  int size = 0;

public:
  void push(const T &);
  T pop();
  T top() const;
  bool empty() const {
    return stack.empty();
  }
};

template <class T>
void Stack<T>::push(const T & x) {
  stack.push_back(x);
  size++;
}

template <class T>
T Stack<T>::pop() {
  if (stack.empty()) {
    throw out_of_range("Stack<>::pop(): empty stack");
  }

  T result = this -> top();
  stack.pop_back();
  size--;
  return result;
}

template <class T>
T Stack<T>::top() const {
  return stack[size-1];
}
```

## Singleton Class
A singleton object can only have one instantiation.  When the `Singleton` is
first used, it will create the object.  Each subsequent call will use the created
`Singleton` object
- Ensure a class only ever has one instantiation
- Provide a global point of access to it

### Example - LogFile
When `LogFile::getInstance()` is used for the first time,  it opens a file to
write to.  Any time `LogFile::getInstance()` is used after this, it simply
returns the LogFile instance without creating a new one.  When the object is no
longer needed it is deleted and the file handle is closed.

```c++
LogFile::LogFile() {
  logFile.open("log.txt");
}

LogFile::~LogFile() {
  logFile.close();
}

LogFile & LogFile::getInstance() {
  static LogFile instance;
  return instance;
}
```

### static
Three Uses:
- similar to final (from C)
- Singleton
- only variable to containing class. (from C)
