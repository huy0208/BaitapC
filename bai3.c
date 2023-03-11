#include <stdio.h>
char arr[] = "The Grammy award-winning  singer. who has been less active on digital platforms in recent weeks. explained her decision to distance herself from social media platforms during an appearance on the Conan OBrien Needs a Friend podcast, alongside her brother Finneas";

//C1
void reverseWords(char *sentence) {
    char *start = sentence;
    char *end = sentence;

    // dao nguoc mot chuoi ky tu duoc truyen vao
    while (*end) {
        end++;
    }
    end--;

    char temp;
    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
    
    // dao nguoc cac tu  trong chuoi ky tu duoc truyen vao
    start = sentence;
    end = sentence;
    while (*end) {
        if (*end == ' ') { //// tim dau cach de xac dinh tu cuoi cung
            
            char *wordEnd = end - 1;
            char wordTemp;
            while (start < wordEnd) {
                wordTemp = *start;
                *start = *wordEnd;
                *wordEnd = wordTemp;
                start++;
                wordEnd--;
            }
            start = end + 1;  // chuyen sang tu tiep theo
        }
        end++;
    }
    // dao nguoc tu cuoi cung trong cau
    char *lastWordEnd = end - 1;
    char lastWordTemp;
    while (start < lastWordEnd) {
        lastWordTemp = *start;
        *start = *lastWordEnd;
        *lastWordEnd = lastWordTemp;
        start++;
        lastWordEnd--;
    }

    // Print the reversed sentence
    printf("%s", sentence);
}

//C2
void uppercaseAfterDotSpace(char sentence[]) {
    int uppercaseNext = 1;
    for (int i = 0; sentence[i] != '\0'; i++) {
        if (sentence[i] == '.' && sentence[i+1] == ' ') {
            uppercaseNext = 1;
        } else if (uppercaseNext && sentence[i] >= 'a' && sentence[i] <= 'z') {
            sentence[i] = sentence[i] - 'a' + 'A';
            uppercaseNext = 0;
        }
    }
    printf("%s", sentence);
}
//C3
void lowcase(char sentence[]) 
{
    for (int i = 0; sentence[i] != '\0'; i++) {
        if (sentence[i] >= 'A' && sentence[i] <= 'Z') {
            printf("%c", sentence[i] + 32); 
        } else {
            printf("%c", sentence[i]);
            }
        }
}
//C4
void upcase(char sentence[]) 
{
    for (int i = 0; sentence[i] != '\0'; i++) {
        if (sentence[i] >= 'a' && sentence[i] <= 'z') {
            printf("%c", sentence[i] - 32); 
        } else {
            printf("%c", sentence[i]); 
            }
        }
}

int main(int argc, char const *argv[]){
    char sentence[3000] = "The Grammy award-winning singer. who has been less active on digital platforms in recent weeks. explained her decision to distance herself from social media platforms during an appearance on the Conan OBrien Needs a Friend podcast, alongside her brother Finneas";
    printf("Chuoi ban dau \n%s\n",arr);
    printf("chuoi dao nguoc:\n");
    reverseWords(sentence);
    printf("\n..............................................\n");
    printf("chuoi in hoa sau dau cham:\n");
    uppercaseAfterDotSpace(sentence);
    printf("\n..............................................\n");
    printf("chuoi viet thuong:\n");
    lowcase(sentence);
    printf("\n..............................................\n");
    printf("chuoi viet hoa:\n");
    upcase(sentence);
    printf("\n..............................................\n");
    return 0;
}
