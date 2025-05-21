# Hashing and Hash Maps

## What is Hashing 

Hashing is a technique use to uniquely map data, of any kind, to a value. This value is referred to as a **hash code** or **hash value**.

A **hash function** is the function that takes that data and returns a numerical value. Useful charicteristcs of hash functions include:
 * Be fast
 * Have a uniform distribution of outputs
 * Minimize **hash collisions** where the different inputs give the same output

---

## What is a Hash Map

A **hash map**, **hash table**, or **dictionary** is a data structure that allows for constant time insertion, lookup, and deletion by using a **key-value pair**.

### The Core Idea
 1. A key is passed to a hash function
 2. The result is mapped to an index of an array
 3. The value is stored at that index

Hash Maps typically have **O(1)** average time complexity

## Types of Hash Functions

Here are some commonly used hash functions for strings:

### 1. Additive Hash

```ruby
def additive_hash(str)
  str.bytes.sum
end
```

Simple and fast, but poor distribution and prone to collisions for anagrams (e.g., "abc" and "cab").

### 2. DJB2 (by Daniel J. Bernstein)

```ruby
def djb2(str)
  hash = 5381
  str.each_byte { |b| hash = ((hash << 5) + hash) + b } # hash * 33 + b
  hash
end
```

Good distribution and speed for strings.

### 3. FNV-1a (Fowler–Noll–Vo)

```ruby
def fnv1a(str)
  hash = 2166136261
  prime = 16777619
  str.each_byte do |b|
    hash ^= b
    hash *= prime
  end
  hash
end
```

Excellent distribution properties, widely used in hash-based structures.

## How To Handle Hash Collisions

### 1. Chaining
Each index in the array points to a list (or another structure) of key-value pairs.

```ruby
@buckets = Array.new(capacity) { [] }
@buckets[5] = [["apple", 3], ["grape", 8]]
```

### 2. Open Addressing

Common strategies:

    Linear probing: Try the next slot

    Quadratic probing: Skip slots in quadratic steps

    Double hashing: Use a second hash function to compute the step size

Example (linear probing):

```ruby
Index 5 taken → try 6 → try 7 → ...
```

## Resizing and Load Factor

The **load factor** is defined as:

```
load factor = number of elements / number of buckets
```

If the load factor becomes too high (e.g. > 0.75), the hash table should resize (usually double the array size) to reduce collisions and maintain performance.

## Sources
1. [https://www.geeksforgeeks.org/hash-table-data-structure/](https://www.geeksforgeeks.org/hash-table-data-structure/)
2. [https://algs4.cs.princeton.edu/34hash/](https://algs4.cs.princeton.edu/34hash/)
3. [https://www.programiz.com/dsa/hash-table](https://www.programiz.com/dsa/hash-table)