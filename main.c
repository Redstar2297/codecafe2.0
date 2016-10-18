#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //Welcome message
    printf("Welcome to the Game.\n");
    //Name
    char name[10];      //stores your input
        printf("\nPlease enter your name: ");
        scanf("%s",&name);      //searches and than sends 'name'
    //The start scenario
    printf("Now %s, imagine waking up in a corridor, made of concrete. There's mold, from leaking water pipes, on some of the walls there.\n",name);
    printf("You have a door in front of you, where you can see a dim light coming out from under the door.\n");
    printf("You also have a door behind you, it has a small sign on the door, but you can't see what the name says.\n");
    printf("So now do you go to 'ahead' or 'behind' you?\n",name);
    //The Corridor scenario
    char door_in_corridor[20];
    while(scanf("%19s",door_in_corridor)){  //'Corridor' while start
            if (!strcmp(door_in_corridor,"behind")||!strcmp(door_in_corridor,"Behind")){
                printf("Going to check the small sign.\n");
                printf("As you get closer to the door, trying to read the sign, the lights starts blinking.\n");
                printf("You see the sign says:\n\nMental patients\n%s\nJudy\nClaus\nStuart\nLisa\n\n",name);
                printf("The lights burn out, the whole corridor is dark.\nThe only light left, is the dim light from the other end of the corridor.\n");
                printf("You hear the door handle, trying to turn.\nWhat do you do?\nTry to 'grab' the handle or 'turn' around toward the dim light.\n");
                        char handle_or_light[20];
                        while(scanf("%19s",handle_or_light)){
                            if(!strcmp(handle_or_light,"grab")||!strcmp(handle_or_light,"Grab")||!strcmp(handle_or_light,"handle")||!strcasecmp(handle_or_light,"Handle")){
                                printf("The door is locked.\nTry to turn around.\n");
                            continue;
                            }   //'grab' if end
                            if(!strcmp(handle_or_light,"turn")||!strcmp(handle_or_light,"Turn")){
                                printf("Turning around.\nDo want to go toward the door, with the light?\n");
                            break;  //'turn/grab' break
                            }   //'turn' if end
                            else{
                                printf("That was not a choice.\nPlease try again.\n");
                            continue;
                            }   //else end
                        }   //'handle or light' while end
            continue;  //'behind' continue
            }   //'behind' if end
            if (!strcmp(door_in_corridor,"ahead")||!strcmp(door_in_corridor,"Ahead")||!strcmp(door_in_corridor,"yes")||!strcasecmp(door_in_corridor,"Yes")){
                printf("Going to check on the door, with the dimmed light.\n");
                printf("As you come closer to the door with the dim light, it opens wide, with a creaking sound.\n");
                printf("You enter through the door, and find yourself in a room with barred windows.\n");
                printf("To your left there's a rocking chair, calmly going back and forth.\n");
                printf("In front of you there's a bunch of letter cubes, it look likes there's some blood on some of them.\n");
                printf("To your right there's a window, through it, you see a single street lamp, which brings the dim light in the room.\n");
                printf("Now do you go to the 'left' to the rocking chair, do you go 'forward' to look on the letter cubes or to the 'right' to look out the window?\n",name);
                    char window_or_chair[20];
                    while(scanf("%19s",window_or_chair)){
                        if(!strcmp(window_or_chair,"left")||!strcmp(window_or_chair,"Left")){
                            printf("The rocking chair calmly going back and forth.\n");
                            printf("When are about an arm's length away from the chair you feel a chill.\n");
                            printf("The chair stops in motion being held back, as if someone was sitting in it.\n");
                            printf("You try to touch the chair, but your hand goes through the wood.\n");
                            printf("The light from the window goes dark and the chair is gone.\n");
                            printf("You hear steps behind you. You turn.\n");
                            printf("A man stands in front of you, smiling. With a grin going from ear to ear.\n");
                            printf("What do you do?\n");
                            char run_from_man[20];
                            while(scanf("%19s",run_from_man)){
                                if (!strcmp(run_from_man,"run")||!strcmp(run_from_man,"RUN")||!strcmp(run_from_man,"Run")){
                                    printf("You start running away from the man, you can hear his laughter right behind you.\n");
                                    if (!strcmp(run_from_man,"run")||!strcmp(run_from_man,"RUN")||!strcmp(run_from_man,"Run")){
                                    printf("While you are running, the man follows you like a shadow.\nWhat do you do?\n");
                                    continue;
                                    }   //running if end
                                    else{
                                    printf("You died.\n");
                                    }   //running else end
                                }   //run if end
                                else{
                                    printf("You died.\n");
                                }   //run else end
                                break;
                            }   //Run from man while end
                        break;
                        }   //Left if end
                        if(!strcmp(window_or_chair,"forward")||!strcmp(window_or_chair,"Forward")){
                            printf("As you some of the letter cubes have blood on them.\n");
                            printf("The ones with blood on spells: %s\n",name);
                            printf("You see that the letter cubes left are paired in four. All pairs spells: KILL\n");
                            printf("You hear the door you came from slams and locks.\n");
                            printf("A piercing laughter goes through the entire room.\n");
                            printf("It's so loud that it could as easily come from yourself.\n");
                            printf("It stops and there's completely silence.\n");
                            printf("Going back to where you came from. What do you do now?\n");
                        continue;
                        }   //Forward if end
                        if(!strcmp(window_or_chair,"right")||!strcmp(window_or_chair,"Right")){
                            printf("You look out the window and see someone standing down in front of the street lamp.\n");
                            printf("The only thing you can see in his dark shadow is his ear to ear grin.\n");
                            printf("As almost a thick fog he glides toward the wall beneath the window.\n");
                            printf("He hits the wall and dissolves into a cloud, and he's gone.\n");
                            printf("Going back to where you came from. What do you do now?\n");
                        continue;
                        }   //right if end
                        else{
                            printf("That was not a choice.\nPlease try again.\n");
                        continue;
                        }   //else end
                    }   //'window of chair' while end
            break;  //'ahead' break
            }   //'ahead' if end
            else{
                printf("That was not a choice.\nPlease try again.\n");
            continue;
            }   //else end
    }   //'Corridor' while end
    printf("\nGame over.\n");
    return 0;
}
