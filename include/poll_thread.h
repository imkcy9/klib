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
#include "mailbox.h"
#include "i_poll_events.h"
#include "pipe.h"

template<class T>
class poll_thread : public i_poll_events {
public:

    poll_thread() {
    };

    virtual ~poll_thread() {
    };

    virtual bool init_before_thread_start() {
        return true;
    }

    bool start() {
        if (init_before_thread_start()) {
            m_poller = new epoll_t();
            m_maibox = new mailbox_t<T>();
            assert(m_poller && m_maibox);
            m_handle = m_poller->add_fd(m_maibox->get_fd(), this);
            m_poller->set_pollin(m_handle);
            m_poller->start();
        }
    };
    
    void post_message(T& msg) {
        m_maibox->send(msg);
    };
    
    virtual void process_msg(T& msg) {
        std::cout << msg << std::endl;
    };

private:
    virtual void in_event() {
        T msg;
        int rc = m_maibox->recv(&msg, 0);
        while (rc == 0 || errno == EINTR) {
            if (rc == 0) {
                process_msg(msg);
            }
            rc = m_maibox->recv(&msg, 0);
        }
        assert(rc != 0 && errno == EAGAIN);
    };

    virtual void out_event() {

    };

    virtual void timer_event(int id_) {

    };

private:
    epoll_t *m_poller;
    mailbox_t<T> *m_maibox;
    epoll_t::handle_t m_handle;
};

#endif /* POLL_THREAD_H */

