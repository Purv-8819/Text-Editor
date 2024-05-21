#include <iostream>
#include "rope.h"

Rope::Rope()
{
    this->parent = nullptr;
    this->left = nullptr;
}

Rope::~Rope()
{
}

int Rope::test()
{
    return this->lCount;
}

/// @brief insert the string S beginning at position i in the rope-string
/// @param i index to insert string at
/// @param S string to be inserted
void Rope::insert(int i, string S)
{
}

/// @brief Get the character at index i
/// @param i index to get char at
/// @return char at index i
char Rope::index(int i)
{
}

/// @brief Concatanate 2 Ropes together
/// @param R2 The root node of the second rope
/// @param before Bool on if the rope goes before or after the current node
void Rope::concat(Rope *R2, bool before)
{
}

/// @brief split the current rope at index i
/// @param i index to split rope at
/// @return pair of 2 ropes split at i, with char at i are in first rope
pair<Rope *, Rope *> Rope::split(int i)
{
}

/// @brief Delete the substring from index i to index j
/// @param i starting index to delete at, inclusive
/// @param j ending index to delte till, exclusive
void Rope::del(int i, int j)
{
}

/// @brief Get the string that the rope represents
/// @return The string
string Rope::getString()
{
}

/// @brief Get the string that the rope represents starting at index i
/// @param i The index to get string from
/// @return substring starting from index i
string Rope::getString(int i)
{
}

/// @brief Get the string that the rope represents starting at index i to index j
/// @param i The index to get string from, inclusive
/// @param j The index to get string till, exclusive
/// @return substring from i to j
string Rope::getString(int i, int j)
{
}