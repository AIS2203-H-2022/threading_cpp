
#include "ais2203/random_gen.hpp"
#include "ais2203/thread_pool.hpp"

#include <iostream>
#include <string>

int main() {

    const int thread_num{100};

    ais2203::thread_pool pool;
    ais2203::random_gen rng(1, 100);

    std::mutex m;
    for (int i = 0; i < thread_num; i++) {
        auto f = std::function<void()>([i, &rng, &m] {
            std::unique_lock<std::mutex> lck(m);
            std::cout << std::to_string(i) << ", thread id=" << std::this_thread::get_id() << std::endl;
            lck.unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(rng()));
        });
        pool.submit(f);
    }

    pool.wait_for_tasks_to_finish();

    return 0;
}