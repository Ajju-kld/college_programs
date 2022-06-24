#include <stdio.h>
#include <stdlib.h>
struct poly
{
    int coefficent;
    int exponential;
    struct poly* ptr;
    
};
typedef struct poly poly;
poly *create_node(int coef,int exp)
{
  poly *newnode = (poly *)malloc(sizeof(poly));
    newnode->coefficent = coef;
    newnode->exponential = exp;
    newnode->ptr = NULL;
    return newnode;
}
poly *add( poly *header,int coef,int expo)
{

     poly *newnode, *temp = header;
    newnode = create_node(coef,expo);
    if (header == NULL)
    {
        header = newnode;
        
    }
    else
    {
        while (temp->ptr != NULL)
        {
            temp = temp->ptr;
        }
        temp->ptr = newnode;
    }
    return header;
}

void display( poly *header)
{

     poly *current = header;

    if (header == NULL)
    {

        printf("list is empty");
    }

    else
    {
        while (current != NULL)
        {
           if(current->ptr!=NULL){
            printf("%d x^%d + ", current->coefficent,current->exponential);
            }
            else
            {
                printf("%d x^%d", current->coefficent, current->exponential);
            }
            
             current = current->ptr;
        }
    }
}

 poly  *addition( poly *p, poly *q, poly *r)
{
   
     poly *pptr, *qptr;
    int result;
    pptr=p,qptr=q;

    while ((pptr != NULL) && (qptr != NULL))
    {
        if (pptr->exponential > qptr->exponential)
        {
            r = add(r, pptr->coefficent, pptr->exponential);
            pptr = pptr->ptr;
        }
        else if (pptr->exponential < qptr->exponential)
        {
            r = add(r, qptr->coefficent, qptr->exponential);
            qptr = qptr->ptr;
        }
        else
        {
            result = pptr->coefficent + qptr->coefficent;
            r = add(r, result, pptr->exponential);
            qptr = qptr->ptr;
            pptr = pptr->ptr;
        }
    }

    while (pptr != NULL)
    {
        r = add(r, pptr->coefficent, pptr->exponential);
        pptr = pptr->ptr;
    }
    while (qptr != NULL)
    {
        r = add(r, qptr->coefficent, qptr->exponential);
        qptr = qptr->ptr;
    }
    return r;
}

 poly *sort_add( poly *header,int coef,int exp)
{
     poly *next = header, *prev = NULL;
     poly *newnode;
      newnode =create_node(coef,exp);
if(header==NULL){
            header=newnode;
}
else
{
    
    while (next != NULL && next->exponential!=exp)
    {  

        prev = next;
        next = next->ptr;
    }
    if (next!=NULL&&next->exponential==exp)
    {
        next->coefficent=next->coefficent+coef;
        
        
    }
    else if(prev!=NULL&&next==NULL)
    {
        prev->ptr=newnode;
    }
    else{
        newnode->ptr=header;
        header=newnode;
    }
    
    }
    return header;
}





 poly * multiplication( poly *p, poly *q, poly *r)
{  
    int coef,exp;
    poly *pptr=p;
     poly *qptr=q;
   
   
    while (pptr!=NULL)
    {  
        qptr=q;
        while (qptr!=NULL)
        {
           coef=pptr->coefficent*qptr->coefficent;
           exp=pptr->exponential+qptr->exponential;
          r= sort_add(r,coef,exp);
           qptr=qptr->ptr;
            
        }
        
       
        pptr=pptr->ptr;
    }
return r;
}


