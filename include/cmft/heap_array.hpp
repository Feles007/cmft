#pragma once

#include "allocation.hpp"
#include "core.hpp"
#include "slice.hpp"

template <typename T>
class HeapArray {
public:
	explicit HeapArray(usize length) {
		m_data   = allocate_array<T>(length);
		m_length = length;
	}
	[[nodiscard]] T *data() {
		return m_data;
	}
	[[nodiscard]] T const *data() const {
		return m_data;
	}
	[[nodiscard]] usize length() const {
		return m_length;
	}
	[[nodiscard]] T& operator[](usize i) {
		return implicit_cast<Slice<T>>(*this)[i];
	}
	[[nodiscard]] T const& operator[](usize i) const {
		return implicit_cast<Slice<const T>>(*this)[i];
	}
	[[nodiscard]] operator Slice<T>() { // NOLINT(google-explicit-constructor)
		return Slice<T>(m_data, m_length);
	}
	[[nodiscard]] operator Slice<const T>() const { // NOLINT(google-explicit-constructor)
		return Slice<const T>(m_data, m_length);
	}
	void deallocate() {
		deallocate_array(m_data, m_length);
	}

private:
	T *m_data      = nullptr;
	usize m_length = 0;
};
