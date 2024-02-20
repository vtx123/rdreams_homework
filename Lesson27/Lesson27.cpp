// Lesson 27

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <iomanip>
#include <algorithm>

constexpr bool DEBUG = false;
constexpr int s10_000      = 10000;
constexpr int s100_000     = 100000;
constexpr int s1_000_000   = 1000000;
constexpr int s10_000_000  = 10000000;
constexpr int s100_000_000 = 100000000;
const int chankSize = 10000;


template <int maxThreadCount = 0, typename Iterator>
void quicksort(Iterator begin, Iterator end) {
    if (begin == end) {
        return; 
    }
    auto pivot = *std::next(begin, std::distance(begin, end) / 2);
    Iterator chank1 = std::partition(begin, end, 
        [pivot](const auto& elem) { return elem < pivot; });
    Iterator chank2 = std::partition(chank1, end, 
        [pivot](const auto& elem) { return !(pivot < elem); });

    std::vector<std::thread> threads(maxThreadCount);
    int curThreadCount = 0;
    if (std::distance(begin, chank1) > chankSize && curThreadCount < maxThreadCount) {
        threads[curThreadCount++] = std::thread(quicksort<maxThreadCount, Iterator>, begin, chank1);
    }
    else {
        quicksort(begin, chank1);
    }
    if (std::distance(chank2, end) > chankSize && curThreadCount < maxThreadCount) {
        threads[curThreadCount++] = std::thread(quicksort<maxThreadCount, Iterator>, chank2, end);
    }
    else {
        quicksort(chank2, end);
    }

    for (int i = 0; i < curThreadCount; i++) {
        threads[i].join();
    }
    if (DEBUG) { std::cout << curThreadCount << std::endl; }
}

std::vector<int> reinitByRandomNum(int size)
{
    std::vector<int> numbers(size);
    for (int i = 0; i < size; i++)
    {
        numbers[i] = std::rand() % 9 + 1;
    }
    return numbers;
}

void reinitByRandomNumM(std::vector<int>& vec, int size)
{
    for (int i = 0; i < size; i++)
    {
        vec[i] = std::rand() % 9 + 1;
    }
}

enum class SortingType {
    SingleThread = 0,
    DoubleThread,
    EightThread,
    SixteenThread
};

// sorting and mesure it time 
long long sortAndTimeInfo(std::vector<int>& vec, SortingType st) {
    if ( DEBUG ) { std::cout << "Sorting Vector " << vec.size() << " elements..." << std::endl; }

    const auto beg = std::chrono::high_resolution_clock::now();
    switch (st)
    {
        case SortingType::DoubleThread: // optimal 2x thread
        {
            quicksort<2>(vec.begin(), vec.end());
            break;
        }
        case SortingType::EightThread: // optimal 8x thread
        {
            quicksort<8>(vec.begin(), vec.end());
            break;
        }
        case SortingType::SixteenThread: // overwhelmed 16x thread
        {
            quicksort<16>(vec.begin(), vec.end());
            break;
        }
        case SortingType::SingleThread: // Super-Duper single thread
        default:
            quicksort<0>(vec.begin(), vec.end());
            break;
    }
    const auto end = std::chrono::high_resolution_clock::now();

    const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - beg);
    if (DEBUG) {
        std::cout << "Sorting time: " << duration.count() << " MICROseconds or "
            << duration.count() / 1000 << " ms" << std::endl << std::endl;
    }

    return duration.count();
}

