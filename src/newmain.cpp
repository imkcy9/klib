
#include <iostream>
#include "mtrie.h"
#include "clock.h"
#include <map>
#include "file_watch.h"
#include "mtrie.h"
#include "epoll.h"
#include "poll_thread.h"
#include <iostream>
#include "trie_t.h"
using namespace std;
using namespace __gnu_cxx;
#define NDEBUG




void int_test();
file_watch fw;
int main(int argc, char** argv) {
    trie_t trie;
    trie.add((unsigned char*)"abcde",6);
    trie.add((unsigned char*)"abcdf",6);
    trie.add((unsigned char*)"abddh",6);
    trie.add((unsigned char*)"abedh",6);
    trie.add((unsigned char*)"abfdh9324",10);
    trie.add((unsigned char*)"abfdhp324",10);
    trie.add((unsigned char*)"abfdh@324",10);
    trie.add((unsigned char*)"abfdh~324",10);
    trie.add((unsigned char*)"abfdh%324",10);
    trie.add((unsigned char*)"abfdh*3*4",10);
    trie.add((unsigned char*)"abgdh",6);
    trie.add((unsigned char*)"abhdh",6);
    trie.add((unsigned char*)"abudh",6);
    trie.add((unsigned char*)"abldh",6);
    std::vector<std::string> vec_str;
    trie.check((unsigned char*)"abf",3,vec_str);


    cout << "result :" << vec_str.size() << endl;
    for(auto i : vec_str) {
        cout << i.c_str() << endl;
    }
    
    
//    string str;
//    str.push_back('a');
//    str.push_back('b');
//    //str.push_back('\0');
//    str.pop_back();
//    cout << str.c_str() << endl;
//    
//    poll_thread<int> thr;
//    thr.start();
//    int i = 9;
//    thr.post_message(i);
//    sleep(10);
    return 0;
}

void int_test() {
    
}

