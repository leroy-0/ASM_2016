#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>
#include <assert.h>

void    memcpy_test()
{
  char    arr[8];

  puts("==> [MEMCPY] Start");
  puts("-> memcpy(arr, \"abcdef\", 7)");
  assert(memcpy(arr, "abcdef", 7) == arr);
  puts(arr);
  //puts("-> memcpy(&arr[3], arr, 3)");
  //assert(memcpy(&arr[3], arr, 3) == &arr[3]);
  //puts(arr);
  puts("==> [MEMCPY] End");
}

void    memmove_test()
{
  char    arr[32];

  puts("==> [MEMMOVE] Start");
  puts("-> memove(arr, \"abcdefghijklmnopqrstuvwxyz\", 27)");
  assert(memmove(arr, "abcdefghijklmnopqrstuvwxyz", 27) == arr);
  puts(arr);
  puts("-> memmove(&arr[4], arr, 27)");
  assert(memmove(&arr[4], arr, 27) == &arr[4]);
  puts(arr);
  puts("-> memmove(arr, &arr[4], 27)");
  assert(memmove(arr, &arr[4], 27) == arr);
  puts(arr);
  puts("==> [MEMMOVE] End");
}

void    memset_test()
{
  char    arr[6];

  puts("==> [MEMSET] Start");
  puts("-> memset(arr, 0, sizeof(arr));");
  assert(memset(arr, 0, sizeof(arr)) == arr);
  puts(arr);
  puts("-> memset(arr,'\\n', 5);");
  assert(memset(arr, '\n', 5) == arr);
  puts(arr);
  puts("-> memset(arr, 256 + 42, 4);");
  assert(memset(arr, 256 + 42, 4) == arr);
  puts(arr);
  puts("==> [MEMSET] End");
}

void    read_test()
{
  char    buffer[4096];
  ssize_t ret;

  puts("==> [READ] Start");
  puts("-> read(0, buffer, sizeof(buffer) - 1) // sizeof(buffer) = 4096");
  if ((ret = read(0, buffer, sizeof(buffer) - 1)) >= 0)
    buffer[ret] = '\0';
  printf("bytes read:%i, content:%s$\n", ret, buffer);
  puts("-> ret = read(42, buffer, sizeof(buffer) - 1)");
  ret = read(42, buffer, sizeof(buffer) - 1);
  printf("bytes read : %u, ret == -1 ? %i\n", ret, ret == -1);
  perror("read");
  puts("==> [READ] End");
  errno = 0;
}

void    rindex_test()
{
  char    *ch;
  char    *str = "abcdefghijklmabcdefghijklm";

  puts("==> [RINDEX] Start");
  puts("-> rindex(str, 'a')");
  ch = rindex(str, 'a');
  printf("rindex str={%p, %s}, ch={%p, %c}, ch-str=%i\n",
   str, str,
   ch, (ch == NULL ? '*' : *ch),
   ch - str);
  puts("-> rindex(str, '$')");
  ch = rindex(str, '$');
  printf("rindex str={%p, %s}, ch={%p, %c}, ch-str=%i\n",
   str, str,
   ch, (ch == NULL ? '*' : *ch),
   ch - str);
  puts("==> [RINDEX] End");
}

void    strcasecmp_test()
{
  size_t  i;
  size_t  j;
  const char  *s[] =
    {
      "amen",
      "AMeN",
      "amen!",
      "AMeN!",
      "cctvvmb",
      NULL
    };

  puts("==> [STRCASECMP] Start");
  for (i = 0; s[i] != NULL; ++i)
    for(j = 0; s[j] != NULL; ++j)
      printf("-> strcasecmp(%s, %s) = %i\n", s[i], s[j],
       strcasecmp(s[i], s[j]));
  puts("==> [STRCASECMP] End");
}

void    strchr_test()
{
  char    *ch;
  char    *str = "abcdefghijklmabcdefghijklm";

  puts("==> [STRCHR] Start");
  puts("-> strchr(str, 'a')");
  ch = strchr(str, 'a');
  printf("str={%p, %s}, ch={%p, %c}, ch-str=%i\n",
   str, str,
   ch, (ch == NULL ? '*' : *ch),
   ch - str);
  puts("-> strchr(str, '$')");
  ch = strchr(str, '$');
  printf("str={%p, %s}, ch={%p, %c}, ch-str=%i\n",
   str, str,
   ch, (ch == NULL ? '*' : *ch),
   ch - str);
  puts("==> [STRCHR] End");
}

void    strcmp_test()
{
  size_t  i;
  size_t  j;
  const char  *s[] =
    {
      "amen",
      "AMeN",
      "amen!",
      "AMeN!",
      "cctvvmb",
      NULL
    };

  puts("==> [STRCMP] Start");
  for (i = 0; s[i] != NULL; ++i)
    for(j = 0; s[j] != NULL; ++j)
      printf("-> strcmp(%s, %s) = %i\n", s[i], s[j],
       strcmp(s[i], s[j]));
  puts("==> [STRCMP] End");
}

