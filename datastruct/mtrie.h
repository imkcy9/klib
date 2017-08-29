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


template<class OBJ>
class mtrie_t {
public:
    mtrie_t();
    virtual ~mtrie_t();
    
    bool add(unsigned char *prefix_, size_t size_, OBJ* object_);

    bool rm(unsigned char *prefix_, size_t size_);
    
    bool check(unsigned char* data_, size_t size_,  std::vector<OBJ>& vec_object,size_t limit_return_size_);
    
    void rm_all();
protected:
    void search_strings(mtrie_t *current, std::string& mstring, size_t& ref_count, size_t limit_count, std::vector<OBJ>& vec_string);
    
    bool add_helper(unsigned char *prefix_, size_t size_, OBJ* object_);
    bool check_helper(unsigned char* data_, size_t size_, size_t depth, std::vector<OBJ>& vec_obj,size_t& cnt, size_t limit_return_size_);
    
    bool rm_helper(unsigned char *prefix_, size_t size_);
    bool is_redundant() const;
    
private:
    typedef std::vector<OBJ> objects_t;
    objects_t *objects;

    
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

