#ifndef DHASHMAP_CPP
#define DHASHMAP_CPP

/**
 * This is my HashMap Object. It stores stuff with DString keys.
 *
 * See Also DIterator.
 *
 * Copyright David Coss, 2010
 */
#include <vector>
#include <algorithm>

#include "DavidException.h"
#include "DString.h"

#ifdef __DEBUG__
#define DEBUG_PRINT(x) std::cout << x << std::endl;
#else
#define DEBUG_PRINT(x) ;
#endif


template <class T> 
class DHashMap
{
 public:
  /**
   * Empty constructor.
   */	  
  DHashMap();
  ~DHashMap();

  /**
   * Copy constructor
   */
  DHashMap(const DHashMap&);
	  
  DHashMap& operator=(const DHashMap&);
  bool operator==(const DHashMap&);
	
  /**
   * Returns a reference to the item associated with the key. If the hash map 
   * does not contain the key, a DavidException is thrown.
   *
   * @throws DavidException
   */
  const T & get(const DString& key) const;

  /**
   * Returns a reference to the item associated with the key. If the hash map 
   * does not contain the key, a DavidException is thrown.
   *
   * @throws DavidException
   */
  const T & get(const char * key) const;

  /**
   * Inserts the key and item combination. If the a key exists, it is removed first.
   */
  void put(const DString&,const T&);

  /**
   * Inserts the key and item combination. If the a key exists, it is removed first.
   */
  void put(const char * name ,const T& tree);

  /**
   * Returns a vector list of keys.
   */
  std::vector<DString> getKeys() const{ return keys; }

  /** 
   * Returns a vector list of items
   */
  std::vector<T> getObjects() const{return objects; }
  
  /**
   * Indicates whether or not the provided string is a key
   */
  bool isKey(const DString& key) const;

  /**
   * @see isKey(const DString& key);
   */
  bool containsKey(const DString&) const;
  
  /**
   * @see isKey(const DString& key)
   */
  bool contains(const DString& bean) const{return containsKey(bean);}
  
  /**
   * Indicates whether an item equal to the provided object is contained in the hash map.
   */
  bool isObject(const T&) const;
  
  /**
   * Returns the number of entries in the hash map
   */
  int getNumberOfKeys() const{return keys.size(); }
  
  /**
   * Removes the entry from the hash map, if it exists.
   */
  void removeKey(const DString&);
  
  /**
   * @see removeKey(const DString&)
   */
  void removeKey(const char * bean){ return removeKey(DString(bean));}
  
  /**
   * @see removeKey(const DString&)
   */
  void remove(const DString& bean){return removeKey(bean);}

  /**
   * @see removeKey(const DString&)
   */
  void remove(const char * bean){return removeKey(bean);}

  /**
   * Removes all entries in the hash map
   */
  void removeAll();
  
  /**
  * Gives the number of entries in the hash map.
  */
  int size(){return getNumberOfKeys();}

 private:
  std::vector<DString> keys;
  std::vector<T> objects;
};


/**
 * DIterator iterators through the DHashmap provided.
 */
template <class T>
class DIterator
{
  
 public:
  DIterator();
  DIterator(DHashMap<T> * stuff);
  DIterator(const DIterator<T>& rhs);
  ~DIterator();

  DIterator<T>& operator=(const DIterator<T>& rhs);
  bool hasNext();
  
  /**
   * Gives the next Object in the list.
   */
  const T& next();

  /**
   * Gives the next Object in the list and a pointer to its DString key
   */
  const T& next(DString * getKeyForNext);

  /**
   * Gives the next object, but does not increment  the iterator.
   */
  const T& peek();

  /**
   * Gives the next object, but does not increment  the iterator. This method gives a point to the Object's DString key.
   */
  const T& peek(DString * getKeyForNext);

 private:
  std::vector<DString> keys;//DON'T DELETE!!! THESE BELONG TO THE HASHMAP!!!
  std::vector<T> objects;
  int curr;
  int total;

};



#endif