// print random array elements just for checking is sorting was correct
void randomCheckSorting(std::vector<int>& vec) 
{
    int shift = vec.size() >> 4;
    std::cout << "------------------------------------------------------------" << std::endl;
    std::cout << std::setw(15) << "idx" << std::setw(15) << "value" << std::endl;

    for (int i = 0; i < vec.size(); i+=shift) {
        std::cout << std::setw(15) << i << std::setw(15) << vec[i] << std::endl;
    }
}
int main()
{
    std::cout << "Initializing Vectors..." << std::endl;

    std::vector<int> vec1 = reinitByRandomNum(s10_000);
    std::vector<int> vec2 = reinitByRandomNum(s100_000);
    std::vector<int> vec3 = reinitByRandomNum(s1_000_000);
    std::vector<int> vec4(s10_000_000); // generate number by multithreading - just for faster init
    std::thread rand1(reinitByRandomNumM, std::ref(vec4), s10_000_000);
    std::vector<int> vec5(s100_000_000); // generate number by multithreading - just for faster init
    std::thread rand2(reinitByRandomNumM, std::ref(vec5), s100_000_000);
    rand1.join();
    rand2.join();

    std::cout << "Initializing DONE." << std::endl;

    std::cout << std::endl;
    std::cout << "+--------------+---------------------------------------------------------------------------------------------+" << std::endl;
    std::cout << "|              |                      C O U N T    E L E M E N T S   of  V E C T O R                         |" << std::endl;
    std::cout << "+--------------+-----------------+-----------------+-----------------+-----------------+---------------------+" << std::endl;
    std::cout << "|              |     10 000      |     100 000     |    1 000 000    |    10 000 000   |     100 000 000     |" << std::endl;
    std::cout << "+--------------+--------+--------+--------+--------+--------+--------+--------+--------+----------+----------+" << std::endl;
    std::cout << "| Thread count |  Time  |  Boost |  Time  |  Boost |  Time  |  Boost |  Time  |  Boost |   Time   |   Boost  |" << std::endl;
    std::cout << "+--------------+--------+--------+--------+--------+--------+--------+--------+--------+----------+----------+" << std::endl;

    long long t1t1 = sortAndTimeInfo(vec1, SortingType::SingleThread);
    long long t1t2 = sortAndTimeInfo(vec2, SortingType::SingleThread);
    long long t1t3 = sortAndTimeInfo(vec3, SortingType::SingleThread);
    long long t1t4 = sortAndTimeInfo(vec4, SortingType::SingleThread);
    long long t1t5 = sortAndTimeInfo(vec5, SortingType::SingleThread);
    std::cout << "+--------------+--------+--------+--------+--------+--------+--------+--------+--------+----------+----------+" << std::endl;
    std::cout << "| 1 Thread:    |" << std::setw(7) << t1t1 << " |" << "   ><   " << "| "
                                    << std::setw(6) << t1t2 << " |" << "   ><   " << "| "
                                    << std::setw(6) << t1t3 << " |" << "   ><   " << "| "
                                    << std::setw(6) << t1t4 << " |" << "   ><   " << "| "
                                    << std::setw(8) << t1t5 << " |" << "    ><    " << "| Microseconds" << std::endl;
    std::cout << "+--------------+--------+--------+--------+--------+--------+--------+--------+--------+----------+----------+" << std::endl;
   
    vec1 = reinitByRandomNum(s10_000);
    vec2 = reinitByRandomNum(s100_000);
    vec3 = reinitByRandomNum(s1_000_000);
    std::thread rand3(reinitByRandomNumM, std::ref(vec4), s10_000_000);
    std::thread rand4(reinitByRandomNumM, std::ref(vec5), s100_000_000);
    rand3.join();
    rand4.join();

    long long t1 = sortAndTimeInfo(vec1, SortingType::DoubleThread);
    long long t2 = sortAndTimeInfo(vec2, SortingType::DoubleThread);
    long long t3 = sortAndTimeInfo(vec3, SortingType::DoubleThread);
    long long t4 = sortAndTimeInfo(vec4, SortingType::DoubleThread);
    long long t5 = sortAndTimeInfo(vec5, SortingType::DoubleThread);
    std::cout << "+--------------+--------+--------+--------+--------+--------+--------+--------+--------+----------+----------+" << std::endl;
    std::cout << "| 2 Thread:    |" << std::setw(7) << t1 << " |" << std::setw(7) << t1t1 - t1 << " | "
                                    << std::setw(6) << t2 << " |" << std::setw(7) << t1t2 - t2 << " | "
                                    << std::setw(6) << t3 << " |" << std::setw(7) << t1t3 - t3 << " | "
                                    << std::setw(6) << t4 << " |" << std::setw(7) << t1t4 - t4 << " | "
                                    << std::setw(8) << t5 << " |" << std::setw(9) << t1t5 - t5 << " | Microseconds" << std::endl;
    std::cout << "+--------------+--------+--------+--------+--------+--------+--------+--------+--------+----------+----------+" << std::endl;

    vec1 = reinitByRandomNum(s10_000);
    vec2 = reinitByRandomNum(s100_000);
    vec3 = reinitByRandomNum(s1_000_000);
    std::thread rand5(reinitByRandomNumM, std::ref(vec4), s10_000_000);
    std::thread rand6(reinitByRandomNumM, std::ref(vec5), s100_000_000);
    rand5.join();
    rand6.join();

    t1 = sortAndTimeInfo(vec1, SortingType::EightThread);
    t2 = sortAndTimeInfo(vec2, SortingType::EightThread);
    t3 = sortAndTimeInfo(vec3, SortingType::EightThread);
    t4 = sortAndTimeInfo(vec4, SortingType::EightThread);
    t5 = sortAndTimeInfo(vec5, SortingType::EightThread);
    std::cout << "+--------------+--------+--------+--------+--------+--------+--------+--------+--------+----------+----------+" << std::endl;
    std::cout << "| 8 Thread:    |" << std::setw(7) << t1 << " |" << std::setw(7) << t1t1 - t1 << " | "
                                    << std::setw(6) << t2 << " |" << std::setw(7) << t1t2 - t2 << " | "
                                    << std::setw(6) << t3 << " |" << std::setw(7) << t1t3 - t3 << " | "
                                    << std::setw(6) << t4 << " |" << std::setw(7) << t1t4 - t4 << " | "
                                    << std::setw(8) << t5 << " |" << std::setw(9) << t1t5 - t5 << " | Microseconds" << std::endl;
    std::cout << "+--------------+--------+--------+--------+--------+--------+--------+--------+--------+----------+----------+" << std::endl;

    vec1 = reinitByRandomNum(s10_000);
    vec2 = reinitByRandomNum(s100_000);
    vec3 = reinitByRandomNum(s1_000_000);
    std::thread rand7(reinitByRandomNumM, std::ref(vec4), s10_000_000);
    std::thread rand8(reinitByRandomNumM, std::ref(vec5), s100_000_000);
    rand7.join();
    rand8.join();

    if (DEBUG) {
        randomCheckSorting(vec1);
        randomCheckSorting(vec2);
        randomCheckSorting(vec3);
        randomCheckSorting(vec4);
        randomCheckSorting(vec5);
    }

    t1 = sortAndTimeInfo(vec1, SortingType::SixteenThread);
    t2 = sortAndTimeInfo(vec2, SortingType::SixteenThread);
    t3 = sortAndTimeInfo(vec3, SortingType::SixteenThread);
    t4 = sortAndTimeInfo(vec4, SortingType::SixteenThread);
    t5 = sortAndTimeInfo(vec5, SortingType::SixteenThread);
    std::cout << "+--------------+--------+--------+--------+--------+--------+--------+--------+--------+----------+----------+" << std::endl;
    std::cout << "| 16 Thread:   |" << std::setw(7) << t1 << " |" << std::setw(7) << t1t1 - t1 << " | " 
                                    << std::setw(6) << t2 << " |" << std::setw(7) << t1t2 - t2 << " | "
                                    << std::setw(6) << t3 << " |" << std::setw(7) << t1t3 - t3 << " | "
                                    << std::setw(6) << t4 << " |" << std::setw(7) << t1t4 - t4 << " | "
                                    << std::setw(8) << t5 << " |" << std::setw(9) << t1t5 - t5 << " | Microseconds" << std::endl;
    std::cout << "+--------------+--------+--------+--------+--------+--------+--------+--------+--------+----------+----------+" << std::endl << std::endl;
    std::cout << "* Boost = time_of_1_thread - time" << std::endl;
    if (DEBUG) {
        randomCheckSorting(vec1);
        randomCheckSorting(vec2);
        randomCheckSorting(vec3);
        randomCheckSorting(vec4);
        randomCheckSorting(vec5);
    }

    std::cout << std::endl << "Hard concurrency: " << std::thread::hardware_concurrency() << std::endl;

    return 0;
}