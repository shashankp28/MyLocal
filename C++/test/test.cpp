#include <iostream>

int main() {
    long long a = 5;
    long long* b = &a;
    long long** c = &b;
    std::cout<<sizeof(&a)<<"\n";
    std::cout<<c<<"\n";
    std::cout<<c+1;

    return 0;
}