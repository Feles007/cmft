#pragma once

#include <cinttypes>
#include <cstdint>

#define FMT_U8  PRIu8
#define FMT_U16 PRIu16
#define FMT_U32 PRIu32
#define FMT_U64 PRIu64

#define FMT_I8  PRIi8
#define FMT_I16 PRIi16
#define FMT_I32 PRIi32
#define FMT_I64 PRIi64

#define FMT_USIZE PRIuPTR
#define FMT_ISIZE PRIiPTR

#define FMT_F32 "f"
#define FMT_F64 "f"

using u8  = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;

using i8  = std::int8_t;
using i16 = std::int16_t;
using i32 = std::int32_t;
using i64 = std::int64_t;

using usize = std::uintptr_t;
using isize = std::intptr_t;

using f32 = float;
using f64 = double;

#define loop for (;;)

// Ideally null terminated strings shouldn't be
// used anywhere, but some APIs require them.
using nt_string = const char *;
