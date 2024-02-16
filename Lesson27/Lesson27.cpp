// Lesson 27

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

std::mutex mut;
constexpr int size = 20;

void sum(const std::vector<int>& vec)
{
    long long sum = 0;
    for (int i : vec) {
        mut.lock();
        sum += i;
        mut.unlock();
    }
    std::cout << "Sum: " << sum;
}
void bubbleSort(std::vector<int>& vec) 
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            mut.lock();
            if (vec[j] > vec[j + 1]) 
            {
                std::swap(vec[j], vec[j + 1]);
            }
            mut.unlock();
        }
    }
}

void quickSork(std::vector<int>& vec)
{

}


int main()
{
    std::vector<int> vec = std::vector<int>();
    vec.resize(2, 100);
    std::vector<int> vec2 = std::vector<int>(size);
    
    for (int i = 0; i < vec2.size() - 1; i++) {
        vec2[i] = rand() % 10;
        //std::cout << vec2[i] << std::endl;
    }

    bubbleSort(vec2);

    //auto time = 0;
    //auto boost = 0;
    //auto time_of_1_thread = 0;
    //auto time_of_2_thread = 0;
    //auto result = boost - time / time_of_1_thread;

    //std::thread t1 (sum, std::ref(vec));
    //std::thread t1 (bubbleSort, std::ref(vec2),0,size/2);
    //std::thread t2(bubbleSort, std::ref(vec2),size/2+1,size);

    //t1.join();
    //t2.join();
    for (int i = 0; i < vec2.size() - 1; i++) {
        std::cout << vec2[i] << std::endl;
    }

    std::cout << std::endl;
    std::cout << "+--------------+---------------------------------------------------------------------+" << std::endl;
    std::cout << "|              |          C O U N T    E L E M E N T S   of  V E C T O R             |" << std::endl;
    std::cout << "+--------------+-------------+-------------+-------------+-------------+-------------+" << std::endl;
    std::cout << "|              |   10 000    |   100 000   |  1 000 000  |  10 000 000 | 100 000 000 |" << std::endl;
    std::cout << "+--------------+------+------+------+------+------+------+------+------+------+------+" << std::endl;
    std::cout << "| Thread count | Time | Boost| Time | Boost| Time | Boost| Time | Boost| Time | Boost|" << std::endl;
    std::cout << "+--------------+------+------+------+------+------+------+------+------+------+------+" << std::endl;
    std::cout << "+       1      +------+------+------+------+------+------+------+------+------+------+" << std::endl;
    std::cout << "+--------------+------+------+------+------+------+------+------+------+------+------+" << std::endl;
    std::cout << "+       2      +------+------+------+------+------+------+------+------+------+------+" << std::endl;
    std::cout << "+--------------+------+------+------+------+------+------+------+------+------+------+" << std::endl;
    std::cout << "+ concurrency  +------+------+------+------+------+------+------+------+------+------+" << std::endl;
    std::cout << "+--------------+------+------+------+------+------+------+------+------+------+------+" << std::endl;
    std::cout << "+ concurrency2 +------+------+------+------+------+------+------+------+------+------+" << std::endl;
    std::cout << "+--------------+------+------+------+------+------+------+------+------+------+------+" << std::endl << std::endl;

    return 0;
}