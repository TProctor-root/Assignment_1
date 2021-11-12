#pragma once
class ordered_array {
  public:
    /* constructor
       Construct a new ordered_array with the given capacity (maximum size).
       The size of a new ordered_array should be 0.
    */
    ordered_array(int c) {
        cap = c;
        data = new int[cap];
        sz = 0;
        t = 0;
    } 

    // destructor
    ~ordered_array() {
        delete[] data;
    }

    /* size()
       Returns the size (number of elements in the array).
    */
    int size() {
        return sz;
    }

    /* capacity()
       Returns the maximum size of the array.
    */
    int capacity() {
        return cap;
    }

    /* insert(e)
       Insert e into the array. If size() == capacity() then this does 
       nothing. Note that it is OK to insert duplicates; if n copies of a value
       are inserted into the array then n copies should appear in the array.
    */
    void insert(int elem) {
        if (size() != capacity()) {
            data[size()] = elem;
            sz++;
            for(int i = 0; i < size(); i++) {
                for(int j = i + 1; j < size(); j++) {
                    if (data[i] > data[j]) {
                        t = data[i];
                        data[i] = data[j];
                        data[j] = t;
                    }
                }
            }
        }
    }
    
    /* remove(e)
       Remove e from the array, if it exists. (If it does not exist, the
       array should be unchanged.) If multiple copies of e are present, only
       one should be removed.
    */
    void remove(int elem) {
        for (int i = 0; i < size(); i++) {
            if (data[i] == elem) {
                for (int j = i; j < size() - 1; j++) {
                    data[j] = data[j + 1];
                }
                sz--;
                break;
            }
        }
    }
    
    /* exists(e)
       Returns true if e is present at least once in the array.
    */
    bool exists(int elem) {
        if(size() == 0) {
            return false;
        }
        for (int i = 0; i <= size(); i++) {
            if (data[i] == elem) {
                return true;
            }
        }
        return false;
    }

    /* begin()
       Return a pointer to the first element of the array. The value pointed to
       by this should be the smallest element in the array (if the array is not
       empty). 
    */
    int* begin() {
        return &data[0];
    }
    
    /* end()
       Returns a pointer to one-past-the-end (last + 1) element of the array. 
       This should ignore any "unused" elements past the end of the array, i.e.,
       > size but < capacity. The value pointed to by *(end() - 1) should be
       the largest value in the array, if the array is not empty. 
    */
    int* end() {
        return &data[size()];
    }

  private:
  int* data;
  int cap;
  int sz;
  int t;
  
    // Private members as needed
};