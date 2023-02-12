#include <thread>
#include <future>
#include <chrono>
#include <vector>

/* Time sort */

template<typename T>
T* Switch(T* beg, T* end){
	T* ptr = beg;
	T temp; 
	for(T* it=beg; it<end; it++){
		if(*it < 0) {
			temp = *ptr;
			*ptr = *it;
			*it = temp;

			ptr++;
		}
	}
	return ptr-1;
}
template<typename T>
void __Tsort(T* begin, T* end, short sign){
	std::vector<std::future<int>> threads;
	size_t size = (end - begin) * sign;
	T* it = begin;
	printf("beg : %f\tend : %f\tsig : %i\n",*begin,*end,sign);

	for(int i=0; i<size; i++){
		threads.push_back(std::async(std::launch::async,[&it,&begin,i,sign](){
			int time = static_cast<int>(*(begin + i * sign));
			std::this_thread::sleep_for(std::chrono::milliseconds(time)); 
			*it= time;
			it+=sign;

			return 1;
		}));
	}
	for(auto&& job : threads)
		job.get();

}

template<typename T>
void TimeSort(T* begin, T* end){
	size_t size = end - begin;
	end--;
	T* neg = Switch(begin,end);
	printf("\n%i\n",size);
	for(int i=0; i<size; i++)
		printf("%f ",*(begin + i));
	printf("\n\n");

	if(*neg< 0) __Tsort(neg,begin,-1);
	__Tsort(neg+1,end,1);

	return;
}
//there is no negative time 

