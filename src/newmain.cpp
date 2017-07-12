
#include <iostream>
#include "mtrie.h"
#include "clock.h"
#include <map>
#include "file_watch.h"
#include "mtrie.h"
#include "epoll.h"
#include "poll_thread.h"
using namespace std;
using namespace __gnu_cxx;
#define NDEBUG




void int_test();
file_watch fw;
int main(int argc, char** argv) {
    
    poll_thread<int> thr;
    thr.start();
    int i = 9;
    thr.post_message(i);
    sleep(10);
    return 0;
}

void int_test() {
    
}

