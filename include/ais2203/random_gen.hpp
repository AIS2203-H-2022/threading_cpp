
#ifndef THREADING_CPP_RANDOM_GEN_HPP
#define THREADING_CPP_RANDOM_GEN_HPP

#include <random>

namespace ais2203 {

    class random_gen {

    public:
        random_gen(int min, int max)
            : rd_(), gen_(rd_()), dist_(min, max) {}

        int operator()() {
            return dist_(gen_);
        }

    private:
        std::random_device rd_;
        std::mt19937 gen_;
        std::uniform_int_distribution<int> dist_;
    };

}// namespace ais2203

#endif//THREADING_CPP_RANDOM_GEN_HPP
