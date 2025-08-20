# C++ Practice Lab — Constructors, OOP, Templates, RAII 🚀

[![Releases](https://img.shields.io/badge/Releases-Download-blue?logo=github)](https://github.com/yvens-stack/cpp-general-practice/releases)

![C++ Logo](https://upload.wikimedia.org/wikipedia/commons/1/18/ISO_C%2B%2B_Logo.svg)

Beginner-friendly C++ practice covering core programming concepts. This repo contains exercises, examples, and small projects that teach real C++ skills: constructors, destructors, inheritance, lambda functions, linked lists, maps, memory management, OOP, polymorphism, RAII, recursion, and templates.

Badges
- ![Topics](https://img.shields.io/badge/topics-constructors%20%7C%20inheritance%20%7C%20templates-lightgrey)
- ![License](https://img.shields.io/badge/license-MIT-green)
- ![C++ Standard](https://img.shields.io/badge/standard-C%2B%2B17-blue)

Table of contents
- What this repo contains
- Quick start
- Build and run
- Exercises and learning path
- Key examples (code)
  - Constructors & Destructors
  - Inheritance & Polymorphism
  - RAII & Memory Management
  - Templates & Generic Code
  - Recursion
  - Lambda Functions
  - Linked List & Maps
- Project structure
- Style guide
- Tests
- Releases
- Contributing
- License

What this repo contains
- Short tutorials for each topic.
- Hands-on exercises with tests.
- Small projects that combine topics.
- Reference implementations you can read and run.

Quick start
- Clone the repo:
  git clone https://github.com/yvens-stack/cpp-general-practice.git
- Enter the folder:
  cd cpp-general-practice
- See the exercises in the exercises/ folder. Each exercise has a README and a test.

Build and run
- This repo uses CMake. Use a modern compiler that supports C++17.
  mkdir build
  cd build
  cmake ..
  cmake --build .
- Run the main examples in build/bin or the test suite in build/tests.

Exercises and learning path
The repo organizes material by concept. Each folder contains:
- exercise.md — problem statement and constraints.
- solution.cpp — a sample solution with comments.
- test.cpp — unit tests for the exercise.

Start order
1. basics/constructors
2. basics/destructors
3. oop/inheritance
4. memory/unique_shared
5. data_structures/linked_list
6. algorithms/recursion
7. templates/generic_stack
8. advanced/lambda_examples
9. maps/unordered_map_practice
10. projects/simple_cli_calculator

Key examples (code)
Constructors & Destructors
- Focus: object lifecycle, default/copy/move constructors, destructor, rule of five.

Example: RAII class that opens a file and closes on destruction.

```cpp
// file_guard.h
#include <cstdio>
#include <stdexcept>

class FileGuard {
  FILE* f_;
public:
  explicit FileGuard(const char* path) : f_(std::fopen(path, "r")) {
    if (!f_) throw std::runtime_error("open failed");
  }
  ~FileGuard() {
    if (f_) std::fclose(f_);
  }
  FILE* get() const { return f_; }
  // disable copy
  FileGuard(const FileGuard&) = delete;
  FileGuard& operator=(const FileGuard&) = delete;
  // allow move
  FileGuard(FileGuard&& other) noexcept : f_(other.f_) { other.f_ = nullptr; }
  FileGuard& operator=(FileGuard&& other) noexcept {
    if (this != &other) {
      if (f_) std::fclose(f_);
      f_ = other.f_;
      other.f_ = nullptr;
    }
    return *this;
  }
};
```

Inheritance & Polymorphism
- Focus: virtual functions, pure virtual interface, dynamic dispatch, slicing.

Example: Shape interface and derived classes.

```cpp
struct Shape {
  virtual double area() const = 0;
  virtual ~Shape() = default;
};

struct Circle : Shape {
  double r;
  Circle(double r_) : r(r_) {}
  double area() const override { return 3.141592653589793 * r * r; }
};

struct Rectangle : Shape {
  double w,h;
  Rectangle(double w_, double h_) : w(w_), h(h_) {}
  double area() const override { return w * h; }
};
```

RAII & Memory Management
- Focus: smart pointers, unique_ptr, shared_ptr, weak_ptr, avoid raw owning pointers.

Example: unique_ptr for dynamic arrays.

```cpp
#include <memory>
#include <iostream>

void demo() {
  std::unique_ptr<int[]> arr(new int[5]{1,2,3,4,5});
  for (int i = 0; i < 5; ++i) std::cout << arr[i] << ' ';
}
```

Templates & Generic Code
- Focus: function templates, class templates, type traits, SFINAE, modern constraints.

Example: A small generic stack.

```cpp
#include <vector>
#include <stdexcept>

template<typename T>
class Stack {
  std::vector<T> data_;
public:
  void push(const T& v) { data_.push_back(v); }
  void push(T&& v) { data_.push_back(std::move(v)); }
  void pop() {
    if (data_.empty()) throw std::runtime_error("pop empty");
    data_.pop_back();
  }
  T& top() { return data_.back(); }
  bool empty() const { return data_.empty(); }
};
```

Recursion
- Focus: recursion patterns, tail recursion, recursion vs iteration, stack depth.

Example: recursive factorial with memoization using unordered_map.

```cpp
#include <unordered_map>

long long factorial(int n, std::unordered_map<int,long long>& cache) {
  if (n <= 1) return 1;
  auto it = cache.find(n);
  if (it != cache.end()) return it->second;
  long long res = n * factorial(n - 1, cache);
  cache[n] = res;
  return res;
}
```

Lambda Functions
- Focus: captures, mutable lambdas, std::function, performance trade-offs.

Example: sort with capture-by-value counter.

```cpp
#include <vector>
#include <algorithm>

void demo_sort() {
  std::vector<int> v{4,1,3,2};
  int count = 0;
  std::sort(v.begin(), v.end(), [&count](int a, int b) {
    ++count;
    return a < b;
  });
}
```

Linked List & Maps
- Focus: pointer manipulation, ownership, iterators, unordered_map vs map performance.

Single-linked list node example:

```cpp
struct Node {
  int val;
  Node* next;
  Node(int v) : val(v), next(nullptr) {}
};

void push_front(Node*& head, int v) {
  Node* n = new Node(v);
  n->next = head;
  head = n;
}

// remember to free list or use smart pointers
```

Project structure
- /exercises - tasks and tests.
- /examples - focused example code.
- /projects - small end-to-end projects.
- /docs - design notes and cheatsheets.
- CMakeLists.txt - top-level build script.

Style guide
- Use RAII for resource management.
- Prefer smart pointers over raw owning pointers.
- Use const for read-only values.
- Pass by const reference for large objects.
- Keep functions small and focused.
- Use explicit for single-argument constructors.
- Follow the rule of five for classes that manage resources.

Tests
- Each exercise has unit tests in tests/.
- Tests use Catch2 or a small custom harness.
- Run tests with: ctest --verbose

Releases
[![Release Page](https://img.shields.io/badge/Get%20Release-download-blue?logo=github)](https://github.com/yvens-stack/cpp-general-practice/releases)

Visit https://github.com/yvens-stack/cpp-general-practice/releases and download the release asset. Download the release file and execute it or extract it according to the asset type. Releases include prebuilt binaries for examples and packaged exercises that you can run on supported platforms. If a release asset includes an installer or script, run it from a terminal with appropriate permissions.

Contributing
- Fork the repo.
- Create a feature branch.
- Open a pull request with a clear description.
- Add tests for new code.
- Keep commits focused and atomic.

Guidelines for contributors
- Write clear commit messages.
- Keep functions short.
- Include a small README for new exercises.
- Add example input and expected output for projects.

Images and diagrams
- Use simple diagrams to explain ownership.
- Use sequence diagrams for object lifetimes.
- Use small UML boxes to show class relations.

Teaching tips
- Start with stack allocation and local objects.
- Show constructor and destructor order.
- Demonstrate move semantics with simple classes.
- Compare raw pointer code and smart pointer code.
- Measure memory and time for map vs unordered_map on sample data.

FAQ
- Q: Which standard do you target?
  A: C++17 by default. Some examples use features from newer standards; they show modern idioms.
- Q: How do I test an exercise?
  A: Follow the exercise README. Run the test executable in build/tests.
- Q: Can I submit new exercises?
  A: Yes. Add them under exercises/, include tests and a README.

License
- MIT. See LICENSE file.

Contacts
- Open issues for bugs or feature requests.
- Use pull requests for fixes and new content.

Keep learning with small, focused tasks. Apply concepts in short projects that link multiple topics.