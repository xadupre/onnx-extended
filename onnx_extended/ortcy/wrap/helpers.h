#pragma once

#include <algorithm>
#include <float.h>
#include <iostream> // cout
#include <iterator>
#include <sstream>
#include <thread>
#include <vector>

namespace ortapi {

inline void MakeStringInternal(std::ostringstream &ss) noexcept {}

template <typename T>
inline void MakeStringInternal(std::ostringstream &ss, const T &t) noexcept {
  ss << t;
}

template <>
inline void MakeStringInternal(std::ostringstream &ss,
                               const std::vector<int32_t> &t) noexcept {
  for (auto it : t)
    ss << "x" << it;
}

template <>
inline void MakeStringInternal(std::ostringstream &ss,
                               const std::vector<uint32_t> &t) noexcept {
  for (auto it : t)
    ss << "x" << it;
}

template <>
inline void MakeStringInternal(std::ostringstream &ss,
                               const std::vector<int64_t> &t) noexcept {
  for (auto it : t)
    ss << "x" << it;
}

template <>
inline void MakeStringInternal(std::ostringstream &ss,
                               const std::vector<uint64_t> &t) noexcept {
  for (auto it : t)
    ss << "x" << it;
}

template <>
inline void MakeStringInternal(std::ostringstream &ss,
                               const std::vector<int16_t> &t) noexcept {
  for (auto it : t)
    ss << "x" << it;
}

template <>
inline void MakeStringInternal(std::ostringstream &ss,
                               const std::vector<uint16_t> &t) noexcept {
  for (auto it : t)
    ss << "x" << it;
}

template <typename T, typename... Args>
inline void MakeStringInternal(std::ostringstream &ss, const T &t,
                               const Args &...args) noexcept {
  MakeStringInternal(ss, t);
  MakeStringInternal(ss, args...);
}

template <typename... Args> inline std::string MakeString(const Args &...args) {
  std::ostringstream ss;
  MakeStringInternal(ss, args...);
  return std::string(ss.str());
}

#if !defined(_THROW_DEFINED)
#define EXT_THROW(...) throw std::runtime_error(MakeString(__VA_ARGS__));
#define _THROW_DEFINED
#endif

#if !defined(_ENFORCE_DEFINED)
#define EXT_ENFORCE(cond, ...)                                                    \
  if (!(cond))                                                                 \
    throw std::runtime_error(                                                  \
        MakeString("`", #cond, "` failed.", MakeString(__VA_ARGS__)));
#define _ENFORCE_DEFINED
#endif

} // namespace ortapi