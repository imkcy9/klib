
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
#include "Dictionary.h"
using namespace std;
using namespace __gnu_cxx;
#define NDEBUG




void int_test();
file_watch fw;
int main(int argc, char** argv) {
    int_test();
    
    return 0;
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
    trie.check((unsigned char*)"abf",4);


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
    struct st_info {
        std::string stcode;
        long ei;
    };
    CDictionary<st_info> trie;
    
    
    
    
    

    //mtrie_t<st_info> trie;
    st_info info;
    
    info.stcode = "6006000";
    info.ei = 1112;
    trie.Add("6006000",&info);
    
    info.stcode = "6000011";
    info.ei = 1144;
    trie.Add("6000011",&info);
    
        info.stcode = "1006000";
    info.ei = 1113;
    trie.Add("1006000",&info);
    
    info.stcode = "1000600";
    info.ei = 1114;
    trie.Add("1000600",&info);
    
    info.stcode = "abfdh~324";
    info.ei = 1115;
    trie.Add("abfdh~324",&info);
    
    info.stcode = "abddh%324";
    info.ei = 1116;
    trie.Add("abddh%324",&info);
    
    info.stcode = "abfdh*3*4";
    info.ei = 1117;
    trie.Add("abfdh*3*4",&info);
    
    info.stcode = "XX钢铁";
    info.ei = 1118;
    trie.Add("XX钢铁",&info);
    
    info.stcode = "钢铁XX";
    info.ei = 1119;
    trie.Add("钢铁XX",&info);


    std::vector<st_info> vec_str;
    vec_str.clear();

    //trie.SearchByPrefix("bfbfabc",vec_str);
    trie.SearchByPrefix("600",vec_str);
    cout << "result y:" << vec_str.size() << endl;
    for(auto i : vec_str) {
        cout << i.ei << " " << i.stcode << endl;
    }
    
}

