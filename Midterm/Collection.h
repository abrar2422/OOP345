#ifndef COLLECTION_H
#define COLLECTION_H
#include <iostream>
extern size_t g_step;
constexpr size_t SIZE = g_step;
class Collection {
	size_t m_id{};
	wchar_t m_name[SIZE]{};
	double* m_values{};
	size_t m_cnt{};

	static size_t idGenerator;

public:
	Collection(const wchar_t* name) : m_name{} {
		m_id = (idGenerator += g_step);
		if (name[0] && name)
		{
			for (auto i = 0; i < 31 && name[i] != L'\0'; ++i)
			{
				m_name[i] = name[i];
			}

		}
	}
	Collection(Collection&& other);
	Collection(const Collection& other);
	Collection& operator=(Collection&&) = delete;
	Collection& operator=(Collection&) = delete;
	~Collection() {
		delete[] m_values;
	}
	void print(std::ostream& out) {
		out << m_id << "-> " << m_cnt << " items!\n";
	}
};
#endif // !COLLECTION_H
