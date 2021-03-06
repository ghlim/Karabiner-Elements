#pragma once

#include "types/absolute_time_duration.hpp"
#include <cstdint>
#include <ostream>
#include <type_safe/strong_typedef.hpp>

namespace krbn {
struct absolute_time : type_safe::strong_typedef<absolute_time, uint64_t>,
                       type_safe::strong_typedef_op::equality_comparison<absolute_time>,
                       type_safe::strong_typedef_op::relational_comparison<absolute_time>,
                       type_safe::strong_typedef_op::increment<absolute_time>,
                       type_safe::strong_typedef_op::decrement<absolute_time> {
  using strong_typedef::strong_typedef;
};

inline absolute_time_duration operator-(const absolute_time& a,
                                        const absolute_time& b) {
  return absolute_time_duration(type_safe::get(a) - type_safe::get(b));
}

inline absolute_time operator+(const absolute_time& a,
                               const absolute_time_duration& b) {
  return absolute_time(type_safe::get(a) + type_safe::get(b));
}

inline absolute_time operator-(const absolute_time& a,
                               const absolute_time_duration& b) {
  return absolute_time(type_safe::get(a) - type_safe::get(b));
}

inline absolute_time& operator+=(absolute_time& a,
                                 const absolute_time_duration& b) {
  a = a + b;
  return a;
}

inline absolute_time& operator-=(absolute_time& a,
                                 const absolute_time_duration& b) {
  a = a - b;
  return a;
}

inline std::ostream& operator<<(std::ostream& stream, const absolute_time& value) {
  return stream << type_safe::get(value);
}
} // namespace krbn
