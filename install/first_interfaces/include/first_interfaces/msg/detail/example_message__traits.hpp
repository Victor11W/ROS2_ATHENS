// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from first_interfaces:msg/ExampleMessage.idl
// generated code does not contain a copyright notice

#ifndef FIRST_INTERFACES__MSG__DETAIL__EXAMPLE_MESSAGE__TRAITS_HPP_
#define FIRST_INTERFACES__MSG__DETAIL__EXAMPLE_MESSAGE__TRAITS_HPP_

#include "first_interfaces/msg/detail/example_message__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<first_interfaces::msg::ExampleMessage>()
{
  return "first_interfaces::msg::ExampleMessage";
}

template<>
inline const char * name<first_interfaces::msg::ExampleMessage>()
{
  return "first_interfaces/msg/ExampleMessage";
}

template<>
struct has_fixed_size<first_interfaces::msg::ExampleMessage>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<first_interfaces::msg::ExampleMessage>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<first_interfaces::msg::ExampleMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // FIRST_INTERFACES__MSG__DETAIL__EXAMPLE_MESSAGE__TRAITS_HPP_
