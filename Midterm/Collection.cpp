#include "Collection.h"

size_t g_step = 32;

Collection::Collection(const Collection& other) {
	m_id = (idGenerator += g_step);

	for (auto i = 0u; i < sizeof(m_name)/sizeof(m_name[0]); ++i)
	{
		m_name[i] = other.m_name[i];
	}
	if (other.m_values !=nullptr)
	{
		m_cnt = other.m_cnt;
		m_values = new double[other.m_cnt];
		for (auto i = 0u; i < m_cnt; ++i)
		{
			m_values[i] = other.m_values[i];
		}
	}
}
Collection::Collection(Collection&& other) : m_name{} {
	m_id = (idGenerator += g_step);

	for (auto i = 0u; i < other.m_name[i++] != L'\0';)
		m_name[i] = other.m_name[i];
	m_cnt = other.m_cnt;
	m_values = other.m_values;

	other.m_cnt = 0u;
	other.m_values = nullptr;
}