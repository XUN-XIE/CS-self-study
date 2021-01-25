/************************************************************************
 @Author: XieXun
 @Created Time : Mon  4 Jan 08:22:51 2021
 @File Name: List.c
 @Description:
 ************************************************************************/

#include "List.h"
#include <stdio.h>
#include <stdlib.h>

struct Node {
    ElementType Element;
    Position Next;
};


// Return true if L is empty
int
IsEmpty( List L )
{
    return L->Next == NULL;
}

// return true if P is the last position in list L
// Parameter L is unused in this implementation
int
IsLast( Position P, List L )
{
    return P->Next == NULL;
}

// Return Position of X in L, NULL if not found
Position
Find( ElementType X, List L )
{
    Position P;

    P = L->Next;
    while ( P != NULL && P->Element != X )
        P = P->Next;
    return P;
}

// Delete first occurrence of X from a list
// assume use of a header node
void
Delete( ElementType X, List L )
{
    Position P, TmpCell;

    P = FindPrevious( X, L );

    if ( !IsLast( P, L ) )  // assumption of header use
    {   // X is found, delete it
        TmpCell = P->Next;
        P->Next = TmpCell->Next;    // bypass deleted cell
        free( TmpCell );
    }
}

// if X is not found, then Next field of returned position is NULL(namely last node or header of empty list)
// Assumes a header
Position
FindPrevious( ElementType X, List L )
{
    Position P;

    P = L;
    while ( P->Next != NULL && strcmp(P->Next->Element , X) )
        P = P->Next;

    return P;
}

// Insert (after legal position P)
// header implementation assumed
// Parameter L is unused in this implementation
void
Insert( ElementType X, List L, Position P )
{
    Position TmpCell;

    TmpCell = malloc( sizeof( struct Node ) );
    if ( TmpCell == NULL )
    {
        printf("malloc failed, out of memory!\n");
        exit(1);
    }

    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}

List
MakeEmpty( List L )
{
    Position P, Tmp;

    P = L->Next;
    L->Next = NULL;
    while ( P != NULL )
    {
        Tmp = P->Next;
        free(P);
        P = Tmp;
    }
    return L;
}

int
ListSize( List L )
{
    int count = 0;
    Position cursor = L->Next;
    while (cursor)
    {
        count++;
        cursor = cursor->Next;
    }
    return count;
}

void
printList( List L )
{
    Position cursor = L->Next;
    while (cursor)
    {
        printf("%s\n", cursor->Element);
        cursor = cursor->Next;
    }
}