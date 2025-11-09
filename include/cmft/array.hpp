#pragma once

#include "core.hpp"
#include "slice.hpp"

template <typename T, usize N>
class Array {
public:
	[[nodiscard]] usize length() {
		return N;
	}
	[[nodiscard]] T& operator[](usize i) {
		return static_cast<Slice<T>>(*this)[i];
	}
	[[nodiscard]] T const& operator[](usize i) const {
		return static_cast<Slice<const T>>(*this)[i];
	}
	operator Slice<T>() { // NOLINT(google-explicit-constructor)
		return Slice<T>(m_data, N);
	}
	operator Slice<const T>() const { // NOLINT(google-explicit-constructor)
		return Slice<const T>(m_data, N);
	}

private:
	T m_data[N]{};
};
