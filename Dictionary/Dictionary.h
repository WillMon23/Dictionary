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
	~Dictionary() { delete m_items; };

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
	/// Overrides braket to take in a key and in resposne get a value in return 
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
	//deletes the items in the list
	delete[] m_items;
	//sets the item pointer to be a nullptr
	m_items = new Item();
	//total list count 
	m_count = 0;
}

template<typename TKey, typename TValue>
inline const bool Dictionary<TKey, TValue>::containsKey(const TKey object)
{
	//for every index in the count 
	for (int i = 0; i < getCount(); i++)
		//if the item key at the index matches the object 
		if (m_items[i].itemKey == object)
			//returns true
			return true;
	//other wise it should end in false
	return false;
}

template<typename TKey, typename TValue>
inline const bool Dictionary<TKey, TValue>::containsValue(const TValue object)
{
	//for every index in the count 
	for (int i = 0; i < getCount(); i++)
	{
		//if the item value at the index matches the object 
		if (m_items[i].itemValue == object)
			//returns true
			return true;
	}
	//other wise it should end in false
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
	//Creats a temporay item adress holder 
	Item* temp = new Item[getCount() + 1];
	//Creats a new item
	Item newItem = Item{};
	//Sets the values of that item 
	newItem.itemKey = key;
	newItem.itemValue = value;

	//For every item int current index 
	for (int i = 0; i < getCount(); i++)
		//set the item to be in the index of the temp array 
		temp[i] = m_items[i];
	//At the end of the index of the temp varaiable set it to be the new item
	temp[getCount()] = newItem;

	//Incrament  it by one 
	m_count++;
	
	//Delete the the items in the currrent array of items 
	delete[] m_items;
	//Set it now to be the new set of items to be the current amount 
	m_items = temp;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::remove(const TKey key)
{
	//Keeps tabs on the value changes 
	bool wasRemoved = false;
	//Checks if the key dose not exist in the items array
	if (!containsKey(key))
		//If not it just returns false
		return false;
	//Creats a temporary array of items 
	Item* temp = new Item[getCount() - 1];
	//a value to iterate through by starting at 0
	int j = 0;
	//at the index of in items 
	for (int i = 0; i < getCount(); i++)
	{
		//if the item in that index is not equal to the key
		if (m_items[i].itemKey != key)
		{
			//set the current in dex of i in the temp array to be that item at the index of j
			temp[i] = m_items[j];
			//incrament j by one
			j++;
		}
		// else wise 
		else
		{
			//Just say the item was removed 
			wasRemoved = true;
			//Then also decrament the count by one 
			m_count--;
		}
	}

	//If the iteem was found and removed 
	if (wasRemoved)
	{
		//Delete the the items in the currrent array of items
		delete m_items; 
		m_items = temp;
	}
	//Delete the the items in the currrent array of items
	return wasRemoved;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::remove(const TKey key, TValue& value)
{
	//Keeps tabs on the value changes 
	bool wasRemoved = false;
	//Checks if the key dose not exist in the items array
	if (!containsKey(key))
		//If not it just returns false
		return false;
	//Creats a temporary array of items 
	Item* temp = new Item[getCount() - 1];
	//a value to iterate through by starting at 0
	int j = 0;
	//at the index of in items 
	for (int i = 0; i < getCount(); i++)
	{
		//if the item in that index is not equal to the key
		if (m_items[i].itemKey != key)
		{
			//set the current in dex of i in the temp array to be that item at the index of j
			temp[i] = m_items[j];
			//incrament j by one
			j++;
		}
		// else wise 
		else
		{
			//Just say the item was removed 
			wasRemoved = true;
			//Then also decrament the count by one 
			m_count--;
			value = m_items[i].itemValue;
		}
	}

	//If the iteem was found and removed 
	if (wasRemoved)
	{
		//Delete the the items in the currrent array of items
		delete m_items;
		m_items = temp;
	}
	//Delete the the items in the currrent array of items
	return wasRemoved;
}

template<typename TKey, typename TValue>
inline const Dictionary<TKey, TValue>& Dictionary<TKey, TValue>::operator=(const Dictionary<TKey, TValue>& other)
{
	//Checks to see if the list is empty 
	if (other.m_count == 0)
		//If the list is empty it just returns a emmpty dictonary 
		return Dictionary<TKey, TValue>();
	//Clears the current dictoanry 
	clear();
	
	//Sets the this dictonary count to be the other dictoanry list
	m_count = other.m_count;
	
	//Creats a new Items array with the new count 
	Item* temp = new Item[getCount()];

	//for every item in the other array
	for (int i = 0; i < other.m_count; i++)
	{
		//Creats a another item variable and gets it set to be the item in that other array
		Item otherItem = other.m_items[i];
		//Ssets the other item to be that item in the index of that temp array 
		temp[i] = otherItem;
	}

	//Sets to current array of items to be the new temp created 
	m_items = temp;
	//Retums this Dictonary
	return  *this;
}

template<typename TKey, typename TValue>
inline TValue Dictionary<TKey, TValue>::operator[](const TKey key)
{
	//For every item in the index
	for (int i = 0; i < getCount(); i++)
		//if the items key equals the the key in the argument
		if (m_items[i].itemKey == key)
			//Retun that items value int he array 
			return m_items[i].itemValue;
		
	//other wise return a empty Value 
	return TValue();
}
