/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   mtrie_imp.h
 * Author: kcy
 *
 * Created on 2017年08月25日, 下午2:24
 */

#ifndef MTRIE_IMP_H
#define MTRIE_IMP_H
#include "mtrie.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#ifdef DEBUG_PRINT
#include <iostream>
using namespace std;
#endif



template<class OBJ>
mtrie_t<OBJ>::mtrie_t() 
:objects(NULL)
,suffix(NULL)
,refcnt(0)
,min(0)
,count(0)
,live_nodes(0)
{
}

template<class OBJ>
mtrie_t<OBJ>::~mtrie_t() {
    if(objects)
    {
        delete objects;
        objects = NULL;
    }
    
    
}

template<class OBJ>
bool mtrie_t<OBJ>::add(unsigned char* prefix_, size_t size_, OBJ* object_)
{
    return add_helper(prefix_, size_,prefix_, size_, object_);
}

//template<class OBJ>
//bool mtrie_t<OBJ>::add(int prefix_, OBJ* object_)
//{
//    return add_helper((unsigned char*)&prefix_, sizeof(prefix_), object_);
//}

template<class OBJ>
trie_t* mtrie_t<OBJ>::create_suffix_trie(unsigned char* ori_string, size_t size_) {
    trie_t* psuffix_trie = new trie_t();
    assert(strlen((const char*)ori_string) + 1 == size_);
    
    size_t suffix_size = size_ - 1;
    for(unsigned char* p = ori_string + 1; p != ori_string + size_; p++) {
        psuffix_trie->add(p,--suffix_size);
    }
    return psuffix_trie;
}

template<class OBJ>
bool mtrie_t<OBJ>::add_helper(unsigned char* prefix_, size_t size_,unsigned char* ori_str_, size_t ori_size_, OBJ* object_)
{
    // We are at the node corresponding to the prefix. We are done.
    if(!size_)
    {
        bool result = !objects;
        if(!objects)
        {
            objects = new (std::nothrow) objects_t;
            assert(objects);
        }
        if(object_)
            objects->push_back(*object_);
        if(!suffix)
            suffix = create_suffix_trie(ori_str_,ori_size_);
        ++refcnt;
        return result;
    }
    
    unsigned char c = *prefix_;
    if(c < min || c >= min + count)
    {
        //字符超出数组范围，需要扩展
        if(!count)
        {
            min = c;
            count = 1;
            next.node = NULL;
        } else if(count == 1)
        {
            unsigned char oldc = min;
            mtrie_t *oldp = next.node;
            count = (min < c ? c - min : min -c) + 1;
            next.table = (mtrie_t**) malloc (sizeof(mtrie_t*) * count);
            assert(next.table);
            for(unsigned short i = 0; i != count; ++i)
            {
                next.table[i] = 0;
            }
            min = std::min(min,c);
            next.table[oldc - min] = oldp;
            
        } else if(min < c)
        {
            unsigned short old_count = count;
            count = c - min + 1;
            next.table = (mtrie_t**) realloc (next.table, sizeof(mtrie_t*) * count);
            assert(next.table);
            for(unsigned short i = old_count; i != count; i++)
            {
                next.table[i] = NULL;
            }
            
        } else
        {
            unsigned short old_count = count;
            count = (min + old_count) - c;
            next.table = (mtrie_t**) realloc(next.table, sizeof(mtrie_t*) * count);
            assert(next.table);
            memmove(next.table + min - c, next.table, old_count * sizeof(mtrie_t*));
            for(unsigned short i = 0; i != min - c; i ++)
            {
                next.table[i] = NULL;
            }
            min = c;
        }
    }
    
    //创建下一个node 如果存在
    if(count == 1)
    {
        if(!next.node)
        {
            next.node = new (std::nothrow) mtrie_t;
            assert(next.node);
            ++live_nodes;
        }
        return next.node->add_helper(prefix_ + 1, size_ -1,ori_str_,ori_size_, object_);
    } else
    {
        if(!next.table[c - min])
        {
            next.table[c - min] = new (std::nothrow) mtrie_t;
            assert(next.table[c - min]);
            ++live_nodes;
        }
        return next.table[c - min]->add_helper(prefix_ + 1, size_ - 1,ori_str_,ori_size_, object_);
    }
}

