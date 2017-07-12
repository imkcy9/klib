/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   thread_base.cpp
 * Author: chengye.ke
 * 
 * Created on 2017年7月12日, 下午12:48
 */

#include "thread_base.h"

thread_base::thread_base() {
}

thread_base::~thread_base() {
}

static void worker_routine(void* arg_) {
    thread_base *p = (thread_base*)arg_;
    p->run();
}

bool thread_base::thread_init_before_start() {
    return true;
}

bool thread_base::start() {
    bool ret = thread_init_before_start();
    if(!ret) {
        return false;
    }
    
    m_worker.start(worker_routine,this);
}

void thread_base::join() {
    m_worker.stop();
}