void    strcspn_test()
{
  char    *s = "Amen is watching you.";
  char    *reject = "abcdefghi";

  puts("==> [STRCSPN] Start");
  printf("-> strcspn(\"%s\", \"%s\") = %zu\n", s, reject,
   strcspn(s, reject));
  puts("==> [STRCSPN] End");
}

void    strlen_test()
{
  size_t  i;
  char    *s[] =
    {
      "haha",
      "",
      "abcdefghijklmnopqrstuvwxyz",
      NULL
    };

  puts("==> [STRLEN] Start");
  for (i = 0; s[i] != NULL; i++)
    printf("-> strlen(\"%s\") = %i\n", s[i], strlen(s[i]));
  puts("==> [STRLEN] End");
}

void    strncmp_test()
{
  size_t  i;
  size_t  j;
  size_t  n;
  const char  *s[] =
    {
      "amen",
      "AMeN",
      "amen!",
      "AMeN!",
      "cctvvmb",
      NULL
    };

  puts("==> [STRNCMP] Start");
  for (i = 0; s[i] != NULL; ++i)
    for(j = 0; s[j] != NULL; ++j)
      {
  n = rand() % (strlen(s[i]) + 8);
  printf("-> strncmp(%s, %s, %zu) = %i\n", s[i], s[j], n,
         strncmp(s[i], s[j], n));
      }
  puts("==> [STRNCMP] End");
}

void    strstr_test()
{
  size_t  i;
  size_t  j;
  char    *r;
  char    *s[] =
    {
      "abcdef",
      "abc",
      "def",
      "ghi"
      "",
      NULL
    };

  puts("==> [STRSTR] Start");
  for (i = 0; s[i] != NULL; i++)
    for (j = 0; s[j] != NULL; j++)
      {
  r = strstr(s[i], s[j]);
  printf("-> strstr(\"%s\", \"%s\") = \"%s\"\n",
         s[i], s[j], (r == NULL ? "(nil)" : r));
      }
  puts("==> [STRSTR] End");
}

void    write_test()
{
  size_t  i;
  ssize_t ret;
  char    *s[] =
    {
      "",
      "\n",
      "a\n",
      "ab\n",
      "abc\n",
      NULL
    };

  puts("==> [WRITE] Start");
  for (i = 0; s[i] != NULL; i++)
    printf("-> write(1, \"%s\", %zu) = %i\n",
     s[i], strlen(s[i]),
     write(1, s[i], strlen(s[i])));
  puts("-> ret = write(42, \"toto\", 4)");
  ret = write(42, "toto", 4);
  printf("bytes write : %u, ret == -1 ? %i\n", ret, ret == -1);
  perror("write");
  puts("==> [WRITE] End");
  errno = 0;
}

