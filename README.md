# Data structures and algorithms

Implementations of some data structures and algorithms

# Table of contents
- [Hashtable](#hashtable)
- [Substring search](#substring-search)
- [Red-Black Tree](#red-black-Tree)
- [Graph](#graph)
- [Encoding](#encoding)

## Hashtable
[(Back to top)](#table-of-contents)

Hashtable template class implementation with [Separate chaining](https://en.wikipedia.org/wiki/Separate_chaining) collision resolving method

- hash function
- rehashing in case of load ratio limit reached
- insert
- remove by key
- find by key

## Substring search
[(Back to top)](#table-of-contents)

[Rabin-Karp](https://en.wikipedia.org/wiki/Rabin–Karp_algorithm) string-searching algorithm implementation
Given a some number of patterns stored in a hashtable we need to count a number of each pattern occerrences in a string


## Red-Black Tree
[(Back to top)](#table-of-contents)

[Left leaning red-black tree](https://en.wikipedia.org/wiki/Left-leaning_red–black_tree) implementation


- node inserting
- hight calculation
- black-hight calculation
- tree traversal
    - prefix
    - infix
    - postfix
    - breadth-first search (BFS) with Queue implementation

## Graph
[(Back to top)](#table-of-contents)

Simple [Bellman–Ford algorithm](https://en.wikipedia.org/wiki/Bellman–Ford_algorithm) to compute the shortest path from a single vertex to all of the other vertices in a weighted digraph
Also there is a BFS search implementation for graph

## Encoding
[(Back to top)](#table-of-contents)

- Building a [prefix-search tree](https://en.wikipedia.org/wiki/Trie) by Shannon–Fano and Huffman methods
- [LZ77 and LZ78](https://en.wikipedia.org/wiki/LZ77_and_LZ78) algorithm implementations
