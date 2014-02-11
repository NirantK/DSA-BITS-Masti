/*
 * Author  : Murali P
 * Created : 12-8-2010
 * Purpose : Assisted Lab1 for DSA 2010
 *
 * Description:  the Number ADT
 * */
#include "NumberOps.h"
#include "BaseOps.h"

#define normalize(a,b,c,d)                 	\
    if(a.base == b.base)                   	\
	{		                                \
			c=a;                  		 	\
			d=b;							\
	}										\
	else                   					\
	{                   					\
			if(a.base > b.base)            	\
			{                   			\
				c=a;                   		\
				d=convert(b, a.base);    	\
				base=a.base;             	\
			}                  		 		\
			else                    		\
			{                   			\
				c=convert(a, b.base);    	\
				base=b.base;                \
				d=b;                   		\
			}                   			\
	}


Number convert(Number old, int to_base)
{
    Number result = { 0, 0, NULL };
//      int num=old.num_digits;
    int base = old.base;

    long int value, balance, power;

    int i = 0;

    int pos = 0;

    Link p, r;

    p = old.lsd;
    r = NULL;

    if (p == NULL || to_base > MAX_BASE)
        return old;


    value = 0L;
    balance = 0L;
    power = 1L;
    result.base = to_base;

    for (p = old.lsd; p != NULL; p = p->next)
      {
          char ch = p->digit;

          value = lookup(p->digit);
          balance = balance + power * value;
          power = power * base;
      }

    if (result.lsd == NULL)     // first node case
      {

          value = balance % to_base;
          balance = balance / to_base;

          r = (Link) malloc(sizeof(struct __node));
          if (r == NULL)
            {
                fprintf(stderr, "Memory full\n");
                exit(-1);
            }
          result.lsd = r;
          r->digit = Base[value];
          r->position = pos;
          r->next = NULL;
          result.num_digits = i++;
      }
//        r=result.lsd;
    while (balance != 0L)
      {
          value = balance % to_base;
          balance = balance / to_base;

//          fprintf(stderr, "DEBUG %d: bal %d val %d\n", __LINE__, balance,value);
          if (r->next == NULL)
            {
                //allocate next digit
                r->next = (Link) malloc(sizeof(struct __node));
                if (r->next == NULL)
                  {
                      fprintf(stderr, "Memory full\n");
                      exit(-1);
                  }
            }
          r = r->next;
          r->digit = Base[value];
          r->position = pos++;

      }                         // p!= NULL

// set total number of digits.
    i = 0;
    for (r = result.lsd; r != NULL; r = r->next)
        i++;

    result.num_digits = i;
    result.base = to_base;

    printf(" Converting  ");
    printNumber(old);
    printf(" to ");
    printNumber(result);
    printf(" \n");
    return result;
}


Number createNumber(char *number_format)
{
    Number new = { 0, 0, NULL };
    Link p;

    char base[10];

    int i = 0, pos = 0;


//   Extract Base from the line
    while (isdigit(number_format[i]))
      {
          base[i] = number_format[i];
          i++;
      }
    if (isspace(number_format[i]))
      {
          base[i] = '\0';
          new.base = atoi(base);
      } else
      {
          fprintf(stderr,
                  " Invalid Number representation in Input file\n");
          exit(-1);
      }
//   verify whether Base is in correct range
    if (new.base > MAX_BASE || new.base <= 0)
      {
          fprintf(stderr, " Invalid Base in Input file\n");
          exit(-1);
      }
//   extract characters with corresponding symbols to the Number
//          if character not matching Base symbols, then error
//          else push it to linked list at lsd.
//
//          XXX: We are reading the number in string from MSD to LSD
    new.lsd = NULL;
    while (number_format[i] != '\0')
      {
          if (!isalnum(number_format[i]))
            {
                if (!isspace(number_format[i]))
                  {
                      fprintf(stderr,
                              " Invalid character in Input file\n");
                      exit(-1);
                  }
                i++;
                continue;

            }
          if (lookup(number_format[i]) == -1)
            {
                fprintf(stderr, " Invalid symbol in Input file\n");
                exit(-1);
            }
          p = (Link) malloc(sizeof(struct __node));
          if (p == NULL)
            {
                fprintf(stderr, "Memory Full \n");
                exit(-1);
            }
          p->position = pos++;
          p->digit = number_format[i];
          p->next = new.lsd;
          new.lsd = p;
          i++;
      }
    new.num_digits = pos;
    return (new);

}

