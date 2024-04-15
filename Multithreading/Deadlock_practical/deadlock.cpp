// Dining philosophers problem (part 2a)
//
// 5 philosophers sit at a round table which has 5 forks on it.
// A philosopher has a fork at each side of them.
// A philosopher can only eat if they can pick up both forks.
// If a philosopher picks up the fork on their right,
// that prevents the next philosopher from picking up their left fork.
//
// The philosophers try to pick up both forks at the same time.
// If they succeed, they can eat.
// If not, both forks are available to their neighbours.
//
// All philosophers are able to eat.
// No deadlock
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <string>
#include <chrono>

//constant due to nfork is used for size of array
const int nforks = 5;
const int nphilosophers = nforks;
std::string names[nphilosophers] ={"A", "B", "C", "D", "E"};
std::chrono::seconds think_time = std::chrono::seconds(1);
std::chrono::seconds eat_time = std::chrono::seconds(2);

std::mutex print_mutex;
std::mutex fork_mutex[nforks];
void print(int n, int lfork, int rfork)
{
	//print_mutex is unlocked in destructor
	std::lock_guard<std::mutex> print_lock(print_mutex);
	std::cout << names[n] << "'s forks are " << lfork <<" and " << rfork << std::endl;
}

void print(int n)
{
	std::lock_guard<std::mutex> print_lock(print_mutex);
	std::cout << names[n] << " is eating\n";
}
void dine(int philos)
{
	int lfork = philos;
	int rfork = (philos + 1) % nforks;

	print(philos, lfork, rfork);
	std::this_thread::sleep_for(think_time);

	//wait until both lfork and rfork mutex are locked
	std::lock(fork_mutex[lfork], fork_mutex[rfork]);
	print(philos);

	std::this_thread::sleep_for(eat_time);
	fork_mutex[lfork].unlock();
	fork_mutex[rfork].unlock();
}

int main()
{
	std::vector<std::thread> philos;

	for(int i=0; i<nphilosophers; i++)
	{
		philos.push_back(std::move(std::thread(dine, i)));
	}

	for(int i=0; i< nphilosophers; i++)
	{
		philos[i].join();
	}
	return 0;
}