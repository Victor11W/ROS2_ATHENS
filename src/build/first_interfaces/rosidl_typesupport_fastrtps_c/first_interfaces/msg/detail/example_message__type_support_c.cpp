// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from first_interfaces:msg/ExampleMessage.idl
// generated code does not contain a copyright notice
#include "first_interfaces/msg/detail/example_message__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "first_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "first_interfaces/msg/detail/example_message__struct.h"
#include "first_interfaces/msg/detail/example_message__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/primitives_sequence.h"  // my_float_array
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // my_float_array
#include "rosidl_runtime_c/string.h"  // my_string
#include "rosidl_runtime_c/string_functions.h"  // my_string

// forward declare type support functions


using _ExampleMessage__ros_msg_type = first_interfaces__msg__ExampleMessage;

static bool _ExampleMessage__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ExampleMessage__ros_msg_type * ros_message = static_cast<const _ExampleMessage__ros_msg_type *>(untyped_ros_message);
  // Field name: my_float
  {
    cdr << ros_message->my_float;
  }

  // Field name: my_float_array
  {
    size_t size = ros_message->my_float_array.size;
    auto array_ptr = ros_message->my_float_array.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: my_string
  {
    const rosidl_runtime_c__String * str = &ros_message->my_string;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

static bool _ExampleMessage__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ExampleMessage__ros_msg_type * ros_message = static_cast<_ExampleMessage__ros_msg_type *>(untyped_ros_message);
  // Field name: my_float
  {
    cdr >> ros_message->my_float;
  }

  // Field name: my_float_array
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->my_float_array.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->my_float_array);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->my_float_array, size)) {
      return "failed to create array for field 'my_float_array'";
    }
    auto array_ptr = ros_message->my_float_array.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: my_string
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->my_string.data) {
      rosidl_runtime_c__String__init(&ros_message->my_string);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->my_string,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'my_string'\n");
      return false;
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_first_interfaces
size_t get_serialized_size_first_interfaces__msg__ExampleMessage(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ExampleMessage__ros_msg_type * ros_message = static_cast<const _ExampleMessage__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name my_float
  {
    size_t item_size = sizeof(ros_message->my_float);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name my_float_array
  {
    size_t array_size = ros_message->my_float_array.size;
    auto array_ptr = ros_message->my_float_array.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name my_string
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->my_string.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _ExampleMessage__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_first_interfaces__msg__ExampleMessage(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_first_interfaces
size_t max_serialized_size_first_interfaces__msg__ExampleMessage(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: my_float
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: my_float_array
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: my_string
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

static size_t _ExampleMessage__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_first_interfaces__msg__ExampleMessage(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_ExampleMessage = {
  "first_interfaces::msg",
  "ExampleMessage",
  _ExampleMessage__cdr_serialize,
  _ExampleMessage__cdr_deserialize,
  _ExampleMessage__get_serialized_size,
  _ExampleMessage__max_serialized_size
};

static rosidl_message_type_support_t _ExampleMessage__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ExampleMessage,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, first_interfaces, msg, ExampleMessage)() {
  return &_ExampleMessage__type_support;
}

#if defined(__cplusplus)
}
#endif