Number add(Number a, Number b)
{
    Number result = { 0, 0, NULL };
    Number c, d;

    int i, num;

    int base = a.base;

    int balance = 0;

    Link p, q, r;

    p = q = r = NULL;
// do work here
    normalize(a, b, c, d);

    result.base = base;
    num = (c.num_digits > d.num_digits) ? c.num_digits : d.num_digits;
    p = c.lsd;
    q = d.lsd;
    r = NULL;

    if (p == NULL)
        return result;
    if (q == NULL)
        return c;

    if (result.lsd == NULL)     // i==0
      {
          int value = lookup(p->digit);

          value = value + lookup(q->digit);
          balance = value / base;
          value = value % base;

          r = (Link) malloc(sizeof(struct __node));
          if (r == NULL)
            {
                fprintf(stderr, "Memory full\n");
                exit(-1);
            }
          result.lsd = r;
          r->digit = Base[value];
          r->position = i;
          r->next = NULL;

      }
    for (i = 1; i < num /*|| p!=NULL */ ; i++)
      {
          p = p->next;
          q = q->next;

          r->next = (Link) malloc(sizeof(struct __node));
          if (r->next == NULL)
            {
                fprintf(stderr, "Memory full\n");
                exit(-1);
            }
          r = r->next;
          if (q == NULL)
            {
                int value = lookup(p->digit);

                if (balance != 0)
                  {
                      value = value + balance;
                      balance = value / c.base;
                      value = value % c.base;
                  }
                r->digit = Base[value];

            } else
            {
                int value = lookup(p->digit);

                value = value + lookup(q->digit) + balance;
                balance = value / c.base;
                value = value % c.base;
                r->digit = Base[value];
            }
          r->position = i;
          r->next = NULL;

      }
	  if(balance != 0)
	  {
//          fprintf(stderr, "DEBUG %d: bal %d val %d\n", __LINE__, balance,value);

           r->next = (Link) malloc(sizeof(struct __node));
          if (r->next == NULL)
            {
                fprintf(stderr, "Memory full\n");
                exit(-1);
            }
          		r = r->next;
                r->digit = Base[balance];
          		r->position = i;
          		r->next = NULL;
				num++;
	  }
    result.num_digits = num;

    return result;
}

