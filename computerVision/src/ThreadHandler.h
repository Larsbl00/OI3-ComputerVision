#ifndef THREAD_HANDLER_H
#define THREAD_HANDLER_H

#include <functional>
#include <thread>

template <typename... Args>
class ThreadHandler
{
    public:
        ThreadHandler(void (*function)(Args...), Args... args)
            : workThread(std::thread(function, args...))
        {
        }

        ~ThreadHandler()
        {
            //Check if the function is completed
            if (workThread.joinable())
            {
                //If so join mainthread
                workThread.join();
            }
            else 
            {
                //Else it'll detach the thread
                workThread.detach();
            }
        }

    private:
        std::thread workThread;  
};

#endif