template<class OBJ>
bool mtrie_t<OBJ>::check_prefix(unsigned char* data_, size_t size_, size_t& cnt, std::vector<OBJ>& vec_obj,size_t limit_return_size_)
{
    //vec_obj.clear();
    
    mtrie_t *current = this;


    while(true)
    {
        //if(current->refcnt && !size_)
            //return true;
        if(!size_) {
            //return false;
            search_strings(data_, size_, current, cnt, limit_return_size_, vec_obj,search_prefix);
            //rurn false;
            return true;
        }
        
        unsigned char c = *data_;
        if(c < current->min || c >= current->min + current->count)
            return false;
        
        if(current->count == 1) {

            current = current->next.node;
        }
        else
        {
            current = current->next.table[c - current->min];
            if(!current)
                return false;

        }
        data_++;
        size_--;
    }
}

template<class OBJ>
bool mtrie_t<OBJ>::check_mid(unsigned char* data_, size_t size_, size_t& cnt, std::vector<OBJ>& vec_object, size_t limit_return_size_) {
    search_strings(data_,size_,this, cnt, limit_return_size_, vec_object, search_mid);
    return true;
}

template<class OBJ>
bool mtrie_t<OBJ>::check_suffix(unsigned char* data_, size_t size_, size_t &cnt,std::vector<OBJ>& vec_object, size_t limit_return_size_) {
     search_strings(data_,size_,this, cnt, limit_return_size_, vec_object, search_suffix);
     return true;
}

template<class OBJ>
void mtrie_t<OBJ>::search_strings(unsigned char* data_, size_t size_,mtrie_t* current, size_t& ref_count, size_t limit_count, std::vector<OBJ>& vec_obj,search_mode mode) {
    if (limit_count > 0 && limit_count <= ref_count) {
        return;
    }

    if (current->count == 0 && current->refcnt) {
        
        
        if (current->objects) {
            if(mode == search_prefix) {
                for (size_t size = 0; size != current->objects->size(); size++) {
                    vec_obj.push_back(*current->objects->begin());
                    ref_count++;
                }
            }
            if(mode == search_suffix) {
                assert(current->suffix);
                if(current->suffix->check(data_,size_) > 0) {
                    for (size_t size = 0; size != current->objects->size(); size++) {
                        vec_obj.push_back(*current->objects->begin());
                        ref_count++;
                    }
                }
            }
            if (mode == search_mid) {
                assert(current->suffix);
                if (current->suffix->check(data_, size_) == 0) {
                    for (size_t size = 0; size != current->objects->size(); size++) {
                        vec_obj.push_back(*current->objects->begin());
                        ref_count++;
                    }
                }
            }
            
        } 
        return;
    }


    if (current->count == 1) {
        
        search_strings(data_,size_,current->next.node, ref_count, limit_count, vec_obj,mode);
    } else {
        //以股票代码从前到后匹配，如搜索”600“，则优先匹配”xxx600“，再匹配”600xxx“，”x600xx“”xx600x“
        if(mode == search_mid) {
            for (int i = current->count - 1; i >= 0; i--) {
                if (!current->next.table[i])
                    continue;

                search_strings(data_,size_,current->next.table[i], ref_count, limit_count, vec_obj,mode);
            }
        } else {
            //多个搜索结果以股票代码数字递增排序，如搜索”3001”，则排序为“300101”“300102”“300103”
            for (int i = 0; i < current->count; i++) {
                if (!current->next.table[i])
                    continue;

                search_strings(data_, size_, current->next.table[i], ref_count, limit_count, vec_obj, mode);
            }
        }
    }

}

template<class OBJ>
bool mtrie_t<OBJ>::rm(unsigned char* prefix_, size_t size_)
{
    return rm_helper(prefix_,size_);
}

