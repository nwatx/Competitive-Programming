#include <bits/stdc++.h>
#include <utility>

struct any
{
	void *data_;
	std::type_info const &(*getType_)();
	void *(*clone_)(void *otherData);
	void (*destroy_)(void *data);

	template <typename T>
	explicit any(T &&value)
		: data_{new T{std::forward<T>(value)}},
		  getType_{[]() -> std::type_info const &
				   { return typeid(T); }},
		  clone_([](void *otherData) -> void *
				 { return new T(*static_cast<T *>(otherData)); }),
		  destroy_([](void *data_)
				   { delete static_cast<T *>(data_); })
	{
	}

	any(any const &other)
		: data_(other.clone_(other.data_)), getType_(other.getType_), clone_(other.clone_), destroy_(other.destroy_)
	{
	}

	template <typename T>
	any &operator=(T &&value)
	{
		destroy_(data_);
		data_ = new T(std::forward<T>(value));
		getType_ = []() -> std::type_info const &
		{ return typeid(T); };
		clone_ = [](void *otherData) -> void *
		{ return new T(*static_cast<T *>(otherData)); };
		destroy_ = [](void *data_)
		{ delete static_cast<T *>(data_); };
		return *this;
	}

	~any()
	{
		destroy_(data_);
	}
};

// struct any
// {
// 	void *data_;
// 	std::type_info const &(*getType_)(); // function poitner to info
// 	void *(*clone_)(void *other);		 // function pointer to clone
// 	void (*destroy_)(void *data);

// 	template <typename T>
// 	explicit any(T &&value)
// 		: data_{new T{std::forward<T>(value)}},
// 		  getType_([]() -> std::type_info const &
// 				   { return typeid(T); }),
// 		  clone_([](void *otherData) -> void *
// 				 { return new T(*static_cast<T *>(otherData)); }),
// 		  destroy_([](void *data_)
// 				   { delete static_cast<T *>(data_); })
// 	{
// 	}

// 	any(any const &other) : data_(other.clone_(other.data_)), getType_(other.getType_), clone_(other.clone_), destroy_(other.destroy_)
// 	{
// 	}

// 	~any()
// 	{
// 		destroy_(data_);
// 	}
// };

int main()
{
	any x(std::vector<int>(100));
	x = 10;
	// x = std::string("10");
	// any x("10");
	// x = any(5);

	// std::cout << (int)x.data_ << "\n";
}