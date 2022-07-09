#include <Windows.h>
#include <iostream>
#include <functional>

class FunctionalThread {
    private:
        HANDLE                      _hThreadHandle;
        DWORD                       _dwThreadId;
        std::function<void(void)>   _threadFunction;

        void runThreadFunction() {
            // Calling the thread function
            _threadFunction();
        }

    public:
        FunctionalThread() {
            _hThreadHandle = NULL;
            _dwThreadId = -1;
        }

        void create() {
            // This is for stopping double creation of the thread handle
            if( _hThreadHandle != NULL ) return;
            
            // The thread task would be assigned later
            _hThreadHandle = CreateThread(
                NULL,
                0,
                FunctionalThread::ThreadExecutionFunction,
                this,
                CREATE_SUSPENDED,
                &_dwThreadId
            );
        }

        void start(std::function<void(void)> threadTask) {
            _threadFunction = threadTask;
            ResumeThread(_hThreadHandle);
        }

        inline HANDLE getHandle() {
            return _hThreadHandle;
        }
        
        // This should run the member which would run the task
        static DWORD ThreadExecutionFunction(PVOID args) {
            FunctionalThread* thrdObj = (FunctionalThread *) args;
            thrdObj->runThreadFunction();
            return 0;
        }

        ~FunctionalThread() {
            // It might be possible the thread id was never created
            if( _hThreadHandle != NULL ) {
                CloseHandle(_hThreadHandle);
                _dwThreadId = 0;
            }
        }
};

int testUsage() {
    FunctionalThread thrd;
    thrd.create();
    
    std::cout << "Input:";
    char ch;
    std::cin >> ch;

    thrd.start([]() {
        std::cout << "Will generate some random number which I would use as some kind of argument\n";
        return;
    });

    std::cout << "Waiting for the thread to be completed\n";
    auto threadHandle = thrd.getHandle();
    WaitForSingleObject(threadHandle, INFINITE);

    return 0;
}
