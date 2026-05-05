#include<iostream>
// void excceptionMethod(){
//     throw std::runtime_error("hello");
// }
// void safe_func()noexcept{
//     throw 3;
// }
//自定义错误异常类型
class myError:public std::runtime_error{
public:
//注意，父类的参数尽量在外部进行初始化，不要写在方法体内部
    myError(const std::string&s,int code):std::runtime_error(s),error_code(code){

    }
    int code()const{
        return error_code;
    }
private:
    int error_code;
};
// int main(){
    
//     // try{
//     //     excceptionMethod();
//     // }catch(const std::runtime_error &e){
//     //     std::cout<<"hello";
//     // }
//     // safe_func();
//     try{
//         throw myError("bad request",400);
//     }catch(const myError&e){
//         std::cout<<e.what()<<",code ="<<e.code()<<"\n";
//     }
// }