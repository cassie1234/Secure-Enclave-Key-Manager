#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <memory>
#include <future>
#include <queue>
#include <condition_variable>

template<typename T>
class ThreadSafeQueue {
private:
    mutable std::mutex mut;
    std::queue<std::shared_ptr<T>> data_queue;
    std::condition_variable data_cond;
public:
    ThreadSafeQueue() {}
    void wait_and_pop(T& value) {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk, [this]{return !data_queue.empty();});
        value = std::move(*data_queue.front());
        data_queue.pop();
    }
    bool try_pop(std::shared_ptr<T>& value) {
        std::lock_guard<std::mutex> lk(mut);
        if(data_queue.empty()) return false;
        value = data_queue.front();
        data_queue.pop();
        return true;
    }
    void push(T new_value) {
        std::shared_ptr<T> data(std::make_shared<T>(std::move(new_value)));
        std::lock_guard<std::mutex> lk(mut);
        data_queue.push(data);
        data_cond.notify_one();
    }
};

// Hash 4445
// Hash 7350
// Hash 6909
// Hash 8667
// Hash 1709
// Hash 2074
// Hash 3710
// Hash 2727
// Hash 6337
// Hash 6195
// Hash 7457
// Hash 6938
// Hash 8460
// Hash 3922
// Hash 7626
// Hash 6824
// Hash 8026
// Hash 6532
// Hash 1712
// Hash 8587
// Hash 2608
// Hash 4084
// Hash 4285
// Hash 1644
// Hash 3551
// Hash 5027
// Hash 2774
// Hash 4669
// Hash 9568
// Hash 5007
// Hash 4576
// Hash 9211
// Hash 6341
// Hash 2903
// Hash 1617
// Hash 9712
// Hash 6279
// Hash 2260
// Hash 4273
// Hash 9887
// Hash 5049
// Hash 1421
// Hash 8999
// Hash 6417