#include <iostream>
#include <memory>
#include <vector>

#include <boost/di.hpp>

class OperationBase {};

using Operations = std::vector<std::shared_ptr<OperationBase>>;

class Operation1 : public OperationBase {
public:
  Operation1() { std::cout << "Operation1 constructed." << std::endl; }
  ~Operation1() { std::cout << "Operation1 destructed." << std::endl; }
};

class Operation2 : public OperationBase {
public:
  Operation2() { std::cout << "Operation2 constructed." << std::endl; }
  ~Operation2() { std::cout << "Operation2 destructed." << std::endl; }
};

class User1 {
public:
  explicit User1(Operations) {
    std::cout << "User1 constructed." << std::endl;
  }
  ~User1() { std::cout << "User1 destructed." << std::endl; }
};

class User2 {
public:
  explicit User2(Operations) {
    std::cout << "User2 constructed." << std::endl;
  }
  ~User2() { std::cout << "User2 destructed." << std::endl; }
};

int main() {
  using namespace boost;
  auto injector = di::make_injector(
      di::bind<OperationBase *[]>().to<Operation1, Operation2>());

  auto user1 = injector.create<User1 &>();
  auto user2 = injector.create<User2 &>();

  return 0;
}