template<class OBJ>
void mtrie_t<OBJ>::rm_all()
{
    mtrie_t* current = this;
    
    if(current->count == 0) {
        if(current->objects) {
#ifdef DEBUG_PRINT
            for(auto i : *current->objects)
                cout << "remove ei " <<i.ei << " stcode " << i.stcode << endl;
#endif
            delete objects;
            objects = 0;
        }
        if(current->suffix) {
            delete suffix;
            suffix = 0;
        }
        return;
    }
    mtrie_t *next_node = NULL;
    if(current->count == 1) {
        next_node = current->next.node;
        if(next_node) {
            next_node->rm_all();
        } else {
            return;
        }
        assert(next_node->is_redundant ());
        if (next_node->is_redundant ()) {
#ifdef DEBUG_PRINT
            cout << "delete node" << current->min << endl;
#endif
            delete next_node;
            next_node = 0;
            --live_nodes;
            current->count = 0;
            current->min = 0;
            current->refcnt = 0;
            assert(live_nodes == 0);
        }
    }
    else {
        for(int i = 0; i < current->count; i++) {

            next_node = current->next.table [i];
            if(next_node) {
                next_node->rm_all();
            } else {
                continue;
            }
            assert(next_node->is_redundant ());
            if (next_node->is_redundant ()) {
#ifdef DEBUG_PRINT
                cout << "delete node" << current->min << endl;
#endif
                delete next_node;
                next_node = 0;
                --live_nodes;
            }
        }
    }
    assert(live_nodes == 0);
    if(live_nodes == 0) {
        current->count = 0;
        current->min = 0;
        current->refcnt = 0;
    }
    
}

template<class OBJ>
bool mtrie_t<OBJ>::rm_helper(unsigned char* prefix_, size_t size_)
{
    if(!size_)
    {
        if(objects)
        {
            //int erased = objects->erase(object_);
            //assert(erased == 1);
            objects->clear();
            if(objects->empty()) {
                delete objects;
                objects = 0;
            }
            if(suffix) {
                delete suffix;
                suffix = 0;
            }
        }
        return !objects;
    }
    unsigned char c = *prefix_;
    if (!count || c < min || c >= min + count)
        return false;

    mtrie_t *next_node =
        count == 1 ? next.node : next.table [c - min];

    if (!next_node)
        return false;

    bool ret = next_node->rm_helper (prefix_ + 1, size_ - 1);

    if (next_node->is_redundant ()) {
        delete next_node;
        assert (count > 0);

        if (count == 1) {
            next.node = 0;
            count = 0;
            --live_nodes;
            assert (live_nodes == 0);
        }
        else {
            next.table [c - min] = 0;
            assert (live_nodes > 1);
            --live_nodes;

            
            if (live_nodes == 1) {
                
                unsigned short i;
                for (i = 0; i < count; ++i)
                    if (next.table [i])
                        break;

                assert (i < count);
                min += i;
                count = 1;
                mtrie_t *oldp = next.table [i];
                free (next.table);
                next.node = oldp;
            }
            else
            if (c == min) {
                
                unsigned short i;
                for (i = 1; i < count; ++i)
                    if (next.table [i])
                        break;

                assert (i < count);
                min += i;
                count -= i;
                mtrie_t **old_table = next.table;
                next.table = (mtrie_t**) malloc (sizeof (mtrie_t*) * count);
                assert (next.table);
                memmove (next.table, old_table + i, sizeof (mtrie_t*) * count);
                free (old_table);
            }
            else
            if (c == min + count - 1) {
                
                unsigned short i;
                for (i = 1; i < count; ++i)
                    if (next.table [count - 1 - i])
                        break;

                assert (i < count);
                count -= i;
                mtrie_t **old_table = next.table;
                next.table = (mtrie_t**) malloc (sizeof (mtrie_t*) * count);
                assert (next.table);
                memmove (next.table, old_table, sizeof (mtrie_t*) * count);
                free (old_table);
            }
        }
    }

    return ret;
}


template<class OBJ>
bool mtrie_t<OBJ>::is_redundant() const
{
    return !objects && live_nodes == 0;
}

#endif /* MTRIE_IMP_H */

