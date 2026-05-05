#include<iostream>
#include<stdexcept>

// class MyError:public std::runtime_error{
// public:
//     MyError(const std::string&s):std::runtime_error(s){

//     };
// };
// int main(){
//     int i = 0;
//     std::cout<<"enter an number:";
//     std::cin>>i;
//     if(i ==3)
//     try{
//         throw MyError("fuck you");
//     }catch(MyError&e){
//     std::cout<<e.what()<<std::endl;
//     }
// }
template <typename T>
T divide(T a, T b){
    static_assert(std::is_integral_v<T>,"divide onlt works with integer types");
    if(b == 0){
        throw std::runtime_error("divide by zero is not allowed");
    }
    return a/b;
}
// int main(){
//     int a = 1;
//     int b = 2;
//     int result = divide(a,b);
// }