/*************************************************************************
 @Author: XieXun
 @Created Time : Mon  4 Jan 08:18:40 2021
 @File Name: List.h
 @Description:
 ************************************************************************/

#ifndef __LIST_H__
#define __LIST_H__
#include <string.h>
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

typedef char *ElementType;

List
MakeEmpty( List L );

int 
IsEmpty( List L );

int 
IsLast( Position P, List L );

Position 
Find( ElementType X, List L );

void 
Delete( ElementType X, List L );

Position 
FindPrevious( ElementType X, List L );

void 
Insert( ElementType X, List L, Position P );

Position 
Header( List L );

Position 
First( List L );

Position 
Advanced( Position P );

ElementType 
Retrieve( Position P );

int
ListSize( List L );

void
printList( List L );

#endif  /* __LIST_H__ */

