#include <thread>
#include <future>
#include <chrono>
#include <vector>

/* Time sort */

template<typename T>
void TimeSort(T* beg, T* end){
    std::vector<std::future<int>> threads;
    size_t len = (end - beg);
    T* it = beg;

    for(int i=0; i<len; i++){
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
//there is no negative time 
