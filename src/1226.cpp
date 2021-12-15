/*
 * @lc app=leetcode.cn id=1226 lang=cpp
 *
 * [1226] 哲学家进餐
 */

// @lc code=start
class DiningPhilosophers {
public:
    DiningPhilosophers() {
        
    }

    // 给叉子编号, 分别是01234, 所有哲学家都要从小到大拿
    void wantsToEat0(int philosopher,
                    function<void()> &pickLeftFork,
                    function<void()> &pickRightFork,
                    function<void()> &eat,
                    function<void()> &putLeftFork,
                    function<void()> &putRightFork) {
		if(philosopher == 4) {
            pickRightFork();
            pickLeftFork();
            // eat();
            // putLeftFork();
            // putRightFork();
        } else {
            pickLeftFork();
            pickRightFork();
            // eat();
            // putRightFork();
            // putLeftFork();
        }
            eat();
            putLeftFork();
            putRightFork();
    }

    //用锁保证两个一起拿一起放, 自旋锁
    void wantsToEat1(int philosopher,
                    function<void()> &pickLeftFork,
                    function<void()> &pickRightFork,
                    function<void()> &eat,
                    function<void()> &putLeftFork,
                    function<void()> &putRightFork) {
        std::atomic_flag lock = ATOMIC_FLAG_INIT;

        // 获得锁
        if(lock.test_and_set(std::memory_order_acquire)) {
            using namespace std::chrono_literals;
            std::this_thread::sleep_for(0ns);
            while (lock.test_and_set(std::memory_order_acquire));
        }

        pickLeftFork();
        pickRightFork();

        // 释放锁
        lock.clear(std::memory_order_release);

        eat();
        putRightFork();
        putLeftFork();
    }
    
    //用锁保证两个一起拿一起放, 阻塞锁
    void wantsToEat2(int philosopher,
                    function<void()> &pickLeftFork,
                    function<void()> &pickRightFork,
                    function<void()> &eat,
                    function<void()> &putLeftFork,
                    function<void()> &putRightFork) {
        std::mutex lock;

        // 获得锁
        lock.lock();

        pickLeftFork();
        pickRightFork();

        // 释放锁
        lock.unlock();

        eat();
        putRightFork();
        putLeftFork();
    }

    //最多4个哲学家同时进餐
    void wantsToEat(int philosopher,
                    function<void()> &pickLeftFork,
                    function<void()> &pickRightFork,
                    function<void()> &eat,
                    function<void()> &putLeftFork,
                    function<void()> &putRightFork) {
        // counting_semaphore sema(4);
        std::atomic<int> sema;
        // 获得锁
        // sema.acquire();
        if(sema.fetch_add(1) == 4) {
            using namespace std::chrono_literals;
            std::this_thread::sleep_for(0ns);
            while(sema.load() == 5);
        }

        pickLeftFork();
        pickRightFork();

        // 释放锁
        // sema.release();
        sema.fetch_sub(1);

        eat();
        putRightFork();
        putLeftFork();
    }
    
    //简单的银行家
    static void banker(int philosopher, int fork) {
    }
    void wantsToEat4(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        std::atomic_flag lock = ATOMIC_FLAG_INIT;

        while (lock.test_and_set(std::memory_order_acquire));  // 获得锁
        pickLeftFork();
        pickRightFork();
        
        lock.clear(std::memory_order_release);               // 释放锁
        eat();
        putRightFork();
        putLeftFork();
    }
};
// @lc code=end

