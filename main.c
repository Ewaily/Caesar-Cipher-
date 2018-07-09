/*
    * Muhammad Ashraf Ewaily        14101380
    * Computer System Security | Caesar Cipher
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{

    char eMessage[100],dMessage[100],message[100], ch,j;
    int i, key;

    printf("1. Encrypt \n2. Decrypt \nEnter 1 or 2:");
    scanf("%c",&j);

    if (j=='1'){

        printf("Enter key: ");
        scanf("%d", &key);
        fflush(stdin);

        printf("\nEnter a message to encrypt: ");
        gets(eMessage);

        for(i = 0; eMessage[i] != '\0'; ++i){
            ch = eMessage[i];

            if(ch >= 'a' && ch <= 'z'){
                ch = ch + key;

                if(ch > 'z'){
                    ch = ch - 'z' + 'a' - 1;
                }

                eMessage[i] = ch;
            }
            else if(ch >= 'A' && ch <= 'Z'){
                ch = ch + key;

                if(ch > 'Z'){
                    ch = ch - 'Z' + 'A' - 1;
                }

                eMessage[i] = ch;
            }
        }

        printf("Encrypted message: %s", eMessage);
    }


    else if (j=='2'){



        fflush(stdin);

        printf("\nEnter a message to decrypt: ");
        gets(message);

      /*int len = strlen(message);
        strncpy(dMessage,message,len-4);*/

        for(i=0; message[i] != '\0'; i++)
            dMessage[i] = message[i];
        int dKey = 0;

        while(dKey<26){



                  for(i = 0; dMessage[i] != '\0'; ++i){
                    ch = dMessage[i];

                    if(ch >= 'a' && ch <= 'z'){
                        ch = ch - dKey;

                        if(ch < 'a'){
                            ch = ch + 'z' - 'a' + 1;
                        }

                        dMessage[i] = ch;
                    }
                    else if(ch >= 'A' && ch <= 'Z'){
                        ch = ch - dKey;

                        if(ch < 'A'){
                            ch = ch + 'Z' - 'A' + 1;
                        }

                        dMessage[i] = ch;
                    }
                }

                printf("Key = %d :: Decrypted message: %s\n",dKey, dMessage);
                dKey ++;

                for(i=0; message[i] != '\0'; i++)
                    dMessage[i] = message[i];

              //  strncpy(dMessage,message,len-4);
            }
    }


    else

      printf("Invalid Input");

    return 0;
}
