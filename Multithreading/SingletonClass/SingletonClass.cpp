#include <iostream>

class singleton
{
    //a pointer point to unique instance
    static singleton *single;

    //constructor is private => cannot access =>cannot create object out side of this class
    singleton()     {   std::cout << "Initialize singleton \n";    }
public:
    // the copy and move operators are deleted
    singleton(const singleton&) = delete;
    singleton& operator=(const singleton&) = delete;
    singleton(singleton&&) = delete;
    singleton& operator=(singleton&&) = delete;

    //static member function to object the singleton object
    //chi khoi tao duoc instance/object neu ham get_singleton nay duoc call
    static singleton* get_singleton()
    {
        if(single == nullptr)
        {
            //if no object is initialized, creat a object
            single = new singleton;
        }
        //if one object is initialized, return that object
        return single;
    }

};

int main()
{
    singleton single1;
    return 0;
}