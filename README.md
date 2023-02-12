# Time sort in c++ 📝

Reads values from a given array. For every element with value 't' creates a async job and pauses it for 't' seconds. Afterwards it assigns value to the array at the addres in memory that 'it' points to. The time sorts our array

```c++
#include <thread>
#include <future>
#include <chrono>
#include <vector>

/* Time sort */
#include <thread>
#include <future>
#include <chrono>
#include <vector>

/* Time sort */

template<typename T>
void TimeSort(T* beg, T* end){
    std::vector<std::future<int>> threads;
    size_t size=(end - beg); end--;
    T* it = beg;

    for(int i=0; i<size; i++){
	threads.push_back(std::async(std::launch::async,[&it,&beg,i](){
		int time = static_cast<int>(*(beg + i));
		std::this_thread::sleep_for(std::chrono::milliseconds(time)); 
		*it = time;
		it++;
		
		return 1;
        }));
    }
    for(auto&& job : threads)
        job.get();

}
```

Sort is in [./src/TimeSort.h](./src/TimeSort.h) and excample of how to use it is in test [./src/main.cpp](./src/main.cpp)

