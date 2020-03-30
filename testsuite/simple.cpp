#include <cstdlib>
#include <thread>
#include <cassert> 
#ifndef _GNU_SOURCE
#define _GNU_SOURCE 1
#endif
#include <sched.h>
#include <sys/sysinfo.h>

#include "affinity.hpp"

void producer( const int avail_cores )
{
    cpu_set_t   *cpuset( nullptr );
    cpuset = CPU_ALLOC( avail_cores );
    assert( cpuset != nullptr );
    for( auto i = 0; i < avail_cores; i++ )
    {
        affinity::set( i );

        /** now we check to see what core we're on **/
        CPU_ZERO_S( avail_cores, cpuset );
        
        CPU_SET( i /** desired core **/ ,
                 cpuset );
        
        if( sched_getaffinity( 0 /** self **/,
                               sizeof( cpu_set_t ), 
                               cpuset ) == -1 /** error per man **/ )
        {
            perror( "failed to get affinty, test case failed" );
            exit( EXIT_FAILURE );
        }
        if( CPU_ISSET_S( i /** desired core **/, sizeof( cpu_set_t ),  cpuset ) == 0 /** error code per man page **/ )
        {
            CPU_FREE( cpuset );
            exit( EXIT_FAILURE );
        }
    }
    CPU_FREE( cpuset );
    return;
}

void consumer( const int avail_cores )
{
    (void) avail_cores;
}

int main()
{
    const auto avail_cores = get_nprocs();
    
    std::thread p( producer, avail_cores );
    std::thread c( consumer, avail_cores );

    //threads will do some stuff...we wait; 

    p.join();
    c.join();
    return( EXIT_SUCCESS );
}
