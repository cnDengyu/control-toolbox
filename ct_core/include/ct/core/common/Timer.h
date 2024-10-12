/**********************************************************************************************************************
This file is part of the Control Toolbox (https://github.com/ethz-adrl/control-toolbox), copyright by ETH Zurich.
Licensed under the BSD-2 license (see LICENSE file in main directory)
**********************************************************************************************************************/

#pragma once

#include <chrono> 

namespace ct {
namespace core {
namespace tpl {

//! A timer ("stop watch") to record elapsed time based on the system clock
/*!
 * Keeps track of time in a stop watch fashion.
 */
template <typename SCALAR = double>
class Timer
{
public:
    //! Default constructor
    Timer() = default;
    //! Trigger start.
    /*!
	 * Starts the time measurement.
	 * Can be re-triggered without calling stop(). Simply overrides the start timestamp.
	 */
    inline void start() { start_time = std::chrono::high_resolution_clock::now(); }
    //! Trigger stop
    /*!
	 * Stops the time measurement.
	 */
    inline void stop() { stop_time = std::chrono::high_resolution_clock::now(); }
    //! Get the elapsed time between calls to start() and stop()
    /*!
	 *
	 * @return time in seconds
	 */
    SCALAR getElapsedTime() const {  
        auto duration = stop_time - start_time;  
        return std::chrono::duration_cast<std::chrono::duration<SCALAR>>(duration).count();  
    }

    //! Resets the clock.
    /*!
	 * Not needed to be called after start()/stop() calls.
	 */
    void reset() {  
        start_time = std::chrono::time_point<std::chrono::high_resolution_clock>::min();  
        stop_time = std::chrono::time_point<std::chrono::high_resolution_clock>::min();  
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time;  
    std::chrono::time_point<std::chrono::high_resolution_clock> stop_time;  
};
}

typedef tpl::Timer<double> Timer;
}
}
