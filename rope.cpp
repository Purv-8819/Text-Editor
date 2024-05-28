#include <iostream>
#include "rope.h"

Rope::Rope()
{
    this->root = new Node;
    this->root->height = 0;
    // space for 4 characters
    this->root->str = new char[this->Max_Len];
    this->root->lCount = 0;
    // set capacity and size
    this->capacity = 1;
    this->size = 1;
}

Rope::Rope(string s)
{
    Rope();
    this->insert(s);
}

Rope::~Rope()
{
    // Travers child first
    // Free char pointer
    // Free node poiner
}

/// @brief Rebalance the tree
void Rope::rebalance()
{
}

/// @brief Add the next in line sibling node
void Rope::addNode()
{
}

/// @brief insert the string S to the beginning
/// @param S string to be inserted
void Rope::insert(string S)
{
    Node *curr = this->root;
    // loop throuhg each character in string
    for (int i = 0; i < S.size(); i++)
    {
        // if current node has space add character
        if (this->curr->lCount < 4)
        {
            this->curr->str[this->curr->lCount] = S[i];
        }
        else
        {
            // else add sibling

            // if no space for sibling travel up ancestors till space for sibling
            // root reached, add new root with current root as left
            // Re-balance
        }
    }
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