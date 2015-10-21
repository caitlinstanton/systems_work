#include <stdio.h>

//String Length
int cstrlen(char *s) {
  int size = 0;
  for (size = 0; *s; s++) {
    size++;
  }
  return size;
}

//String Copy
char *cstrcpy(char *dest, char *src) {
  int destsrc = cstrlen(dest);
  int lensrc = cstrlen(src);
  if (lensrc <= destsrc) {
    int counter = 0;
    while (counter <= lensrc) {
      dest[counter] = src[counter];
      counter++;
    }
    return dest;
  } else {
    char error[] = "ERROR: DEST IS SHORTER THAN SRC";
    return error;
  }
}

//String Cat
char *cstrcat(char *dest, char *src) {
  int lendest = cstrlen(dest);
  int lensrc = cstrlen(src);
  int destcounter = lendest;
  int srccounter = 0;
  int lentotal = lendest + lensrc;
  while (destcounter <= lentotal) {
    dest[destcounter] = src[srccounter];
    destcounter++;
    srccounter++;
  }
  return dest;
}

int cstrcmp(char *str1, char *str2) {
	int lenstr1 = cstrlen(str1);
	int lenstr2 = cstrlen(str2);
	int counter = 0;
	while (counter < 0) {
		if (str1[counter] != str2[counter]) {
			return str1[counter] - str2[counter];
		}
		counter++;
	}
	return str1[counter] - str2[counter];
}

char *cstrchr(char *str, int character) {
	int len = cstrlen(str);
	int counter = 0;
	int *pchar = 0;
	while (counter < len) {
		if (character == str[counter]) {
			*pchar = str[counter];
		}
	}
	return *pchar;
}

char *cstrstr(char *str1, char *str2) {
	while (*str1) {
		char*s1 = str1;
		char*s2 = str2;
		while (*s1 && *s2 && (*s1++ == *s2++));
			if (!*s2){
				return str1; 
			}
		str1++; 
	}
}

int main() {
 char word[30] = "hallway";
  char phrase[30] = "spray paint";
  char y[20] = "everything";
  char s[20] = "I am ";

  printf("\nWORDS:\n");
  printf("s1 = %s\n", word);
  printf("s2 = %s\n", phrase);
  printf("s3 = %s\n", y);
  printf("s4 = %s\n\n", s);

  printf("STRLEN:\n");
  printf("real size of s1 = %d\n", strlen(word));
  printf("my size of s1 = %d\n", cstrlen(word));
  printf("real size of '' = %d\n", strlen(""));
  printf("my size of '' = %d\n\n", cstrlen(""));

  printf("STRCMP:\n");
  printf("real strcmp(s1, s2) = %d\n", strcmp(word, phrase));
  printf("my strcmp(s1, s2) = %d\n", cstrcmp(word, phrase));
  printf("real strcmp(s1, s1) = %d\n", strcmp(word, word));
  printf("my strcmp(s1, s1) = %d\n", cstrcmp(word, word));
  printf("real strcmp('', s1) = %d\n", strcmp("", word));
  printf("my strcmp('', s1) = %d\n\n", cstrcmp("", word));

  printf("STRCPY:\n");
  printf("real copy = %s\n", strcpy(y, word));
  printf("my copy of s1 into s3, s3 = '%s'\n\n", cstrcpy(y, word));

  printf("STRCAT:\n");
  printf("real strcat of s4 and s2= %s\n", strcat(s, phrase));
  printf("my strcat of s4 and s2 = '%s'\n\n", cstrcat(s, phrase));

  printf("UPDATED WORDS:\n");
  printf("s1 = %s\n", word);
  printf("s2 = %s\n", phrase);
  printf("s3 = %s\n", y);
  printf("s4 = %s\n\n", s);

  printf("STRCHR:\n");
  printf("real strchr(s3, 'e') = %p\n", strchr(y, 'e'));
  printf("my strchr(s3, 'e') = %p\n", cstrchr(y, 'e'));
  printf("real strchr(s3, 'z') = %p\n", strchr(y, 'z'));
  printf("my strchr(s3, 'z') = %p\n\n", cstrchr(y, 'z'));

  char*new1 = "all";
  char*new2 = "way";
  printf("STRSTR:\n");
  printf("real strstr(s3, 'ide') = %p\n", strstr(y, new1));
  printf("my strstr(s3, 'ide') = %p\n", cstrstr(y, new1));
  printf("real strstr(s3, 'walk') = %p\n", strstr(y, new2));
  printf("my strstr(s3, 'walk') = %p\n", cstrstr(y, new2));
  printf("real strstr(s3, '') = %p\n", strstr(y, ""));
  printf("my strstr(s3, '') = %p\n\n", cstrstr(y, ""));
  printf("real strstr('', 'side') = %p\n", strstr("", new1));
  printf("my strstr('', 'side') = %p\n\n", cstrstr("", new1));

  return 0;
}