int main()
{

  //TESTS PART 1

  char *str = malloc(sizeof(char) * 100);
  char *str1 = malloc(sizeof(char) * 100);
  char *str2 = malloc(sizeof(char) * 100);
  str = "Salut1";
  str2 = "Sblut";
  str1 = "Salut123";

  printf("/// STRLEN ///\n");
  printf("%d\n", strlen(str));

  printf("Arguments 4 : %s & sont int : %i\n", "4", 4);
  printf("///// STRCMP /////\n");
  printf("-----------------\n[Chaine Salut1 -- Chaine Salut1]\n");
  printf("return == %i\n", strcmp(str, str));
  printf("-----------------\n[Chaine Sblut -- Chaine Salut1]\n");
  printf("return == %i\n", strcmp(str2, str));
  printf("-----------------\n[Chaine Salut1 -- Chaine Salut123]\n");
  printf("return == %i\n", strcmp(str, str1));
  printf("-----------------\n[Chaine Salut123 -- Chaine Salut1]\n");
  printf("return == %i\n", strcmp(str1, str));
  printf("-----------------\n[Chaine Vide -- Chaine Salut]\n");
  str = "Salut";
  str1 = "";
  printf("return == %i\n", strcmp(str1, str));
  printf("-----------------\n[Chaine Salut -- Chaine vide]\n");
  printf("return == %i\n", strcmp(str, str1));

  printf("///// STRNCMP /////\n");
  str = "Salut1";
  str1 = "Salut123";
  str2 = "Sblut";
  printf("-----------------\n[Chaine Salut1 -- Chaine Salut1]\n");
  printf("return == %i\n", strncmp(str, str, 4));
  printf("-----------------\n[Chaine Sblut -- Chaine Salut1]\n");
  printf("return == %i\n", strncmp(str2, str, 4));
  printf("-----------------\n[Chaine Salut1 -- Chaine Salut123]\n");
  printf("return == %i\n", strncmp(str, str1, 4));
  printf("-----------------\n[Chaine Salut123 -- Chaine Salut1]\n");
  printf("return == %i\n", strncmp(str1, str, 4));
  printf("-----------------\n[Chaine Vide -- Chaine Salut]\n");
  str = "Salut";
  str1 = "";
  printf("return == %i\n", strncmp(str1, str, 4));
  printf("-----------------\n[Chaine Salut -- Chaine vide]\n");
  printf("return == %i\n", strncmp(str, str1, 4));

  printf("///// STRCASECMP /////\n");
  str = "Salut1";
  str1 = "salut1";
  str2 = "Sblut";
  printf("-----------------\n[Chaine Salut1 -- Chaine salut1]\n");
  printf("return == %i\n", strcasecmp(str, str1));
  printf("-----------------\n[Chaine Sblut -- Chaine Salut1]\n");
  printf("return == %i\n", strcasecmp(str2, str));
  str = "sblut";
  printf("-----------------\n[Chaine Sblut -- Chaine sblut]\n");
  printf("return == %i\n", strcasecmp(str, str1));


  printf("///// STRCHR /////\n");
  str = "je suis";
  printf("-----------------\n[Chaine je suis -- char s]\n");
  printf("return == %s\n", strchr(str, 's'));
  printf("-----------------\n[Chaine je suis -- char u]\n");
  printf("return == %s\n", strchr(str, 'u'));
  printf("-----------------\n[Chaine je suis -- char NULL]\n");
  printf("return == %s\n", strchr(str, '\0'));

  printf("///// MEMSET /////\n");
  void * test = malloc(sizeof(char) * 100);
  printf("-----------------\n[Chaine je suis -- char 'z' -- length 10]\n");
  printf("return == %s\n", memset(test,'z', 10));
  printf("-----------------\n[Chaine je suis -- char 'w' -- length 1]\n");
  printf("return == %s\n", memset(test,'w', 1));
  printf("-----------------\n[Chaine je suis -- char 'b' -- length 2]\n");
  printf("return == %s\n", memset(test,'b', 2));
  printf("-----------------\n[Chaine je suis -- char 'c' -- length 0]\n");
  printf("return == %s\n", memset(test,'c', 0));
  test = (char *)test;
  printf("///// MEMMOVE /////\n");
  printf("-----------------\n[Chaine je suis -- chaine je suis -- length 1]\n");
  printf("return == %s\n", memmove(test,str, 1));
  printf("-----------------\n[Chaine je suis -- chaine je suis -- length 2]\n");
  printf("return == %s\n", memmove(test,str, 2));
  printf("-----------------\n[Chaine je suis -- chaine je suis -- length 3]\n");
  printf("return == %s\n", memmove(test,str, 3));
  printf("-----------------\n[Chaine je suis -- chaine je suis -- length 0]\n");
  printf("return == %s\n", memmove(test,str, 0));

  printf("///// MEMCPY /////\n");
  test = "salut";
  str  = "abc";
  char lol[4];
  printf("-----------------\n[Chaine vide -- chaine salut -- length 1]\n");
  printf("return == %s\n", memcpy(lol, test, 1));
  printf("-----------------\n[Chaine vide -- chaine salut -- length 2]\n");
  printf("return == %s\n", memcpy(lol,test, 2));
  printf("-----------------\n[Chaine vide -- chaine salut -- length 3]\n");
  printf("return == %s\n", memcpy(lol, test, 3));
  printf("-----------------\n[Chaine vide -- chaine salut -- length 0]\n");
  printf("return == %s\n", memcpy(lol, test, 0));

  printf("///// STRSTR /////\n");
  str  = "salut";
  test = "sa";
  str2 = "lu";
  printf("-----------------\n[Chaine salut -- chaine lu]\n");
  printf("return == %s\n", strstr(str, str2));
  printf("-----------------\n[Chaine salut -- chaine sa]\n");
  printf("return == %s\n", strstr(str, test));

  printf("///// STRSTR /////\n");
  str  = "salut";
  test = "sa";
  str2 = "lu";
  printf("-----------------\n[Chaine salut -- chaine lu]\n");
  printf("return == %s\n", strstr(str, str2));
  printf("-----------------\n[Chaine salut -- chaine sa]\n");
  printf("return == %s\n", strstr(str, test));

  printf("///// RINDEX /////\n");
  str  = "salutlusata";
  printf("-----------------\n[Chaine salutlusata -- char s]\n");
  printf("return == %s\n", rindex(str, 's'));
  printf("-----------------\n[Chaine salutlusata -- char l]\n");
  printf("return == %s\n", rindex(str, 'l'));

  printf("///// STRPBRK /////\n");
  str  = "salutation";
  test = "zxoiuyi";
  str2 = "ti";
  printf("-----------------\n[Chaine salutation -- chaine ti]\n");
  printf("return == %s\n", strpbrk(str, str2));
  printf("-----------------\n[Chaine salutation -- chaine zxoiuyi]\n");
  printf("return == %s\n", strpbrk(str, test));

  printf("///// STRCSPN /////\n");
  str  = "salutation";
  test = "zeze";
  str2 = "zi";
  printf("-----------------\n[Chaine salutation -- chaine zi]\n");
  printf("return == %d\n", strcspn(str, str2));
  printf("-----------------\n[Chaine salutation -- chaine zeze]\n");
  printf("return == %d\n", strcspn(str, test));
  str = "";
  printf("-----------------\n[Chaine salutation -- chaine vide]\n");
  printf("return == %d\n", strcspn(str, test));

  //TESTS PART 2

  char mystr1[] = "Hello world !\n";
  char buf[BUFSIZ];
  str2 = "";
  char str3[] = "worl";
  char str4[] = "toto";
  char c;
  char *p;
  ssize_t ret;

  printf("Test write + sizeof\n");
  ret = write(STDOUT_FILENO, mystr1, sizeof (mystr1));
  printf("=> %d\n", ret);

  printf("Test write + strlen\n");
  ret = write(STDOUT_FILENO, mystr1, strlen(mystr1));
  printf("=> %d\n", ret);

  /*  printf("Test read\n");
  ret = read(STDIN_FILENO, buf, 1);
  printf("=> %d %c\n", ret, *buf);
  */
  printf("=> %s\n", mystr1);

  printf("Test strlen\n");
  printf("=> %d %d\n", strlen(mystr1), strlen(""));

  printf("Test memset\n");
  p = memset(buf, 0, sizeof (buf));
  if (p == buf)
    printf("=> [%s] OK\n", p, buf, p);
  else
    printf("=> [%s] KO\n", p, buf, p);

  printf("Test strcpy\n");
  p = strcpy(buf, "test");
  printf("=> %s\n", p);
  p = strcpy(buf, mystr1);
  printf("=> %s\n", p);

  printf("Test memcpy\n");
  memset(buf, 0, sizeof (buf));
  p = memcpy(buf, mystr1, strlen(mystr1));
  printf("=> %s\n", p);

  printf("Test strchr\n");
  c = 'o';
  printf("=>o [%s]\n", strchr(mystr1, c));
  printf("=>z [%p]\n", strchr(mystr1, 'z'));

  printf("=> %s\n", strrchr(mystr1, c));

  printf("Test strstr\n");
  printf("=> %s\n", strstr(mystr1, str2));
  printf("=> %s\n", strstr(mystr1, str3));
  printf("=> %s\n", strstr(mystr1, str4));

  printf("Test memmove\n");
  memset(buf, 0, sizeof (buf));
  p = memmove(buf, mystr1, strlen(mystr1));
  printf("=> [%s]\n", p);
  p = memmove(buf, buf + 2, 2);
  printf("=> [%s]\n", p);
  p = memmove(buf + 2, buf, 2);
  printf("=> [%s]\n", p);

  {
    char *test = "test";
    char *test2 = "test";
    char *tes = "tes";
    char *a = "a";
    char *b = "b";

    printf("=> strcmp %d %d %d %d\n", strcmp(test, test2), strcmp(test2, tes),
     strcmp(tes, test), strcmp(a, b));

    printf("=> strncmp %d %d %d %d\n", strncmp(test, test2, 3), strncmp(test2, tes, 0),
     strncmp(tes, test, 10), strncmp(a, b, 1));
  }

  {

    char *test = "TeSt";
    char *test2 = "tEsT";
    char *tes = "tES";
    char *a = "a";
    char *b = "b";

    printf("=> strcasecmp %d %d %d %d %d\n", strcasecmp(test, test2), strcasecmp(test2, tes),
     strcasecmp(tes, test), strcasecmp(a, b), strcasecmp(test, "\0"));

  }

  {
  }
  printf("_____________________\n");
  str ="abcdefghijklmnopqrstuvwxyz";
    char c1 = '\0';
    char c2 = '-';
    char c3 = 'a';
    char c4 = 'z';
    char c5 = '0';

    printf("=>strchr [%s] [%s] [%s] [%s] [%s]\n",
           strchr(str, c1),
           strchr(str, c2),
           strchr(str, c3),
           strchr(str, c4),
           strchr(str, c5));


  //TESTS PART 3

  srand(23454);
  memcpy_test();
  memmove_test();
  memset_test();
  //read_test();
  rindex_test();
  strcasecmp_test();
  strchr_test();
  strcmp_test();
  strcspn_test();
  strlen_test();
  strncmp_test();
  strstr_test();
  //write_test();
}