#pragma once
#include <list>
#include <functional>

//オブザーバーパターン Push型のようなもの
//観測するためのクラス
template <class T>
class subject
{
public:
	subject() {};
	//発行
	void OnNext(T value);
	void OnCompleted();
	void OnError(std::exception& e);

	//購読先メソッド登録
	void Subscribe(std::function<void(T value)> next);
	void Subscribe(std::function<void(T value)> next, std::function<void()> completed);
	void Subscribe(std::function<void(T value)> next, std::function<void()> completed, std::function<void()> error);

    ~subject()
    {
        on_next_function_list_.clear();
        on_completed_function_list_.clear();
        on_error_function_list_.clear();
    }

protected:
	std::list<std::function<void(T value)>> on_next_function_list_{};
	std::list<std::function<void()>> on_completed_function_list_{};
	std::list<std::function<void()>> on_error_function_list_{};
};
template<class T>
inline void subject<T>::OnNext(T value)
{
	if (on_next_function_list_.empty())return;
	for (auto function : on_next_function_list_)
	{
		function(value);
	}
}
template<class T>
inline void subject<T>::OnCompleted()
{
	if (on_completed_function_list_.empty())return;
	for (auto function : on_completed_function_list_)
	{
		function();
	}
	delete this;
}
template<class T>
inline void subject<T>::OnError(std::exception& e)
{
	if (on_error_function_list_.empty())return;
	for (auto function : on_error_function_list_)
	{
		function();
	}
	delete this;
}
template<class T>
inline void subject<T>::Subscribe(std::function<void(T value)> next)
{
	on_next_function_list_.push_back(next);
}
template<class T>
inline void subject<T>::Subscribe(std::function<void(T value)> next, std::function<void()> completed)
{
	on_next_function_list_.push_back(next);
	on_completed_function_list_.push_back(completed);
}
template<class T>
inline void subject<T>::Subscribe(std::function<void(T value)> next, std::function<void()> completed, std::function<void()> error)
{
	on_next_function_list_.push_back(next);
	on_completed_function_list_.push_back(completed);
	on_error_function_list_.push_back(error);
}
