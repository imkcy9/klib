
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
    trie.check((unsigned char*)"abf",3,vec_str,2);


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
    info.stcode = "国泰群安";
    info.ei = 111;
    trie.Add("abcde",&info);
    trie.Add("abcdf",&info);
    trie.Add("abddh",&info);
    trie.Add("abedh",&info);
    
    info.stcode = "国泰群安abfdh9324";
    info.ei = 1112;
    trie.Add("abfdh9324",&info);
        info.stcode = "国泰群安abfdhp324";
    info.ei = 1113;
    trie.Add("abfdhp324",&info);
    info.stcode = "国泰群安abfdh@324";
    info.ei = 1114;
    trie.Add("abfdh@324",&info);
    info.stcode = "国泰群安abfdh~324";
    info.ei = 1115;
    trie.Add("abfdh~324",&info);
    info.stcode = "国泰群安abfdh%324";
    info.ei = 1116;
    trie.Add("abfdh%324",&info);
    info.stcode = "国泰群安abfdh*3*4";
    info.ei = 1117;
    trie.Add("abfdh*3*4",&info);

    trie.Add("abgdh",&info);
    trie.Add("abhdh",&info);
    trie.Add("abudh",&info);
    trie.Add("abldh",&info);
    std::vector<st_info> vec_str;
    trie.SearchByPrefix("abf",vec_str);


    cout << "result :" << vec_str.size() << endl;
    for(auto i : vec_str) {
        cout << i.ei << " " << i.stcode << endl;
    }
    vec_str.clear();
    bool ret = trie.Remove("abfdh*3*4");
    trie.SearchByPrefix("abf",vec_str);
    cout << "result :" << vec_str.size() << endl;
    for(auto i : vec_str) {
        cout << i.ei << " " << i.stcode << endl;
    }
    
    vec_str.clear();
    ret = trie.Remove("abfdh%324");
    trie.SearchByPrefix("abf",vec_str);
    cout << "result :" << vec_str.size() << endl;
    for(auto i : vec_str) {
        cout << i.ei << " " << i.stcode << endl;
    }
    
    trie.RemoveAll();
}

