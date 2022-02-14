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
	Dictionary() { m_items = nullptr, m_count = 0; };
	Dictionary(const Dictionary<TKey, TValue>& other) { m_items = other.m_items, m_count = other.m_count;};
	~Dictionary() { };

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
	/// <param name="key">Key being looked for </param>
	/// <param name="value">Value being comapred with</param>
	/// <returns></returns>
	bool tryGetValue(const TKey key, const TValue& value);

	/// <summary>
	/// Creats a new item with the given key and value 
	/// and adds it to the dictionary
	/// </summary>
	/// <param name="key">item being added the key associated with item</param>
	/// <param name="value">the value of this item</param>
	void addItem(const TKey& key, const TValue& value);

	/// <summary>
	/// Removes this item put in the list
	/// </summary>
	/// <param name="key">THe key associated with the value</param>
	/// <returns>returns true if key is found</returns>
	bool remove(const TKey key);

	/// <summary>
	/// Removes the item that has the given key and gives
	/// back the value of the item that was removed
	/// </summary>
	/// <param name="key">key comared to the value in the list</param>
	/// <param name="value"></param>
	/// <returns>returns true if values match</returns>
	bool remove(const TKey key, TValue& value);
	
	/// <summary>
	/// Returns the current count amount of the list
	/// </summary>
	/// <returns>count value </returns>
	const int getCount() { return m_count; };

	/// <summary>
	/// overrides = to comaore dictionary nodes 
	/// </summary>
	/// <param name="other">The comapred value</param>
	/// <returns></returns>
	const Dictionary<TKey, TValue>& operator=(const Dictionary<TKey, TValue>& other);

	/// <summary>
	/// Overrides 
	/// </summary>
	/// <param name="key"></param>
	/// <returns></returns>
	TValue operator[](const TKey key);


private: 
	Item* m_items;

	int m_count;
};

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::clear()
{
	delete[] m_items;
	m_items = nullptr;
	m_count = 0;
}

template<typename TKey, typename TValue>
inline const bool Dictionary<TKey, TValue>::containsKey(const TKey object)
{
	for (int i = 0; i < getCount(); i++)
		if (m_items[i].itemKey == object)
			return true;
	return false;
}

template<typename TKey, typename TValue>
inline const bool Dictionary<TKey, TValue>::containsValue(const TValue object)
{
	for (int i = 0; i < getCount(); i++)
		if (m_items[i].itemValue == object)
			return true;
	return false;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::tryGetValue(const TKey key, const TValue& value)
{
	return (containsKey(key) && containsValue(value));
}

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::addItem(const TKey& key, const TValue& value)
{
	Item* temp = new Item[getCount() + 1];
	Item newItem = Item{};

	newItem.itemKey = key;
	newItem.itemValue = value;

	for (int i = 0; i < getCount(); i++)
		temp[i] = m_items[i];
	temp[getCount()] = newItem;

	m_count++;

	delete[] m_items;
	m_items = temp;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::remove(const TKey key)
{
	bool wasRemoved = false;
	if (!containsKey(key))
		return false;

	Item* temp = new Item[getCount() - 1];
	int j = 0;
	for (int i = 0; i < getCount(); i++)
	{
		if (m_items[i].itemKey != key)
		{
			temp[i] = m_items[j];
			j++;
		}
		else
		{
			wasRemoved = true;
			m_count--;
		}
		
	}

	if (wasRemoved)
	{
		delete m_items; 
		m_items = temp;
	}

	return wasRemoved;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::remove(const TKey key, TValue& value)
{
	bool wasRemoved = false;
	if (!containsKey(key))
		return false;

	Item* temp = new Item[getCount() - 1];
	int j = 0;
	for (int i = 0; i < getCount(); i++)
		if (m_items[i].itemKey != key)
		{
			temp[i] = m_items[j];
			j++;
		}

		else
		{
			wasRemoved = true;
			value = m_items[i].itemValue;
		}

	if (wasRemoved)
	{
		delete m_items;
		m_items = temp;
	}

	return wasRemoved;
}

template<typename TKey, typename TValue>
inline const Dictionary<TKey, TValue>& Dictionary<TKey, TValue>::operator=(const Dictionary<TKey, TValue>& other)
{
	clear();
	
	Dictionary<TKey, TValue>* temp = new Dictionary<TKey, TValue>(other);
	
	m_count = temp->m_count;

	m_items = temp->m_items;

	return  *temp;
}

template<typename TKey, typename TValue>
inline TValue Dictionary<TKey, TValue>::operator[](const TKey key)
{
	for (int i = 0; i < getCount(); i++)
		if (m_items[i].itemKey == key)
			return m_items[i].itemValue;
		
	return TValue();
}
