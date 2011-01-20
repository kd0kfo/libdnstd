#include "DHashMap.h"

template <class T> DHashMap<T>::DHashMap()
{
  keys = std::vector<DString>();
  objects = std::vector<T>();
}

  template <class T> DHashMap<T>::DHashMap(const DHashMap<T>& rhs)
  {
    objects = rhs.objects;
    keys = rhs.keys;
  }

	template <class T> DHashMap<T>::~DHashMap()
	{
	  1;
	}
	
template <class T> const T & DHashMap<T>::get(const char * bean) const {return get(DString(bean));}

template <class T> const T & DHashMap<T>::get(const DString & key) const
	{
	  if(keys.size() == 0)
	    throw DavidException("Empty DHashMap.",DavidException::DHashMap_ERROR_CODE);
	  if((keys.size() == 0) ^ (objects.size() == 0))
	    throw DavidException("DHashMap error",DavidException::DHashMap_ERROR_CODE);
	  
	  for(int i = 0;i<keys.size();i++)
	    {
	      if(keys[i] == key)
		{
		  return objects[i];
		}
	    }
	  throw DavidException(DString("No such element found: ") + key, DavidException::DHashMap_ERROR_CODE);
	}

template <class T> void DHashMap<T>::put(const char * name ,const T& tree)
{
  DString newKey(name);
  return put(newKey,tree);
}

template <class T> void DHashMap<T> ::put(const DString & key, const T & object)
{
  removeKey(key);
  keys.push_back(key);
  objects.push_back(object);
}


	template <class T> DHashMap<T>& DHashMap<T>::operator=(const DHashMap<T>& hm)
	{
		if(this == &hm)
			return *this;
		keys = std::vector<DString>(hm.keys.size());
		objects = std::vector<T>(hm.keys.size());
		for(int i = 0;i<hm.keys.size();i++)
		  {
		    keys[i] = hm.keys[i];
		    objects[i] = hm.objects[i];
		  }
		return *this;
	}

	template <class T> bool DHashMap<T>::operator==(const DHashMap<T>& hm)
	{
	  if(this == &hm)
	    return true;
	  if(keys.size() != hm.keys.size() || objects.size() != hm.objects.size())
	    return false;

	  for(int i = 0;i<keys.size();i++)
	    if(keys[i] != hm.keys[i] || objects[i] != hm.objects[i])
	      return false;

	  return true;
	}

	template <class T> bool DHashMap<T>::isKey(const DString& bean) const
	{
	  if(keys.size() == 0)
	    return false;
	  for(int i = 0;i<keys.size();i++)
	    {
	      if(keys[i] == bean)
		return true;
		
	    }
	  return false;
	}

	template <class T> bool DHashMap<T>::containsKey(const DString& bean) const
	{
	  return isKey(bean);
	}

	template <class T> bool DHashMap<T>::isObject(const T& tree) const
	{
	  if(objects.size() == 0)
	    return false;
	  for(int i = 0;i<objects.size();i++)
	    {
	      if(objects[i] == tree)
		return true;
	    }
	  return false;
	}


template <class T> void DHashMap<T>::removeKey( const DString& key)
{
  for(int i = 0;i<keys.size();i++)
    {
      if(keys[i] == key)
	{
	  objects.erase(objects.begin()+i);
	  keys.erase(keys.begin()+i);
	}
    }
}

template <class T> void DHashMap<T>::removeAll()
{
  keys.clear();
  objects.clear();
}

template <class T> DIterator<T>::DIterator()
{
  keys = std::vector<DString>();
  objects = std::vector<T>();
  curr = 10000;
}

template <class T> DIterator<T>::DIterator(const DIterator<T>& rhs)
{
  keys = rhs.keys;
  objects = rhs.objects;
  curr = rhs.curr;
}

template <class T> DIterator<T>::DIterator(DHashMap<T> * stuff)
{
  keys = stuff->getKeys();
  objects = stuff->getObjects();
  curr = 0;
}

template <class T> DIterator<T>::~DIterator()
{
  total = 0;
}

template <class T> DIterator<T>& DIterator<T>::operator=(const DIterator<T>& rhs)
{

  if(this == &rhs)
    return *this;

  keys = rhs.keys;
  objects = rhs.objects;
  curr = rhs.curr;

  return *this;
}

template <class T> bool DIterator<T>::hasNext()
{
  return curr < keys.size();
}

template <class T> const T& DIterator<T>::next()
{
  if(!hasNext())
    throw DavidException("There are no more objects.");

  return objects[curr++];
}

template <class T> const T& DIterator<T>::next(DString * getKeyForNext)
{
  const T& returnMe = next();
  if(getKeyForNext == 0)
    getKeyForNext = new DString();
  *getKeyForNext = keys[curr - 1];

  return returnMe;
}


template <class T> const T& DIterator<T>::peek()
{
  const T& returnMe = next();
  curr--;
  return returnMe;

}

template <class T> const T& DIterator<T>::peek(DString * getKeyForNext)
{
  const T& returnMe = peek();
  
  if(getKeyForNext == 0)
    getKeyForNext = new DString();
  *getKeyForNext = keys[curr];

  return returnMe;  
}


template class DHashMap<DString>;
