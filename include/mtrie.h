/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   mtrie.h
 * Author: kcy
 *
 * Created on 2017年08月25日, 下午2:40
 */

#ifndef MTRIE_H
#define MTRIE_H
#include <stddef.h>
#include <set>
#include <string.h>
#include <stdint.h>
#include <vector>
#include <string>
#include <trie_t.h>

template<class OBJ>
class mtrie_t {
public:
    mtrie_t();
    virtual ~mtrie_t();
    
    bool add(unsigned char *prefix_, size_t size_, OBJ* object_);

    bool rm(unsigned char *prefix_, size_t size_);
    
    bool check_prefix(unsigned char* data_, size_t size_, size_t& cnt, std::vector<OBJ>& vec_object,size_t limit_return_size_);
    
    bool check_suffix(unsigned char* data_, size_t size_, size_t& cnt, std::vector<OBJ>& vec_object,size_t limit_return_size_);
    
    bool check_mid(unsigned char* data_, size_t size_, size_t& cnt, std::vector<OBJ>& vec_object,size_t limit_return_size_);
    void rm_all();
protected:
    enum search_mode {
        search_prefix = 0,
        search_suffix,
        search_mid
    };
    trie_t* create_suffix_trie(unsigned char *ori_string, size_t size_);
    void search_strings(unsigned char* data_, size_t size_,mtrie_t *current, size_t& ref_count, size_t limit_count, std::vector<OBJ>& vec_string, search_mode mode);
    
    bool add_helper(unsigned char *prefix_, size_t size_,unsigned char* ori_str_, size_t ori_size_, OBJ* object_);
    
    bool rm_helper(unsigned char *prefix_, size_t size_);
    bool is_redundant() const;
    
private:
    typedef std::vector<OBJ> objects_t;
    objects_t *objects;
    //后缀树
    trie_t *suffix;
    
    uint32_t refcnt;
    unsigned char min;
    unsigned short count;
    unsigned short live_nodes;
    union {
        class mtrie_t *node;
        class mtrie_t **table;
    }next;
    
    
};

#include "mtrie_imp.h"

#endif /* MTRIE_H */

