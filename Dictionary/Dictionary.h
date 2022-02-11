#pragma once


template <typename TKey, typename TValue>
class Dictionary {
private:
	struct Item
	{
		TKey itemKey;
		TValue itemValue;
	};


public:
	Dictionary();
	Dictionary(const Dictionary<TKey, TValue>& other);
	~Dictionary();

	/// <summary>
	/// Meant to clear the whole dictionary 
	/// </summary>
	void clear();

	/// <summary>
	/// checks to see if a item with the given key is in the dictionary
	/// </summary>
	/// <param name="object">Key being looked for </param>
	/// <returns></returns>
	const bool containsKey(const TKey object);

	/// <summary>
	/// Checks to see if a given value exists in the dictonary
	/// </summary>
	/// <param name="object">Value being comapred with</param>
	/// <returns></returns>
	const bool containsValue(const TValue object);

	/// <summary>
	/// Tries to get the key and the value and get the value and checks to see if it exists
	/// in the dictionary
	/// </summary>
	/// <param name="key"></param>
	/// <param name="value"></param>
	/// <returns></returns>
	const bool tryGetValue(const TKey key, const TValue& value);


	void addItem(const TKey& key, const TValue& value);
	bool remove(const TKey key);
	bool remove(const TKey key, TValue& value);
	const int getCount();
	const Dictionary<TKey, TValue> operator=(const Dictionary<TKey, TValue>& other);


private: 
	Item* m_item = nullptr;

	int m_count = 0;


};