#include "third_party/getTimeOfDay/include/TimeStamp.h"
#include <ctime>
#include <iostream>


TimeStamp::TimeStamp(){
}


std::string TimeStamp::process()  {

        // Declaring argument for time()
    time_t tt;

    // Declaring variable to store return value of
    // localtime()
    struct tm * ti;

    // Applying time()
    time (&tt);

    // Using localtime()
    ti = localtime(&tt);

    return asctime(ti);


}


