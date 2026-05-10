#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include<random>
std::mutex mtx;
std::condition_variable cv;
int data = 0;
bool ready = false;

void consumer() {
    std::unique_lock<std::mutex> lk(mtx);
    std::cout << "[消费者] 等待数据...\n";

    cv.wait(lk, []{ return ready; });
    //  predicate 问: ready 是 true 了吗?
    //  不是 → 继续等; 是 → 往下走

    std::cout << "[消费者] 收到数据: " << data << "\n";
}

void producer() {
    std::this_thread::sleep_for(std::chrono::seconds(2));

    {
        std::lock_guard<std::mutex> lk(mtx);
        data = 42;
        ready = true;
        std::cout << "[生产者] 数据已准备好\n";
    } // 解锁

    cv.notify_one();  // 通知消费者
}

// int main() {
//     std::uniform_int_distribution
//     system("chcp 65001");
//     std::thread t1(consumer);
//     std::thread t2(producer);
//     t1.join();
//     t2.join();
//     return 0;
// }