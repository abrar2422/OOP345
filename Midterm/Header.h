
	//template<typename T, int size>
	//bool allof(T& a, int s, T b) {
	//	return true;
	//}
	//template<>
	//bool allof<std::string&, int, std::string>(std::string& a, int s, std::string d) {

	//}
template<typename T>
bool allof(T*c , int s, T val) {
	bool res = false;
	for (size_t i = 0; i < s; i++)
	{
		res = c[i] == val;
	}
	return res;
}

template<>
bool allof<std::string>(std::string* c, int s, std::string val) {
	return false;
}