/* 
 * File:   ListNode.h
 * Author: igui
 *
 * Created on 26 de mayo de 2012, 02:36 PM
 */

#ifndef LISTNODE_H
#define	LISTNODE_H

#include <cstddef>
#include "./../interfaces/ICollection.h"

class ListNode {
public:
    /**
     * Crea un ListNode que almacena un elemento no NULL y su próximo elemento
     * @param elem
     * @param next
     */
    ListNode(ICollectible *elem, ListNode *next = NULL);
    
    // métodos de acceso para elem
    ICollectible *getElem() const;
    void setElem(ICollectible *elem);
    
    // métodos de acceso para next
    ListNode *getNext() const;
    void setNext(ListNode *next);
    
private:
    ICollectible *elem;
    ListNode *next;
};

#endif	/* LISTNODE_H */

