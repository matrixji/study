#include <array>
#include <iostream>
#include <map>
#include <tuple>

using User = struct {
  std::string name;
  unsigned int age;
  std::string email;
  std::tuple<int, double> data1;
  std::array<int, 3> data2;
};

int main() {
  std::map<int, User> data{
      {1, User{"Bob", 30, "bob@163.com", {10, 9.8}, {1, 2, 3}}},
      {2, User{"Tom", 34, "tom@163.com", {8, 7.6}, {3, 6, 9}}}};
  for (const auto &[id, user] : data) {
    std::cout << id << ": " << std::endl;
    auto &[name, age, email, d1, d2] = user;
    auto [d11, d12] = d1;
    auto [d21, d22, d23] = d2;
    std::cout << "  name: " << name << std::endl;
    std::cout << "  age: " << age << std::endl;
    std::cout << "  email: " << email << std::endl;
    std::cout << "  data1: " << d11 << ", " << d12 << std::endl;
    std::cout << "  data2: " << d21 << ", " << d22 << ", " << d23 << std::endl;
  }
  return 0;
}
