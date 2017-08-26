/* 
 * File:   trie_t.cpp
 * Author: kcy
 * 
 * Created on 2016年4月21日, 上午9:47
 */
#define NDEBUG
#include "trie_t.h"
#include <assert.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>

trie_t::trie_t()
: refcnt(0)
, min(0)
, count(0)
, live_nodes(0) {
}

trie_t::~trie_t() {
}

bool trie_t::add(unsigned char* prefix_, size_t size_) {
    if (!size_) {
        ++refcnt;
        return refcnt == 1;
    }

    unsigned char c = *prefix_;
    if (c < min || c >= min + count) {
        if (!count) {
            min = c;
            count = 1;
            next.node = NULL;
        } else if (count == 1) {
            unsigned char oldc = min;
            trie_t *oldp = next.node;
            count = (min < c ? c - min : min - c) + 1;
            next.table = (trie_t**) malloc(sizeof (trie_t*) * count);
            assert(next.table);
            for (unsigned short i = 0; i != count; ++i)
                next.table[i] = 0;

            min = std::min(min, c);
            next.table[oldc - min] = oldp;
        } else if (min < c) {
            unsigned short old_count = count;
            count = c - min + 1;
            next.table = (trie_t**) realloc((void*) next.table, sizeof (trie_t*) * count);
            assert(next.table);
            for (unsigned short i = old_count; i != count; i++)
                next.table[i] = NULL;
        } else {
            unsigned short old_count = count;
            count = (min + old_count) - c;
            next.table = (trie_t**) realloc((void*) next.table, sizeof (trie_t*) * count);
            assert(next.table);
            memmove(next.table + min - c, next.table, old_count * sizeof (trie_t*));
            for (unsigned short i = 0; i != min - c; i++)
                next.table[i] = NULL;

            min = c;
        }
    }

    if (count == 1) {
        if (!next.node) {
            next.node = new (std::nothrow) trie_t;
            assert(next.node);
            ++live_nodes;
            assert(live_nodes == 1);
        }
        return next.node->add(prefix_ + 1, size_ - 1);
    } else {
        if (!next.table[c - min]) {
            next.table[c - min] = new (std::nothrow) trie_t;
            assert(next.table[c - min]);
            ++live_nodes;
            assert(live_nodes > 1);
        }
        return next.table[c - min]->add(prefix_ + 1, size_ - 1);
    }
}

bool trie_t::check(unsigned char* data_, size_t size_, std::vector<std::string>& vec_string,size_t limit_return_size_) {
    trie_t *current = this;
    std::string m_string;
    int cnt = 0;
    while (true) {
        //        if(current->refcnt && !size_) {
        //            vec_string.push_back(m_string);
        //            return true;
        //        }
        if (!size_) {
            search_strings(current, m_string, cnt, limit_return_size_, vec_string);
            //rurn false;
            return true;
        }

        unsigned char c = *data_;
        if (c < current->min || c >= current->min + current->count)
            return false;

        if (current->count == 1) {
            m_string.push_back(c);
            current = current->next.node;
        } else {
            current = current->next.table[c - current->min];
            if (!current)
                return false;
            m_string.push_back(c);

        }
        data_++;
        size_--;
    }
}

void trie_t::search_strings(trie_t* current, std::string& mstring, int& ref_count, size_t limit_count, std::vector<std::string>& vec_string) {
    if (limit_count <= ref_count) {
        return;
    }
    if (current->count == 0) {
        ref_count++;
        vec_string.push_back(mstring);

        mstring.pop_back();

        return;
    }

    if (current->count == 1) {
        mstring.push_back(current->min);
        search_strings(current->next.node, mstring, ref_count, limit_count, vec_string);
    } else {
        for (int i = 0; i < current->count; i++) {
            if (!current->next.table[i])
                continue;
            mstring.push_back(current->min + i);
            search_strings(current->next.table[i], mstring, ref_count, limit_count, vec_string);
        }
    }
    mstring.pop_back();
}
