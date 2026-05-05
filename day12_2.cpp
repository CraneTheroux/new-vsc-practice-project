#include<iostream>
#include<memory>
struct Thing{
    int id;
    Thing(int i):id(i){std::cout<<"Thing "<<id<<" created";}
    ~Thing(){
    std::cout << "Thing " << id << " destroyed\n";
    }
};

std::unique_ptr<Thing> makeThing(int id){
    return std::make_unique<Thing>(id);
}
struct node{
    int val;
    std::shared_ptr<node>next;
    std::weak_ptr<node>prev;
    node(int val1):val(val1){

    };
};

// int main(){

//     // auto u = makeThing(1);
//     // std::cout<<u->id<<std::endl;
//     //转交所有权
    

//     //share_ptr
//     auto s1 = std::make_shared<Thing>(2);
//     {
//         auto s2 = s1;
//         int count = s1.use_count();
//         std::cout<<"useCount:"<<count<<std::endl;

//     }
//     std::cout<<"useCount:"<<s1.use_count()<<std::endl;
//     std::weak_ptr<Thing>w = s1;
//     std::cout<<"useCount:"<<s1.use_count()<<std::endl;
//     if(auto lock =w.lock()){
//         std::cout<<lock->id<<std::endl;
//     }
//     s1.reset(); // 释放 Thing(2)
//     if (auto locked = w.lock()) {
//         std::cout << "still alive\n";
//     } else {
//         std::cout << "object expired\n"; // ✅ 进入这里
//     }
// }