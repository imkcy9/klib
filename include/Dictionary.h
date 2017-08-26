/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Dictionary.h
 * Author: chengyeke
 *
 * Created on 2017年8月26日, 下午3:51
 */
#include "mtrie.h"
#ifndef DICTIONARY_H
#define DICTIONARY_H

template<class OBJ>
class CDictionary {
public:
    /**
     * 
     * @param key 添加一个字符串做为key到字典中
     * @param object 对应key的值
     * @return 成功或失败
     */
    inline bool Add(const char* key, OBJ* object) {
        return m_dictionary.add((unsigned char*)key, strlen(key) + 1,object);
    }
    
    /**
     * 
     * @param key 删除以key为关键字的值
     * @return 
     */
    inline bool Remove(const char* key) {
        return m_dictionary.rm((unsigned char*)key, strlen(key) + 1);
    }
    
    /**
     * 清空删除字典里的全部内容
     */
    inline void RemoveAll() {
        m_dictionary.rm_all();
    }
    
    /**
     * 
     * @param prefix 搜索的字符串前辍
     * @param vec_result 存放搜索结果的数组
     * @param max_result_size 最多返回的匹配的结果，默认-1：返回全部结果
     * @return 
     */
    inline bool SearchByPrefix(const char* prefix, std::vector<OBJ>& vec_result, size_t max_result_size = -1) {
        return m_dictionary.check((unsigned char*)prefix, strlen(prefix), vec_result, max_result_size);
    }
private:
    mtrie_t<OBJ> m_dictionary;
};

#endif /* DICTIONARY_H */

