#include <iostream>
#include <vector>

using namespace std;

constexpr bool doNoExcept = true;

struct Noisy {
   Noisy() noexcept(doNoExcept) { cout << "Default constructor." << endl; };
   ~Noisy() noexcept { cout << "Destructor." << endl; };

   Noisy& operator=(const Noisy& other) noexcept(doNoExcept) { cout << "Copy Assignment." << endl; };
   Noisy(const Noisy& other) noexcept(doNoExcept) { cout << "Copy Constructor." << endl; };

   Noisy& operator=(Noisy&& other) noexcept(doNoExcept) { cout << "Move Assignment." << endl; };
   Noisy(Noisy&& other) noexcept(doNoExcept) { cout << "Move Constructor." << endl; };
};

struct MyClass {
   Noisy noisy{};
};

int main() {
   cout << "hello world! " << endl;
   size_t max{ 2 };
   std::vector<MyClass> named_vector;
   //named_vector.reserve(3);
   for (size_t index{ 0 }; index < max; index++) {
      cout << "Vec Capactiy: " << named_vector.capacity() << endl;
      named_vector.push_back(MyClass{});
   }
   cout << "Vec Capactiy: " << named_vector.capacity() << endl;

   cout << "---LEAVING SCOPE---" << endl;
}