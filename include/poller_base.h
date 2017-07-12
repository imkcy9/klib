/* 
 * File:   poller_base.h
 * Author: kcy
 *
 * Created on 2015年12月7日, 上午10:07
 */

#ifndef POLLER_BASE_H
#define	POLLER_BASE_H
#include <map>
#include "clock.h"
#include "atomic_counter.h"
#include "i_poll_events.h"

namespace kcy
{
    struct i_poll_events;
    class poller_base_t
    {
    public:
        poller_base_t();
        virtual ~poller_base_t();
        
        int get_load();
        void add_timer(int timeout_, kcy::i_poll_events *sink_, int id_);
        void cancel_timer(kcy::i_poll_events *sink_, int id_);
        
    protected:
        void adjust_load(int amount_);
        uint64_t execute_timers();
    private:
        clock_t clock;
        
        struct timer_info_t
        {
            kcy::i_poll_events *sink;
            int id;
        };
        
        typedef std::multimap<uint64_t, timer_info_t> timers_t;
        timers_t timers;
        //原子计数器
        atomic_counter_t load;
        
        poller_base_t(const poller_base_t&);
        const poller_base_t& operator=(const poller_base_t&);
    };
    
    
    
    
    
    
}


#endif	/* POLLER_BASE_H */

