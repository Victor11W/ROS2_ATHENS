// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from first_interfaces:srv/AddTwoInts.idl
// generated code does not contain a copyright notice

#ifndef FIRST_INTERFACES__SRV__DETAIL__ADD_TWO_INTS__STRUCT_H_
#define FIRST_INTERFACES__SRV__DETAIL__ADD_TWO_INTS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/AddTwoInts in the package first_interfaces.
typedef struct first_interfaces__srv__AddTwoInts_Request
{
  int32_t a;
  int32_t b;
} first_interfaces__srv__AddTwoInts_Request;

// Struct for a sequence of first_interfaces__srv__AddTwoInts_Request.
typedef struct first_interfaces__srv__AddTwoInts_Request__Sequence
{
  first_interfaces__srv__AddTwoInts_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} first_interfaces__srv__AddTwoInts_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/AddTwoInts in the package first_interfaces.
typedef struct first_interfaces__srv__AddTwoInts_Response
{
  int32_t sum;
} first_interfaces__srv__AddTwoInts_Response;

// Struct for a sequence of first_interfaces__srv__AddTwoInts_Response.
typedef struct first_interfaces__srv__AddTwoInts_Response__Sequence
{
  first_interfaces__srv__AddTwoInts_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} first_interfaces__srv__AddTwoInts_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FIRST_INTERFACES__SRV__DETAIL__ADD_TWO_INTS__STRUCT_H_
