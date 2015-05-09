  #include <stdio.h>
  #include <ctype.h>
  #include <stdlib.h>

  int get_word(char *buf, int buf_size, FILE *fp)
  {
      int len;
      int ch;

     while ((ch = getc(fp)) != EOF && !isalnum(ch))
          ;
      if (ch == EOF)
          return EOF;

      len = 0;
      do {
          buf[len] = ch;
          len++;
          if (len >= buf_size) {
              fprintf(stderr, "word too long.\n");
              exit(1);
         }
     } while ((ch = getc(fp)) != EOF && isalnum(ch));
     buf[len] = '\0';

     return len;
  }

  int main(void)
  {
      char buf[256];

      while (get_word(buf, 256, stdin) != EOF) {
          printf("<<%s>>\n", buf);
      }

      return 0;
  }



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *deleteDuplicates(struct ListNode *head) {
    struct ListNode *watch, *pre, *q;
    int flag = 0;

    if(head == NULL)
        return NULL;

    watch = NULL;
    pre = head;
    q   = head->next;
    while(q){

        while(q && (pre->val == q->val)){
            pre->next = q->next;
            q = q->next;
            flag = 1;
        }
        if(flag == 1){
            if(pre == head){
                head = pre->next;
            }else if(watch)
                watch->next = pre->next;
            pre = pre->next;
            if(q)
                q = q->next;
            flag = 0;
            continue;
        }

        if(watch == NULL)
            watch = pre;
        else
            watch = watch->next;
        pre = pre->next;
        q = q->next;
    }

    return head;
}
