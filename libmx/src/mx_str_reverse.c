#include"../inc/libmx.h"


void mx_str_reverse(char* s)
{
  if(!s)
  {
    return;
  }
  int n = mx_strlen(s) -1 ;
  int i = 0;
  while(i < n)
  {
    mx_swap_char(&s[i], &s[n]);
    n--;
    i++;
  }
}

