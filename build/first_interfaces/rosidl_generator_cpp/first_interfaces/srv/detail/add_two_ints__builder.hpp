// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from first_interfaces:srv/AddTwoInts.idl
// generated code does not contain a copyright notice

#ifndef FIRST_INTERFACES__SRV__DETAIL__ADD_TWO_INTS__BUILDER_HPP_
#define FIRST_INTERFACES__SRV__DETAIL__ADD_TWO_INTS__BUILDER_HPP_

#include "first_interfaces/srv/detail/add_two_ints__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace first_interfaces
{

namespace srv
{

namespace builder
{

class Init_AddTwoInts_Request_b
{
public:
  explicit Init_AddTwoInts_Request_b(::first_interfaces::srv::AddTwoInts_Request & msg)
  : msg_(msg)
  {}
  ::first_interfaces::srv::AddTwoInts_Request b(::first_interfaces::srv::AddTwoInts_Request::_b_type arg)
  {
    msg_.b = std::move(arg);
    return std::move(msg_);
  }

private:
  ::first_interfaces::srv::AddTwoInts_Request msg_;
};

class Init_AddTwoInts_Request_a
{
public:
  Init_AddTwoInts_Request_a()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AddTwoInts_Request_b a(::first_interfaces::srv::AddTwoInts_Request::_a_type arg)
  {
    msg_.a = std::move(arg);
    return Init_AddTwoInts_Request_b(msg_);
  }

private:
  ::first_interfaces::srv::AddTwoInts_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::first_interfaces::srv::AddTwoInts_Request>()
{
  return first_interfaces::srv::builder::Init_AddTwoInts_Request_a();
}

}  // namespace first_interfaces


namespace first_interfaces
{

namespace srv
{

namespace builder
{

class Init_AddTwoInts_Response_sum
{
public:
  Init_AddTwoInts_Response_sum()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::first_interfaces::srv::AddTwoInts_Response sum(::first_interfaces::srv::AddTwoInts_Response::_sum_type arg)
  {
    msg_.sum = std::move(arg);
    return std::move(msg_);
  }

private:
  ::first_interfaces::srv::AddTwoInts_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::first_interfaces::srv::AddTwoInts_Response>()
{
  return first_interfaces::srv::builder::Init_AddTwoInts_Response_sum();
}

}  // namespace first_interfaces

#endif  // FIRST_INTERFACES__SRV__DETAIL__ADD_TWO_INTS__BUILDER_HPP_
