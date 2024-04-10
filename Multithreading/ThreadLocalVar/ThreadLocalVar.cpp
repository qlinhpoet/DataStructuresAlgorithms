#include <iostream> 
#include <thread> 
using namespace std; 
  
thread_local int counter = 0; 
  
void increment_counter() 
{ 
    counter++; 
    cout << "Thread " << this_thread::get_id() 
         << " counter = " << counter << endl; 
} 
  
int main() 
{ 
    // Create first thread 
    thread t1(increment_counter); 
    // Create second thread 
    thread t2(increment_counter); 
    // Wait for the first thread to finish 
    t1.join(); 
    // Wait for the second thread to finish 
    t2.join(); 
    return 0; 
}