//
// Created by zts on 16-12-14.
//

#ifndef SSDB_PTIMER_H
#define SSDB_PTIMER_H

#include "log.h"
#include <string>
#include <sys/time.h>

class PTimer {
private:
    timeval t_start;
    timeval t_end;
    std::string name;
public:
    PTimer(std::string name) {
        this->name = name;
    }

    void begin() {
        gettimeofday(&t_start, NULL);
    }

    void end() {
        gettimeofday(&t_end, NULL);
        double delta = (double) ((t_end.tv_sec - t_start.tv_sec) * 1000000 + (t_end.tv_usec - t_start.tv_usec)) /
                       1000000.0;                                       //second
        log_info("%s costs: %f second", name.c_str(), delta);

     }
};

#ifdef PTIMER
#define PTS(name) PTimer name(#name);name.begin();
#define PTE(name) name.end();
#else
#define PTS(name) "";
#define PTE(name) "";
#endif

// -D PTIMER=ON
#endif //SSDB_PTIMER_H