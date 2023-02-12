#include <thread>
#include <future>
#include <chrono>
#include <vector>

/* Time sort */

template<typename T>
void TimeSort(T* arr, size_t size){
    std::vector<std::future<int>> threads;
    size_t it=0;

    for(int i=0; i<size; i++){
	threads.push_back(std::async(std::launch::async,[&it,&arr,i](){
		int time = static_cast<int>(arr[i]);
		std::this_thread::sleep_for(std::chrono::milliseconds(time)); 
		arr[it] = time; 
		it++;
		
		return 1;
        }));
    }
    for(auto&& job : threads)
        job.get();

}
//there is no negative time 