Number subtract(Number a, Number b)
{
    Number result = { 0, 0, NULL };
    Number c, d;

    int i, num;

    int base = a.base;

    int balance = 0;

    Link p, q, r;

    p = q = r = NULL;
// do work here
    normalize(a, b, c, d);

    result.base = base;
    // p is the larger number, and q is the smaller number
    if (c.num_digits >= d.num_digits)
      {
          num = c.num_digits;
          p = c.lsd;
          q = d.lsd;
      } else
      {
          num = d.num_digits;
          q = c.lsd;
          p = d.lsd;
      }
    r = NULL;

    if (p == NULL)
        return result;
    if (q == NULL)
        return c;

    if (result.lsd == NULL)     // i==0
      {
          int value = lookup(p->digit);

          value = value - lookup(q->digit) - balance;
          if (value < 0)        // we have to borrow 1 from left
            {
                balance = 1;
                value = value + base;
            } else
              balance = 0;
          value = value % base;

          r = (Link) malloc(sizeof(struct __node));
          if (r == NULL)
            {
                fprintf(stderr, "Memory full\n");
                exit(-1);
            }
          result.lsd = r;
          r->digit = Base[value];
          r->position = i;
          r->next = NULL;

      }
    for (i = 1; i < num /* || p!=NULL*/ ; i++)
      {
          p = p->next;
          q = q->next;

          r->next = (Link) malloc(sizeof(struct __node));
          if (r->next == NULL)
            {
                fprintf(stderr, "Memory full\n");
                exit(-1);
            }
          if (q == NULL)
            {
                int value = lookup(p->digit);

                if (balance != 0)
                  {
                      value = value - balance;
                      if (value < 0)    // we have to borrow 1 from left
                        {
                            balance = 1;
                            value = value + base;
                        } else
                          balance = 0;
                      value = value % base;

                  }

				if(value == 0)
				{
					free(r->next);
					break;
				}
          		r = r->next;
                r->digit = Base[value];
          		r->position = i;
          		r->next = NULL;

            } else
            {
                int value = lookup(p->digit);

                value = value - lookup(q->digit) - balance;
                if (value < 0)  // we have to borrow 1 from left
                  {
                      balance = 1;
                      value = value + base;
                  } else
                    balance = 0;
                value = value % base;

          		r = r->next;
                r->digit = Base[value];
          		r->position = i;
          		r->next = NULL;
            }
          r->next = NULL;

      }

    result.num_digits = num;

    return result;

}

static void print_rec(Link l)
{
    if (l == NULL)
        return;
      else
      {
          print_rec(l->next);
          printf("%c", l->digit);
          return;
      }
}

void printNumber(Number n)
{
    printf("(");
    print_rec(n.lsd);
    printf(")%d ", n.base);
}

/*
Number convert(Number old, int to_base)
{
    Number result = { 0, 0, NULL };
//      int num=old.num_digits;
    int base = old.base;
    long long int value, power, balance;
	int i = 0;
    int pos = 0;

    Link p, r;

    p = old.lsd;
    r = NULL;

	fprintf(stderr,"DEBUG %d : Printing number to convert: %d\n" , __LINE__, to_base);
	printNumber(old);
	printf(" _____ \n");

    if (p == NULL || to_base > MAX_BASE)
        return old;
    if (result.lsd == NULL)     // first node case
      {
          value = lookup(p->digit);

          balance = value / to_base;
          value = value % to_base;

          r = (Link) malloc(sizeof(struct __node));
          if (r == NULL)
            {
                fprintf(stderr, "Memory full\n");
                exit(-1);
            }
          result.lsd = r;
          r->digit = Base[value];
          r->position = pos;
          r->next = NULL;
          power = power * base;
          p = p->next;
      }

    while (p != NULL)
      {
          long long int eq = 0;

          // for all other nodes
          //
          r = result.lsd;

          // extract next digit from old
          // compute equivalent
          eq = lookup(p->digit) * power;

          value = eq % to_base + lookup(r->digit);
          balance = eq / to_base + value / to_base;
          value = value % to_base;
          r->digit = Base[value];
          r->position = pos++;

          while (balance > 0)
            {
                if (r->next == NULL)
                  {
                      //allocate next digit
                      r->next = (Link) malloc(sizeof(struct __node));
                      if (r->next == NULL)
                        {
                            fprintf(stderr, "Memory full\n");
                            exit(-1);
                        }
                  }
                r = r->next;
                eq = balance;
                value = eq % to_base + lookup(r->digit);
                balance = eq / to_base + value / to_base;
                value = value % to_base;
                r->digit = Base[value];
                r->position = pos++;
            }                   // balance > 0

          power = power * base;
          p = p->next;
      }                         // p!= NULL

// set total number of digits.
    i = 0;
    for (r = result.lsd; r != NULL; r = r->next)
        i++;

    result.num_digits = i;
    result.base = to_base;

	fprintf(stderr,"DEBUG %d : converted lsd %d\n" , __LINE__, result.lsd -> digit);
	printNumber(result);
	printf(" _____ \n");

    return result;
}


*/
