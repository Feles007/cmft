#pragma once

#include "core.hpp"
#include "error.hpp"
#include <type_traits>

template <typename T>
class Slice;

template <typename T>
class Slice {
public:
	Slice() = default;
	Slice(T *data, usize length) : m_data(data), m_length(length) {}
	template <typename U>
		requires(std::is_const_v<T> && std::is_same_v<U, std::remove_const_t<T>>)
	Slice(Slice<U> non_const) : m_data(non_const.m_data), m_length(non_const.m_length) {} // NOLINT(google-explicit-constructor)

	[[nodiscard]] T *data() {
		return m_data;
	}
	[[nodiscard]] T const *data() const {
		return m_data;
	}
	[[nodiscard]] T *length() const {
		return m_length;
	}
	[[nodiscard]] T& operator[](usize i) {
		debug_xassert(m_data);
		debug_xassert(i < m_length);
		return m_data[i];
	}
	[[nodiscard]] T const& operator[](usize i) const {
		debug_xassert(m_data);
		debug_xassert(i < m_length);
		return m_data[i];
	}

private:
	template <typename>
	friend class Slice;

	T *m_data      = nullptr;
	usize m_length = 0;
};
