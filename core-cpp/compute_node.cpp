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
// Hash 9484
// Hash 5518
// Hash 8210
// Hash 4778
// Hash 9576
// Hash 9879
// Hash 4218
// Hash 5611
// Hash 2164
// Hash 2222
// Hash 6614
// Hash 2898
// Hash 8061
// Hash 8249
// Hash 1084
// Hash 5666
// Hash 1986
// Hash 5659
// Hash 8209
// Hash 2052
// Hash 1238
// Hash 8982
// Hash 6115
// Hash 5004
// Hash 5010
// Hash 5210
// Hash 7879
// Hash 9970
// Hash 8829
// Hash 6006
// Hash 9184
// Hash 7072
// Hash 6234
// Hash 3767
// Hash 1660
// Hash 8490
// Hash 5232
// Hash 1165
// Hash 2322
// Hash 7845
// Hash 3445
// Hash 9748
// Hash 7306
// Hash 8565
// Hash 6916
// Hash 5996
// Hash 8710
// Hash 9269
// Hash 2624
// Hash 7323
// Hash 8064
// Hash 5709
// Hash 9553
// Hash 4219
// Hash 2836
// Hash 9855
// Hash 2886
// Hash 7045
// Hash 2423
// Hash 5553
// Hash 8573
// Hash 4001
// Hash 2618
// Hash 1869
// Hash 2093
// Hash 2640
// Hash 3002
// Hash 3979
// Hash 5101
// Hash 7357
// Hash 9253
// Hash 9891
// Hash 8307
// Hash 5284
// Hash 7959
// Hash 1010
// Hash 7453
// Hash 8075
// Hash 9168
// Hash 4987
// Hash 9947
// Hash 2025
// Hash 3250
// Hash 3975
// Hash 5494
// Hash 8126
// Hash 6632