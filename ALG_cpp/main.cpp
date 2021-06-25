#include <iostream>

using namespace std;
void pool(int *a){
    *a= (*a)+1;
    cout<< *a<<endl;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    int a = 0;
    pool(&a);
    cout<< a<<endl;
    return 0;
}
