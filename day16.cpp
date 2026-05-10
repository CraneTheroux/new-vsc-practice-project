#include<iostream>
#include<thread>
#include<chrono>
#include<vector>
#include<mutex>
std::mutex mtx;
void downloadTask(int id, int TaskStep){
    for(int i = 0;i<=TaskStep;++i){
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::unique_lock<std::mutex>lock(mtx);
        //用一个整形数据记录百分比，转换成20个格子，一个#号代表5%
        int percent = i*100/TaskStep;
        //std::string(percent/5,'#')：20个格子，一个#号代表5%
        std::cout<<"[tack"<<i+1<<"]:"<<std::string(percent/5,'#')<<std::string(20-percent/5,'.')<<"\n";
        lock.unlock();
    }
}
int main(){
    std::vector<std::thread>threads;
    for(int i = 0;i<3;i++){
        /*emplace方法可以让vector容器中直接添加方法并自动进行构造，等价于
        threads.push_back(std::thread(downloadTask,i+1,10))
        */
        threads.emplace_back(downloadTask,i+1,10);
    }
    //t.join：所有子线程执行完毕，主线程等待
    for(auto& t:threads)t.join(); 

}
