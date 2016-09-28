#include <stdio.h>
#include <string.h>

int main()
{
   printf("Hello! What's your name, my lovely human?\n"); //Welcome message
   char name[20]; //initializes the "name" variable
   gets(name); //gets input and stores it in the "name" variable

   if(!strcmp(name, "Leon") || !strcmp(name, "Mads")) // if input is Leon or Mads, this will give a nonzero value. You need "!" at the start, otherwise it won't work
    {
    printf("Cool name, %s! Welcome! \nMy name is God Emperor Claudius Septimus Julius Massivus Dickus\n", name);
    }
   else //if input is anything other than Leon or Mads
   {
    printf("Nice to meet you! \nMy name is God Emperor Claudius Septimus Julius Massivus Dickus\n"); //prints this out to screen
   }
   printf("How are you feeling on this fine day? Type \"happy\" or 'sad', depending on your feelings\n");
   char HappySad; //initializes the variable HappySad
   MyLabel:
   HappySad = getc(stdin); //gets input to HappySad
   switch(HappySad) {
    case 'h':
        printf("Yay! I'm happy too. I guess. I'm a computer. I don't have feelings");
        break;
    case 's':
        printf("Oh no :( don't be sad. Here's some fun facts to cheer you up: \n");
        printf("Crows are left winged\n");
        printf("You can determine a horse's sex by the number of their teeth. Males have 40, females have 38\n");
        printf("It's illegal to own a pet dog in Iceland\n");
        printf("A savköpõ menyétek megtámadták Európát\n");
        break;
    default:
        printf("You idiot. You typed in something that isn't 'happy' or 'sad'. You fail at following directions. Pls type happy or sad\n");
        goto MyLabel;
        break;

        }
    return 0;
}

