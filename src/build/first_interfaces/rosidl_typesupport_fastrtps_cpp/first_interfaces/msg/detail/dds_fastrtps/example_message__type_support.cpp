// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from first_interfaces:msg/ExampleMessage.idl
// generated code does not contain a copyright notice
#include "first_interfaces/msg/detail/example_message__rosidl_typesupport_fastrtps_cpp.hpp"
#include "first_interfaces/msg/detail/example_message__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace first_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_first_interfaces
cdr_serialize(
  const first_interfaces::msg::ExampleMessage & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: my_float
  cdr << ros_message.my_float;
  // Member: my_float_array
  {
    cdr << ros_message.my_float_array;
  }
  // Member: my_string
  cdr << ros_message.my_string;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_first_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  first_interfaces::msg::ExampleMessage & ros_message)
{
  // Member: my_float
  cdr >> ros_message.my_float;

  // Member: my_float_array
  {
    cdr >> ros_message.my_float_array;
  }

  // Member: my_string
  cdr >> ros_message.my_string;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_first_interfaces
get_serialized_size(
  const first_interfaces::msg::ExampleMessage & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: my_float
  {
    size_t item_size = sizeof(ros_message.my_float);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: my_float_array
  {
    size_t array_size = ros_message.my_float_array.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.my_float_array[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: my_string
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.my_string.size() + 1);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_first_interfaces
max_serialized_size_ExampleMessage(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: my_float
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: my_float_array
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: my_string
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  return current_alignment - initial_alignment;
}

static bool _ExampleMessage__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const first_interfaces::msg::ExampleMessage *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ExampleMessage__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<first_interfaces::msg::ExampleMessage *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ExampleMessage__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const first_interfaces::msg::ExampleMessage *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ExampleMessage__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_ExampleMessage(full_bounded, 0);
}

static message_type_support_callbacks_t _ExampleMessage__callbacks = {
  "first_interfaces::msg",
  "ExampleMessage",
  _ExampleMessage__cdr_serialize,
  _ExampleMessage__cdr_deserialize,
  _ExampleMessage__get_serialized_size,
  _ExampleMessage__max_serialized_size
};

static rosidl_message_type_support_t _ExampleMessage__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ExampleMessage__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace first_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_first_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<first_interfaces::msg::ExampleMessage>()
{
  return &first_interfaces::msg::typesupport_fastrtps_cpp::_ExampleMessage__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, first_interfaces, msg, ExampleMessage)() {
  return &first_interfaces::msg::typesupport_fastrtps_cpp::_ExampleMessage__handle;
}

#ifdef __cplusplus
}
#endif
