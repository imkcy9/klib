/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   poll_thread.h
 * Author: chengye.ke
 *
 * Created on 2017年7月12日, 下午12:59
 */

#ifndef POLL_THREAD_H
#define POLL_THREAD_H
#include "epoll.h"

class poll_thread {
public:
    poll_thread();

    virtual ~poll_thread();
private:
    kcy::epoll_t *m_poller;
};

#endif /* POLL_THREAD_H */

