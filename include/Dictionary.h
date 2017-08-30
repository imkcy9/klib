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
        size_t cnt = 0;
        int i = isdigit(prefix);
        //股票代码(根据是否是数字判断)从前到后匹配，如搜索”600“，则优先匹配”xxx600“，再匹配”600xxx“，”x600xx“”xx600x“
        if(0 == i) {
            m_dictionary.check_suffix((unsigned char*)prefix, strlen(prefix),cnt, vec_result, max_result_size);
            m_dictionary.check_prefix((unsigned char*)prefix, strlen(prefix),cnt, vec_result, max_result_size);
            m_dictionary.check_mid((unsigned char*)prefix, strlen(prefix),cnt, vec_result, max_result_size);
        } else {
            m_dictionary.check_prefix((unsigned char*)prefix, strlen(prefix),cnt, vec_result, max_result_size);
            m_dictionary.check_suffix((unsigned char*)prefix, strlen(prefix),cnt, vec_result, max_result_size);
            m_dictionary.check_mid((unsigned char*)prefix, strlen(prefix),cnt, vec_result, max_result_size);
        }
        return true;
    }
    
    /**
     * 判断字符串是否为数字
     * @param strinfo 判断的字符串
     * @return 0 为数字，-1 非数字
     */
    inline int isdigit(std::string strinfo) {
        std::string strset = "1234567890";
        int first = strinfo.find_first_of(strset);
        if (first == std::string::npos) {
            return -1;
        }
        return 0;
    } 
private:
    mtrie_t<OBJ> m_dictionary;
};

#endif /* DICTIONARY_H */

