/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   thread_base.h
 * Author: chengye.ke
 *
 * Created on 2017年7月12日, 下午12:48
 */

#ifndef THREAD_BASE_H
#define THREAD_BASE_H
#include "thread.h"

class thread_base {
public:
    thread_base();
    virtual ~thread_base();
    
    virtual bool thread_init_before_start();
    virtual void run() = 0;
    
    
    bool start();
    void join();
private:

    thread_t m_worker;
};

#endif /* THREAD_BASE_H */

