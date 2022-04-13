#include <math.h>
#include <cfloat>
#include "capture.hpp"

namespace pimoroni {

  ////////////////////////////////////////////////////////////////////////////////////////////////////
  // CONSTRUCTORS
  ////////////////////////////////////////////////////////////////////////////////////////////////////
  Capture::Capture(int32_t captured_count, int32_t count_change, float average_frequency, float counts_per_revolution) :
    captured_count(captured_count), capture_count_change(count_change), average_frequency(average_frequency),
    counts_per_revolution(MAX(counts_per_revolution, FLT_MIN)) { //Clamp counts_per_rev to avoid potential NaN
  }



  ////////////////////////////////////////////////////////////////////////////////////////////////////
  // METHODS
  ////////////////////////////////////////////////////////////////////////////////////////////////////
  int32_t Capture::count() const {
    return captured_count;
  }

  ////////////////////////////////////////////////////////////////////////////////////////////////////
  float Capture::revolutions() const {
    return (float)count() / counts_per_revolution;
  }

  ////////////////////////////////////////////////////////////////////////////////////////////////////
  float Capture::angle_degrees() const {
    return revolutions() * 360.0f;
  }

  ////////////////////////////////////////////////////////////////////////////////////////////////////
  float Capture::angle_radians() const {
    return revolutions() * M_TWOPI;
  }

  ////////////////////////////////////////////////////////////////////////////////////////////////////  
  int32_t Capture::count_change() const {
    return capture_count_change;
  }

  ////////////////////////////////////////////////////////////////////////////////////////////////////
  float Capture::frequency() const {
    return average_frequency;
  }

  ////////////////////////////////////////////////////////////////////////////////////////////////////
  float Capture::revolutions_per_second() const {
    return frequency() / counts_per_revolution;
  }

  ////////////////////////////////////////////////////////////////////////////////////////////////////
  float Capture::revolutions_per_minute() const {
    return revolutions_per_second() * 60.0f;
  }

  ////////////////////////////////////////////////////////////////////////////////////////////////////
  float Capture::degrees_per_second() const {
    return revolutions_per_second() * 360.0f;
  }

  ////////////////////////////////////////////////////////////////////////////////////////////////////
  float Capture::radians_per_second() const {
    return revolutions_per_second() * M_TWOPI;
  }
  ////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////////////////
}